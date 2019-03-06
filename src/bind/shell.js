// Game
function Game() { throw "cannot construct a Game, no constructor in IDL" }
Game.prototype = Object.create(WrapperObject.prototype);
Game.prototype.constructor = Game;
Game.prototype.__class__ = Game;
Game.__cache__ = {};
Module['Game'] = Game;
Object.defineProperty(Game.prototype, "user", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_user(self), User);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Game__set_user(self, value.ptr);
    }
});
Object.defineProperty(Game.prototype, "mode", {
    get: function() {
        var self = this.ptr;
        return _toy_Game__get_mode(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Game__set_mode(self, value);
    }
});
Object.defineProperty(Game.prototype, "shell", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_shell(self), GameShell);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Game__set_shell(self, value.ptr);
    }
});
Object.defineProperty(Game.prototype, "module", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_module(self), GameModule);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Game__set_module(self, value.ptr);
    }
});
Object.defineProperty(Game.prototype, "player", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_player(self), Ref);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Game__set_player(self, ensureRef(value), ensureRefType(value));
    }
});
Object.defineProperty(Game.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_world(self), World);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Game__set_world(self, value.ptr);
    }
});
Object.defineProperty(Game.prototype, "screen", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_screen(self), Widget);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Game__set_screen(self, value.ptr);
    }
});
Game.prototype["__destroy__"] = Game.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Game__destroy(self);
};
// GameModule
function GameModule() { throw "cannot construct a GameModule, no constructor in IDL" }
GameModule.prototype = Object.create(WrapperObject.prototype);
GameModule.prototype.constructor = GameModule;
GameModule.prototype.__class__ = GameModule;
GameModule.__cache__ = {};
Module['GameModule'] = GameModule;
GameModule.prototype["init"] = GameModule.prototype.init = function(a0, a1) {
    var self = this.ptr;
    _toy_GameModule_init_2(self, /*shell*/a0.ptr, /*game*/a1.ptr);
};
GameModule.prototype["start"] = GameModule.prototype.start = function(a0, a1) {
    var self = this.ptr;
    _toy_GameModule_start_2(self, /*shell*/a0.ptr, /*game*/a1.ptr);
};
GameModule.prototype["pump"] = GameModule.prototype.pump = function(a0, a1, a2) {
    var self = this.ptr;
    _toy_GameModule_pump_3(self, /*shell*/a0.ptr, /*game*/a1.ptr, /*ui*/a2.ptr);
};
GameModule.prototype["scene"] = GameModule.prototype.scene = function(a0, a1) {
    var self = this.ptr;
    _toy_GameModule_scene_2(self, /*shell*/a0.ptr, /*scene*/a1.ptr);
};
GameModule.prototype["paint"] = GameModule.prototype.paint = function(a0, a1, a2) {
    var self = this.ptr;
    _toy_GameModule_paint_3(self, /*shell*/a0.ptr, /*scene*/a1.ptr, /*graph*/a2.ptr);
};
GameModule.prototype["__destroy__"] = GameModule.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GameModule__destroy(self);
};
// GameScene
function GameScene() { throw "cannot construct a GameScene, no constructor in IDL" }
GameScene.prototype = Object.create(WrapperObject.prototype);
GameScene.prototype.constructor = GameScene;
GameScene.prototype.__class__ = GameScene;
GameScene.__cache__ = {};
Module['GameScene'] = GameScene;
GameScene.prototype["__destroy__"] = GameScene.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GameScene__destroy(self);
};
// GameShell
function GameShell(a0, a1) {
    ensureCache.prepare();
    if (a1 === undefined) { this.ptr = _toy_GameShell__construct_1(ensureString(/*resource_path*/a0)); this.type = GameShell; getCache(GameShell)[this.ptr] = this; return; }
    this.ptr = _toy_GameShell__construct_2(ensureString(/*resource_path*/a0), ensureString(/*exec_path*/a1)); this.type = GameShell; getCache(GameShell)[this.ptr] = this;
};
GameShell.prototype = Object.create(WrapperObject.prototype);
GameShell.prototype.constructor = GameShell;
GameShell.prototype.__class__ = GameShell;
GameShell.__cache__ = {};
Module['GameShell'] = GameShell;
GameShell.prototype["init"] = GameShell.prototype.init = function() {
    var self = this.ptr;
    _toy_GameShell_init_0(self);
};
GameShell.prototype["load"] = GameShell.prototype.load = function(a0) {
    var self = this.ptr;
    _toy_GameShell_load_1(self, /*module*/a0.ptr);
};
GameShell.prototype["load_path"] = GameShell.prototype.load_path = function(a0) {
    var self = this.ptr;
    ensureCache.prepare();
    _toy_GameShell_load_path_1(self, ensureString(/*module_path*/a0));
};
GameShell.prototype["run"] = GameShell.prototype.run = function(a0) {
    var self = this.ptr;
    if (a0 === undefined) { _toy_GameShell_run_0(self); return; }
    _toy_GameShell_run_1(self, /*iterations*/a0);
};
GameShell.prototype["run_game"] = GameShell.prototype.run_game = function(a0, a1) {
    var self = this.ptr;
    if (a1 === undefined) { _toy_GameShell_run_game_1(self, /*module*/a0.ptr); return; }
    _toy_GameShell_run_game_2(self, /*module*/a0.ptr, /*iterations*/a1);
};
GameShell.prototype["run_editor"] = GameShell.prototype.run_editor = function(a0, a1) {
    var self = this.ptr;
    if (a1 === undefined) { _toy_GameShell_run_editor_1(self, /*module*/a0.ptr); return; }
    _toy_GameShell_run_editor_2(self, /*module*/a0.ptr, /*iterations*/a1);
};
GameShell.prototype["run_game_path"] = GameShell.prototype.run_game_path = function(a0, a1) {
    var self = this.ptr;
    ensureCache.prepare();
    if (a1 === undefined) { _toy_GameShell_run_game_path_1(self, ensureString(/*module_path*/a0)); return; }
    _toy_GameShell_run_game_path_2(self, ensureString(/*module_path*/a0), /*iterations*/a1);
};
GameShell.prototype["run_editor_path"] = GameShell.prototype.run_editor_path = function(a0, a1) {
    var self = this.ptr;
    ensureCache.prepare();
    if (a1 === undefined) { _toy_GameShell_run_editor_path_1(self, ensureString(/*module_path*/a0)); return; }
    _toy_GameShell_run_editor_path_2(self, ensureString(/*module_path*/a0), /*iterations*/a1);
};
GameShell.prototype["launch"] = GameShell.prototype.launch = function() {
    var self = this.ptr;
    _toy_GameShell_launch_0(self);
};
GameShell.prototype["save"] = GameShell.prototype.save = function() {
    var self = this.ptr;
    _toy_GameShell_save_0(self);
};
GameShell.prototype["reload"] = GameShell.prototype.reload = function() {
    var self = this.ptr;
    _toy_GameShell_reload_0(self);
};
GameShell.prototype["pump"] = GameShell.prototype.pump = function() {
    var self = this.ptr;
    return !!(_toy_GameShell_pump_0(self));
};
GameShell.prototype["cleanup"] = GameShell.prototype.cleanup = function() {
    var self = this.ptr;
    _toy_GameShell_cleanup_0(self);
};
GameShell.prototype["add_scene"] = GameShell.prototype.add_scene = function() {
    var self = this.ptr;
    return wrapPointer(_toy_GameShell_add_scene_0(self), GameScene);
};
GameShell.prototype["remove_scene"] = GameShell.prototype.remove_scene = function(a0) {
    var self = this.ptr;
    _toy_GameShell_remove_scene_1(self, /*scene*/a0.ptr);
};
GameShell.prototype["clear_scenes"] = GameShell.prototype.clear_scenes = function() {
    var self = this.ptr;
    _toy_GameShell_clear_scenes_0(self);
};
Object.defineProperty(GameShell.prototype, "core", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_core(self), Core);
    }});
