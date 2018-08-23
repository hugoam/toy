import "random" for Random
import "toy" for ScriptClass, Complex, Vec2, Vec3, Colour, Capsule, Axis, Cube, Sphere, Quad, Symbol, Ui, Key, EventType, InputMod, Gfx, ItemFlag, BackgroundMode, DefaultWorld, Entity, Movable, Solid, CollisionShape, GameMode, OrbitMode

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
    
    static bind() { __cls = ScriptClass.new("Terrain", [Entity.type, Solid.type]) }
}

var GWorld = null
var GScene = null
var GTerrain = null
var GBodies = []

foreign class MyGame {
    static new(module) { __constructor.call(MyGame, module) }
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) { start(app, game) }
    
    start(app, game) {
        GWorld = DefaultWorld.new("")
        game.world = GWorld.world
        
        GTerrain = Terrain.new(0, GWorld.world.origin, 100)
        
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
        
		GScene = app.add_scene()
    }
    
    pump(app, game, ui) {
        var viewer = Ui.viewer(ui, GScene.scene)
        var orbit = Ui.orbit_controller(viewer, 0, 0, 1)
    }
    
    scene(app, scene) {}
    
    paint(app, scene, graph) {
        //Toy.paint_physics(graph, GWorld.world)
        this.paint_scene(app, graph)
        this.paint_terrain(app, graph, GTerrain)
        
        for (body in GBodies) {
            this.paint_body(app, graph, body)
        }
    }
    
    paint_scene(app, parent) {
        Gfx.radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode.Radiance)
        Gfx.sun_light(parent, 0, 0.37)
    }
    
    paint_terrain(app, parent, terrain) {
        var self = Gfx.node(parent, terrain, terrain.entity.position, terrain.entity.rotation)
        var material = Gfx.pbr_material(app.gfx, "ground", Colour.new(0.3, 1))
        Gfx.shape(self, terrain.quad, Symbol.new(Colour.White), 0, material)
    }
    
    paint_body(app, parent, body) {
        var self = Gfx.node(parent, body, body.entity.position, body.entity.rotation)
        var material = Gfx.pbr_material(app.gfx, "body %(body.entity.id)", body.colour)
        Gfx.shape(self, body.shape, Symbol.new(Colour.White), 0, material)
    }
}

Body.bind()
Terrain.bind()
MyGame.bind()

var game = MyGame.new(module)
