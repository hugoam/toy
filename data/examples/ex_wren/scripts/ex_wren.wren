import "random" for Random
import "mud" for ScriptClass, Complex, Vec2, Vec3, Quat, Colour, Capsule, Axis, Cube, Quad, Symbol, SymbolDetail, Ui, Gfx, ItemFlag
import "toy" for World, BulletWorld, Entity, Movable, Solid, CollisionShape, CollisionGroup, GameShell

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
        
        _state = State.new("Idle", true)
    }
    
    entity { _entity }
    state { _state }
    
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

	construct new(id, parent) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, Vec3.new(0), Quat.new(1,0,0,0))
        _solid = Solid.new(_entity, CollisionShape.new(Quad.new(Vec3.new(1,0,1), Vec3.new(1,0,-1), Vec3.new(-1,0,-1), Vec3.new(-1,0,1)), Vec3.new(0, -10, 0), 0), true, 1.0)
        _complex.setup([_entity, _solid])
    }
    
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
        
        _terrain = Terrain.new(0, _world.origin)
        _player = Player.new(_world)
        _crates = []
        
        var rand = Random.new()
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), 0, rand.float(-50, 50))
            _crates.add(Crate.new(0, _world.origin, position, Vec3.new(1)))
        }
    }
    
    world { _world }
    player { _player }
    crates { _crates }
    
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
        MainWorld = GameWorld.new(0)
        game.world = MainWorld.world
    }
    
    pump(app, game) {
    
        var ui = app.ui.begin()
        var viewer = Ui.scene_viewer(ui, Vec2.new(0))
        var orbit = Ui.orbit_controller(viewer, 0, 0, 1)
        
        var scene = viewer.scene.begin()
        
        paint_human(app, scene, MainWorld.player.human)
        
        for(crate in MainWorld.crates) {
            paint_crate(scene, crate)
        }
    }
    
    scene(app, game) {}
    
    paint_human(app, parent, human) {
    
        var model = app.gfx.models.file("human00")
        
        var self = Gfx.node(parent, human, human.entity.position, human.entity.rotation, Vec3.new(1))
        var item = Gfx.item(self, model, ItemFlag.ITEM_SELECTABLE, null, 0, [])
        var animated = Gfx.animated(self, item)

        if(animated.playing() != human.state.name) {
            animated.play(human.state.name, human.state.loop, 0, 1, false)
        }
    }
    
    paint_crate(parent, crate) {
    
        var self = Gfx.node(parent, crate, crate.entity.position, crate.entity.rotation, Vec3.new(1))
        var symbol = Symbol.new(Colour.None, Colour.White, false, false, SymbolDetail.Medium)
        Gfx.shape(self, Cube.new(crate.extents), symbol, 0, null, 0)
    }
}

Human.bind()
Crate.bind()
Terrain.bind()
GameWorld.bind()
MyGame.bind()

var game = MyGame.new(module)
