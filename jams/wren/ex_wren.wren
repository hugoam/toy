class Human : public Complex 
{
	construct Human(id, parent, position) {
        super(id, Human.type, movable, *this)
        _entity = Entity.create(id, this, parent, position, quat.create(0,0,0,1))
        _movable = Movable.create(_entity)
        _solid = Solid.create(_entity, this, CollisionShape.create(Capsule.create(0.35, 1.1), Y3 * 0.9), false, 1.0)
    }
}

class Crate : public Complex
{
	construct create(id, parent, position, extents) {
        _entity = Entity.create()
        _movable = Movable.create()
        _solid = Solid.create()
        _extents = extents
    }
}

class Player
{
	construct create(world) {
        _world = world
        _human = null
    }
}

foreign class GameModule
{
    static create(module) { __interface.new(module) }
    
    static init() { __interface = Interface.create("GameModule") }
    
    init(app, game) {}
    
    start(app, game) {
        _world = World.new(0, 'Example')
        _crates = []
        for (i in 0...50)
            _crates[i] = Crate.new(0, _world.origin, vec3.new(), vec3.new(1))
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

GameModule.init()

var game = GameModule.create(module)
app.run_game(game)