Module['two']['ui'] = Module['two']['ui'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
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
        /* value <User> [] */
        value = value.ptr;
        _toy_Game__set_user(self, value);
    }
});
Object.defineProperty(Game.prototype, "mode", {
    get: function() {
        var self = this.ptr;
        return _toy_Game__get_mode(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <GameMode> [] */
        if (value && typeof value === "object") value = value.ptr;
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
        /* value <GameShell> [] */
        value = value.ptr;
        _toy_Game__set_shell(self, value);
    }
});
Object.defineProperty(Game.prototype, "module", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_module(self), GameModule);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <GameModule> [] */
        value = value.ptr;
        _toy_Game__set_module(self, value);
    }
});
Object.defineProperty(Game.prototype, "player", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_player(self), Ref);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Ref> [] */
        var value_type;
        if(typeof value !== "undefined" && value !== null) { value = value.ptr; value_type = value.type.__type__; }
        else { value = 0; value_type = 0; }
        _toy_Game__set_player(self, value);
    }
});
Object.defineProperty(Game.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_world(self), World);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <World> [] */
        value = value.ptr;
        _toy_Game__set_world(self, value);
    }
});
Object.defineProperty(Game.prototype, "screen", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Game__get_screen(self), Widget);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Widget> [] */
        value = value.ptr;
        _toy_Game__set_screen(self, value);
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
GameModule.prototype["init"] = GameModule.prototype.init = function(self, shell, game) {
    var self = this.ptr;
    /* shell <GameShell> [] */
    shell = shell.ptr;
    /* game <Game> [] */
    game = game.ptr;
    _toy_GameModule_init_2(self, shell, game);
};
GameModule.prototype["start"] = GameModule.prototype.start = function(self, shell, game) {
    var self = this.ptr;
    /* shell <GameShell> [] */
    shell = shell.ptr;
    /* game <Game> [] */
    game = game.ptr;
    _toy_GameModule_start_2(self, shell, game);
};
GameModule.prototype["pump"] = GameModule.prototype.pump = function(self, shell, game, ui) {
    var self = this.ptr;
    /* shell <GameShell> [] */
    shell = shell.ptr;
    /* game <Game> [] */
    game = game.ptr;
    /* ui <Widget> [] */
    ui = ui.ptr;
    _toy_GameModule_pump_3(self, shell, game, ui);
};
GameModule.prototype["scene"] = GameModule.prototype.scene = function(self, shell, scene) {
    var self = this.ptr;
    /* shell <GameShell> [] */
    shell = shell.ptr;
    /* scene <GameScene> [] */
    scene = scene.ptr;
    _toy_GameModule_scene_2(self, shell, scene);
};
GameModule.prototype["paint"] = GameModule.prototype.paint = function(self, shell, scene, graph) {
    var self = this.ptr;
    /* shell <GameShell> [] */
    shell = shell.ptr;
    /* scene <GameScene> [] */
    scene = scene.ptr;
    /* graph <Gnode> [] */
    graph = graph.ptr;
    _toy_GameModule_paint_3(self, shell, scene, graph);
};
GameModule.prototype["__destroy__"] = GameModule.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GameModule__destroy(self);
};
// GameShell
function GameShell(resource_path, exec_path) {
    ensureCache.prepare();
    /* resource_path <string> [] */
    if (resource_path && typeof resource_path === "object") resource_path = resource_path.ptr;
    else resource_path = ensureString(resource_path);
    /* exec_path <const char*> [] */
    if (exec_path && typeof exec_path === "object") exec_path = exec_path.ptr;
    else exec_path = ensureString(exec_path);
    if (exec_path === undefined) { this.ptr = _toy_GameShell_GameShell_1(resource_path); getCache(GameShell)[this.ptr] = this; return; }
    this.ptr = _toy_GameShell_GameShell_2(resource_path, exec_path); getCache(GameShell)[this.ptr] = this;
    this.type = GameShell;
};
GameShell.prototype = Object.create(WrapperObject.prototype);
GameShell.prototype.constructor = GameShell;
GameShell.prototype.__class__ = GameShell;
GameShell.__cache__ = {};
Module['GameShell'] = GameShell;
GameShell.prototype["init"] = GameShell.prototype.init = function(self) {
    var self = this.ptr;
    _toy_GameShell_init_0(self);
};
GameShell.prototype["load"] = GameShell.prototype.load = function(self, module) {
    var self = this.ptr;
    /* module <GameModule> [] */
    module = module.ptr;
    _toy_GameShell_load_1(self, module);
};
GameShell.prototype["load_path"] = GameShell.prototype.load_path = function(self, module_path) {
    var self = this.ptr;
    ensureCache.prepare();
    /* module_path <string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    _toy_GameShell_load_path_1(self, module_path);
};
GameShell.prototype["run"] = GameShell.prototype.run = function(self, iterations) {
    var self = this.ptr;
    /* iterations <size_t> [] */
    if (iterations === undefined) { _toy_GameShell_run_0(self); return; }
    _toy_GameShell_run_1(self, iterations);
};
GameShell.prototype["run_game"] = GameShell.prototype.run_game = function(self, module, iterations) {
    var self = this.ptr;
    /* module <GameModule> [] */
    module = module.ptr;
    /* iterations <size_t> [] */
    if (iterations === undefined) { _toy_GameShell_run_game_1(self, module); return; }
    _toy_GameShell_run_game_2(self, module, iterations);
};
GameShell.prototype["run_editor"] = GameShell.prototype.run_editor = function(self, module, iterations) {
    var self = this.ptr;
    /* module <GameModule> [] */
    module = module.ptr;
    /* iterations <size_t> [] */
    if (iterations === undefined) { _toy_GameShell_run_editor_1(self, module); return; }
    _toy_GameShell_run_editor_2(self, module, iterations);
};
GameShell.prototype["run_game_path"] = GameShell.prototype.run_game_path = function(self, module_path, iterations) {
    var self = this.ptr;
    ensureCache.prepare();
    /* module_path <string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    /* iterations <size_t> [] */
    if (iterations === undefined) { _toy_GameShell_run_game_path_1(self, module_path); return; }
    _toy_GameShell_run_game_path_2(self, module_path, iterations);
};
GameShell.prototype["run_editor_path"] = GameShell.prototype.run_editor_path = function(self, module_path, iterations) {
    var self = this.ptr;
    ensureCache.prepare();
    /* module_path <string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    /* iterations <size_t> [] */
    if (iterations === undefined) { _toy_GameShell_run_editor_path_1(self, module_path); return; }
    _toy_GameShell_run_editor_path_2(self, module_path, iterations);
};
GameShell.prototype["launch"] = GameShell.prototype.launch = function(self) {
    var self = this.ptr;
    _toy_GameShell_launch_0(self);
};
GameShell.prototype["save"] = GameShell.prototype.save = function(self) {
    var self = this.ptr;
    _toy_GameShell_save_0(self);
};
GameShell.prototype["reload"] = GameShell.prototype.reload = function(self) {
    var self = this.ptr;
    _toy_GameShell_reload_0(self);
};
GameShell.prototype["pump"] = GameShell.prototype.pump = function(self) {
    var self = this.ptr;
    return !!(_toy_GameShell_pump_0(self));
};
GameShell.prototype["cleanup"] = GameShell.prototype.cleanup = function(self) {
    var self = this.ptr;
    _toy_GameShell_cleanup_0(self);
};
GameShell.prototype["add_scene"] = GameShell.prototype.add_scene = function(self) {
    var self = this.ptr;
    return wrapPointer(_toy_GameShell_add_scene_0(self), GameScene);
};
GameShell.prototype["remove_scene"] = GameShell.prototype.remove_scene = function(self, scene) {
    var self = this.ptr;
    /* scene <GameScene> [] */
    scene = scene.ptr;
    _toy_GameShell_remove_scene_1(self, scene);
};
GameShell.prototype["clear_scenes"] = GameShell.prototype.clear_scenes = function(self) {
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
        /* value <Ui> [] */
        value = value.ptr;
        _toy_GameShell__set_ui(self, value);
    }
});
GameShell.prototype["__destroy__"] = GameShell.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GameShell__destroy(self);
};
// GameModuleBind
function GameModuleBind(module, call) {
    /* module <Module> [] */
    module = module.ptr;
    /* call <two::VirtualMethod> [] */
    this.ptr = _toy_GameModuleBind_GameModuleBind_2(module, call); getCache(GameModuleBind)[this.ptr] = this;
    this.type = GameModuleBind;
};
GameModuleBind.prototype = Object.create(WrapperObject.prototype);
GameModuleBind.prototype.constructor = GameModuleBind;
GameModuleBind.prototype.__class__ = GameModuleBind;
GameModuleBind.__cache__ = {};
Module['GameModuleBind'] = GameModuleBind;
GameModuleBind.prototype["__destroy__"] = GameModuleBind.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GameModuleBind__destroy(self);
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
Module['paint_physics'] = function(parent, world) {
    var self = this.ptr;
    /* parent <Gnode> [] */
    parent = parent.ptr;
    /* world <World> [] */
    world = world.ptr;
    _toy_paint_physics_2(parent, world);
};
Module['physic_painter'] = function(scene) {
    var self = this.ptr;
    /* scene <GameScene> [] */
    scene = scene.ptr;
    _toy_physic_painter_1(scene);
};

(function() {
    function setup() {
        Game.__type__ = _toy_Game__type();
        GameModule.__type__ = _toy_GameModule__type();
        GameShell.__type__ = _toy_GameShell__type();
        GameModuleBind.__type__ = _toy_GameModuleBind__type();
        GameScene.__type__ = _toy_GameScene__type();
        // GameMode
        Module['GameMode'] = Module['GameMode'] || {};
        Module['GameMode']['Play'] = _toy_GameMode_Play();
        Module['GameMode']['PlayEditor'] = _toy_GameMode_PlayEditor();
        Module['GameMode']['Pause'] = _toy_GameMode_Pause();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
