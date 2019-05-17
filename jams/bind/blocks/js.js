Module['two']['ui'] = Module['two']['ui'] || {};
Module['boids'] = Module['boids'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
Module['toy'] = Module['toy'] || {};
// Camp
function Camp(spatial, position, faction) {
    /* spatial <toy::HSpatial> [] */
    /* position <vec3> [] */
    if(typeof position !== "undefined" && position !== null) { position = position.ptr; }
    /* faction <Faction> [] */
    if(typeof faction !== "undefined" && faction !== null) { faction = faction.ptr; }
    if (spatial === undefined) { this.ptr = _Camp_Camp_0(); getCache(Camp)[this.ptr] = this; return; }
    this.ptr = _Camp_Camp_3(spatial, position, faction); getCache(Camp)[this.ptr] = this;
    this.type = Camp;
};
Camp.prototype = Object.create(WrapperObject.prototype);
Camp.prototype.constructor = Camp;
Camp.prototype.__class__ = Camp;
Camp.__cache__ = {};
Module['Camp'] = Camp;
Object.defineProperty(Camp.prototype, "position", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Camp__get_position(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Camp__set_position(self, value);
    }
});
Object.defineProperty(Camp.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Camp__get_faction(self), Faction);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Faction> [] */
        value = value.ptr;
        _Camp__set_faction(self, value);
    }
});
Camp.prototype["__destroy__"] = Camp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Camp__destroy(self);
};
// Faction
function Faction(id, colour) {
    /* id <uint32_t> [] */
    /* colour <Colour> [] */
    colour = colour.ptr;
    this.ptr = _Faction_Faction_2(id, colour); getCache(Faction)[this.ptr] = this;
    this.type = Faction;
};
Faction.prototype = Object.create(WrapperObject.prototype);
Faction.prototype.constructor = Faction;
Faction.prototype.__class__ = Faction;
Faction.__cache__ = {};
Module['Faction'] = Faction;
Object.defineProperty(Faction.prototype, "id", {
    get: function() {
        var self = this.ptr;
        return _Faction__get_id(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint32_t> [] */
        _Faction__set_id(self, value);
    }
});
Object.defineProperty(Faction.prototype, "colour", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Faction__get_colour(self), Colour);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Colour> [] */
        value = value.ptr;
        _Faction__set_colour(self, value);
    }
});
Faction.prototype["__destroy__"] = Faction.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Faction__destroy(self);
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
// Shield
function Shield(spatial, emitter, faction, radius) {
    /* spatial <toy::HSpatial> [] */
    /* emitter <toy::HEmitter> [] */
    /* faction <Faction> [] */
    if(typeof faction !== "undefined" && faction !== null) { faction = faction.ptr; }
    /* radius <float> [] */
    if (spatial === undefined) { this.ptr = _Shield_Shield_0(); getCache(Shield)[this.ptr] = this; return; }
    this.ptr = _Shield_Shield_4(spatial, emitter, faction, radius); getCache(Shield)[this.ptr] = this;
    this.type = Shield;
};
Shield.prototype = Object.create(WrapperObject.prototype);
Shield.prototype.constructor = Shield;
Shield.prototype.__class__ = Shield;
Shield.__cache__ = {};
Module['Shield'] = Shield;
Object.defineProperty(Shield.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Shield__get_faction(self), Faction);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Faction> [] */
        value = value.ptr;
        _Shield__set_faction(self, value);
    }
});
Object.defineProperty(Shield.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _Shield__get_radius(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Shield__set_radius(self, value);
    }
});
Object.defineProperty(Shield.prototype, "charge", {
    get: function() {
        var self = this.ptr;
        return _Shield__get_charge(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Shield__set_charge(self, value);
    }
});
Object.defineProperty(Shield.prototype, "discharge", {
    get: function() {
        var self = this.ptr;
        return _Shield__get_discharge(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Shield__set_discharge(self, value);
    }
});
Shield.prototype["__destroy__"] = Shield.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Shield__destroy(self);
};
// Slug
function Slug() { throw "cannot construct a Slug, no constructor in IDL" }
Slug.prototype = Object.create(WrapperObject.prototype);
Slug.prototype.constructor = Slug;
Slug.prototype.__class__ = Slug;
Slug.__cache__ = {};
Module['Slug'] = Slug;
Object.defineProperty(Slug.prototype, "source", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Slug__get_source(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Slug__set_source(self, value);
    }
});
Object.defineProperty(Slug.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Slug__get_velocity(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Slug__set_velocity(self, value);
    }
});
Object.defineProperty(Slug.prototype, "power", {
    get: function() {
        var self = this.ptr;
        return _Slug__get_power(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Slug__set_power(self, value);
    }
});
Slug.prototype["__destroy__"] = Slug.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Slug__destroy(self);
};
// Tank
function Tank(spatial, movable, emitter, receptor, faction) {
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* emitter <toy::HEmitter> [] */
    /* receptor <toy::HReceptor> [] */
    /* faction <Faction> [] */
    if(typeof faction !== "undefined" && faction !== null) { faction = faction.ptr; }
    if (spatial === undefined) { this.ptr = _Tank_Tank_0(); getCache(Tank)[this.ptr] = this; return; }
    this.ptr = _Tank_Tank_5(spatial, movable, emitter, receptor, faction); getCache(Tank)[this.ptr] = this;
    this.type = Tank;
};
Tank.prototype = Object.create(WrapperObject.prototype);
Tank.prototype.constructor = Tank;
Tank.prototype.__class__ = Tank;
Tank.__cache__ = {};
Module['Tank'] = Tank;
Tank.prototype["__destroy__"] = Tank.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Tank__destroy(self);
};
// BlockWorld
function BlockWorld(name, job_system) {
    ensureCache.prepare();
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _BlockWorld_BlockWorld_2(name, job_system); getCache(BlockWorld)[this.ptr] = this;
    this.type = BlockWorld;
};
BlockWorld.prototype = Object.create(WrapperObject.prototype);
BlockWorld.prototype.constructor = BlockWorld;
BlockWorld.prototype.__class__ = BlockWorld;
BlockWorld.__cache__ = {};
Module['BlockWorld'] = BlockWorld;
Object.defineProperty(BlockWorld.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_world(self), World);
    }});
Object.defineProperty(BlockWorld.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_bullet_world(self), BulletWorld);
    }});
Object.defineProperty(BlockWorld.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_navmesh(self), Navmesh);
    }});
Object.defineProperty(BlockWorld.prototype, "block_subdiv", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_block_subdiv(self), uvec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec3> [] */
        value = value.ptr;
        _BlockWorld__set_block_subdiv(self, value);
    }
});
Object.defineProperty(BlockWorld.prototype, "tile_scale", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_tile_scale(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _BlockWorld__set_tile_scale(self, value);
    }
});
Object.defineProperty(BlockWorld.prototype, "block_size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_block_size(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _BlockWorld__set_block_size(self, value);
    }
});
Object.defineProperty(BlockWorld.prototype, "world_size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_world_size(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _BlockWorld__set_world_size(self, value);
    }
});
BlockWorld.prototype["__destroy__"] = BlockWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _BlockWorld__destroy(self);
};

(function() {
    function setup() {
        Camp.__type__ = _Camp__type();
        Faction.__type__ = _Faction__type();
        Player.__type__ = _Player__type();
        Shield.__type__ = _Shield__type();
        Slug.__type__ = _Slug__type();
        Tank.__type__ = _Tank__type();
        BlockWorld.__type__ = _BlockWorld__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
