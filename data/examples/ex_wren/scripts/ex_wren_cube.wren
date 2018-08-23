import "toy" for Vec3, Colour, Cube, Symbol, Ui, Gfx

foreign class MyGame {
    static new(module) { __constructor.call(MyGame, module) }
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) {}
    
    start(app, game) {}
    
    pump(app, game, ui) {
        var viewer = Ui.scene_viewer(ui)
        var orbit = Ui.orbit_controller(viewer, 0.67, -0.37, 8.0)
        
        var graph = viewer.scene.begin()
        
        var node = Gfx.node(graph)
        Gfx.shape(node, Cube.new(Vec3.new(1)), Symbol.new(Colour.White))
        Gfx.shape(node, Cube.new(Vec3.new(2)), Symbol.new(Colour.None, Colour.White))
    }
    
    scene(app, scene) {}
    
    paint(app, scene, graph) {}
}

MyGame.bind()

var game = MyGame.new(module)
