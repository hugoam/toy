
// Bindings utilities
function WrapperObject() {
}
// Camp
function Camp(spatial, position, faction) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* position <vec3> [] */
    /* faction <Faction> [] */
    if (spatial === undefined) { this.ptr = _Camp_Camp_0(self); getCache(Camp)[this.ptr] = this; return; }
    this.ptr = _Camp_Camp_3(self, spatial, position, faction); getCache(Camp)[this.ptr] = this;
};
Camp.prototype = Object.create(WrapperObject.prototype);
Camp.prototype.constructor = Camp;
Camp.prototype.__class__ = Camp;
Camp.__cache__ = {};
Module['Camp'] = Camp;
Object.defineProperty(Camp.prototype, "position", {
    get: function() {
        var self = this.ptr;
        return _Camp_get_position(self);
    },
    set: function(position) {
        var self = this.ptr;
        /* position <vec3> [] */
        _Camp_set_position(self, position);
    }
});
Object.defineProperty(Camp.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return _Camp_get_faction(self);
    },
    set: function(faction) {
        var self = this.ptr;
        /* faction <Faction> [] */
        _Camp_set_faction(self, faction);
    }
});
Camp.prototype["__destroy__"] = Camp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Camp___destroy__(self);
};
// Faction
function Faction(id, colour) {
    var self = this.ptr;
    /* id <uint32_t> [] */
    /* colour <Colour> [] */
    this.ptr = _Faction_Faction_2(self, id, colour); getCache(Faction)[this.ptr] = this;
};
Faction.prototype = Object.create(WrapperObject.prototype);
Faction.prototype.constructor = Faction;
Faction.prototype.__class__ = Faction;
Faction.__cache__ = {};
Module['Faction'] = Faction;
Object.defineProperty(Faction.prototype, "id", {
    get: function() {
        var self = this.ptr;
        return _Faction_get_id(self);
    },
    set: function(id) {
        var self = this.ptr;
        /* id <uint32_t> [] */
        _Faction_set_id(self, id);
    }
});
Object.defineProperty(Faction.prototype, "colour", {
    get: function() {
        var self = this.ptr;
        return _Faction_get_colour(self);
    },
    set: function(colour) {
        var self = this.ptr;
        /* colour <Colour> [] */
        _Faction_set_colour(self, colour);
    }
});
Faction.prototype["__destroy__"] = Faction.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Faction___destroy__(self);
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
// Shield
function Shield(spatial, emitter, faction, radius) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* emitter <toy::HEmitter> [] */
    /* faction <Faction> [] */
    /* radius <float> [] */
    if (spatial === undefined) { this.ptr = _Shield_Shield_0(self); getCache(Shield)[this.ptr] = this; return; }
    this.ptr = _Shield_Shield_4(self, spatial, emitter, faction, radius); getCache(Shield)[this.ptr] = this;
};
Shield.prototype = Object.create(WrapperObject.prototype);
Shield.prototype.constructor = Shield;
Shield.prototype.__class__ = Shield;
Shield.__cache__ = {};
Module['Shield'] = Shield;
Object.defineProperty(Shield.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return _Shield_get_faction(self);
    },
    set: function(faction) {
        var self = this.ptr;
        /* faction <Faction> [] */
        _Shield_set_faction(self, faction);
    }
});
Object.defineProperty(Shield.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _Shield_get_radius(self);
    },
    set: function(radius) {
        var self = this.ptr;
        /* radius <float> [] */
        _Shield_set_radius(self, radius);
    }
});
Object.defineProperty(Shield.prototype, "charge", {
    get: function() {
        var self = this.ptr;
        return _Shield_get_charge(self);
    },
    set: function(charge) {
        var self = this.ptr;
        /* charge <float> [] */
        _Shield_set_charge(self, charge);
    }
});
Object.defineProperty(Shield.prototype, "discharge", {
    get: function() {
        var self = this.ptr;
        return _Shield_get_discharge(self);
    },
    set: function(discharge) {
        var self = this.ptr;
        /* discharge <float> [] */
        _Shield_set_discharge(self, discharge);
    }
});
Shield.prototype["__destroy__"] = Shield.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Shield___destroy__(self);
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
        return _Slug_get_source(self);
    },
    set: function(source) {
        var self = this.ptr;
        /* source <vec3> [] */
        _Slug_set_source(self, source);
    }
});
Object.defineProperty(Slug.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return _Slug_get_velocity(self);
    },
    set: function(velocity) {
        var self = this.ptr;
        /* velocity <vec3> [] */
        _Slug_set_velocity(self, velocity);
    }
});
Object.defineProperty(Slug.prototype, "power", {
    get: function() {
        var self = this.ptr;
        return _Slug_get_power(self);
    },
    set: function(power) {
        var self = this.ptr;
        /* power <float> [] */
        _Slug_set_power(self, power);
    }
});
Slug.prototype["__destroy__"] = Slug.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Slug___destroy__(self);
};
// Tank
function Tank(spatial, movable, emitter, receptor, faction) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* emitter <toy::HEmitter> [] */
    /* receptor <toy::HReceptor> [] */
    /* faction <Faction> [] */
    if (spatial === undefined) { this.ptr = _Tank_Tank_0(self); getCache(Tank)[this.ptr] = this; return; }
    this.ptr = _Tank_Tank_5(self, spatial, movable, emitter, receptor, faction); getCache(Tank)[this.ptr] = this;
};
Tank.prototype = Object.create(WrapperObject.prototype);
Tank.prototype.constructor = Tank;
Tank.prototype.__class__ = Tank;
Tank.__cache__ = {};
Module['Tank'] = Tank;
Tank.prototype["__destroy__"] = Tank.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Tank___destroy__(self);
};
// BlockWorld
function BlockWorld(name, job_system) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    this.ptr = _BlockWorld_BlockWorld_2(self, name, job_system); getCache(BlockWorld)[this.ptr] = this;
};
BlockWorld.prototype = Object.create(WrapperObject.prototype);
BlockWorld.prototype.constructor = BlockWorld;
BlockWorld.prototype.__class__ = BlockWorld;
BlockWorld.__cache__ = {};
Module['BlockWorld'] = BlockWorld;
Object.defineProperty(BlockWorld.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return _BlockWorld_get_world(self);
    },
    set: function(world) {
        var self = this.ptr;
        /* world <World> [] */
        _BlockWorld_set_world(self, world);
    }
});
Object.defineProperty(BlockWorld.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return _BlockWorld_get_bullet_world(self);
    },
    set: function(bullet_world) {
        var self = this.ptr;
        /* bullet_world <BulletWorld> [] */
        _BlockWorld_set_bullet_world(self, bullet_world);
    }
});
Object.defineProperty(BlockWorld.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return _BlockWorld_get_navmesh(self);
    },
    set: function(navmesh) {
        var self = this.ptr;
        /* navmesh <Navmesh> [] */
        _BlockWorld_set_navmesh(self, navmesh);
    }
});
Object.defineProperty(BlockWorld.prototype, "block_subdiv", {
    get: function() {
        var self = this.ptr;
        return _BlockWorld_get_block_subdiv(self);
    },
    set: function(block_subdiv) {
        var self = this.ptr;
        /* block_subdiv <uvec3> [] */
        _BlockWorld_set_block_subdiv(self, block_subdiv);
    }
});
Object.defineProperty(BlockWorld.prototype, "tile_scale", {
    get: function() {
        var self = this.ptr;
        return _BlockWorld_get_tile_scale(self);
    },
    set: function(tile_scale) {
        var self = this.ptr;
        /* tile_scale <vec3> [] */
        _BlockWorld_set_tile_scale(self, tile_scale);
    }
});
Object.defineProperty(BlockWorld.prototype, "block_size", {
    get: function() {
        var self = this.ptr;
        return _BlockWorld_get_block_size(self);
    },
    set: function(block_size) {
        var self = this.ptr;
        /* block_size <vec3> [] */
        _BlockWorld_set_block_size(self, block_size);
    }
});
Object.defineProperty(BlockWorld.prototype, "world_size", {
    get: function() {
        var self = this.ptr;
        return _BlockWorld_get_world_size(self);
    },
    set: function(world_size) {
        var self = this.ptr;
        /* world_size <vec3> [] */
        _BlockWorld_set_world_size(self, world_size);
    }
});
BlockWorld.prototype["__destroy__"] = BlockWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _BlockWorld___destroy__(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
