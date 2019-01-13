
// Bindings utilities
function WrapperObject() {
}
// Game
/** @suppress {undefinedVars, duplicate} */ function Game() { throw "cannot construct a Game, no constructor in IDL" }
Game.prototype = Object.create(WrapperObject.prototype);
Game.prototype.constructor = Game;
Game.prototype.__class__ = Game;
Game.__cache__ = {};
Module['Game'] = Game;

Game.prototype["get_user"] = Game.prototype.get_user = function() {
    var self = this.ptr;
    return _Game_get_user(self);
};

Game.prototype["set_user"] = Game.prototype.set_user = function(user) {
    var self = this.ptr;
    /* user <User> [] */
    _Game_set_user(self, user);
};

Object.defineProperty(Game.prototype, "user", { get: Game.prototype.get_user, set: Game.prototype.set_user }) 

Game.prototype["get_mode"] = Game.prototype.get_mode = function() {
    var self = this.ptr;
    return _Game_get_mode(self);
};

Game.prototype["set_mode"] = Game.prototype.set_mode = function(mode) {
    var self = this.ptr;
    /* mode <GameMode> [] */
    _Game_set_mode(self, mode);
};

Object.defineProperty(Game.prototype, "mode", { get: Game.prototype.get_mode, set: Game.prototype.set_mode }) 

Game.prototype["get_shell"] = Game.prototype.get_shell = function() {
    var self = this.ptr;
    return _Game_get_shell(self);
};

Game.prototype["set_shell"] = Game.prototype.set_shell = function(shell) {
    var self = this.ptr;
    /* shell <GameShell> [] */
    _Game_set_shell(self, shell);
};

Object.defineProperty(Game.prototype, "shell", { get: Game.prototype.get_shell, set: Game.prototype.set_shell }) 

Game.prototype["get_module"] = Game.prototype.get_module = function() {
    var self = this.ptr;
    return _Game_get_module(self);
};

Game.prototype["set_module"] = Game.prototype.set_module = function(module) {
    var self = this.ptr;
    /* module <GameModule> [] */
    _Game_set_module(self, module);
};

Object.defineProperty(Game.prototype, "module", { get: Game.prototype.get_module, set: Game.prototype.set_module }) 

Game.prototype["get_player"] = Game.prototype.get_player = function() {
    var self = this.ptr;
    return _Game_get_player(self);
};

Game.prototype["set_player"] = Game.prototype.set_player = function(player) {
    var self = this.ptr;
    /* player <Ref> [] */
    _Game_set_player(self, player);
};

Object.defineProperty(Game.prototype, "player", { get: Game.prototype.get_player, set: Game.prototype.set_player }) 

Game.prototype["get_world"] = Game.prototype.get_world = function() {
    var self = this.ptr;
    return _Game_get_world(self);
};

Game.prototype["set_world"] = Game.prototype.set_world = function(world) {
    var self = this.ptr;
    /* world <World> [] */
    _Game_set_world(self, world);
};

Object.defineProperty(Game.prototype, "world", { get: Game.prototype.get_world, set: Game.prototype.set_world }) 

Game.prototype["get_screen"] = Game.prototype.get_screen = function() {
    var self = this.ptr;
    return _Game_get_screen(self);
};

Game.prototype["set_screen"] = Game.prototype.set_screen = function(screen) {
    var self = this.ptr;
    /* screen <Widget> [] */
    _Game_set_screen(self, screen);
};

Object.defineProperty(Game.prototype, "screen", { get: Game.prototype.get_screen, set: Game.prototype.set_screen }) 

Game.prototype["__destroy__"] = Game.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Game___destroy__(self);
};
// GameModule
/** @suppress {undefinedVars, duplicate} */ function GameModule() { throw "cannot construct a GameModule, no constructor in IDL" }
GameModule.prototype = Object.create(WrapperObject.prototype);
GameModule.prototype.constructor = GameModule;
GameModule.prototype.__class__ = GameModule;
GameModule.__cache__ = {};
Module['GameModule'] = GameModule;

GameModule.prototype["init"] = GameModule.prototype.init = /** @suppress {undefinedVars, duplicate} */ function(shell, game) {
    /* shell <GameShell> [] */
    /* game <Game> [] */
};

GameModule.prototype["paint"] = GameModule.prototype.paint = /** @suppress {undefinedVars, duplicate} */ function(shell, scene, graph) {
    /* shell <GameShell> [] */
    /* scene <GameScene> [] */
    /* graph <Gnode> [] */
};