Object.defineProperty(GameShell.prototype, "lua", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_lua(self), LuaInterpreter);
    }});
Object.defineProperty(GameShell.prototype, "wren", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_wren(self), WrenInterpreter);
    }});
Object.defineProperty(GameShell.prototype, "gfx", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_gfx(self), GfxSystem);
    }});
Object.defineProperty(GameShell.prototype, "context", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_context(self), Context);
    }});
Object.defineProperty(GameShell.prototype, "vg", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_vg(self), Vg);
    }});
Object.defineProperty(GameShell.prototype, "ui_window", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_ui_window(self), UiWindow);
    }});
Object.defineProperty(GameShell.prototype, "editor", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_editor(self), Editor);
    }});
Object.defineProperty(GameShell.prototype, "ui", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_GameShell__get_ui(self), Ui);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_GameShell__set_ui(self, value.ptr);
    }
});
GameShell.prototype["__destroy__"] = GameShell.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GameShell__destroy(self);
};
// GameModuleBind
function GameModuleBind() { throw "cannot construct a GameModuleBind, no constructor in IDL" }
GameModuleBind.prototype = Object.create(GameModule.prototype);
GameModuleBind.prototype.constructor = GameModuleBind;
GameModuleBind.prototype.__class__ = GameModuleBind;
GameModuleBind.__cache__ = {};
Module['GameModuleBind'] = GameModuleBind;
GameModuleBind.prototype["__destroy__"] = GameModuleBind.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GameModuleBind__destroy(self);
};
Module['paint_physics'] = function(a0, a1) {
    _toy_paint_physics_2(/*parent*/a0.ptr, /*world*/a1.ptr);
};
Module['physic_painter'] = function(a0) {
    _toy_physic_painter_1(/*scene*/a0.ptr);
};
Module['Selection'] = vector_mud_Ref;

(function() {
    function setup() {
        Game.__type__ = _toy_Game__type();
        GameModule.__type__ = _toy_GameModule__type();
        GameScene.__type__ = _toy_GameScene__type();
        GameShell.__type__ = _toy_GameShell__type();
        GameModuleBind.__type__ = _toy_GameModuleBind__type();
        // GameMode
        Module['GameMode'] = Module['GameMode'] || {};
        Module['GameMode']['Play'] = _toy_GameMode_Play();
        Module['GameMode']['PlayEditor'] = _toy_GameMode_PlayEditor();
        Module['GameMode']['Pause'] = _toy_GameMode_Pause();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
