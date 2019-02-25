Module['mud'] = Module['mud'] || {};
// Bullet
function Bullet() { throw "cannot construct a Bullet, no constructor in IDL" }
Bullet.prototype = Object.create(WrapperObject.prototype);
Bullet.prototype.constructor = Bullet;
Bullet.prototype.__class__ = Bullet;
Bullet.__cache__ = {};
Module['Bullet'] = Bullet;
Object.defineProperty(Bullet.prototype, "source", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Bullet__get_source(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Bullet__set_source(self, value.ptr);
    }
});
Object.defineProperty(Bullet.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Bullet__get_velocity(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Bullet__set_velocity(self, value.ptr);
    }
});
Bullet.prototype["__destroy__"] = Bullet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Bullet__destroy(self);
};
// ComponentHandle<Bullet>
function ComponentHandle_Bullet() {
    this.ptr = _mud_ComponentHandle_Bullet__construct_0(); this.type = ComponentHandle_Bullet; getCache(ComponentHandle_Bullet)[this.ptr] = this;
};
ComponentHandle_Bullet.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Bullet.prototype.constructor = ComponentHandle_Bullet;
ComponentHandle_Bullet.prototype.__class__ = ComponentHandle_Bullet;
ComponentHandle_Bullet.__cache__ = {};
Module['mud']['ComponentHandle_Bullet'] = ComponentHandle_Bullet;
ComponentHandle_Bullet.prototype["__destroy__"] = ComponentHandle_Bullet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Bullet__destroy(self);
};
// ComponentHandle<Crate>
function ComponentHandle_Crate() {
    this.ptr = _mud_ComponentHandle_Crate__construct_0(); this.type = ComponentHandle_Crate; getCache(ComponentHandle_Crate)[this.ptr] = this;
};
ComponentHandle_Crate.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Crate.prototype.constructor = ComponentHandle_Crate;
ComponentHandle_Crate.prototype.__class__ = ComponentHandle_Crate;
ComponentHandle_Crate.__cache__ = {};
Module['mud']['ComponentHandle_Crate'] = ComponentHandle_Crate;
ComponentHandle_Crate.prototype["__destroy__"] = ComponentHandle_Crate.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Crate__destroy(self);
};
// ComponentHandle<Human>
function ComponentHandle_Human() {
    this.ptr = _mud_ComponentHandle_Human__construct_0(); this.type = ComponentHandle_Human; getCache(ComponentHandle_Human)[this.ptr] = this;
};
ComponentHandle_Human.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Human.prototype.constructor = ComponentHandle_Human;
ComponentHandle_Human.prototype.__class__ = ComponentHandle_Human;
ComponentHandle_Human.__cache__ = {};
Module['mud']['ComponentHandle_Human'] = ComponentHandle_Human;
ComponentHandle_Human.prototype["__destroy__"] = ComponentHandle_Human.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Human__destroy(self);
};
// Crate
function Crate(a0, a1, a2) {
    if (a0 === undefined) { this.ptr = _Crate__construct_0(); this.type = Crate; getCache(Crate)[this.ptr] = this; return; }
    this.ptr = _Crate__construct_3(/*spatial*/a0.ptr, /*movable*/a1.ptr, /*extents*/a2.ptr); this.type = Crate; getCache(Crate)[this.ptr] = this;
};
Crate.prototype = Object.create(WrapperObject.prototype);
Crate.prototype.constructor = Crate;
Crate.prototype.__class__ = Crate;
Crate.__cache__ = {};
Module['Crate'] = Crate;
Object.defineProperty(Crate.prototype, "extents", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Crate__get_extents(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Crate__set_extents(self, value.ptr);
    }
});
Crate.prototype["__destroy__"] = Crate.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Crate__destroy(self);
};
// Human
function Human(a0, a1) {
    if (a0 === undefined) { this.ptr = _Human__construct_0(); this.type = Human; getCache(Human)[this.ptr] = this; return; }
    this.ptr = _Human__construct_2(/*spatial*/a0.ptr, /*movable*/a1.ptr); this.type = Human; getCache(Human)[this.ptr] = this;
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class__ = Human;
Human.__cache__ = {};
Module['Human'] = Human;
Human.prototype["__destroy__"] = Human.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Human__destroy(self);
};
// Player
function Player() { throw "cannot construct a Player, no constructor in IDL" }
Player.prototype = Object.create(WrapperObject.prototype);
Player.prototype.constructor = Player;
Player.prototype.__class__ = Player;
Player.__cache__ = {};
Module['Player'] = Player;
Player.prototype["__destroy__"] = Player.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Player__destroy(self);
};
Module['HBullet'] = ComponentHandle_Bullet;
Module['HHuman'] = ComponentHandle_Human;
Module['HCrate'] = ComponentHandle_Crate;

(function() {
    function setup() {
        Bullet.__type__ = _Bullet__type();
        Crate.__type__ = _Crate__type();
        Human.__type__ = _Human__type();
        Player.__type__ = _Player__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
