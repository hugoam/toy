import "mud" for ScriptClass, Complex, Vec2, Vec3, Quat, Colour, Capsule, Cube, Symbol, SymbolDetail, Ui, Gfx
import "toy" for World, BulletWorld, Entity, Movable, Solid, CollisionShape, GameShell

class Human {

	construct Human(id, parent, position) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position, quat.new(0,0,0,1))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, CollisionShape.new(Capsule.new(0.35, 1.1), vec3.new(0, 0.9, 0)), false, 1.0)
        _complex.setup([_entity, _movable, _solid])
    }
    
    static bind() { __cls = ScriptClass.new("Human", [Entity.type, Movable.type, Solid.type]) }
}

class Crate {

	construct new(id, parent, position, extents) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position, quat.new(0,0,0,1))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, CollisionShape.new(Cube.new(extents)), false, 1.0)
        _extents = extents
        _complex.setup([_entity, _movable, _solid])
    }
    
    static bind() { __cls = ScriptClass.new("Crate", [Entity.type, Movable.type, Solid.type]) }
}

class Player {

	construct new(world) {
        _world = world
        _human = Human.new(0, _world.origin, vec3.new(0))
    }
}

class GameWorld {

    construct new(id) {
        _complex = Complex.new(id, __cls.type)
        _world = World.new(id, _complex, "Example")
        _bullet_world = BulletWorld.new(_world)
        _complex.setup([_world, _bullet_world])
        
        _player = Player.new(_world)
        _crates = []
        for (i in 0...50) {
            _crates[i] = Crate.new(0, _world.origin, vec3.new(), vec3.new(1))
        }
    }
    
    static bind() { __cls = ScriptClass.new("GameWorld", [World.type, BulletWorld.type]) }
}

var MainWorld = null

foreign class MyGame {

    static new(module) { __constructor.call(MyGame, module) }
    
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) { start(app, game) }
    
    start(app, game) { MainWorld = GameWorld.new(0) }
    
    pump(app, game) {
        var ui = app.ui.begin()
        var viewer = Ui.scene_viewer(ui, Vec2.new(0))
        
        var scene = viewer.scene.begin()
    }
    
    scene(app, game) {}
}

Human.bind()
Crate.bind()
GameWorld.bind()
MyGame.bind()

var game = MyGame.new(module)
