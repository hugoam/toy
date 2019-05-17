// ProcedureType
function ProcedureType() { throw "cannot construct a ProcedureType, no constructor in IDL" }
ProcedureType.prototype = Object.create(WrapperObject.prototype);
ProcedureType.prototype.constructor = ProcedureType;
ProcedureType.prototype.__class = ProcedureType;
ProcedureType.__cache = {};
Module['ProcedureType'] = ProcedureType;
Object.defineProperty(ProcedureType.prototype, "type", {
    get: function() {
        return wrapPointer(_toy_ProcedureType__get_type(this.__ptr), Type);
    }});
Object.defineProperty(ProcedureType.prototype, "index", {
    get: function() {
        return _toy_ProcedureType__get_index(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('ProcedureType.index: expected integer');
        _toy_ProcedureType__set_index(this.__ptr, value);
    }
});
Object.defineProperty(ProcedureType.prototype, "name", {
    get: function() {
        return UTF8ToString(_toy_ProcedureType__get_name(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('ProcedureType.name: expected string');
        _toy_ProcedureType__set_name(this.__ptr, ensureString(value));
    }
});
ProcedureType.prototype["__destroy"] = ProcedureType.prototype.__destroy = function() {
    _toy_ProcedureType__destroy(this.__ptr);
};
// Procedure
function Procedure() { throw "cannot construct a Procedure, no constructor in IDL" }
Procedure.prototype = Object.create(WrapperObject.prototype);
Procedure.prototype.constructor = Procedure;
Procedure.prototype.__class = Procedure;
Procedure.__cache = {};
Module['Procedure'] = Procedure;
Procedure.prototype["__destroy"] = Procedure.prototype.__destroy = function() {
    _toy_Procedure__destroy(this.__ptr);
};

(function() {
    function setup() {
        ProcedureType.prototype.__type = _toy_ProcedureType__type();
        Procedure.prototype.__type = _toy_Procedure__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
