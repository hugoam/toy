Module['two'] = Module['two'] || {};
// ComponentHandle<Camp>
function ComponentHandle_Camp() {
    
    this.__ptr = _two_ComponentHandle_Camp__construct_0(); getCache(ComponentHandle_Camp)[this.__ptr] = this;
};
ComponentHandle_Camp.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Camp.prototype.constructor = ComponentHandle_Camp;
ComponentHandle_Camp.prototype.__class = ComponentHandle_Camp;
ComponentHandle_Camp.__cache = {};
Module['two']['ComponentHandle_Camp'] = ComponentHandle_Camp;
ComponentHandle_Camp.prototype["__destroy"] = ComponentHandle_Camp.prototype.__destroy = function() {
    _two_ComponentHandle_Camp__destroy(this.__ptr);
};
// ComponentHandle<Shield>
function ComponentHandle_Shield() {
    
    this.__ptr = _two_ComponentHandle_Shield__construct_0(); getCache(ComponentHandle_Shield)[this.__ptr] = this;
};
ComponentHandle_Shield.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Shield.prototype.constructor = ComponentHandle_Shield;
ComponentHandle_Shield.prototype.__class = ComponentHandle_Shield;
ComponentHandle_Shield.__cache = {};
Module['two']['ComponentHandle_Shield'] = ComponentHandle_Shield;
ComponentHandle_Shield.prototype["__destroy"] = ComponentHandle_Shield.prototype.__destroy = function() {
    _two_ComponentHandle_Shield__destroy(this.__ptr);
};
// ComponentHandle<Slug>
function ComponentHandle_Slug() {
    
    this.__ptr = _two_ComponentHandle_Slug__construct_0(); getCache(ComponentHandle_Slug)[this.__ptr] = this;
};
ComponentHandle_Slug.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Slug.prototype.constructor = ComponentHandle_Slug;
ComponentHandle_Slug.prototype.__class = ComponentHandle_Slug;
ComponentHandle_Slug.__cache = {};
Module['two']['ComponentHandle_Slug'] = ComponentHandle_Slug;
ComponentHandle_Slug.prototype["__destroy"] = ComponentHandle_Slug.prototype.__destroy = function() {
    _two_ComponentHandle_Slug__destroy(this.__ptr);
};
// ComponentHandle<Tank>
function ComponentHandle_Tank() {
    
    this.__ptr = _two_ComponentHandle_Tank__construct_0(); getCache(ComponentHandle_Tank)[this.__ptr] = this;
};
ComponentHandle_Tank.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Tank.prototype.constructor = ComponentHandle_Tank;
ComponentHandle_Tank.prototype.__class = ComponentHandle_Tank;
ComponentHandle_Tank.__cache = {};
Module['two']['ComponentHandle_Tank'] = ComponentHandle_Tank;
ComponentHandle_Tank.prototype["__destroy"] = ComponentHandle_Tank.prototype.__destroy = function() {
    _two_ComponentHandle_Tank__destroy(this.__ptr);
};
// Faction
function Faction(a0, a1) {
    if (typeof a0 !== 'number') throw Error('Faction(0:id): expected integer'); if (!checkClass(a1, Colour)) throw Error('Faction(1:colour): expected Colour');
    this.__ptr = _Faction__construct_2(/*id*/a0, /*colour*/a1.__ptr); getCache(Faction)[this.__ptr] = this;
};
Faction.prototype = Object.create(WrapperObject.prototype);
Faction.prototype.constructor = Faction;
Faction.prototype.__class = Faction;
Faction.__cache = {};
Module['Faction'] = Faction;
Object.defineProperty(Faction.prototype, "id", {
    get: function() {
        return _Faction__get_id(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Faction.id: expected integer');
        _Faction__set_id(this.__ptr, value);
    }
});
Object.defineProperty(Faction.prototype, "colour", {
    get: function() {
        return wrapPointer(_Faction__get_colour(this.__ptr), Colour);
    },
    set: function(value) {
        if (!checkClass(value, Colour)) throw Error('Faction.colour: expected Colour');
        _Faction__set_colour(this.__ptr, value.__ptr);
    }
});
Faction.prototype["__destroy"] = Faction.prototype.__destroy = function() {
    _Faction__destroy(this.__ptr);
};
// Camp
function Camp(a0, a1, a2) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Camp(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, v3_float)) throw Error('Camp(1:position): expected v3<float>'); if (!checkClass(a2, Faction)) throw Error('Camp(2:faction): expected Faction'); }
    if (a0 === undefined) { this.__ptr = _Camp__construct_0(); getCache(Camp)[this.__ptr] = this; }
    else { this.__ptr = _Camp__construct_3(/*spatial*/a0.__ptr, /*position*/a1.__ptr, /*faction*/a2.__ptr); getCache(Camp)[this.__ptr] = this; }
};
Camp.prototype = Object.create(WrapperObject.prototype);
Camp.prototype.constructor = Camp;
Camp.prototype.__class = Camp;
Camp.__cache = {};
Module['Camp'] = Camp;
Object.defineProperty(Camp.prototype, "position", {
    get: function() {
        return wrapPointer(_Camp__get_position(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Camp.position: expected v3<float>');
        _Camp__set_position(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Camp.prototype, "faction", {
    get: function() {
        return wrapPointer(_Camp__get_faction(this.__ptr), Faction);
    },
    set: function(value) {
        if (!checkClass(value, Faction)) throw Error('Camp.faction: expected Faction');
        _Camp__set_faction(this.__ptr, value.__ptr);
    }
});
Camp.prototype["__destroy"] = Camp.prototype.__destroy = function() {
    _Camp__destroy(this.__ptr);
};
// Shield
function Shield(a0, a1, a2, a3) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Shield(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_Emitter)) throw Error('Shield(1:emitter): expected ComponentHandle<toy::Emitter>'); if (!checkClass(a2, Faction)) throw Error('Shield(2:faction): expected Faction'); if (typeof a3 !== 'number') throw Error('Shield(3:radius): expected number'); }
    if (a0 === undefined) { this.__ptr = _Shield__construct_0(); getCache(Shield)[this.__ptr] = this; }
    else { this.__ptr = _Shield__construct_4(/*spatial*/a0.__ptr, /*emitter*/a1.__ptr, /*faction*/a2.__ptr, /*radius*/a3); getCache(Shield)[this.__ptr] = this; }
};
Shield.prototype = Object.create(WrapperObject.prototype);
Shield.prototype.constructor = Shield;
Shield.prototype.__class = Shield;
Shield.__cache = {};
Module['Shield'] = Shield;
Object.defineProperty(Shield.prototype, "faction", {
    get: function() {
        return wrapPointer(_Shield__get_faction(this.__ptr), Faction);
    },
    set: function(value) {
        if (!checkClass(value, Faction)) throw Error('Shield.faction: expected Faction');
        _Shield__set_faction(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Shield.prototype, "radius", {
    get: function() {
        return _Shield__get_radius(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Shield.radius: expected number');
        _Shield__set_radius(this.__ptr, value);
    }
});
Object.defineProperty(Shield.prototype, "charge", {
    get: function() {
        return _Shield__get_charge(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Shield.charge: expected number');
        _Shield__set_charge(this.__ptr, value);
    }
});
Object.defineProperty(Shield.prototype, "discharge", {
    get: function() {
        return _Shield__get_discharge(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Shield.discharge: expected number');
        _Shield__set_discharge(this.__ptr, value);
    }
});
Shield.prototype["__destroy"] = Shield.prototype.__destroy = function() {
    _Shield__destroy(this.__ptr);
};
// Slug
function Slug() { throw "cannot construct a Slug, no constructor in IDL" }
Slug.prototype = Object.create(WrapperObject.prototype);
Slug.prototype.constructor = Slug;
Slug.prototype.__class = Slug;
Slug.__cache = {};
Module['Slug'] = Slug;
Object.defineProperty(Slug.prototype, "source", {
    get: function() {
        return wrapPointer(_Slug__get_source(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Slug.source: expected v3<float>');
        _Slug__set_source(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Slug.prototype, "velocity", {
    get: function() {
        return wrapPointer(_Slug__get_velocity(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Slug.velocity: expected v3<float>');
        _Slug__set_velocity(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Slug.prototype, "power", {
    get: function() {
        return _Slug__get_power(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Slug.power: expected number');
        _Slug__set_power(this.__ptr, value);
    }
});
Slug.prototype["__destroy"] = Slug.prototype.__destroy = function() {
    _Slug__destroy(this.__ptr);
};
// Tank
function Tank(a0, a1, a2, a3, a4) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Tank(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_Movable)) throw Error('Tank(1:movable): expected ComponentHandle<toy::Movable>'); if (!checkClass(a2, ComponentHandle_toy_Emitter)) throw Error('Tank(2:emitter): expected ComponentHandle<toy::Emitter>'); if (!checkClass(a3, ComponentHandle_toy_Receptor)) throw Error('Tank(3:receptor): expected ComponentHandle<toy::Receptor>'); if (!checkClass(a4, Faction)) throw Error('Tank(4:faction): expected Faction'); }
    if (a0 === undefined) { this.__ptr = _Tank__construct_0(); getCache(Tank)[this.__ptr] = this; }
    else { this.__ptr = _Tank__construct_5(/*spatial*/a0.__ptr, /*movable*/a1.__ptr, /*emitter*/a2.__ptr, /*receptor*/a3.__ptr, /*faction*/a4.__ptr); getCache(Tank)[this.__ptr] = this; }
};
Tank.prototype = Object.create(WrapperObject.prototype);
Tank.prototype.constructor = Tank;
Tank.prototype.__class = Tank;
Tank.__cache = {};
Module['Tank'] = Tank;
Tank.prototype["__destroy"] = Tank.prototype.__destroy = function() {
    _Tank__destroy(this.__ptr);
};
// BlockWorld
function BlockWorld(a0, a1) {
    ensureCache.prepare();
    if (typeof a0 !== 'string') throw Error('BlockWorld(0:name): expected string'); if (!checkClass(a1, JobSystem)) throw Error('BlockWorld(1:job_system): expected JobSystem');
    this.__ptr = _BlockWorld__construct_2(ensureString(/*name*/a0), /*job_system*/a1.__ptr); getCache(BlockWorld)[this.__ptr] = this;
};
BlockWorld.prototype = Object.create(Complex.prototype);
BlockWorld.prototype.constructor = BlockWorld;
BlockWorld.prototype.__class = BlockWorld;
BlockWorld.__base = Complex;
BlockWorld.__cache = {};
Module['BlockWorld'] = BlockWorld;
Object.defineProperty(BlockWorld.prototype, "world", {
    get: function() {
        return wrapPointer(_BlockWorld__get_world(this.__ptr), World);
    }});
Object.defineProperty(BlockWorld.prototype, "bullet_world", {
    get: function() {
        return wrapPointer(_BlockWorld__get_bullet_world(this.__ptr), BulletWorld);
    }});
Object.defineProperty(BlockWorld.prototype, "navmesh", {
    get: function() {
        return wrapPointer(_BlockWorld__get_navmesh(this.__ptr), Navmesh);
    }});
Object.defineProperty(BlockWorld.prototype, "block_subdiv", {
    get: function() {
        return wrapPointer(_BlockWorld__get_block_subdiv(this.__ptr), v3_uint);
    },
    set: function(value) {
        if (!checkClass(value, v3_uint)) throw Error('BlockWorld.block_subdiv: expected v3<uint>');
        _BlockWorld__set_block_subdiv(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(BlockWorld.prototype, "tile_scale", {
    get: function() {
        return wrapPointer(_BlockWorld__get_tile_scale(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('BlockWorld.tile_scale: expected v3<float>');
        _BlockWorld__set_tile_scale(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(BlockWorld.prototype, "block_size", {
    get: function() {
        return wrapPointer(_BlockWorld__get_block_size(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('BlockWorld.block_size: expected v3<float>');
        _BlockWorld__set_block_size(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(BlockWorld.prototype, "world_size", {
    get: function() {
        return wrapPointer(_BlockWorld__get_world_size(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('BlockWorld.world_size: expected v3<float>');
        _BlockWorld__set_world_size(this.__ptr, value.__ptr);
    }
});
BlockWorld.prototype["__destroy"] = BlockWorld.prototype.__destroy = function() {
    _BlockWorld__destroy(this.__ptr);
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
Module['HCamp'] = ComponentHandle_Camp;
Module['HShield'] = ComponentHandle_Shield;
Module['HSlug'] = ComponentHandle_Slug;
Module['HTank'] = ComponentHandle_Tank;

(function() {
    function setup() {
        Faction.prototype.__type = _Faction__type();
        Camp.prototype.__type = _Camp__type();
        Shield.prototype.__type = _Shield__type();
        Slug.prototype.__type = _Slug__type();
        Tank.prototype.__type = _Tank__type();
        BlockWorld.prototype.__type = _BlockWorld__type();
        Player.prototype.__type = _Player__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
