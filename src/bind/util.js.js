Module['two']['ui'] = Module['two']['ui'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
// ProcedureType
function ProcedureType() { throw "cannot construct a ProcedureType, no constructor in IDL" }
ProcedureType.prototype = Object.create(WrapperObject.prototype);
ProcedureType.prototype.constructor = ProcedureType;
ProcedureType.prototype.__class__ = ProcedureType;
ProcedureType.__cache__ = {};
Module['ProcedureType'] = ProcedureType;
Object.defineProperty(ProcedureType.prototype, "type", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_ProcedureType__get_type(self), Type);
    }});
Object.defineProperty(ProcedureType.prototype, "index", {
    get: function() {
        var self = this.ptr;
        return _toy_ProcedureType__get_index(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint32_t> [] */
        _toy_ProcedureType__set_index(self, value);
    }
});
Object.defineProperty(ProcedureType.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return _toy_ProcedureType__get_name(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <stl::string> [] */
        _toy_ProcedureType__set_name(self, value);
    }
});
ProcedureType.prototype["__destroy__"] = ProcedureType.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_ProcedureType__destroy(self);
};
// Procedure
function Procedure() { throw "cannot construct a Procedure, no constructor in IDL" }
Procedure.prototype = Object.create(WrapperObject.prototype);
Procedure.prototype.constructor = Procedure;
Procedure.prototype.__class__ = Procedure;
Procedure.__cache__ = {};
Module['Procedure'] = Procedure;
Procedure.prototype["__destroy__"] = Procedure.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Procedure__destroy(self);
};

(function() {
    function setup() {
        ProcedureType.__type__ = _toy_ProcedureType__type();
        Procedure.__type__ = _toy_Procedure__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
