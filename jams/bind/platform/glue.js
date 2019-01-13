
// Bindings utilities
function WrapperObject() {
}
// Aim
function Aim() {
    var self = this.ptr;
    this.ptr = _Aim_Aim_0(self); getCache(Aim)[this.ptr] = this;
};
Aim.prototype = Object.create(WrapperObject.prototype);
Aim.prototype.constructor = Aim;
Aim.prototype.__class__ = Aim;
Aim.__cache__ = {};
Module['Aim'] = Aim;
Object.defineProperty(Aim.prototype, "rotation", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim_get_rotation(self), mud::quat);
    },
    set: function(rotation) {
        var self = this.ptr;
        /* rotation <quat> [] */
        rotation = rotation.ptr;
        _Aim_set_rotation(self, rotation);
    }
});
Object.defineProperty(Aim.prototype, "start", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim_get_start(self), mud::vec3);
    },
    set: function(start) {
        var self = this.ptr;
        /* start <vec3> [] */
        start = start.ptr;
        _Aim_set_start(self, start);
    }
});
Object.defineProperty(Aim.prototype, "end", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim_get_end(self), mud::vec3);
    },
    set: function(end) {
        var self = this.ptr;
        /* end <vec3> [] */
        end = end.ptr;
        _Aim_set_end(self, end);
    }
});
Object.defineProperty(Aim.prototype, "hit", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Aim_get_hit(self), toy::Spatial);
    },
    set: function(hit) {
        var self = this.ptr;
        /* hit <Spatial> [] */
        hit = hit.ptr;
        _Aim_set_hit(self, hit);
    }
});
Aim.prototype["__destroy__"] = Aim.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Aim___destroy__(self);
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
        return wrapPointer(_Bullet_get_source(self), mud::vec3);
    },
    set: function(source) {
        var self = this.ptr;
        /* source <vec3> [] */
        source = source.ptr;
        _Bullet_set_source(self, source);
    }
});
Object.defineProperty(Bullet.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Bullet_get_velocity(self), mud::vec3);
    },
    set: function(velocity) {
        var self = this.ptr;
        /* velocity <vec3> [] */
        velocity = velocity.ptr;
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
    extents = extents.ptr;
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
        return wrapPointer(_Crate_get_extents(self), mud::vec3);
    },
    set: function(extents) {
        var self = this.ptr;
        /* extents <vec3> [] */
        extents = extents.ptr;
        _Crate_set_extents(self, extents);
    }
});
Crate.prototype["__destroy__"] = Crate.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Crate___destroy__(self);
};
// Human
function Human(spatial, movable, emitter, receptor, script, faction) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* emitter <toy::HEmitter> [] */
    /* receptor <toy::HReceptor> [] */
    /* script <toy::HEntityScript> [] */
    /* faction <Faction> [] */
    if (faction && typeof faction === "object") faction = faction.ptr;
    if (spatial === undefined) { this.ptr = _Human_Human_0(self); getCache(Human)[this.ptr] = this; return; }
    this.ptr = _Human_Human_6(self, spatial, movable, emitter, receptor, script, faction); getCache(Human)[this.ptr] = this;
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class__ = Human;
Human.__cache__ = {};
Module['Human'] = Human;
Human.prototype["aim"] = Human.prototype.aim = function() {
    return wrapPointer(_Human_aim_0(), Aim);
};
Human.prototype["shoot"] = Human.prototype.shoot = function() {
    _Human_shoot_0();
};
Human.prototype["sight"] = Human.prototype.sight = function(aiming) {
    /* aiming <bool> [] */
    if (aiming === undefined) { return wrapPointer(_Human_sight_0(), mud::quat); return; }
    return wrapPointer(_Human_sight_1(aiming), mud::quat);
};
Human.prototype["stop"] = Human.prototype.stop = function() {
    _Human_stop_0();
};
Object.defineProperty(Human.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return _Human_get_faction(self);
    },
    set: function(faction) {
        var self = this.ptr;
        /* faction <Faction> [] */
        if (faction && typeof faction === "object") faction = faction.ptr;
        _Human_set_faction(self, faction);
    }
});
Object.defineProperty(Human.prototype, "life", {
    get: function() {
        var self = this.ptr;
        return _Human_get_life(self);
    },
    set: function(life) {
        var self = this.ptr;
        /* life <float> [] */
        _Human_set_life(self, life);
    }
});
Object.defineProperty(Human.prototype, "energy", {
    get: function() {
        var self = this.ptr;
        return _Human_get_energy(self);
    },
    set: function(energy) {
        var self = this.ptr;
        /* energy <float> [] */
        _Human_set_energy(self, energy);
    }
});
Object.defineProperty(Human.prototype, "discharge", {
    get: function() {
        var self = this.ptr;
        return _Human_get_discharge(self);
    },
    set: function(discharge) {
        var self = this.ptr;
        /* discharge <float> [] */
        _Human_set_discharge(self, discharge);
    }
});
Object.defineProperty(Human.prototype, "headlight", {
    get: function() {
        var self = this.ptr;
        return !!(_Human_get_headlight(self));
    },
    set: function(headlight) {
        var self = this.ptr;
        /* headlight <bool> [] */
        _Human_set_headlight(self, headlight);
    }
});
Object.defineProperty(Human.prototype, "shield", {
    get: function() {
        var self = this.ptr;
        return !!(_Human_get_shield(self));
    },
    set: function(shield) {
        var self = this.ptr;
        /* shield <bool> [] */
        _Human_set_shield(self, shield);
    }
});
Object.defineProperty(Human.prototype, "walk", {
    get: function() {
        var self = this.ptr;
        return !!(_Human_get_walk(self));
    },
    set: function(walk) {
        var self = this.ptr;
        /* walk <bool> [] */
        _Human_set_walk(self, walk);
    }
});
Object.defineProperty(Human.prototype, "target", {
    get: function() {
        var self = this.ptr;
        return _Human_get_target(self);
    },
    set: function(target) {
        var self = this.ptr;
        /* target <HHuman> [] */
        _Human_set_target(self, target);
    }
});
Object.defineProperty(Human.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Human_get_dest(self), mud::vec3);
    },
    set: function(dest) {
        var self = this.ptr;
        /* dest <vec3> [] */
        dest = dest.ptr;
        _Human_set_dest(self, dest);
    }
});
Object.defineProperty(Human.prototype, "cooldown", {
    get: function() {
        var self = this.ptr;
        return _Human_get_cooldown(self);
    },
    set: function(cooldown) {
        var self = this.ptr;
        /* cooldown <float> [] */
        _Human_set_cooldown(self, cooldown);
    }
});
Object.defineProperty(Human.prototype, "state", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Human_get_state(self), Stance);
    },
    set: function(state) {
        var self = this.ptr;
        /* state <Stance> [] */
        state = state.ptr;
        _Human_set_state(self, state);
    }
});
Human.prototype["__destroy__"] = Human.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Human___destroy__(self);
};
// Lamp
function Lamp(spatial, movable) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    if (spatial === undefined) { this.ptr = _Lamp_Lamp_0(self); getCache(Lamp)[this.ptr] = this; return; }
    this.ptr = _Lamp_Lamp_2(self, spatial, movable); getCache(Lamp)[this.ptr] = this;
};
Lamp.prototype = Object.create(WrapperObject.prototype);
Lamp.prototype.constructor = Lamp;
Lamp.prototype.__class__ = Lamp;
Lamp.__cache__ = {};
Module['Lamp'] = Lamp;
Lamp.prototype["__destroy__"] = Lamp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Lamp___destroy__(self);
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
// Stance
function Stance(name, loop) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* loop <bool> [] */
    if (name === undefined) { this.ptr = _Stance_Stance_0(self); getCache(Stance)[this.ptr] = this; return; }
    this.ptr = _Stance_Stance_2(self, name, loop); getCache(Stance)[this.ptr] = this;
};
Stance.prototype = Object.create(WrapperObject.prototype);
Stance.prototype.constructor = Stance;
Stance.prototype.__class__ = Stance;
Stance.__cache__ = {};
Module['Stance'] = Stance;
Object.defineProperty(Stance.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Stance_get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _Stance_set_name(self, name);
    }
});
Object.defineProperty(Stance.prototype, "loop", {
    get: function() {
        var self = this.ptr;
        return !!(_Stance_get_loop(self));
    },
    set: function(loop) {
        var self = this.ptr;
        /* loop <bool> [] */
        _Stance_set_loop(self, loop);
    }
});
Stance.prototype["__destroy__"] = Stance.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Stance___destroy__(self);
};
// TileWorld
function TileWorld(name, job_system) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _TileWorld_TileWorld_2(self, name, job_system); getCache(TileWorld)[this.ptr] = this;
};
TileWorld.prototype = Object.create(WrapperObject.prototype);
TileWorld.prototype.constructor = TileWorld;
TileWorld.prototype.__class__ = TileWorld;
TileWorld.__cache__ = {};
Module['TileWorld'] = TileWorld;
Object.defineProperty(TileWorld.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_TileWorld_get_world(self), toy::World);
    },
    set: function(world) {
        var self = this.ptr;
        /* world <World> [] */
        world = world.ptr;
        _TileWorld_set_world(self, world);
    }
});
Object.defineProperty(TileWorld.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_TileWorld_get_bullet_world(self), toy::BulletWorld);
    },
    set: function(bullet_world) {
        var self = this.ptr;
        /* bullet_world <BulletWorld> [] */
        bullet_world = bullet_world.ptr;
        _TileWorld_set_bullet_world(self, bullet_world);
    }
});
Object.defineProperty(TileWorld.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_TileWorld_get_navmesh(self), toy::Navmesh);
    },
    set: function(navmesh) {
        var self = this.ptr;
        /* navmesh <Navmesh> [] */
        navmesh = navmesh.ptr;
        _TileWorld_set_navmesh(self, navmesh);
    }
});
TileWorld.prototype["__destroy__"] = TileWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _TileWorld___destroy__(self);
};

(function() {
    function setupEnums() {
        // Faction
        Module['Faction']['Ally'] = _Faction_Ally();
        Module['Faction']['Enemy'] = _Faction_Enemy();
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
