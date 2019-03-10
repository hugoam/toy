Module['mud'] = Module['mud'] || {};
// Bullet
function Bullet() { throw "cannot construct a Bullet, no constructor in IDL" }
Bullet.prototype = Object.create(WrapperObject.prototype);
Bullet.prototype.constructor = Bullet;
Bullet.prototype.__class = Bullet;
Bullet.__cache = {};
Module['Bullet'] = Bullet;
Object.defineProperty(Bullet.prototype, "source", {
    get: function() {
        return wrapPointer(_Bullet__get_source(this.__ptr), v3_float);
    },
    set: function(value) {
        _Bullet__set_source(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Bullet.prototype, "velocity", {
    get: function() {
        return wrapPointer(_Bullet__get_velocity(this.__ptr), v3_float);
    },
    set: function(value) {
        _Bullet__set_velocity(this.__ptr, value.__ptr);
    }
});
Bullet.prototype["__destroy"] = Bullet.prototype.__destroy = function() {
    _Bullet__destroy(this.__ptr);
};
// ComponentHandle<Bullet>
function ComponentHandle_Bullet() {
    this.__ptr = _mud_ComponentHandle_Bullet__construct_0(); this.__type = ComponentHandle_Bullet.__type; getCache(ComponentHandle_Bullet)[this.__ptr] = this;
};
ComponentHandle_Bullet.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Bullet.prototype.constructor = ComponentHandle_Bullet;
ComponentHandle_Bullet.prototype.__class = ComponentHandle_Bullet;
ComponentHandle_Bullet.__cache = {};
Module['mud']['ComponentHandle_Bullet'] = ComponentHandle_Bullet;
ComponentHandle_Bullet.prototype["__destroy"] = ComponentHandle_Bullet.prototype.__destroy = function() {
    _mud_ComponentHandle_Bullet__destroy(this.__ptr);
};
// ComponentHandle<Crate>
function ComponentHandle_Crate() {
    this.__ptr = _mud_ComponentHandle_Crate__construct_0(); this.__type = ComponentHandle_Crate.__type; getCache(ComponentHandle_Crate)[this.__ptr] = this;
};
ComponentHandle_Crate.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Crate.prototype.constructor = ComponentHandle_Crate;
ComponentHandle_Crate.prototype.__class = ComponentHandle_Crate;
ComponentHandle_Crate.__cache = {};
Module['mud']['ComponentHandle_Crate'] = ComponentHandle_Crate;
ComponentHandle_Crate.prototype["__destroy"] = ComponentHandle_Crate.prototype.__destroy = function() {
    _mud_ComponentHandle_Crate__destroy(this.__ptr);
};
// ComponentHandle<Human>
function ComponentHandle_Human() {
    this.__ptr = _mud_ComponentHandle_Human__construct_0(); this.__type = ComponentHandle_Human.__type; getCache(ComponentHandle_Human)[this.__ptr] = this;
};
ComponentHandle_Human.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Human.prototype.constructor = ComponentHandle_Human;
ComponentHandle_Human.prototype.__class = ComponentHandle_Human;
ComponentHandle_Human.__cache = {};
Module['mud']['ComponentHandle_Human'] = ComponentHandle_Human;
ComponentHandle_Human.prototype["__destroy"] = ComponentHandle_Human.prototype.__destroy = function() {
    _mud_ComponentHandle_Human__destroy(this.__ptr);
};
// Crate
function Crate(a0, a1, a2) {
    if (a0 === undefined) { this.__ptr = _Crate__construct_0(); this.__type = Crate.__type; getCache(Crate)[this.__ptr] = this; return; }
    this.__ptr = _Crate__construct_3(/*spatial*/a0.__ptr, /*movable*/a1.__ptr, /*extents*/a2.__ptr); this.__type = Crate.__type; getCache(Crate)[this.__ptr] = this;
};
Crate.prototype = Object.create(WrapperObject.prototype);
Crate.prototype.constructor = Crate;
Crate.prototype.__class = Crate;
Crate.__cache = {};
Module['Crate'] = Crate;
Object.defineProperty(Crate.prototype, "extents", {
    get: function() {
        return wrapPointer(_Crate__get_extents(this.__ptr), v3_float);
    },
    set: function(value) {
        _Crate__set_extents(this.__ptr, value.__ptr);
    }
});
Crate.prototype["__destroy"] = Crate.prototype.__destroy = function() {
    _Crate__destroy(this.__ptr);
};
// Human
function Human(a0, a1) {
    if (a0 === undefined) { this.__ptr = _Human__construct_0(); this.__type = Human.__type; getCache(Human)[this.__ptr] = this; return; }
    this.__ptr = _Human__construct_2(/*spatial*/a0.__ptr, /*movable*/a1.__ptr); this.__type = Human.__type; getCache(Human)[this.__ptr] = this;
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class = Human;
Human.__cache = {};
Module['Human'] = Human;
Human.prototype["__destroy"] = Human.prototype.__destroy = function() {
    _Human__destroy(this.__ptr);
};
// Player
function Player() { throw "cannot construct a Player, no constructor in IDL" }
Player.prototype = Object.create(WrapperObject.prototype);
Player.prototype.constructor = Player;
Player.prototype.__class = Player;
Player.__cache = {};
Module['Player'] = Player;
Player.prototype["__destroy"] = Player.prototype.__destroy = function() {
    _Player__destroy(this.__ptr);
};
Module['HBullet'] = ComponentHandle_Bullet;
Module['HHuman'] = ComponentHandle_Human;
Module['HCrate'] = ComponentHandle_Crate;

(function() {
    function setup() {
        Bullet.__type = _Bullet__type();
        Crate.__type = _Crate__type();
        Human.__type = _Human__type();
        Player.__type = _Player__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
