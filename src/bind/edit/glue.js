
// Bindings utilities
function WrapperObject() {
}
// ActionGroup
function ActionGroup() {
    var self = this.ptr;
    this.ptr = _toy_ActionGroup_ActionGroup_0(self); getCache(ActionGroup)[this.ptr] = this;
};
ActionGroup.prototype = Object.create(WrapperObject.prototype);
ActionGroup.prototype.constructor = ActionGroup;
ActionGroup.prototype.__class__ = ActionGroup;
ActionGroup.__cache__ = {};
Module['ActionGroup'] = ActionGroup;
ActionGroup.prototype["__destroy__"] = ActionGroup.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_ActionGroup___destroy__(self);
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
    _toy_Clone___destroy__(self);
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
    _toy_Cut___destroy__(self);
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
    _toy_Edit___destroy__(self);
};
// GraphicsDebug
function GraphicsDebug() {
    var self = this.ptr;
    this.ptr = _toy_GraphicsDebug_GraphicsDebug_0(self); getCache(GraphicsDebug)[this.ptr] = this;
};
GraphicsDebug.prototype = Object.create(WrapperObject.prototype);
GraphicsDebug.prototype.constructor = GraphicsDebug;
GraphicsDebug.prototype.__class__ = GraphicsDebug;
GraphicsDebug.__cache__ = {};
Module['GraphicsDebug'] = GraphicsDebug;
GraphicsDebug.prototype["__destroy__"] = GraphicsDebug.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_GraphicsDebug___destroy__(self);
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
    _toy_Paste___destroy__(self);
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
    _toy_Toolbelt___destroy__(self);
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
    _toy_Toolbox___destroy__(self);
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
    _toy_DynamicToolbox___destroy__(self);
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
        return wrapPointer(_toy_Editor_get_run_tool(self), toy::RunTool);
    }});
Object.defineProperty(Editor.prototype, "play_tool", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Editor_get_play_tool(self), toy::PlayTool);
    }});
Object.defineProperty(Editor.prototype, "frame_view_tool", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Editor_get_frame_view_tool(self), mud::FrameViewTool);
    }});
Object.defineProperty(Editor.prototype, "edited_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Editor_get_edited_world(self), toy::World);
    },
    set: function(edited_world) {
        var self = this.ptr;
        /* edited_world <World> [] */
        edited_world = edited_world.ptr;
        _toy_Editor_set_edited_world(self, edited_world);
    }
});
Object.defineProperty(Editor.prototype, "run_game", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Editor_get_run_game(self));
    },
    set: function(run_game) {
        var self = this.ptr;
        /* run_game <bool> [] */
        _toy_Editor_set_run_game(self, run_game);
    }
});
Object.defineProperty(Editor.prototype, "play_game", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Editor_get_play_game(self));
    },
    set: function(play_game) {
        var self = this.ptr;
        /* play_game <bool> [] */
        _toy_Editor_set_play_game(self, play_game);
    }
});
Editor.prototype["__destroy__"] = Editor.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Editor___destroy__(self);
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
    _toy_PlayTool___destroy__(self);
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
    _toy_RunTool___destroy__(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
