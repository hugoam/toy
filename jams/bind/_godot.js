Module['mud'] = Module['mud'] || {};
// Aim
function Aim() {
    this.__ptr = _Aim__construct_0(); this.__type = Aim.__type; getCache(Aim)[this.__ptr] = this;
};
Aim.prototype = Object.create(WrapperObject.prototype);
Aim.prototype.constructor = Aim;
Aim.prototype.__class = Aim;
Aim.__cache = {};
Module['Aim'] = Aim;
Object.defineProperty(Aim.prototype, "rotation", {
    get: function() {
        return wrapPointer(_Aim__get_rotation(this.__ptr), quat);
    },
    set: function(value) {
        _Aim__set_rotation(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Aim.prototype, "start", {
    get: function() {
        return wrapPointer(_Aim__get_start(this.__ptr), v3_float);
    },
    set: function(value) {
        _Aim__set_start(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Aim.prototype, "end", {
    get: function() {
        return wrapPointer(_Aim__get_end(this.__ptr), v3_float);
    },
    set: function(value) {
        _Aim__set_end(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Aim.prototype, "hit", {
    get: function() {
        return wrapPointer(_Aim__get_hit(this.__ptr), Spatial);
    },
    set: function(value) {
        _Aim__set_hit(this.__ptr, value.__ptr);
    }
});
Aim.prototype["__destroy"] = Aim.prototype.__destroy = function() {
    _Aim__destroy(this.__ptr);
};
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
// ComponentHandle<Lamp>
function ComponentHandle_Lamp() {
    this.__ptr = _mud_ComponentHandle_Lamp__construct_0(); this.__type = ComponentHandle_Lamp.__type; getCache(ComponentHandle_Lamp)[this.__ptr] = this;
};
ComponentHandle_Lamp.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Lamp.prototype.constructor = ComponentHandle_Lamp;
ComponentHandle_Lamp.prototype.__class = ComponentHandle_Lamp;
ComponentHandle_Lamp.__cache = {};
Module['mud']['ComponentHandle_Lamp'] = ComponentHandle_Lamp;
ComponentHandle_Lamp.prototype["__destroy"] = ComponentHandle_Lamp.prototype.__destroy = function() {
    _mud_ComponentHandle_Lamp__destroy(this.__ptr);
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
function Human(a0, a1, a2, a3, a4, a5) {
    if (a0 === undefined) { this.__ptr = _Human__construct_0(); this.__type = Human.__type; getCache(Human)[this.__ptr] = this; return; }
    this.__ptr = _Human__construct_6(/*spatial*/a0.__ptr, /*movable*/a1.__ptr, /*emitter*/a2.__ptr, /*receptor*/a3.__ptr, /*script*/a4.__ptr, /*faction*/a5); this.__type = Human.__type; getCache(Human)[this.__ptr] = this;
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class = Human;
Human.__cache = {};
Module['Human'] = Human;
Human.prototype["sight"] = Human.prototype.sight = function(a0) {
    if (a0 === undefined) { return wrapPointer(_Human_sight_0(this.__ptr), quat); }
    return wrapPointer(_Human_sight_1(this.__ptr, /*aiming*/a0), quat);
};
Human.prototype["aim"] = Human.prototype.aim = function() {
    return wrapPointer(_Human_aim_0(this.__ptr), Aim);
};
Human.prototype["shoot"] = Human.prototype.shoot = function() {
    _Human_shoot_0(this.__ptr);
};
Human.prototype["stop"] = Human.prototype.stop = function() {
    _Human_stop_0(this.__ptr);
};
Object.defineProperty(Human.prototype, "faction", {
    get: function() {
        return _Human__get_faction(this.__ptr);
    },
    set: function(value) {
        _Human__set_faction(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "life", {
    get: function() {
        return _Human__get_life(this.__ptr);
    },
    set: function(value) {
        _Human__set_life(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "energy", {
    get: function() {
        return _Human__get_energy(this.__ptr);
    },
    set: function(value) {
        _Human__set_energy(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "discharge", {
    get: function() {
        return _Human__get_discharge(this.__ptr);
    },
    set: function(value) {
        _Human__set_discharge(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "headlight", {
    get: function() {
        return !!(_Human__get_headlight(this.__ptr));
    },
    set: function(value) {
        _Human__set_headlight(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "shield", {
    get: function() {
        return !!(_Human__get_shield(this.__ptr));
    },
    set: function(value) {
        _Human__set_shield(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "walk", {
    get: function() {
        return !!(_Human__get_walk(this.__ptr));
    },
    set: function(value) {
        _Human__set_walk(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "target", {
    get: function() {
        return wrapPointer(_Human__get_target(this.__ptr), ComponentHandle_Human);
    },
    set: function(value) {
        _Human__set_target(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Human.prototype, "dest", {
    get: function() {
        return wrapPointer(_Human__get_dest(this.__ptr), v3_float);
    },
    set: function(value) {
        _Human__set_dest(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Human.prototype, "cooldown", {
    get: function() {
        return _Human__get_cooldown(this.__ptr);
    },
    set: function(value) {
        _Human__set_cooldown(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "state", {
    get: function() {
        return wrapPointer(_Human__get_state(this.__ptr), Stance);
    },
    set: function(value) {
        _Human__set_state(this.__ptr, value.__ptr);
    }
});
Human.prototype["__destroy"] = Human.prototype.__destroy = function() {
    _Human__destroy(this.__ptr);
};
// Lamp
function Lamp(a0, a1) {
    if (a0 === undefined) { this.__ptr = _Lamp__construct_0(); this.__type = Lamp.__type; getCache(Lamp)[this.__ptr] = this; return; }
    this.__ptr = _Lamp__construct_2(/*spatial*/a0.__ptr, /*movable*/a1.__ptr); this.__type = Lamp.__type; getCache(Lamp)[this.__ptr] = this;
};
Lamp.prototype = Object.create(WrapperObject.prototype);
Lamp.prototype.constructor = Lamp;
Lamp.prototype.__class = Lamp;
Lamp.__cache = {};
Module['Lamp'] = Lamp;
Lamp.prototype["__destroy"] = Lamp.prototype.__destroy = function() {
    _Lamp__destroy(this.__ptr);
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
// Stance
function Stance(a0, a1) {
    ensureCache.prepare();
    if (a0 === undefined) { this.__ptr = _Stance__construct_0(); this.__type = Stance.__type; getCache(Stance)[this.__ptr] = this; return; }
    this.__ptr = _Stance__construct_2(ensureString(/*name*/a0), /*loop*/a1); this.__type = Stance.__type; getCache(Stance)[this.__ptr] = this;
};
Stance.prototype = Object.create(WrapperObject.prototype);
Stance.prototype.constructor = Stance;
Stance.prototype.__class = Stance;
Stance.__cache = {};
Module['Stance'] = Stance;
Object.defineProperty(Stance.prototype, "name", {
    get: function() {
        return UTF8ToString(_Stance__get_name(this.__ptr));
    },
    set: function(value) {
        _Stance__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Stance.prototype, "loop", {
    get: function() {
        return !!(_Stance__get_loop(this.__ptr));
    },
    set: function(value) {
        _Stance__set_loop(this.__ptr, value);
    }
});
Stance.prototype["__destroy"] = Stance.prototype.__destroy = function() {
    _Stance__destroy(this.__ptr);
};
// WorldBlock
function WorldBlock(a0, a1, a2, a3) {
    if (a0 === undefined) { this.__ptr = _WorldBlock__construct_0(); this.__type = WorldBlock.__type; getCache(WorldBlock)[this.__ptr] = this; return; }
    this.__ptr = _WorldBlock__construct_4(/*spatial*/a0.__ptr, /*world_page*/a1.__ptr, /*navblock*/a2.__ptr, /*extents*/a3.__ptr); this.__type = WorldBlock.__type; getCache(WorldBlock)[this.__ptr] = this;
};
WorldBlock.prototype = Object.create(WrapperObject.prototype);
WorldBlock.prototype.constructor = WorldBlock;
WorldBlock.prototype.__class = WorldBlock;
WorldBlock.__cache = {};
Module['WorldBlock'] = WorldBlock;
Object.defineProperty(WorldBlock.prototype, "extents", {
    get: function() {
        return wrapPointer(_WorldBlock__get_extents(this.__ptr), v3_float);
    },
    set: function(value) {
        _WorldBlock__set_extents(this.__ptr, value.__ptr);
    }
});
WorldBlock.prototype["__destroy"] = WorldBlock.prototype.__destroy = function() {
    _WorldBlock__destroy(this.__ptr);
};
Module['HBullet'] = ComponentHandle_Bullet;
Module['HHuman'] = ComponentHandle_Human;
Module['HLamp'] = ComponentHandle_Lamp;
Module['HCrate'] = ComponentHandle_Crate;

(function() {
    function setup() {
        Aim.__type = _Aim__type();
        Bullet.__type = _Bullet__type();
        Crate.__type = _Crate__type();
        Human.__type = _Human__type();
        Lamp.__type = _Lamp__type();
        Player.__type = _Player__type();
        Stance.__type = _Stance__type();
        WorldBlock.__type = _WorldBlock__type();
        // Faction
        Module['Faction'] = Module['Faction'] || {};
        Module['Faction']['Ally'] = _Faction_Ally();
        Module['Faction']['Enemy'] = _Faction_Enemy();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
