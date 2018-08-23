import "random" for Random
import "toy" for ScriptClass, Complex, Vec2, Vec3, Colour, Capsule, Axis, Cube, Sphere, Quad, Symbol, Ui, Key, EventType, InputMod, Gfx, ItemFlag, BackgroundMode, DefaultWorld, Entity, Movable, Solid, CollisionShape, GameMode, OrbitMode

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
        _entity = Entity.new(id, _complex, parent, position)
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

class Body {
	construct new(id, parent, position, shape, colour) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position)
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, CollisionShape.new(shape), false, 1.0)
        _shape = shape
        _colour = colour
        _complex.setup([_entity, _movable, _solid])
    }
    
    entity { _entity }
    shape { _shape }
    colour { _colour }
    
    model { _model }
    model=(value) { _model = value }
    material { _material }
    material=(value) { _material = value }
    
    static bind() { __cls = ScriptClass.new("Body", [Entity.type, Movable.type, Solid.type]) }
}

class Terrain {
	construct new(id, parent, size) {
        _quad = Quad.new(Vec3.new(size,0,size), Vec3.new(size,0,-size), Vec3.new(-size,0,-size), Vec3.new(-size,0,size))
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, Vec3.new(0, -10, 0))
        _solid = Solid.new(_entity, CollisionShape.new(_quad), true, 0.0)
        _complex.setup([_entity, _solid])
    }
    
    quad { _quad }
    entity { _entity }
    material { _material }
    material=(value) { _material = value }
    
    static bind() { __cls = ScriptClass.new("Terrain", [Entity.type, Solid.type]) }
}

class Player {
	construct new(world) {
        _world = world
        _human = Human.new(0, _world.origin, Vec3.new(0))
    }
    
    human { _human }
}

var GWorld = null
var GTerrain = null
var GPlayer = null
var GBodies = []
var GScene = null

foreign class MyGame {

    static new(module) { __constructor.call(MyGame, module) }
    
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) {
        app.gfx.add_resource_path("examples/05_character/")
        start(app, game)
    }
    
    start(app, game) {
        GWorld = DefaultWorld.new("")
        game.world = GWorld.world
        
        GTerrain = Terrain.new(0, GWorld.world.origin, 100)
        GTerrain.material = Gfx.pbr_material(app.gfx, "ground", Colour.new(0.3, 1))
        
        GPlayer = Player.new(GWorld.world)
        
        var rand = Random.new()
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), rand.float(0, 20), rand.float(-50, 50))
            var colour = Colour.hsl(rand.float(0, 1), 1, 0.5)
            GBodies.add(Body.new(0, GWorld.world.origin, position, Cube.new(Vec3.new(rand.float(1, 5))), colour)) // Colour.new(0.7, 1)
        }
        
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), rand.float(0, 20), rand.float(-50, 50))
            var colour = Colour.hsl(rand.float(0, 1), 1, 0.5)
            GBodies.add(Body.new(0, GWorld.world.origin, position, Sphere.new(rand.float(1, 5)), colour)) // Colour.new(0.7, 1)
        }
        
        for (body in GBodies) {
            body.model = app.gfx.fetch_symbol(Symbol.new(Colour.White), body.shape, DrawMode.PLAIN)
            body.material = Gfx.pbr_material(app.gfx, "body %(body.entity.id)", body.colour)
        }
        
		GScene = app.add_scene() // if this is before creating the bodies meshes, wren crashes... WHY
    }
    
    pump(app, game, ui) {
        var viewer = Ui.viewer(ui, GScene.scene)
        this.control_human(app, game, viewer, GPlayer.human)
    }
    
    scene(app, scene) {}
    
    paint(app, scene, graph) {
        //Toy.paint_physics(graph, GWorld.world)
        
        this.paint_scene(app, graph)
        this.paint_terrain(app, graph, GTerrain)
        this.paint_human(app, graph, GPlayer.human)
        
        for (body in GBodies) {
            this.paint_body(app, graph, body)
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
    
    paint_scene(app, parent) {
        Gfx.radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode.Radiance)
        Gfx.sun_light(parent, 0, 0.37)
    }
    
    paint_terrain(app, parent, terrain) {
        var self = Gfx.node(parent, terrain, terrain.entity.position, terrain.entity.rotation)
        Gfx.shape(self, terrain.quad, Symbol.new(Colour.White), 0, terrain.material)
    }
    
    paint_human(app, parent, human) {
        var model = app.gfx.models.file("human00")
        
        var self = Gfx.node(parent, human, human.entity.position, human.entity.rotation)
        var item = Gfx.item(self, model, ItemFlag.ITEM_SELECTABLE)
        var animated = Gfx.animated(self, item)

        if(animated.playing() != human.state.name) {
            animated.play(human.state.name, human.state.loop)
        }
    }
    
    paint_body(app, parent, body) {
        var self = Gfx.node(parent, body, body.entity.position, body.entity.rotation)
        Gfx.item(self, body.model, 0, body.material, 0, [])
    }
}

Human.bind()
Body.bind()
Terrain.bind()
MyGame.bind()

var game = MyGame.new(module)
