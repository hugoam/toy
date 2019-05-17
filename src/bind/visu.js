// PhysicDebugDraw
function PhysicDebugDraw() { throw "cannot construct a PhysicDebugDraw, no constructor in IDL" }
PhysicDebugDraw.prototype = Object.create(WrapperObject.prototype);
PhysicDebugDraw.prototype.constructor = PhysicDebugDraw;
PhysicDebugDraw.prototype.__class = PhysicDebugDraw;
PhysicDebugDraw.__cache = {};
Module['PhysicDebugDraw'] = PhysicDebugDraw;
PhysicDebugDraw.prototype["__destroy"] = PhysicDebugDraw.prototype.__destroy = function() {
    _toy_PhysicDebugDraw__destroy(this.__ptr);
};
// VisuScene
function VisuScene() { throw "cannot construct a VisuScene, no constructor in IDL" }
VisuScene.prototype = Object.create(WrapperObject.prototype);
VisuScene.prototype.constructor = VisuScene;
VisuScene.prototype.__class = VisuScene;
VisuScene.__cache = {};
Module['VisuScene'] = VisuScene;
VisuScene.prototype["next_frame"] = VisuScene.prototype.next_frame = function() {
    
    _toy_VisuScene_next_frame_0(this.__ptr);
};
Object.defineProperty(VisuScene.prototype, "gfx", {
    get: function() {
        return wrapPointer(_toy_VisuScene__get_gfx(this.__ptr), GfxSystem);
    }});
Object.defineProperty(VisuScene.prototype, "scene", {
    get: function() {
        return wrapPointer(_toy_VisuScene__get_scene(this.__ptr), Scene);
    }});
VisuScene.prototype["__destroy"] = VisuScene.prototype.__destroy = function() {
    _toy_VisuScene__destroy(this.__ptr);
};

(function() {
    function setup() {
        PhysicDebugDraw.prototype.__type = _toy_PhysicDebugDraw__type();
        VisuScene.prototype.__type = _toy_VisuScene__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
