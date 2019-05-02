Module['two']['ui'] = Module['two']['ui'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
// ActionGroup
function ActionGroup() {
    this.ptr = _toy_ActionGroup_ActionGroup_0(); getCache(ActionGroup)[this.ptr] = this;
    this.type = ActionGroup;
};
ActionGroup.prototype = Object.create(WrapperObject.prototype);
ActionGroup.prototype.constructor = ActionGroup;
ActionGroup.prototype.__class__ = ActionGroup;
ActionGroup.__cache__ = {};
Module['ActionGroup'] = ActionGroup;
ActionGroup.prototype["__destroy__"] = ActionGroup.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_ActionGroup__destroy(self);
};
// Clone
function Clone() { throw "cannot construct a Clone, no constructor in IDL" }
Clone.prototype = Object.create(WrapperObject.prototype);
Clone.prototype.constructor = Clone;
Clone.prototype.__class__ = Clone;
Clone.__cache__ = {};
Module['Clone'] = Clone;
Clone.prototype["__destroy__"] = Clone.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Clone__destroy(self);
};
// Cut
function Cut() { throw "cannot construct a Cut, no constructor in IDL" }
Cut.prototype = Object.create(WrapperObject.prototype);
Cut.prototype.constructor = Cut;
Cut.prototype.__class__ = Cut;
Cut.__cache__ = {};
Module['Cut'] = Cut;
Cut.prototype["__destroy__"] = Cut.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Cut__destroy(self);
};
// Edit
function Edit() { throw "cannot construct a Edit, no constructor in IDL" }
Edit.prototype = Object.create(WrapperObject.prototype);
Edit.prototype.constructor = Edit;
Edit.prototype.__class__ = Edit;
Edit.__cache__ = {};
Module['Edit'] = Edit;
Edit.prototype["__destroy__"] = Edit.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Edit__destroy(self);
};
// GraphicsDebug
function GraphicsDebug() {
    this.ptr = _toy_GraphicsDebug_GraphicsDebug_0(); getCache(GraphicsDebug)[this.ptr] = this;
    this.type = GraphicsDebug;
};
GraphicsDebug.prototype = Object.create(WrapperObject.prototype);
GraphicsDebug.prototype.constructor = GraphicsDebug;
GraphicsDebug.prototype.__class__ = GraphicsDebug;
GraphicsDebug.__cache__ = {};
Module['GraphicsDebug'] = GraphicsDebug;
GraphicsDebug.prototype["__destroy__"] = GraphicsDebug.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GraphicsDebug__destroy(self);
};
// Paste
function Paste() { throw "cannot construct a Paste, no constructor in IDL" }
Paste.prototype = Object.create(WrapperObject.prototype);
Paste.prototype.constructor = Paste;
Paste.prototype.__class__ = Paste;
Paste.__cache__ = {};
Module['Paste'] = Paste;
Paste.prototype["__destroy__"] = Paste.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Paste__destroy(self);
};
// Toolbelt
function Toolbelt() { throw "cannot construct a Toolbelt, no constructor in IDL" }
Toolbelt.prototype = Object.create(WrapperObject.prototype);
Toolbelt.prototype.constructor = Toolbelt;
Toolbelt.prototype.__class__ = Toolbelt;
Toolbelt.__cache__ = {};
Module['Toolbelt'] = Toolbelt;
Toolbelt.prototype["__destroy__"] = Toolbelt.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Toolbelt__destroy(self);
};
// Toolbox
function Toolbox() { throw "cannot construct a Toolbox, no constructor in IDL" }
Toolbox.prototype = Object.create(WrapperObject.prototype);
Toolbox.prototype.constructor = Toolbox;
Toolbox.prototype.__class__ = Toolbox;
Toolbox.__cache__ = {};
Module['Toolbox'] = Toolbox;
Toolbox.prototype["__destroy__"] = Toolbox.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Toolbox__destroy(self);
};
// DynamicToolbox
function DynamicToolbox() { throw "cannot construct a DynamicToolbox, no constructor in IDL" }
DynamicToolbox.prototype = Object.create(WrapperObject.prototype);
DynamicToolbox.prototype.constructor = DynamicToolbox;
DynamicToolbox.prototype.__class__ = DynamicToolbox;
DynamicToolbox.__cache__ = {};
Module['DynamicToolbox'] = DynamicToolbox;
DynamicToolbox.prototype["__destroy__"] = DynamicToolbox.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_DynamicToolbox__destroy(self);
};
// Editor
function Editor() { throw "cannot construct a Editor, no constructor in IDL" }
Editor.prototype = Object.create(WrapperObject.prototype);
Editor.prototype.constructor = Editor;
Editor.prototype.__class__ = Editor;
Editor.__cache__ = {};
Module['Editor'] = Editor;
Object.defineProperty(Editor.prototype, "run_tool", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Editor__get_run_tool(self), RunTool);
    }});
Object.defineProperty(Editor.prototype, "play_tool", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Editor__get_play_tool(self), PlayTool);
    }});
Object.defineProperty(Editor.prototype, "frame_view_tool", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Editor__get_frame_view_tool(self), FrameViewTool);
    }});
Object.defineProperty(Editor.prototype, "edited_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Editor__get_edited_world(self), World);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <World> [] */
        value = value.ptr;
        _toy_Editor__set_edited_world(self, value);
    }
});
Object.defineProperty(Editor.prototype, "run_game", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Editor__get_run_game(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Editor__set_run_game(self, value);
    }
});
Object.defineProperty(Editor.prototype, "play_game", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Editor__get_play_game(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Editor__set_play_game(self, value);
    }
});
Editor.prototype["__destroy__"] = Editor.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Editor__destroy(self);
};
// PlayTool
function PlayTool() { throw "cannot construct a PlayTool, no constructor in IDL" }
PlayTool.prototype = Object.create(WrapperObject.prototype);
PlayTool.prototype.constructor = PlayTool;
PlayTool.prototype.__class__ = PlayTool;
PlayTool.__cache__ = {};
Module['PlayTool'] = PlayTool;
PlayTool.prototype["__destroy__"] = PlayTool.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_PlayTool__destroy(self);
};
// RunTool
function RunTool() { throw "cannot construct a RunTool, no constructor in IDL" }
RunTool.prototype = Object.create(WrapperObject.prototype);
RunTool.prototype.constructor = RunTool;
RunTool.prototype.__class__ = RunTool;
RunTool.__cache__ = {};
Module['RunTool'] = RunTool;
RunTool.prototype["__destroy__"] = RunTool.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_RunTool__destroy(self);
};

(function() {
    function setup() {
        ActionGroup.__type__ = _toy_ActionGroup__type();
        Clone.__type__ = _toy_Clone__type();
        Cut.__type__ = _toy_Cut__type();
        Edit.__type__ = _toy_Edit__type();
        GraphicsDebug.__type__ = _toy_GraphicsDebug__type();
        Paste.__type__ = _toy_Paste__type();
        Toolbelt.__type__ = _toy_Toolbelt__type();
        Toolbox.__type__ = _toy_Toolbox__type();
        DynamicToolbox.__type__ = _toy_DynamicToolbox__type();
        Editor.__type__ = _toy_Editor__type();
        PlayTool.__type__ = _toy_PlayTool__type();
        RunTool.__type__ = _toy_RunTool__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
