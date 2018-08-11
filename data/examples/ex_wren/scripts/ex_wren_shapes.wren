import "random" for Random
import "mud" for ScriptClass, Complex, Vec2, Vec3, Quat, Colour, Capsule, Axis, Cube, Sphere, Quad, Symbol, SymbolDetail, Ui, Key, EventType, InputMod, Gfx, ItemFlag, BackgroundMode
import "toy" for World, BulletWorld, Entity, Movable, Solid, CollisionShape, CollisionGroup, GameShell, GameMode
import "ui" for OrbitMode

class Body {

	construct new(id, parent, position, shape, colour) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position, Quat.new(1,0,0,0))
        _movable = Movable.new(_entity)
        _solid = Solid.new(_entity, CollisionShape.new(shape, Vec3.new(0), 0), false, 1.0)
        _shape = shape
        _colour = colour
        _complex.setup([_entity, _movable, _solid])
    }
    
    entity { _entity }
    shape { _shape }
    colour { _colour }
    
    static bind() { __cls = ScriptClass.new("Body", [Entity.type, Movable.type, Solid.type]) }
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

class GameWorld {

    construct new(id) {
        _complex = Complex.new(id, __cls.type)
        _world = World.new(id, _complex, "Example")
        _bullet_world = BulletWorld.new(_world)
        _complex.setup([_world, _bullet_world])
        
        _terrain = Terrain.new(0, _world.origin, 100)
        _bodies = []
        
        var rand = Random.new()
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), rand.float(0, 20), rand.float(-50, 50))
            var colour = Colour.copy(Mud.hsl_to_rgb(rand.float(0, 1), 1, 0.5))
            _bodies.add(Body.new(0, _world.origin, position, Cube.new(Vec3.new(rand.float(1, 5))), colour)) // Colour.new(0.7, 1)
        }
        
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), rand.float(0, 20), rand.float(-50, 50))
            var colour = Colour.copy(Mud.hsl_to_rgb(rand.float(0, 1), 1, 0.5))
            _bodies.add(Body.new(0, _world.origin, position, Sphere.new(rand.float(1, 5)), colour)) // Colour.new(0.7, 1)
        }
    }
    
    world { _world }
    terrain { _terrain }
    player { _player }
    bodies { _bodies }
    
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
        var orbit = Ui.orbit_controller(viewer, 0, 0, 1)
    }
    
    scene(app, scene) {}
    
    paint(app, scene) {
    
        var world = MainWorld
        var root = scene.scene.graph
        
        //Toy.paint_physics(root, world.world)
        this.paint_scene(app, root)
        this.paint_terrain(app, root, world.terrain)
        
        for(body in world.bodies) {
            this.paint_body(app, root, body)
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
    
    paint_body(app, parent, body) {
    
        var self = Gfx.node(parent, body, body.entity.position, body.entity.rotation, Vec3.new(1))
        var symbol = Symbol.new(Colour.None, Colour.White, false, false, SymbolDetail.Medium)
        var material = this.pbr_material(app, "body %(body.entity.id)", body.colour)
        Gfx.shape(self, body.shape, symbol, 0, material, 0)
    }
}

Body.bind()
Terrain.bind()
GameWorld.bind()
MyGame.bind()

var game = MyGame.new(module)
