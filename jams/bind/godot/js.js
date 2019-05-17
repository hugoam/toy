Module['two']['ui'] = Module['two']['ui'] || {};
Module['boids'] = Module['boids'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
Module['toy'] = Module['toy'] || {};
// Aim
function Aim() {
    this.ptr = _Aim_Aim_0(); getCache(Aim)[this.ptr] = this;
    this.type = Aim;
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
        /* value <quat> [] */
        value = value.ptr;
        _Aim__set_rotation(self, value);
    }
});
Object.defineProperty(Aim.prototype, "start", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim__get_start(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Aim__set_start(self, value);
    }
});
Object.defineProperty(Aim.prototype, "end", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim__get_end(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Aim__set_end(self, value);
    }
});
Object.defineProperty(Aim.prototype, "hit", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim__get_hit(self), Spatial);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Spatial> [] */
        value = value.ptr;
        _Aim__set_hit(self, value);
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
        return wrapPointer(_Bullet__get_source(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Bullet__set_source(self, value);
    }
});
Object.defineProperty(Bullet.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Bullet__get_velocity(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Bullet__set_velocity(self, value);
    }
});
Bullet.prototype["__destroy__"] = Bullet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Bullet__destroy(self);
};
// Crate
function Crate(spatial, movable, extents) {
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* extents <vec3> [] */
    if(typeof extents !== "undefined" && extents !== null) { extents = extents.ptr; }
    if (spatial === undefined) { this.ptr = _Crate_Crate_0(); getCache(Crate)[this.ptr] = this; return; }
    this.ptr = _Crate_Crate_3(spatial, movable, extents); getCache(Crate)[this.ptr] = this;
    this.type = Crate;
};
Crate.prototype = Object.create(WrapperObject.prototype);
Crate.prototype.constructor = Crate;
Crate.prototype.__class__ = Crate;
Crate.__cache__ = {};
Module['Crate'] = Crate;
Object.defineProperty(Crate.prototype, "extents", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Crate__get_extents(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Crate__set_extents(self, value);
    }
});
Crate.prototype["__destroy__"] = Crate.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Crate__destroy(self);
};
// Human
function Human(spatial, movable, emitter, receptor, script, faction) {
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* emitter <toy::HEmitter> [] */
    /* receptor <toy::HReceptor> [] */
    /* script <toy::HEntityScript> [] */
    /* faction <Faction> [] */
    if (faction && typeof faction === "object") faction = faction.ptr;
    if (spatial === undefined) { this.ptr = _Human_Human_0(); getCache(Human)[this.ptr] = this; return; }
    this.ptr = _Human_Human_6(spatial, movable, emitter, receptor, script, faction); getCache(Human)[this.ptr] = this;
    this.type = Human;
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class__ = Human;
Human.__cache__ = {};
Module['Human'] = Human;
Human.prototype["sight"] = Human.prototype.sight = function(self, aiming) {
    var self = this.ptr;
    /* aiming <bool> [] */
    if (aiming === undefined) { return wrapPointer(_Human_sight_0(self), quat); }
    return wrapPointer(_Human_sight_1(self, aiming), quat);
};
Human.prototype["aim"] = Human.prototype.aim = function(self) {
    var self = this.ptr;
    return wrapPointer(_Human_aim_0(self), Aim);
};
Human.prototype["shoot"] = Human.prototype.shoot = function(self) {
    var self = this.ptr;
    _Human_shoot_0(self);
};
Human.prototype["stop"] = Human.prototype.stop = function(self) {
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
        /* value <Faction> [] */
        if (value && typeof value === "object") value = value.ptr;
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
        /* value <float> [] */
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
        /* value <float> [] */
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
        /* value <float> [] */
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
        /* value <bool> [] */
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
        /* value <bool> [] */
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
        /* value <bool> [] */
        _Human__set_walk(self, value);
    }
});
Object.defineProperty(Human.prototype, "target", {
    get: function() {
        var self = this.ptr;
        return _Human__get_target(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <HHuman> [] */
        _Human__set_target(self, value);
    }
});
Object.defineProperty(Human.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Human__get_dest(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Human__set_dest(self, value);
    }
});
Object.defineProperty(Human.prototype, "cooldown", {
    get: function() {
        var self = this.ptr;
        return _Human__get_cooldown(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
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
        /* value <Stance> [] */
        value = value.ptr;
        _Human__set_state(self, value);
    }
});
Human.prototype["__destroy__"] = Human.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Human__destroy(self);
};
// Lamp
function Lamp(spatial, movable) {
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    if (spatial === undefined) { this.ptr = _Lamp_Lamp_0(); getCache(Lamp)[this.ptr] = this; return; }
    this.ptr = _Lamp_Lamp_2(spatial, movable); getCache(Lamp)[this.ptr] = this;
    this.type = Lamp;
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
function Stance(name, loop) {
    ensureCache.prepare();
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* loop <bool> [] */
    if (name === undefined) { this.ptr = _Stance_Stance_0(); getCache(Stance)[this.ptr] = this; return; }
    this.ptr = _Stance_Stance_2(name, loop); getCache(Stance)[this.ptr] = this;
    this.type = Stance;
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
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Stance__set_name(self, value);
    }
});
Object.defineProperty(Stance.prototype, "loop", {
    get: function() {
        var self = this.ptr;
        return !!(_Stance__get_loop(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _Stance__set_loop(self, value);
    }
});
Stance.prototype["__destroy__"] = Stance.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Stance__destroy(self);
};
// WorldBlock
function WorldBlock(spatial, world_page, navblock, extents) {
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navblock <toy::HNavblock> [] */
    /* extents <vec3> [] */
    if(typeof extents !== "undefined" && extents !== null) { extents = extents.ptr; }
    if (spatial === undefined) { this.ptr = _WorldBlock_WorldBlock_0(); getCache(WorldBlock)[this.ptr] = this; return; }
    this.ptr = _WorldBlock_WorldBlock_4(spatial, world_page, navblock, extents); getCache(WorldBlock)[this.ptr] = this;
    this.type = WorldBlock;
};
WorldBlock.prototype = Object.create(WrapperObject.prototype);
WorldBlock.prototype.constructor = WorldBlock;
WorldBlock.prototype.__class__ = WorldBlock;
WorldBlock.__cache__ = {};
Module['WorldBlock'] = WorldBlock;
Object.defineProperty(WorldBlock.prototype, "extents", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_WorldBlock__get_extents(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _WorldBlock__set_extents(self, value);
    }
});
WorldBlock.prototype["__destroy__"] = WorldBlock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _WorldBlock__destroy(self);
};

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
