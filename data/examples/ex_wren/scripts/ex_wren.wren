import "mud" for Complex, vec3, quat, Colour, Capsule, Cube, Symbol
import "toy" for Entity, Movable, Solid, CollisionShape, GameShell

class Human {

	construct Human(id, parent, position) {
        _complex = Complex.new(id, __type)
        _entity = Entity.new(id, _complex, parent, position, quat.new(0,0,0,1))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, this, CollisionShape.new(Capsule.new(0.35, 1.1), vec3.new(0, 0.9, 0)), false, 1.0)
    }
    
    static init() { __type = Type.new("Human") }
}

class Crate {

	construct new(id, parent, position, extents) {
        _complex = Complex.new(id, __type)
        _entity = Entity.new(id, this, parent, position, quat.new(0,0,0,1))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, this, CollisionShape.new(Cube.new(extents)), false, 1.0)
        _extents = extents
    }
    
    static init() { __type = Type.new("Crate") }
}

class Player {

	construct new(world) {
        _world = world
        _human = Human.new(0, _world.origin, vec3.new(0))
    }
}

foreign class GameModule {

    static new(module) { __constructor.call(module) }
    
    static init() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) {}
    
    start(app, game) {
        //_world = World.new(0, 'Example')
        //_player = Player.new(_world)
        //_crates = []
        //for (i in 0...50)
        //    _crates[i] = Crate.new(0, _world.origin, vec3.new(), vec3.new(1))
    }
    
    pump(app, game) {
        var ui = app.ui.begin()
        var viewer = ui.scene_viewer(ui)
        
        var scene = viewer.scene.begin()
        
        var node = gfx.node(scene, {}, vec3.new(0, 0, 0))
        gfx.shape(node, Cube.new(), Symbol.new(Colour.Pink))
    }
    
    scene(app, game) {}
}

Human.init()
Crate.init()
GameModule.init()

var game = GameModule.new(module)
app.run_game(game)

while (true) {
    System.print("one frame")
}