Module['two'] = Module['two'] || {};
// ComponentHandle<Bullet>
function ComponentHandle_Bullet() {
    
    this.__ptr = _two_ComponentHandle_Bullet__construct_0(); getCache(ComponentHandle_Bullet)[this.__ptr] = this;
};
ComponentHandle_Bullet.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Bullet.prototype.constructor = ComponentHandle_Bullet;
ComponentHandle_Bullet.prototype.__class = ComponentHandle_Bullet;
ComponentHandle_Bullet.__cache = {};
Module['two']['ComponentHandle_Bullet'] = ComponentHandle_Bullet;
ComponentHandle_Bullet.prototype["__destroy"] = ComponentHandle_Bullet.prototype.__destroy = function() {
    _two_ComponentHandle_Bullet__destroy(this.__ptr);
};
// ComponentHandle<Human>
function ComponentHandle_Human() {
    
    this.__ptr = _two_ComponentHandle_Human__construct_0(); getCache(ComponentHandle_Human)[this.__ptr] = this;
};
ComponentHandle_Human.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Human.prototype.constructor = ComponentHandle_Human;
ComponentHandle_Human.prototype.__class = ComponentHandle_Human;
ComponentHandle_Human.__cache = {};
Module['two']['ComponentHandle_Human'] = ComponentHandle_Human;
ComponentHandle_Human.prototype["__destroy"] = ComponentHandle_Human.prototype.__destroy = function() {
    _two_ComponentHandle_Human__destroy(this.__ptr);
};
// ComponentHandle<Lamp>
function ComponentHandle_Lamp() {
    
    this.__ptr = _two_ComponentHandle_Lamp__construct_0(); getCache(ComponentHandle_Lamp)[this.__ptr] = this;
};
ComponentHandle_Lamp.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Lamp.prototype.constructor = ComponentHandle_Lamp;
ComponentHandle_Lamp.prototype.__class = ComponentHandle_Lamp;
ComponentHandle_Lamp.__cache = {};
Module['two']['ComponentHandle_Lamp'] = ComponentHandle_Lamp;
ComponentHandle_Lamp.prototype["__destroy"] = ComponentHandle_Lamp.prototype.__destroy = function() {
    _two_ComponentHandle_Lamp__destroy(this.__ptr);
};
// ComponentHandle<Crate>
function ComponentHandle_Crate() {
    
    this.__ptr = _two_ComponentHandle_Crate__construct_0(); getCache(ComponentHandle_Crate)[this.__ptr] = this;
};
ComponentHandle_Crate.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Crate.prototype.constructor = ComponentHandle_Crate;
ComponentHandle_Crate.prototype.__class = ComponentHandle_Crate;
ComponentHandle_Crate.__cache = {};
Module['two']['ComponentHandle_Crate'] = ComponentHandle_Crate;
ComponentHandle_Crate.prototype["__destroy"] = ComponentHandle_Crate.prototype.__destroy = function() {
    _two_ComponentHandle_Crate__destroy(this.__ptr);
};
// TileWorld
function TileWorld(a0, a1) {
    ensureCache.prepare();
    if (typeof a0 !== 'string') throw Error('TileWorld(0:name): expected string'); if (!checkClass(a1, JobSystem)) throw Error('TileWorld(1:job_system): expected JobSystem');
    this.__ptr = _TileWorld__construct_2(ensureString(/*name*/a0), /*job_system*/a1.__ptr); getCache(TileWorld)[this.__ptr] = this;
};
TileWorld.prototype = Object.create(Complex.prototype);
TileWorld.prototype.constructor = TileWorld;
TileWorld.prototype.__class = TileWorld;
TileWorld.__base = Complex;
TileWorld.__cache = {};
Module['TileWorld'] = TileWorld;
Object.defineProperty(TileWorld.prototype, "world", {
    get: function() {
        return wrapPointer(_TileWorld__get_world(this.__ptr), World);
    }});
Object.defineProperty(TileWorld.prototype, "bullet_world", {
    get: function() {
        return wrapPointer(_TileWorld__get_bullet_world(this.__ptr), BulletWorld);
    }});
Object.defineProperty(TileWorld.prototype, "navmesh", {
    get: function() {
        return wrapPointer(_TileWorld__get_navmesh(this.__ptr), Navmesh);
    }});
