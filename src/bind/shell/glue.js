
// Bindings utilities
function WrapperObject() {
}
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
        return _Game_get_user(self);
    },
    set: function(user) {
        var self = this.ptr;
        /* user <User> [] */
        _Game_set_user(self, user);
    }
});
Object.defineProperty(Game.prototype, "mode", {
    get: function() {
        var self = this.ptr;
        return _Game_get_mode(self);
    },
    set: function(mode) {
        var self = this.ptr;
        /* mode <GameMode> [] */
        _Game_set_mode(self, mode);
    }
});
Object.defineProperty(Game.prototype, "shell", {
    get: function() {
        var self = this.ptr;
        return _Game_get_shell(self);
    },
    set: function(shell) {
        var self = this.ptr;
        /* shell <GameShell> [] */
        _Game_set_shell(self, shell);
    }
});
Object.defineProperty(Game.prototype, "module", {
    get: function() {
        var self = this.ptr;
        return _Game_get_module(self);
    },
    set: function(module) {
        var self = this.ptr;
        /* module <GameModule> [] */
        _Game_set_module(self, module);
    }
});
Object.defineProperty(Game.prototype, "player", {
    get: function() {
        var self = this.ptr;
        return _Game_get_player(self);
    },
    set: function(player) {
        var self = this.ptr;
        /* player <Ref> [] */
        _Game_set_player(self, player);
    }
});
Object.defineProperty(Game.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return _Game_get_world(self);
    },
    set: function(world) {
        var self = this.ptr;
        /* world <World> [] */
        _Game_set_world(self, world);
    }
});
Object.defineProperty(Game.prototype, "screen", {
    get: function() {
        var self = this.ptr;
        return _Game_get_screen(self);
    },
    set: function(screen) {
        var self = this.ptr;
        /* screen <Widget> [] */
        _Game_set_screen(self, screen);
    }
});
Game.prototype["__destroy__"] = Game.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Game___destroy__(self);
};
// GameModule
function GameModule() { throw "cannot construct a GameModule, no constructor in IDL" }
GameModule.prototype = Object.create(WrapperObject.prototype);
GameModule.prototype.constructor = GameModule;
GameModule.prototype.__class__ = GameModule;
GameModule.__cache__ = {};
Module['GameModule'] = GameModule;
GameModule.prototype["init"] = GameModule.prototype.init = function(shell, game) {
    /* shell <GameShell> [] */
    /* game <Game> [] */
    _GameModule_init_2(shell, game);
};
GameModule.prototype["paint"] = GameModule.prototype.paint = function(shell, scene, graph) {
    /* shell <GameShell> [] */
    /* scene <GameScene> [] */
    /* graph <Gnode> [] */
    _GameModule_paint_3(shell, scene, graph);
};
GameModule.prototype["pump"] = GameModule.prototype.pump = function(shell, game, ui) {
    /* shell <GameShell> [] */
    /* game <Game> [] */
    /* ui <Widget> [] */
    _GameModule_pump_3(shell, game, ui);
};
GameModule.prototype["scene"] = GameModule.prototype.scene = function(shell, scene) {
    /* shell <GameShell> [] */
    /* scene <GameScene> [] */
    _GameModule_scene_2(shell, scene);
};
GameModule.prototype["start"] = GameModule.prototype.start = function(shell, game) {
    /* shell <GameShell> [] */
    /* game <Game> [] */
    _GameModule_start_2(shell, game);
};
GameModule.prototype["__destroy__"] = GameModule.prototype.__destroy__ = function() {
    var self = this.ptr;
    _GameModule___destroy__(self);
};
// GameShell
function GameShell() { throw "cannot construct a GameShell, no constructor in IDL" }
GameShell.prototype = Object.create(WrapperObject.prototype);
GameShell.prototype.constructor = GameShell;
GameShell.prototype.__class__ = GameShell;
GameShell.__cache__ = {};
Module['GameShell'] = GameShell;
GameShell.prototype["add_scene"] = GameShell.prototype.add_scene = function() {
    return _GameShell_add_scene_0();
};
GameShell.prototype["cleanup"] = GameShell.prototype.cleanup = function() {
    _GameShell_cleanup_0();
};
GameShell.prototype["clear_scenes"] = GameShell.prototype.clear_scenes = function() {
    _GameShell_clear_scenes_0();
};
GameShell.prototype["init"] = GameShell.prototype.init = function() {
    _GameShell_init_0();
};
GameShell.prototype["launch"] = GameShell.prototype.launch = function() {
    _GameShell_launch_0();
};
GameShell.prototype["load"] = GameShell.prototype.load = function(module) {
    /* module <GameModule> [] */
    _GameShell_load_1(module);
};
GameShell.prototype["load_path"] = GameShell.prototype.load_path = function(module_path) {
    ensureCache.prepare();
    /* module_path <std::string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    _GameShell_load_path_1(module_path);
};
GameShell.prototype["pump"] = GameShell.prototype.pump = function() {
    return !!(_GameShell_pump_0());
};
GameShell.prototype["reload"] = GameShell.prototype.reload = function() {
    _GameShell_reload_0();
};
GameShell.prototype["remove_scene"] = GameShell.prototype.remove_scene = function(scene) {
    /* scene <GameScene> [] */
    _GameShell_remove_scene_1(scene);
};
GameShell.prototype["run"] = GameShell.prototype.run = function(iterations) {
    /* iterations <size_t> [] */
    if (iterations === undefined) { _GameShell_run_0(); return; }
    _GameShell_run_1(iterations);
};
GameShell.prototype["run_editor"] = GameShell.prototype.run_editor = function(module, iterations) {
    /* module <GameModule> [] */
    /* iterations <size_t> [] */
    if (iterations === undefined) { _GameShell_run_editor_1(module); return; }
    _GameShell_run_editor_2(module, iterations);
};
GameShell.prototype["run_editor_path"] = GameShell.prototype.run_editor_path = function(module_path, iterations) {
    ensureCache.prepare();
    /* module_path <std::string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    /* iterations <size_t> [] */
    if (iterations === undefined) { _GameShell_run_editor_path_1(module_path); return; }
    _GameShell_run_editor_path_2(module_path, iterations);
};
GameShell.prototype["run_game"] = GameShell.prototype.run_game = function(module, iterations) {
    /* module <GameModule> [] */
    /* iterations <size_t> [] */
    if (iterations === undefined) { _GameShell_run_game_1(module); return; }
    _GameShell_run_game_2(module, iterations);
};
GameShell.prototype["run_game_path"] = GameShell.prototype.run_game_path = function(module_path, iterations) {
    ensureCache.prepare();
    /* module_path <std::string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    /* iterations <size_t> [] */
    if (iterations === undefined) { _GameShell_run_game_path_1(module_path); return; }
    _GameShell_run_game_path_2(module_path, iterations);
};
GameShell.prototype["save"] = GameShell.prototype.save = function() {
    _GameShell_save_0();
};
Object.defineProperty(GameShell.prototype, "core", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_core(self);
    },
    set: function(core) {
        var self = this.ptr;
        /* core <Core> [] */
        _GameShell_set_core(self, core);
    }
});
Object.defineProperty(GameShell.prototype, "lua", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_lua(self);
    },
    set: function(lua) {
        var self = this.ptr;
        /* lua <LuaInterpreter> [] */
        _GameShell_set_lua(self, lua);
    }
});
Object.defineProperty(GameShell.prototype, "wren", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_wren(self);
    },
    set: function(wren) {
        var self = this.ptr;
        /* wren <WrenInterpreter> [] */
        _GameShell_set_wren(self, wren);
    }
});
Object.defineProperty(GameShell.prototype, "gfx", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_gfx(self);
    },
    set: function(gfx) {
        var self = this.ptr;
        /* gfx <GfxSystem> [] */
        _GameShell_set_gfx(self, gfx);
    }
});
Object.defineProperty(GameShell.prototype, "context", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_context(self);
    },
    set: function(context) {
        var self = this.ptr;
        /* context <Context> [] */
        _GameShell_set_context(self, context);
    }
});
Object.defineProperty(GameShell.prototype, "vg", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_vg(self);
    },
    set: function(vg) {
        var self = this.ptr;
        /* vg <Vg> [] */
        _GameShell_set_vg(self, vg);
    }
});
Object.defineProperty(GameShell.prototype, "ui_window", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_ui_window(self);
    },
    set: function(ui_window) {
        var self = this.ptr;
        /* ui_window <UiWindow> [] */
        _GameShell_set_ui_window(self, ui_window);
    }
});
Object.defineProperty(GameShell.prototype, "editor", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_editor(self);
    },
    set: function(editor) {
        var self = this.ptr;
        /* editor <Editor> [] */
        _GameShell_set_editor(self, editor);
    }
});
Object.defineProperty(GameShell.prototype, "ui", {
    get: function() {
        var self = this.ptr;
        return _GameShell_get_ui(self);
    },
    set: function(ui) {
        var self = this.ptr;
        /* ui <Ui> [] */
        _GameShell_set_ui(self, ui);
    }
});
GameShell.prototype["__destroy__"] = GameShell.prototype.__destroy__ = function() {
    var self = this.ptr;
    _GameShell___destroy__(self);
};
// GameModuleBind
function GameModuleBind(module, call) {
    var self = this.ptr;
    /* module <Module> [] */
    /* call <mud::VirtualMethod> [] */
    this.ptr = _GameModuleBind_GameModuleBind_2(self, module, call); getCache(GameModuleBind)[this.ptr] = this;
};
GameModuleBind.prototype = Object.create(WrapperObject.prototype);
GameModuleBind.prototype.constructor = GameModuleBind;
GameModuleBind.prototype.__class__ = GameModuleBind;
GameModuleBind.__cache__ = {};
Module['GameModuleBind'] = GameModuleBind;
GameModuleBind.prototype["__destroy__"] = GameModuleBind.prototype.__destroy__ = function() {
    var self = this.ptr;
    _GameModuleBind___destroy__(self);
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
    _GameScene___destroy__(self);
};

(function() {
    function setupEnums() {
        // GameMode
        Module['GameMode']['Play'] = _emscripten_enum_GameMode_Play();
        Module['GameMode']['PlayEditor'] = _emscripten_enum_GameMode_PlayEditor();
        Module['GameMode']['Pause'] = _emscripten_enum_GameMode_Pause();
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
