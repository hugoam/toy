import "random" for Random
import "mud" for ScriptClass, Complex, Vec2, Vec3, Quat, Colour, Capsule, Axis, Cube, Quad, Symbol, SymbolDetail, Ui, Key, EventType, InputMod, Gfx, ItemFlag, BackgroundMode
import "toy" for World, BulletWorld, Entity, Movable, Solid, CollisionShape, CollisionGroup, GameShell, GameMode
import "ui" for OrbitMode

class State {

    construct new(name, loop) {
        _name = name
        _loop = loop
    }
    
    name { _name }
    loop { _loop }
}

class Human {

	construct new(id, parent, position) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position, Quat.new(1,0,0,0))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, CollisionShape.new(Capsule.new(0.35, 1.1, Axis.X), Vec3.new(0, 0.9, 0), 0), false, 1.0)
        _complex.setup([_entity, _movable, _solid])
        
        _aiming = true
        _angles = Vec2.new(0)
        _force = Vec3.new(0)
        _torque = Vec3.new(0)
        _state = State.new("Idle", true)
    }
    
    update() {
        if (Mud.length2(_force) != 0 || Mud.length2(_torque) != 0) {
            _state = State.new("RunAim", true)
        } else {
            _state = State.new("Idle", true)
        }
        
        var velocity = _solid.impl.linear_velocity()
        var force = Mud.rotate(_entity.rotation, _force)
        _solid.impl.set_linear_velocity(Vec3.new(force.x, velocity.y - 1, force.z))
        _solid.impl.set_angular_velocity(_torque)
        _solid.impl.set_angular_factor(Vec3.new(0))
    }
    
    entity { _entity }
    solid { _solid }
    state { _state }
    aiming { _aiming }
    angles { _angles }
    force { _force }
    torque { _torque }
    
    static bind() { __cls = ScriptClass.new("Human", [Entity.type, Movable.type, Solid.type]) }
}

class Crate {

	construct new(id, parent, position, extents) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position, Quat.new(1,0,0,0))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, CollisionShape.new(Cube.new(extents), Vec3.new(0), 0), false, 1.0)
        _extents = extents
        _complex.setup([_entity, _movable, _solid])
    }
    
    entity { _entity }
    extents { _extents }
    
    static bind() { __cls = ScriptClass.new("Crate", [Entity.type, Movable.type, Solid.type]) }
}

class Terrain {

	construct new(id, parent, size) {
        _quad = Quad.new(Vec3.new(size,0,size), Vec3.new(size,0,-size), Vec3.new(-size,0,-size), Vec3.new(-size,0,size))
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, Vec3.new(0, -10, 0), Quat.new(1,0,0,0))
        _solid = Solid.new(_entity, CollisionShape.new(_quad, Vec3.new(0), 0), true, 0.0)
        _complex.setup([_entity, _solid])
    }
    
    quad { _quad }
    entity { _entity }
    
    static bind() { __cls = ScriptClass.new("Terrain", [Entity.type, Solid.type]) }
}

class Player {

	construct new(world) {
        _world = world
        _human = Human.new(0, _world.origin, Vec3.new(0))
    }
    
    human { _human }
}

class GameWorld {

    construct new(id) {
        _complex = Complex.new(id, __cls.type)
        _world = World.new(id, _complex, "Example")
        _bullet_world = BulletWorld.new(_world)
        _complex.setup([_world, _bullet_world])
        
        _terrain = Terrain.new(0, _world.origin, 100)
        _player = Player.new(_world)
        _crates = []
        
        var rand = Random.new()
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), 0, rand.float(-50, 50))
            _crates.add(Crate.new(0, _world.origin, position, Vec3.new(1)))
        }
    }
    
    world { _world }
    terrain { _terrain }
    player { _player }
    crates { _crates }
    
    scene { _scene }
    scene=(value) { _scene = value }
    
    static bind() { __cls = ScriptClass.new("GameWorld", [World.type, BulletWorld.type]) }
}

var MainWorld = null

foreign class MyGame {

    static new(module) { __constructor.call(MyGame, module) }
    
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) {
        app.gfx.add_resource_path("examples/05_character/")
        start(app, game)
    }
    
    start(app, game) {
        var world = GameWorld.new(0)
        MainWorld = world
        game.world = world.world
		world.scene = app.add_scene()
    }
    
    pump(app, game) {
    
        var world = MainWorld
        
        var ui = game.screen ? game.screen : app.ui.begin()
        var viewer = Ui.viewer(ui, world.scene.scene)
        //var orbit = Ui.orbit_controller(viewer, 0, 0, 1)
        
        this.control_human(app, game, viewer, world.player.human)
        
    }
    
    scene(app, scene) {}
    
    paint(app, scene) {
    
        var world = MainWorld
        var root = scene.scene.graph
        
        //Toy.paint_physics(root, world.world)
        
        this.paint_scene(app, root)
        
        this.paint_terrain(app, root, world.terrain)
        
        this.paint_human(app, root, world.player.human)
        
        for(crate in world.crates) {
            this.paint_crate(app, root, crate)
        }
    }
    
    control_human(app, game, viewer, human) {
    
        if(game.mode == GameMode.Play && !viewer.modal()) {
            viewer.take_modal(62)
        }
        
        Ui.hybrid_controller(viewer, OrbitMode.ThirdPerson, human.entity, human.aiming, human.angles)
        Ui.velocity_controller(viewer, human.force, human.torque, 10)

        human.update()
        
        if(viewer.key_stroke(Key.Escape, InputMod.None).valid()) {
            app.editor.play_game = false
            viewer.yield_modal()
            if(app.context.mouse_lock) {
                app.context.lock_mouse(false)
            }
        }
    }
    
    pbr_material(app, name, colour) {
    
        var program = app.gfx.programs.file("pbr/pbr")
        var material = app.gfx.materials.fetch(name)
        material.program = program
        material.pbr_block.enabled = true
        material.pbr_block.albedo.value = colour
        return material
    }
    
    paint_scene(app, parent) {
    
        Gfx.radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode.Radiance)
        Gfx.sun_light(parent, 0, 0.37)
    }
    
    paint_terrain(app, parent, terrain) {
    
        var self = Gfx.node(parent, terrain, terrain.entity.position, terrain.entity.rotation, Vec3.new(1))
        var symbol = Symbol.new(Colour.None, Colour.White, false, false, SymbolDetail.Medium)
        var material = this.pbr_material(app, "ground", Colour.new(0.3, 1))
        Gfx.shape(self, terrain.quad, symbol, 0, material, 0)
    }
    
    paint_human(app, parent, human) {
    
        var model = app.gfx.models.file("human00")
        
        var self = Gfx.node(parent, human, human.entity.position, human.entity.rotation, Vec3.new(1))
        var item = Gfx.item(self, model, ItemFlag.ITEM_SELECTABLE, null, 0, [])
        var animated = Gfx.animated(self, item)

        if(animated.playing() != human.state.name) {
            animated.play(human.state.name, human.state.loop, 0, 1, false)
        }
    }
    
    paint_crate(app, parent, crate) {
    
        var self = Gfx.node(parent, crate, crate.entity.position, crate.entity.rotation, Vec3.new(1))
        var symbol = Symbol.new(Colour.None, Colour.White, false, false, SymbolDetail.Medium)
        var material = this.pbr_material(app, "crate", Colour.new(0.7, 1))
        Gfx.shape(self, Cube.new(crate.extents), symbol, 0, material, 0)
    }
}

Human.bind()
Crate.bind()
Terrain.bind()
GameWorld.bind()
MyGame.bind()

var game = MyGame.new(module)
