// Edit
function Edit() { throw "cannot construct a Edit, no constructor in IDL" }
Edit.prototype = Object.create(WrapperObject.prototype);
Edit.prototype.constructor = Edit;
Edit.prototype.__class = Edit;
Edit.__cache = {};
Module['Edit'] = Edit;
Edit.prototype["__destroy"] = Edit.prototype.__destroy = function() {
    _toy_Edit__destroy(this.__ptr);
};
// Clone
function Clone() { throw "cannot construct a Clone, no constructor in IDL" }
Clone.prototype = Object.create(WrapperObject.prototype);
Clone.prototype.constructor = Clone;
Clone.prototype.__class = Clone;
Clone.__cache = {};
Module['Clone'] = Clone;
Clone.prototype["__destroy"] = Clone.prototype.__destroy = function() {
    _toy_Clone__destroy(this.__ptr);
};
// Cut
function Cut() { throw "cannot construct a Cut, no constructor in IDL" }
Cut.prototype = Object.create(WrapperObject.prototype);
Cut.prototype.constructor = Cut;
Cut.prototype.__class = Cut;
Cut.__cache = {};
Module['Cut'] = Cut;
Cut.prototype["__destroy"] = Cut.prototype.__destroy = function() {
    _toy_Cut__destroy(this.__ptr);
};
// Paste
function Paste() { throw "cannot construct a Paste, no constructor in IDL" }
Paste.prototype = Object.create(WrapperObject.prototype);
Paste.prototype.constructor = Paste;
Paste.prototype.__class = Paste;
Paste.__cache = {};
Module['Paste'] = Paste;
Paste.prototype["__destroy"] = Paste.prototype.__destroy = function() {
    _toy_Paste__destroy(this.__ptr);
};
// Toolbox
function Toolbox() { throw "cannot construct a Toolbox, no constructor in IDL" }
Toolbox.prototype = Object.create(WrapperObject.prototype);
Toolbox.prototype.constructor = Toolbox;
Toolbox.prototype.__class = Toolbox;
Toolbox.__cache = {};
Module['Toolbox'] = Toolbox;
Toolbox.prototype["__destroy"] = Toolbox.prototype.__destroy = function() {
    _toy_Toolbox__destroy(this.__ptr);
};
// DynamicToolbox
function DynamicToolbox() { throw "cannot construct a DynamicToolbox, no constructor in IDL" }
DynamicToolbox.prototype = Object.create(Toolbox.prototype);
DynamicToolbox.prototype.constructor = DynamicToolbox;
DynamicToolbox.prototype.__class = DynamicToolbox;
DynamicToolbox.__base = Toolbox;
DynamicToolbox.__cache = {};
Module['DynamicToolbox'] = DynamicToolbox;
DynamicToolbox.prototype["__destroy"] = DynamicToolbox.prototype.__destroy = function() {
    _toy_DynamicToolbox__destroy(this.__ptr);
};
// Toolbelt
function Toolbelt() { throw "cannot construct a Toolbelt, no constructor in IDL" }
Toolbelt.prototype = Object.create(WrapperObject.prototype);
Toolbelt.prototype.constructor = Toolbelt;
Toolbelt.prototype.__class = Toolbelt;
Toolbelt.__cache = {};
Module['Toolbelt'] = Toolbelt;
Toolbelt.prototype["__destroy"] = Toolbelt.prototype.__destroy = function() {
    _toy_Toolbelt__destroy(this.__ptr);
};
// PlayTool
function PlayTool() { throw "cannot construct a PlayTool, no constructor in IDL" }
PlayTool.prototype = Object.create(Tool.prototype);
PlayTool.prototype.constructor = PlayTool;
PlayTool.prototype.__class = PlayTool;
PlayTool.__base = Tool;
PlayTool.__cache = {};
Module['PlayTool'] = PlayTool;
PlayTool.prototype["__destroy"] = PlayTool.prototype.__destroy = function() {
    _toy_PlayTool__destroy(this.__ptr);
};
// RunTool
function RunTool() { throw "cannot construct a RunTool, no constructor in IDL" }
RunTool.prototype = Object.create(Tool.prototype);
RunTool.prototype.constructor = RunTool;
RunTool.prototype.__class = RunTool;
RunTool.__base = Tool;
RunTool.__cache = {};
Module['RunTool'] = RunTool;
RunTool.prototype["__destroy"] = RunTool.prototype.__destroy = function() {
    _toy_RunTool__destroy(this.__ptr);
};
// ActionGroup
function ActionGroup() {
    
    this.__ptr = _toy_ActionGroup__construct_0(); getCache(ActionGroup)[this.__ptr] = this;
};
ActionGroup.prototype = Object.create(WrapperObject.prototype);
ActionGroup.prototype.constructor = ActionGroup;
ActionGroup.prototype.__class = ActionGroup;
ActionGroup.__cache = {};
Module['ActionGroup'] = ActionGroup;
ActionGroup.prototype["__destroy"] = ActionGroup.prototype.__destroy = function() {
    _toy_ActionGroup__destroy(this.__ptr);
};
// GraphicsDebug
function GraphicsDebug() {
    
    this.__ptr = _toy_GraphicsDebug__construct_0(); getCache(GraphicsDebug)[this.__ptr] = this;
};
GraphicsDebug.prototype = Object.create(WrapperObject.prototype);
GraphicsDebug.prototype.constructor = GraphicsDebug;
GraphicsDebug.prototype.__class = GraphicsDebug;
GraphicsDebug.__cache = {};
Module['GraphicsDebug'] = GraphicsDebug;
GraphicsDebug.prototype["__destroy"] = GraphicsDebug.prototype.__destroy = function() {
    _toy_GraphicsDebug__destroy(this.__ptr);
};
// Editor
function Editor() { throw "cannot construct a Editor, no constructor in IDL" }
Editor.prototype = Object.create(EditContext.prototype);
Editor.prototype.constructor = Editor;
Editor.prototype.__class = Editor;
Editor.__base = EditContext;
Editor.__cache = {};
Module['Editor'] = Editor;
Object.defineProperty(Editor.prototype, "run_tool", {
    get: function() {
        return wrapPointer(_toy_Editor__get_run_tool(this.__ptr), RunTool);
    }});
