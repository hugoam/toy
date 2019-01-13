
// Bindings utilities
function WrapperObject() {
}
// PhysicDebugDraw
function PhysicDebugDraw() { throw "cannot construct a PhysicDebugDraw, no constructor in IDL" }
PhysicDebugDraw.prototype = Object.create(WrapperObject.prototype);
PhysicDebugDraw.prototype.constructor = PhysicDebugDraw;
PhysicDebugDraw.prototype.__class__ = PhysicDebugDraw;
PhysicDebugDraw.__cache__ = {};
Module['PhysicDebugDraw'] = PhysicDebugDraw;
PhysicDebugDraw.prototype["__destroy__"] = PhysicDebugDraw.prototype.__destroy__ = function() {
    var self = this.ptr;
    _PhysicDebugDraw___destroy__(self);
};
// VisuScene
function VisuScene() { throw "cannot construct a VisuScene, no constructor in IDL" }
VisuScene.prototype = Object.create(WrapperObject.prototype);
VisuScene.prototype.constructor = VisuScene;
VisuScene.prototype.__class__ = VisuScene;
VisuScene.__cache__ = {};
Module['VisuScene'] = VisuScene;
VisuScene.prototype["next_frame"] = VisuScene.prototype.next_frame = function() {
    _VisuScene_next_frame_0();
};
Object.defineProperty(VisuScene.prototype, "gfx_system", {
    get: function() {
        var self = this.ptr;
        return _VisuScene_get_gfx_system(self);
    },
    set: function(gfx_system) {
        var self = this.ptr;
        /* gfx_system <GfxSystem> [] */
        _VisuScene_set_gfx_system(self, gfx_system);
    }
});
Object.defineProperty(VisuScene.prototype, "scene", {
    get: function() {
        var self = this.ptr;
        return _VisuScene_get_scene(self);
    },
    set: function(scene) {
        var self = this.ptr;
        /* scene <Scene> [] */
        _VisuScene_set_scene(self, scene);
    }
});
VisuScene.prototype["__destroy__"] = VisuScene.prototype.__destroy__ = function() {
    var self = this.ptr;
    _VisuScene___destroy__(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