GameModule.prototype["pump"] = GameModule.prototype.pump = /** @suppress {undefinedVars, duplicate} */ function(shell, game, ui) {
    /* shell <GameShell> [] */
    /* game <Game> [] */
    /* ui <Widget> [] */
};

GameModule.prototype["scene"] = GameModule.prototype.scene = /** @suppress {undefinedVars, duplicate} */ function(shell, scene) {
    /* shell <GameShell> [] */
    /* scene <GameScene> [] */
};

GameModule.prototype["start"] = GameModule.prototype.start = /** @suppress {undefinedVars, duplicate} */ function(shell, game) {
    /* shell <GameShell> [] */
    /* game <Game> [] */
};

GameModule.prototype["__destroy__"] = GameModule.prototype.__destroy__ = function() {
    var self = this.ptr;
    _GameModule___destroy__(self);
};
// GameShell
/** @suppress {undefinedVars, duplicate} */ function GameShell() { throw "cannot construct a GameShell, no constructor in IDL" }
GameShell.prototype = Object.create(WrapperObject.prototype);
GameShell.prototype.constructor = GameShell;
GameShell.prototype.__class__ = GameShell;
GameShell.__cache__ = {};
Module['GameShell'] = GameShell;

GameShell.prototype["add_scene"] = GameShell.prototype.add_scene = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["cleanup"] = GameShell.prototype.cleanup = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["clear_scenes"] = GameShell.prototype.clear_scenes = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["init"] = GameShell.prototype.init = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["launch"] = GameShell.prototype.launch = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["load"] = GameShell.prototype.load = /** @suppress {undefinedVars, duplicate} */ function(module) {
    /* module <GameModule> [] */
};