TileWorld.prototype["__destroy"] = TileWorld.prototype.__destroy = function() {
    _TileWorld__destroy(this.__ptr);
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
        if (!checkClass(value, v3_float)) throw Error('Bullet.source: expected v3<float>');
        _Bullet__set_source(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Bullet.prototype, "velocity", {
    get: function() {
        return wrapPointer(_Bullet__get_velocity(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Bullet.velocity: expected v3<float>');
        _Bullet__set_velocity(this.__ptr, value.__ptr);
    }
});
Bullet.prototype["__destroy"] = Bullet.prototype.__destroy = function() {
    _Bullet__destroy(this.__ptr);
};
// Aim
function Aim() {
    
    this.__ptr = _Aim__construct_0(); getCache(Aim)[this.__ptr] = this;
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
        if (!checkClass(value, quat)) throw Error('Aim.rotation: expected quat');
        _Aim__set_rotation(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Aim.prototype, "start", {
    get: function() {
        return wrapPointer(_Aim__get_start(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Aim.start: expected v3<float>');
        _Aim__set_start(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Aim.prototype, "end", {
    get: function() {
        return wrapPointer(_Aim__get_end(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Aim.end: expected v3<float>');
        _Aim__set_end(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Aim.prototype, "hit", {
    get: function() {
        return wrapPointer(_Aim__get_hit(this.__ptr), Spatial);
    },
    set: function(value) {
        if (!checkClass(value, Spatial)) throw Error('Aim.hit: expected Spatial');
        _Aim__set_hit(this.__ptr, value.__ptr);
    }
});
Aim.prototype["__destroy"] = Aim.prototype.__destroy = function() {
    _Aim__destroy(this.__ptr);
};
// Stance
function Stance(a0, a1) {
    ensureCache.prepare();
    if (a0 === undefined) {  }
    else { if (typeof a0 !== 'string') throw Error('Stance(0:name): expected string'); if (typeof a1 !== 'boolean') throw Error('Stance(1:loop): expected boolean'); }
    if (a0 === undefined) { this.__ptr = _Stance__construct_0(); getCache(Stance)[this.__ptr] = this; }
    else { this.__ptr = _Stance__construct_2(ensureString(/*name*/a0), /*loop*/a1); getCache(Stance)[this.__ptr] = this; }
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
        if (typeof value !== 'string') throw Error('Stance.name: expected string');
        _Stance__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Stance.prototype, "loop", {
    get: function() {
        return !!(_Stance__get_loop(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Stance.loop: expected boolean');
        _Stance__set_loop(this.__ptr, value);
    }
});
Stance.prototype["__destroy"] = Stance.prototype.__destroy = function() {
    _Stance__destroy(this.__ptr);
};
// Human
function Human(a0, a1, a2, a3, a4, a5) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Human(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_Movable)) throw Error('Human(1:movable): expected ComponentHandle<toy::Movable>'); if (!checkClass(a2, ComponentHandle_toy_Emitter)) throw Error('Human(2:emitter): expected ComponentHandle<toy::Emitter>'); if (!checkClass(a3, ComponentHandle_toy_Receptor)) throw Error('Human(3:receptor): expected ComponentHandle<toy::Receptor>'); if (!checkClass(a4, ComponentHandle_toy_EntityScript)) throw Error('Human(4:script): expected ComponentHandle<toy::EntityScript>'); if (typeof a5 !== 'number') throw Error('Human(5:faction): expected integer'); }
    if (a0 === undefined) { this.__ptr = _Human__construct_0(); getCache(Human)[this.__ptr] = this; }
    else { this.__ptr = _Human__construct_6(/*spatial*/a0.__ptr, /*movable*/a1.__ptr, /*emitter*/a2.__ptr, /*receptor*/a3.__ptr, /*script*/a4.__ptr, /*faction*/a5); getCache(Human)[this.__ptr] = this; }
};
Human.prototype = Object.create(WrapperObject.prototype);
Human.prototype.constructor = Human;
Human.prototype.__class = Human;
Human.__cache = {};
Module['Human'] = Human;
Human.prototype["sight"] = Human.prototype.sight = function(a0) {
    if (a0 === undefined) {  }
    else { if (typeof a0 !== 'boolean') throw Error('sight(0:aiming): expected boolean'); }
    if (a0 === undefined) { return wrapPointer(_Human_sight_0(this.__ptr), quat); }
    else { return wrapPointer(_Human_sight_1(this.__ptr, /*aiming*/a0), quat); }
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
        if (typeof value !== 'number') throw Error('Human.faction: expected integer');
        _Human__set_faction(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "life", {
    get: function() {
        return _Human__get_life(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Human.life: expected number');
        _Human__set_life(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "energy", {
    get: function() {
        return _Human__get_energy(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Human.energy: expected number');
        _Human__set_energy(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "discharge", {
    get: function() {
        return _Human__get_discharge(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Human.discharge: expected number');
        _Human__set_discharge(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "headlight", {
    get: function() {
        return !!(_Human__get_headlight(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Human.headlight: expected boolean');
        _Human__set_headlight(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "shield", {
    get: function() {
        return !!(_Human__get_shield(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Human.shield: expected boolean');
        _Human__set_shield(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "walk", {
    get: function() {
        return !!(_Human__get_walk(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Human.walk: expected boolean');
        _Human__set_walk(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "target", {
    get: function() {
        return wrapPointer(_Human__get_target(this.__ptr), ComponentHandle_Human);
    },
    set: function(value) {
        if (!checkClass(value, ComponentHandle_Human)) throw Error('Human.target: expected ComponentHandle<Human>');
        _Human__set_target(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Human.prototype, "dest", {
    get: function() {
        return wrapPointer(_Human__get_dest(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Human.dest: expected v3<float>');
        _Human__set_dest(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Human.prototype, "cooldown", {
    get: function() {
        return _Human__get_cooldown(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Human.cooldown: expected number');
        _Human__set_cooldown(this.__ptr, value);
    }
});
Object.defineProperty(Human.prototype, "state", {
    get: function() {
        return wrapPointer(_Human__get_state(this.__ptr), Stance);
    },
    set: function(value) {
        if (!checkClass(value, Stance)) throw Error('Human.state: expected Stance');
        _Human__set_state(this.__ptr, value.__ptr);
    }
});
Human.prototype["__destroy"] = Human.prototype.__destroy = function() {
    _Human__destroy(this.__ptr);
};
// Lamp
function Lamp(a0, a1) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Lamp(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_Movable)) throw Error('Lamp(1:movable): expected ComponentHandle<toy::Movable>'); }
    if (a0 === undefined) { this.__ptr = _Lamp__construct_0(); getCache(Lamp)[this.__ptr] = this; }
    else { this.__ptr = _Lamp__construct_2(/*spatial*/a0.__ptr, /*movable*/a1.__ptr); getCache(Lamp)[this.__ptr] = this; }
};
Lamp.prototype = Object.create(WrapperObject.prototype);
Lamp.prototype.constructor = Lamp;
Lamp.prototype.__class = Lamp;
Lamp.__cache = {};
Module['Lamp'] = Lamp;
Lamp.prototype["__destroy"] = Lamp.prototype.__destroy = function() {
    _Lamp__destroy(this.__ptr);
};
// Crate
function Crate(a0, a1, a2) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Crate(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_Movable)) throw Error('Crate(1:movable): expected ComponentHandle<toy::Movable>'); if (!checkClass(a2, v3_float)) throw Error('Crate(2:extents): expected v3<float>'); }
    if (a0 === undefined) { this.__ptr = _Crate__construct_0(); getCache(Crate)[this.__ptr] = this; }
    else { this.__ptr = _Crate__construct_3(/*spatial*/a0.__ptr, /*movable*/a1.__ptr, /*extents*/a2.__ptr); getCache(Crate)[this.__ptr] = this; }
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
        if (!checkClass(value, v3_float)) throw Error('Crate.extents: expected v3<float>');
        _Crate__set_extents(this.__ptr, value.__ptr);
    }
});
Crate.prototype["__destroy"] = Crate.prototype.__destroy = function() {
    _Crate__destroy(this.__ptr);
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
Module['HLamp'] = ComponentHandle_Lamp;
Module['HCrate'] = ComponentHandle_Crate;

(function() {
    function setup() {
        TileWorld.prototype.__type = _TileWorld__type();
        Bullet.prototype.__type = _Bullet__type();
        Aim.prototype.__type = _Aim__type();
        Stance.prototype.__type = _Stance__type();
        Human.prototype.__type = _Human__type();
        Lamp.prototype.__type = _Lamp__type();
        Crate.prototype.__type = _Crate__type();
        Player.prototype.__type = _Player__type();
        // Faction
        Module['Faction'] = Module['Faction'] || {};
        Module['Faction']['Ally'] = _Faction_Ally();
        Module['Faction']['Enemy'] = _Faction_Enemy();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
