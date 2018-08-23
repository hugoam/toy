import "random" for Random
import "toy" for ScriptClass, Complex, Vec2, Vec3, Colour, Cube, Sphere, Quad, Symbol, Ui, Gfx, BackgroundMode, DefaultWorld, Entity, Movable, Solid, CollisionShape, GameMode, OrbitMode

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
    solid { _solid }
    shape { _shape }
    colour { _colour }
    
    static bind() { __cls = ScriptClass.new("Body", [Entity.type, Movable.type, Solid.type]) }
}

class Agent is Body {
    construct new(id, parent, position, shape, colour) {
        super(id, parent, position, shape, colour)
        _aiming = true
        _angles = Vec2.new(0)
        _force = Vec3.new(0)
        _torque = Vec3.new(0)
    }
    
    update() {
        var velocity = this.solid.impl.linear_velocity()
        var force = Mud.rotate(this.entity.rotation, _force)
        this.solid.impl.set_linear_velocity(Vec3.new(force.x, velocity.y - 1, force.z))
        this.solid.impl.set_angular_velocity(_torque)
        this.solid.impl.set_angular_factor(Vec3.new(0))
    }
    
    aiming { _aiming }
    angles { _angles }
    force { _force }
    torque { _torque }
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
var GAgent = null

foreign class MyGame {
    static new(module) { __constructor.call(MyGame, module) }
    static bind() { __constructor = VirtualConstructor.ref("GameModuleBind") }
    
    init(app, game) { start(app, game) }
    
    start(app, game) {
        GWorld = DefaultWorld.new("World")
        game.world = GWorld.world
        
        GTerrain = Terrain.new(0, GWorld.world.origin, 100)
        GAgent = Agent.new(0, GWorld.world.origin, Vec3.new(0), Cube.new(), Colour.White)
        
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

        if(game.mode == GameMode.Play && !viewer.modal()) {
            viewer.take_modal(62)
        }
        
        Ui.hybrid_controller(viewer, OrbitMode.ThirdPerson, GAgent.entity, GAgent.aiming, GAgent.angles)
        Ui.velocity_controller(viewer, GAgent.force, GAgent.torque, 20)

        GAgent.update()
    }
    
    scene(app, scene) {}
    
    paint(app, scene, graph) {
        Gfx.radiance(graph, "radiance/tiber_1_1k.hdr", BackgroundMode.Radiance)
        Gfx.sun_light(graph, 0, 0.37)
        
        var terrain = Gfx.node(graph, GTerrain, GTerrain.entity.position, GTerrain.entity.rotation)
        var material = Gfx.pbr_material(app.gfx, "ground", Colour.new(0.3, 1))
        Gfx.shape(terrain, GTerrain.quad, Symbol.new(Colour.White), 0, material)
        
        paint_body(app, graph, GAgent)
        
        for (body in GBodies) {
            paint_body(app, graph, body)
        }
    }
    
    paint_body(app, graph, body) {
        var node = Gfx.node(graph, body, body.entity.position, body.entity.rotation)
        var material = Gfx.pbr_material(app.gfx, "body %(body.entity.id)", body.colour)
        Gfx.shape(node, body.shape, Symbol.new(Colour.White), 0, material)
    }
}

Body.bind()
Terrain.bind()
MyGame.bind()

var game = MyGame.new(module)
