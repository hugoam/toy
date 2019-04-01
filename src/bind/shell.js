// Game
function Game() { throw "cannot construct a Game, no constructor in IDL" }
Game.prototype = Object.create(WrapperObject.prototype);
Game.prototype.constructor = Game;
Game.prototype.__class = Game;
Game.__cache = {};
Module['Game'] = Game;
Object.defineProperty(Game.prototype, "user", {
    get: function() {
        return wrapPointer(_toy_Game__get_user(this.__ptr), User);
    },
    set: function(value) {
        _toy_Game__set_user(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Game.prototype, "mode", {
    get: function() {
        return _toy_Game__get_mode(this.__ptr);
    },
    set: function(value) {
        _toy_Game__set_mode(this.__ptr, value);
    }
});
Object.defineProperty(Game.prototype, "shell", {
    get: function() {
        return wrapPointer(_toy_Game__get_shell(this.__ptr), GameShell);
    },
    set: function(value) {
        _toy_Game__set_shell(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Game.prototype, "module", {
    get: function() {
        return wrapPointer(_toy_Game__get_module(this.__ptr), GameModule);
    },
    set: function(value) {
        _toy_Game__set_module(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Game.prototype, "player", {
    get: function() {
        return wrapPointer(_toy_Game__get_player(this.__ptr), Ref);
    },
    set: function(value) {
        _toy_Game__set_player(this.__ptr, ensureRef(value), ensureRefType(value));
    }
});
Object.defineProperty(Game.prototype, "world", {
    get: function() {
        return wrapPointer(_toy_Game__get_world(this.__ptr), World);
    },
    set: function(value) {
        _toy_Game__set_world(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Game.prototype, "screen", {
    get: function() {
        return wrapPointer(_toy_Game__get_screen(this.__ptr), Widget);
    },
    set: function(value) {
        _toy_Game__set_screen(this.__ptr, value.__ptr);
    }
});
Game.prototype["__destroy"] = Game.prototype.__destroy = function() {
    _toy_Game__destroy(this.__ptr);
};
// GameModule
function GameModule() { throw "cannot construct a GameModule, no constructor in IDL" }
GameModule.prototype = Object.create(WrapperObject.prototype);
GameModule.prototype.constructor = GameModule;
GameModule.prototype.__class = GameModule;
GameModule.__cache = {};
Module['GameModule'] = GameModule;
GameModule.prototype["init"] = GameModule.prototype.init = function(a0, a1) {
    _toy_GameModule_init_2(this.__ptr, /*shell*/a0.__ptr, /*game*/a1.__ptr);
};
GameModule.prototype["start"] = GameModule.prototype.start = function(a0, a1) {
    _toy_GameModule_start_2(this.__ptr, /*shell*/a0.__ptr, /*game*/a1.__ptr);
};
GameModule.prototype["pump"] = GameModule.prototype.pump = function(a0, a1, a2) {
    _toy_GameModule_pump_3(this.__ptr, /*shell*/a0.__ptr, /*game*/a1.__ptr, /*ui*/a2.__ptr);
};
GameModule.prototype["scene"] = GameModule.prototype.scene = function(a0, a1) {
    _toy_GameModule_scene_2(this.__ptr, /*shell*/a0.__ptr, /*scene*/a1.__ptr);
};
GameModule.prototype["paint"] = GameModule.prototype.paint = function(a0, a1, a2) {
    _toy_GameModule_paint_3(this.__ptr, /*shell*/a0.__ptr, /*scene*/a1.__ptr, /*graph*/a2.__ptr);
};
GameModule.prototype["__destroy"] = GameModule.prototype.__destroy = function() {
    _toy_GameModule__destroy(this.__ptr);
};
// GameShell
function GameShell(a0, a1) {
    ensureCache.prepare();
    if (a1 === undefined) { this.__ptr = _toy_GameShell__construct_1(ensureString(/*resource_path*/a0)); this.__type = GameShell.__type; getCache(GameShell)[this.__ptr] = this; return; }
    this.__ptr = _toy_GameShell__construct_2(ensureString(/*resource_path*/a0), ensureString(/*exec_path*/a1)); this.__type = GameShell.__type; getCache(GameShell)[this.__ptr] = this;
};
GameShell.prototype = Object.create(WrapperObject.prototype);
GameShell.prototype.constructor = GameShell;
GameShell.prototype.__class = GameShell;
GameShell.__cache = {};
Module['GameShell'] = GameShell;
GameShell.prototype["init"] = GameShell.prototype.init = function(a0) {
    _toy_GameShell_init_1(this.__ptr, /*window*/a0);
};
GameShell.prototype["window"] = GameShell.prototype.window = function(a0, a1, a2) {
    ensureCache.prepare();
    if (a2 === undefined) { return wrapPointer(_toy_GameShell_window_2(this.__ptr, ensureString(/*name*/a0), /*size*/a1.__ptr), GameWindow); }
    return wrapPointer(_toy_GameShell_window_3(this.__ptr, ensureString(/*name*/a0), /*size*/a1.__ptr, /*fullscreen*/a2), GameWindow);
};
GameShell.prototype["load"] = GameShell.prototype.load = function(a0) {
    _toy_GameShell_load_1(this.__ptr, /*module*/a0.__ptr);
};
GameShell.prototype["load_path"] = GameShell.prototype.load_path = function(a0) {
    ensureCache.prepare();
    _toy_GameShell_load_path_1(this.__ptr, ensureString(/*module_path*/a0));
};
GameShell.prototype["run"] = GameShell.prototype.run = function(a0) {
    if (a0 === undefined) { _toy_GameShell_run_0(this.__ptr); return; }
    _toy_GameShell_run_1(this.__ptr, /*iterations*/a0);
};
GameShell.prototype["run_game"] = GameShell.prototype.run_game = function(a0, a1) {
    if (a1 === undefined) { _toy_GameShell_run_game_1(this.__ptr, /*module*/a0.__ptr); return; }
    _toy_GameShell_run_game_2(this.__ptr, /*module*/a0.__ptr, /*iterations*/a1);
};
GameShell.prototype["run_editor"] = GameShell.prototype.run_editor = function(a0, a1) {
    if (a1 === undefined) { _toy_GameShell_run_editor_1(this.__ptr, /*module*/a0.__ptr); return; }
    _toy_GameShell_run_editor_2(this.__ptr, /*module*/a0.__ptr, /*iterations*/a1);
};
GameShell.prototype["run_game_path"] = GameShell.prototype.run_game_path = function(a0, a1) {
    ensureCache.prepare();
    if (a1 === undefined) { _toy_GameShell_run_game_path_1(this.__ptr, ensureString(/*module_path*/a0)); return; }
    _toy_GameShell_run_game_path_2(this.__ptr, ensureString(/*module_path*/a0), /*iterations*/a1);
};
GameShell.prototype["run_editor_path"] = GameShell.prototype.run_editor_path = function(a0, a1) {
    ensureCache.prepare();
    if (a1 === undefined) { _toy_GameShell_run_editor_path_1(this.__ptr, ensureString(/*module_path*/a0)); return; }
    _toy_GameShell_run_editor_path_2(this.__ptr, ensureString(/*module_path*/a0), /*iterations*/a1);
};
GameShell.prototype["launch"] = GameShell.prototype.launch = function() {
    _toy_GameShell_launch_0(this.__ptr);
};
GameShell.prototype["save"] = GameShell.prototype.save = function() {
    _toy_GameShell_save_0(this.__ptr);
};
GameShell.prototype["reload"] = GameShell.prototype.reload = function() {
    _toy_GameShell_reload_0(this.__ptr);
};
GameShell.prototype["pump"] = GameShell.prototype.pump = function() {
    return !!(_toy_GameShell_pump_0(this.__ptr));
};
GameShell.prototype["cleanup"] = GameShell.prototype.cleanup = function() {
    _toy_GameShell_cleanup_0(this.__ptr);
};
GameShell.prototype["main_window"] = GameShell.prototype.main_window = function() {
    return wrapPointer(_toy_GameShell_main_window_0(this.__ptr), GameWindow);
};
GameShell.prototype["add_scene"] = GameShell.prototype.add_scene = function() {
    return wrapPointer(_toy_GameShell_add_scene_0(this.__ptr), GameScene);
};
GameShell.prototype["remove_scene"] = GameShell.prototype.remove_scene = function(a0) {
    _toy_GameShell_remove_scene_1(this.__ptr, /*scene*/a0.__ptr);
};
GameShell.prototype["clear_scenes"] = GameShell.prototype.clear_scenes = function() {
    _toy_GameShell_clear_scenes_0(this.__ptr);
};
Object.defineProperty(GameShell.prototype, "core", {
    get: function() {
        return wrapPointer(_toy_GameShell__get_core(this.__ptr), Core);
    }});
Object.defineProperty(GameShell.prototype, "lua", {
    get: function() {
        return wrapPointer(_toy_GameShell__get_lua(this.__ptr), LuaInterpreter);
    }});
Object.defineProperty(GameShell.prototype, "wren", {
    get: function() {
        return wrapPointer(_toy_GameShell__get_wren(this.__ptr), WrenInterpreter);
    }});
Object.defineProperty(GameShell.prototype, "gfx", {
    get: function() {
        return wrapPointer(_toy_GameShell__get_gfx(this.__ptr), GfxSystem);
    }});
Object.defineProperty(GameShell.prototype, "editor", {
    get: function() {
        return wrapPointer(_toy_GameShell__get_editor(this.__ptr), Editor);
    }});
GameShell.prototype["__destroy"] = GameShell.prototype.__destroy = function() {
    _toy_GameShell__destroy(this.__ptr);
};
// GameModuleBind
function GameModuleBind() { throw "cannot construct a GameModuleBind, no constructor in IDL" }
GameModuleBind.prototype = Object.create(GameModule.prototype);
GameModuleBind.prototype.constructor = GameModuleBind;
GameModuleBind.prototype.__class = GameModuleBind;
GameModuleBind.__cache = {};
Module['GameModuleBind'] = GameModuleBind;
GameModuleBind.prototype["__destroy"] = GameModuleBind.prototype.__destroy = function() {
    _toy_GameModuleBind__destroy(this.__ptr);
};
// GameScene
function GameScene() { throw "cannot construct a GameScene, no constructor in IDL" }
GameScene.prototype = Object.create(VisuScene.prototype);
GameScene.prototype.constructor = GameScene;
GameScene.prototype.__class = GameScene;
GameScene.__cache = {};
Module['GameScene'] = GameScene;
GameScene.prototype["__destroy"] = GameScene.prototype.__destroy = function() {
    _toy_GameScene__destroy(this.__ptr);
};
// GameWindow
function GameWindow() { throw "cannot construct a GameWindow, no constructor in IDL" }
GameWindow.prototype = Object.create(GfxWindow.prototype);
GameWindow.prototype.constructor = GameWindow;
GameWindow.prototype.__class = GameWindow;
GameWindow.__cache = {};
Module['GameWindow'] = GameWindow;
Object.defineProperty(GameWindow.prototype, "index", {
    get: function() {
        return _toy_GameWindow__get_index(this.__ptr);
    },
    set: function(value) {
        _toy_GameWindow__set_index(this.__ptr, value);
    }
});
Object.defineProperty(GameWindow.prototype, "ui_window", {
    get: function() {
        return wrapPointer(_toy_GameWindow__get_ui_window(this.__ptr), UiWindow);
    }});
Object.defineProperty(GameWindow.prototype, "ui", {
    get: function() {
        return wrapPointer(_toy_GameWindow__get_ui(this.__ptr), Ui);
    },
    set: function(value) {
        _toy_GameWindow__set_ui(this.__ptr, value.__ptr);
    }
});
GameWindow.prototype["__destroy"] = GameWindow.prototype.__destroy = function() {
    _toy_GameWindow__destroy(this.__ptr);
};
Module['paint_physics'] = function(a0, a1) {
    _toy_paint_physics_2(/*parent*/a0.__ptr, /*world*/a1.__ptr);
};
Module['physic_painter'] = function(a0) {
    _toy_physic_painter_1(/*scene*/a0.__ptr);
};

(function() {
    function setup() {
        Game.__type = _toy_Game__type();
        GameModule.__type = _toy_GameModule__type();
        GameShell.__type = _toy_GameShell__type();
        GameModuleBind.__type = _toy_GameModuleBind__type();
        GameScene.__type = _toy_GameScene__type();
        GameWindow.__type = _toy_GameWindow__type();
        // GameMode
        Module['GameMode'] = Module['GameMode'] || {};
        Module['GameMode']['Play'] = _toy_GameMode_Play();
        Module['GameMode']['PlayEditor'] = _toy_GameMode_PlayEditor();
        Module['GameMode']['Pause'] = _toy_GameMode_Pause();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