GameShell.prototype["load_path"] = GameShell.prototype.load_path = /** @suppress {undefinedVars, duplicate} */ function(module_path) {
    ensureCache.prepare();
    /* module_path <std::string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
};

GameShell.prototype["pump"] = GameShell.prototype.pump = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["reload"] = GameShell.prototype.reload = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["remove_scene"] = GameShell.prototype.remove_scene = /** @suppress {undefinedVars, duplicate} */ function(scene) {
    /* scene <GameScene> [] */
};

GameShell.prototype["run"] = GameShell.prototype.run = /** @suppress {undefinedVars, duplicate} */ function(iterations) {
    /* iterations <size_t> [] */
};

GameShell.prototype["run_editor"] = GameShell.prototype.run_editor = /** @suppress {undefinedVars, duplicate} */ function(module, iterations) {
    /* module <GameModule> [] */
    /* iterations <size_t> [] */
};

GameShell.prototype["run_editor_path"] = GameShell.prototype.run_editor_path = /** @suppress {undefinedVars, duplicate} */ function(module_path, iterations) {
    ensureCache.prepare();
    /* module_path <std::string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    /* iterations <size_t> [] */
};

GameShell.prototype["run_game"] = GameShell.prototype.run_game = /** @suppress {undefinedVars, duplicate} */ function(module, iterations) {
    /* module <GameModule> [] */
    /* iterations <size_t> [] */
};

GameShell.prototype["run_game_path"] = GameShell.prototype.run_game_path = /** @suppress {undefinedVars, duplicate} */ function(module_path, iterations) {
    ensureCache.prepare();
    /* module_path <std::string> [] */
    if (module_path && typeof module_path === "object") module_path = module_path.ptr;
    else module_path = ensureString(module_path);
    /* iterations <size_t> [] */
};

GameShell.prototype["save"] = GameShell.prototype.save = /** @suppress {undefinedVars, duplicate} */ function() {
};

GameShell.prototype["get_core"] = GameShell.prototype.get_core = function() {
    var self = this.ptr;
    return _GameShell_get_core(self);
};

GameShell.prototype["set_core"] = GameShell.prototype.set_core = function(core) {
    var self = this.ptr;
    /* core <Core> [] */
    _GameShell_set_core(self, core);
};

Object.defineProperty(GameShell.prototype, "core", { get: GameShell.prototype.get_core, set: GameShell.prototype.set_core }) 

GameShell.prototype["get_lua"] = GameShell.prototype.get_lua = function() {
    var self = this.ptr;
    return _GameShell_get_lua(self);
};

GameShell.prototype["set_lua"] = GameShell.prototype.set_lua = function(lua) {
    var self = this.ptr;
    /* lua <LuaInterpreter> [] */
    _GameShell_set_lua(self, lua);
};

Object.defineProperty(GameShell.prototype, "lua", { get: GameShell.prototype.get_lua, set: GameShell.prototype.set_lua }) 

GameShell.prototype["get_wren"] = GameShell.prototype.get_wren = function() {
    var self = this.ptr;
    return _GameShell_get_wren(self);
};

GameShell.prototype["set_wren"] = GameShell.prototype.set_wren = function(wren) {
    var self = this.ptr;
    /* wren <WrenInterpreter> [] */
    _GameShell_set_wren(self, wren);
};

Object.defineProperty(GameShell.prototype, "wren", { get: GameShell.prototype.get_wren, set: GameShell.prototype.set_wren }) 

GameShell.prototype["get_gfx"] = GameShell.prototype.get_gfx = function() {
    var self = this.ptr;
    return _GameShell_get_gfx(self);
};

GameShell.prototype["set_gfx"] = GameShell.prototype.set_gfx = function(gfx) {
    var self = this.ptr;
    /* gfx <GfxSystem> [] */
    _GameShell_set_gfx(self, gfx);
};

Object.defineProperty(GameShell.prototype, "gfx", { get: GameShell.prototype.get_gfx, set: GameShell.prototype.set_gfx }) 

GameShell.prototype["get_context"] = GameShell.prototype.get_context = function() {
    var self = this.ptr;
    return _GameShell_get_context(self);
};

GameShell.prototype["set_context"] = GameShell.prototype.set_context = function(context) {
    var self = this.ptr;
    /* context <Context> [] */
    _GameShell_set_context(self, context);
};

Object.defineProperty(GameShell.prototype, "context", { get: GameShell.prototype.get_context, set: GameShell.prototype.set_context }) 

GameShell.prototype["get_vg"] = GameShell.prototype.get_vg = function() {
    var self = this.ptr;
    return _GameShell_get_vg(self);
};

GameShell.prototype["set_vg"] = GameShell.prototype.set_vg = function(vg) {
    var self = this.ptr;
    /* vg <Vg> [] */
    _GameShell_set_vg(self, vg);
};

Object.defineProperty(GameShell.prototype, "vg", { get: GameShell.prototype.get_vg, set: GameShell.prototype.set_vg }) 

GameShell.prototype["get_ui_window"] = GameShell.prototype.get_ui_window = function() {
    var self = this.ptr;
    return _GameShell_get_ui_window(self);
};

GameShell.prototype["set_ui_window"] = GameShell.prototype.set_ui_window = function(ui_window) {
    var self = this.ptr;
    /* ui_window <UiWindow> [] */
    _GameShell_set_ui_window(self, ui_window);
};

Object.defineProperty(GameShell.prototype, "ui_window", { get: GameShell.prototype.get_ui_window, set: GameShell.prototype.set_ui_window }) 

GameShell.prototype["get_editor"] = GameShell.prototype.get_editor = function() {
    var self = this.ptr;
    return _GameShell_get_editor(self);
};

GameShell.prototype["set_editor"] = GameShell.prototype.set_editor = function(editor) {
    var self = this.ptr;
    /* editor <Editor> [] */
    _GameShell_set_editor(self, editor);
};

Object.defineProperty(GameShell.prototype, "editor", { get: GameShell.prototype.get_editor, set: GameShell.prototype.set_editor }) 

GameShell.prototype["get_ui"] = GameShell.prototype.get_ui = function() {
    var self = this.ptr;
    return _GameShell_get_ui(self);
};

GameShell.prototype["set_ui"] = GameShell.prototype.set_ui = function(ui) {
    var self = this.ptr;
    /* ui <Ui> [] */
    _GameShell_set_ui(self, ui);
};

Object.defineProperty(GameShell.prototype, "ui", { get: GameShell.prototype.get_ui, set: GameShell.prototype.set_ui }) 

GameShell.prototype["__destroy__"] = GameShell.prototype.__destroy__ = function() {
    var self = this.ptr;
    _GameShell___destroy__(self);
};
// GameModuleBind
/** @suppress {undefinedVars, duplicate} */ function GameModuleBind(module, call) {
    var self = this.ptr;
    /* module <Module> [] */
    /* call <mud::VirtualMethod> [] */
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
/** @suppress {undefinedVars, duplicate} */ function GameScene() { throw "cannot construct a GameScene, no constructor in IDL" }
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
            
          }
      if (Module['calledRun']) setupEnums();
      else addOnPreMain(setupEnums);
})();
