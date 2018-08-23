import "random" for Random
import "toy" for ScriptClass, Complex, Vec2, Vec3, Colour, Cube, Sphere, Quad, Symbol, Ui, Gfx, BackgroundMode, DefaultWorld, Entity, Movable, Solid, CollisionShape, GameMode, OrbitMode

class Body {
    construct new(id, parent, position, shape, colour) {
        _complex = Complex.new(id, __cls.type)
        _entity = Entity.new(id, _complex, parent, position)
        _movable = Movable.new(_entity)
        _shape = shape
        _colour = colour
        _complex.setup([_entity, _movable])
    }
    
    entity { _entity }
    shape { _shape }
    colour { _colour }
    
    static bind() { __cls = ScriptClass.new("Body", [Entity.type, Movable.type]) }
}

var GWorld = null
var GScene = null
var GBodies = []

foreign class MyGame {
    static new(module) { __constructor.call(MyGame, module) }
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) { start(app, game) }
    
    start(app, game) {
        GWorld = DefaultWorld.new("Example")
        game.world = GWorld.world
        
        var rand = Random.new()
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), rand.float(0, 20), rand.float(-50, 50))
            var colour = Colour.hsl(rand.float(0, 1), 1, 0.5)
            var size = Vec3.new(rand.float(1, 5))
            
            GBodies.add(Body.new(0, GWorld.world.origin, position, Cube.new(size), colour))
        }
        
        GScene = app.add_scene()
    }
    
    pump(app, game, ui) {
        var viewer = Ui.viewer(ui, GScene.scene)
        var orbit = Ui.orbit_controller(viewer, 0, -0.37, 100.0)
    }
    
    scene(app, scene) {}
    
    paint(app, scene, graph) {
        Gfx.radiance(graph, "radiance/tiber_1_1k.hdr", BackgroundMode.Radiance)
        Gfx.sun_light(graph, 0, 0.37)
        
        for (body in GBodies) {
            var node = Gfx.node(graph, body, body.entity.position, body.entity.rotation)
            Gfx.shape(node, body.shape, Symbol.new(body.colour))
        }
    }
}

Body.bind()
MyGame.bind()

var game = MyGame.new(module)
