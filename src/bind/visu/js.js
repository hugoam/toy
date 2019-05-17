Module['two']['ui'] = Module['two']['ui'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
// PhysicDebugDraw
function PhysicDebugDraw() { throw "cannot construct a PhysicDebugDraw, no constructor in IDL" }
PhysicDebugDraw.prototype = Object.create(WrapperObject.prototype);
PhysicDebugDraw.prototype.constructor = PhysicDebugDraw;
PhysicDebugDraw.prototype.__class__ = PhysicDebugDraw;
PhysicDebugDraw.__cache__ = {};
Module['PhysicDebugDraw'] = PhysicDebugDraw;
PhysicDebugDraw.prototype["__destroy__"] = PhysicDebugDraw.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_PhysicDebugDraw__destroy(self);
};
// VisuScene
function VisuScene() { throw "cannot construct a VisuScene, no constructor in IDL" }
VisuScene.prototype = Object.create(WrapperObject.prototype);
VisuScene.prototype.constructor = VisuScene;
VisuScene.prototype.__class__ = VisuScene;
VisuScene.__cache__ = {};
Module['VisuScene'] = VisuScene;
VisuScene.prototype["next_frame"] = VisuScene.prototype.next_frame = function(self) {
    var self = this.ptr;
    _toy_VisuScene_next_frame_0(self);
};
Object.defineProperty(VisuScene.prototype, "gfx_system", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_VisuScene__get_gfx_system(self), GfxSystem);
    }});
Object.defineProperty(VisuScene.prototype, "scene", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_VisuScene__get_scene(self), Scene);
    }});
VisuScene.prototype["__destroy__"] = VisuScene.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_VisuScene__destroy(self);
};

(function() {
    function setup() {
        PhysicDebugDraw.__type__ = _toy_PhysicDebugDraw__type();
        VisuScene.__type__ = _toy_VisuScene__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
