
// Bindings utilities
function WrapperObject() {
}
// Procedure
function Procedure() { throw "cannot construct a Procedure, no constructor in IDL" }
Procedure.prototype = Object.create(WrapperObject.prototype);
Procedure.prototype.constructor = Procedure;
Procedure.prototype.__class__ = Procedure;
Procedure.__cache__ = {};
Module['Procedure'] = Procedure;
Procedure.prototype["__destroy__"] = Procedure.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Procedure___destroy__(self);
};
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
        return wrapPointer(_ProcedureType_get_type(self), mud::Type);
    }});
Object.defineProperty(ProcedureType.prototype, "index", {
    get: function() {
        var self = this.ptr;
        return _ProcedureType_get_index(self);
    },
    set: function(index) {
        var self = this.ptr;
        /* index <uint32_t> [] */
        _ProcedureType_set_index(self, index);
    }
});
Object.defineProperty(ProcedureType.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_ProcedureType_get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _ProcedureType_set_name(self, name);
    }
});
ProcedureType.prototype["__destroy__"] = ProcedureType.prototype.__destroy__ = function() {
    var self = this.ptr;
    _ProcedureType___destroy__(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
