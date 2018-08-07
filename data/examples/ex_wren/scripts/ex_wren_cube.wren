import "mud" for Complex, Vec2, Vec3, Quat, Colour, Capsule, Cube, Symbol, SymbolDetail, Ui, Gfx
import "toy" for Entity, Movable, Solid, CollisionShape, GameShell

foreign class MyGame {

    static new(module) { __constructor.call(MyGame, module) }
    
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) {}
    
    start(app, game) {}
    
    pump(app, game) {
        var ui = app.ui.begin()
        var viewer = Ui.scene_viewer(ui, Vec2.new(0))
        var orbit = Ui.orbit_controller(viewer, 0, 0, 1)
        
        var scene = viewer.scene.begin()
        
        var node = Gfx.node(scene, {}, Vec3.new(0), Quat.new(1, 0, 0, 0), Vec3.new(1))
        var symbol = Symbol.new(Colour.Pink, Colour.None, false, false, SymbolDetail.Medium)
        Gfx.shape(node, Cube.new(), symbol, 0, null, 0)
    }
    
    scene(app, scene) {}
}

MyGame.bind()

var game = MyGame.new(module)
