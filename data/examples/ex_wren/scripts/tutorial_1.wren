import "random" for Random
import "toy" for ScriptClass, Complex, Vec2, Vec3, Colour, Cube, Sphere, Quad, Symbol, Ui, Gfx, BackgroundMode, DefaultWorld, Entity, Movable, Solid, CollisionShape, GameMode, OrbitMode

foreign class MyGame {
    static new(module) { __constructor.call(MyGame, module) }
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) { start(app, game) }
    
    start(app, game) { System.print("MyGame - start !") }
    
    pump(app, game, ui) {
        var viewer = Ui.scene_viewer(ui)
        var orbit = Ui.orbit_controller(viewer)
        
        var graph = viewer.scene.begin()
        
        var node = Gfx.node(graph)
        Gfx.shape(node, Cube.new(), Symbol.new(Colour.White))
        
        var rand = Random.new()
        for (i in 0...50) {
            var position = Vec3.new(rand.float(-50, 50), rand.float(0, 20), rand.float(-50, 50))
            var extents = Vec3.new(rand.float(1, 5))
            var colour = Colour.hsl(rand.float(0, 1), 1, 0.5)
                
            var node = Gfx.node(graph, null, position)
            Gfx.draw(node, Cube.new(extents), Symbol.new(colour))
        }
    }
    
    scene(app, scene) {}
    
    paint(app, scene, graph) {}
}

MyGame.bind()

var game = MyGame.new(module)
