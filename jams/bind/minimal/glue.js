
// Bindings utilities
function WrapperObject() {
}
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
        return _Bullet_get_source(self);
    },
    set: function(source) {
        var self = this.ptr;
        /* source <vec3> [] */
        _Bullet_set_source(self, source);
    }
});
Object.defineProperty(Bullet.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return _Bullet_get_velocity(self);
    },
    set: function(velocity) {
        var self = this.ptr;
        /* velocity <vec3> [] */
        _Bullet_set_velocity(self, velocity);
    }
});
Bullet.prototype["__destroy__"] = Bullet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Bullet___destroy__(self);
};
// Crate
function Crate(spatial, movable, extents) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* extents <vec3> [] */
    if (spatial === undefined) { this.ptr = _Crate_Crate_0(self); getCache(Crate)[this.ptr] = this; return; }
    this.ptr = _Crate_Crate_3(self, spatial, movable, extents); getCache(Crate)[this.ptr] = this;
};
Crate.prototype = Object.create(WrapperObject.prototype);
Crate.prototype.constructor = Crate;
Crate.prototype.__class__ = Crate;
Crate.__cache__ = {};
Module['Crate'] = Crate;
Object.defineProperty(Crate.prototype, "extents", {
    get: function() {
        var self = this.ptr;
        return _Crate_get_extents(self);
    },
    set: function(extents) {
        var self = this.ptr;
        /* extents <vec3> [] */
        _Crate_set_extents(self, extents);
    }
});
Crate.prototype["__destroy__"] = Crate.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Crate___destroy__(self);
};
// Human
function Human(spatial, movable) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    if (spatial === undefined) { this.ptr = _Human_Human_0(self); getCache(Human)[this.ptr] = this; return; }
    this.ptr = _Human_Human_2(self, spatial, movable); getCache(Human)[this.ptr] = this;
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class__ = Human;
Human.__cache__ = {};
Module['Human'] = Human;
Human.prototype["__destroy__"] = Human.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Human___destroy__(self);
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
    _Player___destroy__(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
