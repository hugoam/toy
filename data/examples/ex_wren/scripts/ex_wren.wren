import "mud" for ScriptClass, Complex, Vec2, Vec3, Quat, Colour, Capsule, Axis, Cube, Symbol, SymbolDetail, Ui, Gfx
import "toy" for World, BulletWorld, Entity, Movable, Solid, CollisionShape, CollisionGroup, GameShell

class Human {

	construct new(id, parent, position) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position, Quat.new(1,0,0,0))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, CollisionShape.new(Capsule.new(0.35, 1.1, Axis.X), Vec3.new(0, 0.9, 0), 0), false, 1.0)
        _complex.setup([_entity, _movable, _solid])
    }
    
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
    
    extents { _extents }
    
    static bind() { __cls = ScriptClass.new("Crate", [Entity.type, Movable.type, Solid.type]) }
}

class Terrain {

	construct new(id, parent) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, Vec3.new(0), Quat.new(1,0,0,0))
        _solid = Solid.new(_entity, CollisionShape.new(Quad.new(1.f), Vec3.new(0), 0), true, 1.0)
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
        for (i in 0...50) {
            _crates.add(Crate.new(0, _world.origin, Vec3.new(0), Vec3.new(1)))
        }
    }
    
    player { _player }
    crates { _crates }
    
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
        var orbit = Ui.orbit_controller(viewer, 0, 0, 1)
        
        var scene = viewer.scene.begin()
        
        paint_human(scene, MainWorld.player.human)
        
        for(crate in MainWorld.crates)
            paint_crate(scene, crate)
    }
    
    scene(app, game) {}
    
    paint_human(parent, human) {
    
        //var model = app.gfx.models().file("human00")
        
        var self = Gfx.node(parent, human, human.entity.position, human.entity..rotation)
        var item = Gfx.model(self, "human00", ItemFlags.ITEM_SELECTABLE)
        //var item = Gfx.item(self, model, ItemFlags.ITEM_SELECTABLE)
        var animated = Gfx.animated(self, item)

        //if(animated.playing.empty() || animated.playing() != human.m_state.name)
        //    animated.play(human.m_state.name.c_str(), human.m_state.loop, 0.f, human.m_walk ? 0.7f : 1.f)
    }
    
    paint_crate(parent, crate) {
        var symbol = Symbol.create(Colour.None, Colour.White, false, false, SymbolDetail.Medium)
        Gfx.shape(parent, Cube.create(crate.extents), symbol, 0, null, 0)
    }
}

Human.bind()
Crate.bind()
GameWorld.bind()
MyGame.bind()

var game = MyGame.new(module)
