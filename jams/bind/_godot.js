Module['mud'] = Module['mud'] || {};
// Aim
function Aim() {
    this.ptr = _Aim__construct_0(); this.type = Aim; getCache(Aim)[this.ptr] = this;
};
Aim.prototype = Object.create(WrapperObject.prototype);
Aim.prototype.constructor = Aim;
Aim.prototype.__class__ = Aim;
Aim.__cache__ = {};
Module['Aim'] = Aim;
Object.defineProperty(Aim.prototype, "rotation", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim__get_rotation(self), quat);
    },
    set: function(value) {
        var self = this.ptr;
        _Aim__set_rotation(self, value.ptr);
    }
});
Object.defineProperty(Aim.prototype, "start", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim__get_start(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Aim__set_start(self, value.ptr);
    }
});
Object.defineProperty(Aim.prototype, "end", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim__get_end(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Aim__set_end(self, value.ptr);
    }
});
Object.defineProperty(Aim.prototype, "hit", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim__get_hit(self), Spatial);
    },
    set: function(value) {
        var self = this.ptr;
        _Aim__set_hit(self, value.ptr);
    }
});
Aim.prototype["__destroy__"] = Aim.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Aim__destroy(self);
};
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
// ComponentHandle<Lamp>
function ComponentHandle_Lamp() {
    this.ptr = _mud_ComponentHandle_Lamp__construct_0(); this.type = ComponentHandle_Lamp; getCache(ComponentHandle_Lamp)[this.ptr] = this;
};
ComponentHandle_Lamp.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Lamp.prototype.constructor = ComponentHandle_Lamp;
ComponentHandle_Lamp.prototype.__class__ = ComponentHandle_Lamp;
ComponentHandle_Lamp.__cache__ = {};
Module['mud']['ComponentHandle_Lamp'] = ComponentHandle_Lamp;
ComponentHandle_Lamp.prototype["__destroy__"] = ComponentHandle_Lamp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Lamp__destroy(self);
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
function Human(a0, a1, a2, a3, a4, a5) {
    if (a0 === undefined) { this.ptr = _Human__construct_0(); this.type = Human; getCache(Human)[this.ptr] = this; return; }
    this.ptr = _Human__construct_6(/*spatial*/a0.ptr, /*movable*/a1.ptr, /*emitter*/a2.ptr, /*receptor*/a3.ptr, /*script*/a4.ptr, /*faction*/a5); this.type = Human; getCache(Human)[this.ptr] = this;
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class__ = Human;
Human.__cache__ = {};
Module['Human'] = Human;
Human.prototype["sight"] = Human.prototype.sight = function(a0) {
    var self = this.ptr;
    if (a0 === undefined) { return wrapPointer(_Human_sight_0(self), quat); }
    return wrapPointer(_Human_sight_1(self, /*aiming*/a0), quat);
};
Human.prototype["aim"] = Human.prototype.aim = function() {
    var self = this.ptr;
    return wrapPointer(_Human_aim_0(self), Aim);
};
Human.prototype["shoot"] = Human.prototype.shoot = function() {
    var self = this.ptr;
    _Human_shoot_0(self);
};
Human.prototype["stop"] = Human.prototype.stop = function() {
    var self = this.ptr;
    _Human_stop_0(self);
};
Object.defineProperty(Human.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return _Human__get_faction(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_faction(self, value);
    }
});
Object.defineProperty(Human.prototype, "life", {
    get: function() {
        var self = this.ptr;
        return _Human__get_life(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_life(self, value);
    }
});
Object.defineProperty(Human.prototype, "energy", {
    get: function() {
        var self = this.ptr;
        return _Human__get_energy(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_energy(self, value);
    }
});
Object.defineProperty(Human.prototype, "discharge", {
    get: function() {
        var self = this.ptr;
        return _Human__get_discharge(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_discharge(self, value);
    }
});
Object.defineProperty(Human.prototype, "headlight", {
    get: function() {
        var self = this.ptr;
        return !!(_Human__get_headlight(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_headlight(self, value);
    }
});
Object.defineProperty(Human.prototype, "shield", {
    get: function() {
        var self = this.ptr;
        return !!(_Human__get_shield(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_shield(self, value);
    }
});
Object.defineProperty(Human.prototype, "walk", {
    get: function() {
        var self = this.ptr;
        return !!(_Human__get_walk(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_walk(self, value);
    }
});
Object.defineProperty(Human.prototype, "target", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Human__get_target(self), ComponentHandle_Human);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_target(self, value.ptr);
    }
});
Object.defineProperty(Human.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Human__get_dest(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_dest(self, value.ptr);
    }
});
Object.defineProperty(Human.prototype, "cooldown", {
    get: function() {
        var self = this.ptr;
        return _Human__get_cooldown(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_cooldown(self, value);
    }
});
Object.defineProperty(Human.prototype, "state", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Human__get_state(self), Stance);
    },
    set: function(value) {
        var self = this.ptr;
        _Human__set_state(self, value.ptr);
    }
});
Human.prototype["__destroy__"] = Human.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Human__destroy(self);
};
// Lamp
function Lamp(a0, a1) {
    if (a0 === undefined) { this.ptr = _Lamp__construct_0(); this.type = Lamp; getCache(Lamp)[this.ptr] = this; return; }
    this.ptr = _Lamp__construct_2(/*spatial*/a0.ptr, /*movable*/a1.ptr); this.type = Lamp; getCache(Lamp)[this.ptr] = this;
};
Lamp.prototype = Object.create(WrapperObject.prototype);
Lamp.prototype.constructor = Lamp;
Lamp.prototype.__class__ = Lamp;
Lamp.__cache__ = {};
Module['Lamp'] = Lamp;
Lamp.prototype["__destroy__"] = Lamp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Lamp__destroy(self);
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
// Stance
function Stance(a0, a1) {
    ensureCache.prepare();
    if (a0 === undefined) { this.ptr = _Stance__construct_0(); this.type = Stance; getCache(Stance)[this.ptr] = this; return; }
    this.ptr = _Stance__construct_2(ensureString(/*name*/a0), /*loop*/a1); this.type = Stance; getCache(Stance)[this.ptr] = this;
};
Stance.prototype = Object.create(WrapperObject.prototype);
Stance.prototype.constructor = Stance;
Stance.prototype.__class__ = Stance;
Stance.__cache__ = {};
Module['Stance'] = Stance;
Object.defineProperty(Stance.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Stance__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Stance__set_name(self, ensureString(value));
    }
});
Object.defineProperty(Stance.prototype, "loop", {
    get: function() {
        var self = this.ptr;
        return !!(_Stance__get_loop(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Stance__set_loop(self, value);
    }
});
Stance.prototype["__destroy__"] = Stance.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Stance__destroy(self);
};
// WorldBlock
function WorldBlock(a0, a1, a2, a3) {
    if (a0 === undefined) { this.ptr = _WorldBlock__construct_0(); this.type = WorldBlock; getCache(WorldBlock)[this.ptr] = this; return; }
    this.ptr = _WorldBlock__construct_4(/*spatial*/a0.ptr, /*world_page*/a1.ptr, /*navblock*/a2.ptr, /*extents*/a3.ptr); this.type = WorldBlock; getCache(WorldBlock)[this.ptr] = this;
};
WorldBlock.prototype = Object.create(WrapperObject.prototype);
WorldBlock.prototype.constructor = WorldBlock;
WorldBlock.prototype.__class__ = WorldBlock;
WorldBlock.__cache__ = {};
Module['WorldBlock'] = WorldBlock;
Object.defineProperty(WorldBlock.prototype, "extents", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_WorldBlock__get_extents(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _WorldBlock__set_extents(self, value.ptr);
    }
});
WorldBlock.prototype["__destroy__"] = WorldBlock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _WorldBlock__destroy(self);
};
Module['HBullet'] = ComponentHandle_Bullet;
Module['HHuman'] = ComponentHandle_Human;
Module['HLamp'] = ComponentHandle_Lamp;
Module['HCrate'] = ComponentHandle_Crate;

(function() {
    function setup() {
        Aim.__type__ = _Aim__type();
        Bullet.__type__ = _Bullet__type();
        Crate.__type__ = _Crate__type();
        Human.__type__ = _Human__type();
        Lamp.__type__ = _Lamp__type();
        Player.__type__ = _Player__type();
        Stance.__type__ = _Stance__type();
        WorldBlock.__type__ = _WorldBlock__type();
        // Faction
        Module['Faction'] = Module['Faction'] || {};
        Module['Faction']['Ally'] = _Faction_Ally();
        Module['Faction']['Enemy'] = _Faction_Enemy();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