Object.defineProperty(Editor.prototype, "play_tool", {
    get: function() {
        return wrapPointer(_toy_Editor__get_play_tool(this.__ptr), PlayTool);
    }});
Object.defineProperty(Editor.prototype, "frame_view_tool", {
    get: function() {
        return wrapPointer(_toy_Editor__get_frame_view_tool(this.__ptr), FrameViewTool);
    }});
Object.defineProperty(Editor.prototype, "edited_world", {
    get: function() {
        return wrapPointer(_toy_Editor__get_edited_world(this.__ptr), World);
    },
    set: function(value) {
        if (!checkClass(value, World)) throw Error('Editor.edited_world: expected World');
        _toy_Editor__set_edited_world(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Editor.prototype, "run_game", {
    get: function() {
        return !!(_toy_Editor__get_run_game(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Editor.run_game: expected boolean');
        _toy_Editor__set_run_game(this.__ptr, value);
    }
});
Object.defineProperty(Editor.prototype, "play_game", {
    get: function() {
        return !!(_toy_Editor__get_play_game(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Editor.play_game: expected boolean');
        _toy_Editor__set_play_game(this.__ptr, value);
    }
});
Editor.prototype["__destroy"] = Editor.prototype.__destroy = function() {
    _toy_Editor__destroy(this.__ptr);
};

(function() {
    function setup() {
        Edit.prototype.__type = _toy_Edit__type();
        Clone.prototype.__type = _toy_Clone__type();
        Cut.prototype.__type = _toy_Cut__type();
        Paste.prototype.__type = _toy_Paste__type();
        Toolbox.prototype.__type = _toy_Toolbox__type();
        DynamicToolbox.prototype.__type = _toy_DynamicToolbox__type();
        Toolbelt.prototype.__type = _toy_Toolbelt__type();
        PlayTool.prototype.__type = _toy_PlayTool__type();
        RunTool.prototype.__type = _toy_RunTool__type();
        ActionGroup.prototype.__type = _toy_ActionGroup__type();
        GraphicsDebug.prototype.__type = _toy_GraphicsDebug__type();
        Editor.prototype.__type = _toy_Editor__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
