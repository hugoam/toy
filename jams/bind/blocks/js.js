
// Bindings utilities
function WrapperObject() {
}
// Camp
function Camp(spatial, position, faction) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* position <vec3> [] */
    position = position.ptr;
    /* faction <Faction> [] */
    faction = faction.ptr;
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
        return wrapPointer(_Camp__get_position(self), mud::vec3);
    },
    set: function(position) {
        var self = this.ptr;
        /* position <vec3> [] */
        position = position.ptr;
        _Camp__set_position(self, position);
    }
});
Object.defineProperty(Camp.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Camp__get_faction(self), Faction);
    },
    set: function(faction) {
        var self = this.ptr;
        /* faction <Faction> [] */
        faction = faction.ptr;
        _Camp__set_faction(self, faction);
    }
});
Camp.prototype["__destroy__"] = Camp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Camp__destroy(self);
};
// Faction
function Faction(id, colour) {
    var self = this.ptr;
    /* id <uint32_t> [] */
    /* colour <Colour> [] */
    colour = colour.ptr;
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
        return _Faction__get_id(self);
    },
    set: function(id) {
        var self = this.ptr;
        /* id <uint32_t> [] */
        _Faction__set_id(self, id);
    }
});
Object.defineProperty(Faction.prototype, "colour", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Faction__get_colour(self), mud::Colour);
    },
    set: function(colour) {
        var self = this.ptr;
        /* colour <Colour> [] */
        colour = colour.ptr;
        _Faction__set_colour(self, colour);
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
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* emitter <toy::HEmitter> [] */
    /* faction <Faction> [] */
    faction = faction.ptr;
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
        return wrapPointer(_Shield__get_faction(self), Faction);
    },
    set: function(faction) {
        var self = this.ptr;
        /* faction <Faction> [] */
        faction = faction.ptr;
        _Shield__set_faction(self, faction);
    }
});
Object.defineProperty(Shield.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _Shield__get_radius(self);
    },
    set: function(radius) {
        var self = this.ptr;
        /* radius <float> [] */
        _Shield__set_radius(self, radius);
    }
});
Object.defineProperty(Shield.prototype, "charge", {
    get: function() {
        var self = this.ptr;
        return _Shield__get_charge(self);
    },
    set: function(charge) {
        var self = this.ptr;
        /* charge <float> [] */
        _Shield__set_charge(self, charge);
    }
});
Object.defineProperty(Shield.prototype, "discharge", {
    get: function() {
        var self = this.ptr;
        return _Shield__get_discharge(self);
    },
    set: function(discharge) {
        var self = this.ptr;
        /* discharge <float> [] */
        _Shield__set_discharge(self, discharge);
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
        return wrapPointer(_Slug__get_source(self), mud::vec3);
    },
    set: function(source) {
        var self = this.ptr;
        /* source <vec3> [] */
        source = source.ptr;
        _Slug__set_source(self, source);
    }
});
Object.defineProperty(Slug.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Slug__get_velocity(self), mud::vec3);
    },
    set: function(velocity) {
        var self = this.ptr;
        /* velocity <vec3> [] */
        velocity = velocity.ptr;
        _Slug__set_velocity(self, velocity);
    }
});
Object.defineProperty(Slug.prototype, "power", {
    get: function() {
        var self = this.ptr;
        return _Slug__get_power(self);
    },
    set: function(power) {
        var self = this.ptr;
        /* power <float> [] */
        _Slug__set_power(self, power);
    }
});
Slug.prototype["__destroy__"] = Slug.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Slug__destroy(self);
};
// Tank
function Tank(spatial, movable, emitter, receptor, faction) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* emitter <toy::HEmitter> [] */
    /* receptor <toy::HReceptor> [] */
    /* faction <Faction> [] */
    faction = faction.ptr;
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
    _Tank__destroy(self);
};
// BlockWorld
function BlockWorld(name, job_system) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
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
        return wrapPointer(_BlockWorld__get_world(self), toy::World);
    }});
Object.defineProperty(BlockWorld.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_bullet_world(self), toy::BulletWorld);
    }});
Object.defineProperty(BlockWorld.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_navmesh(self), toy::Navmesh);
    }});
Object.defineProperty(BlockWorld.prototype, "block_subdiv", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_block_subdiv(self), mud::uvec3);
    },
    set: function(block_subdiv) {
        var self = this.ptr;
        /* block_subdiv <uvec3> [] */
        block_subdiv = block_subdiv.ptr;
        _BlockWorld__set_block_subdiv(self, block_subdiv);
    }
});
Object.defineProperty(BlockWorld.prototype, "tile_scale", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_tile_scale(self), mud::vec3);
    },
    set: function(tile_scale) {
        var self = this.ptr;
        /* tile_scale <vec3> [] */
        tile_scale = tile_scale.ptr;
        _BlockWorld__set_tile_scale(self, tile_scale);
    }
});
Object.defineProperty(BlockWorld.prototype, "block_size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_block_size(self), mud::vec3);
    },
    set: function(block_size) {
        var self = this.ptr;
        /* block_size <vec3> [] */
        block_size = block_size.ptr;
        _BlockWorld__set_block_size(self, block_size);
    }
});
Object.defineProperty(BlockWorld.prototype, "world_size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_world_size(self), mud::vec3);
    },
    set: function(world_size) {
        var self = this.ptr;
        /* world_size <vec3> [] */
        world_size = world_size.ptr;
        _BlockWorld__set_world_size(self, world_size);
    }
});
BlockWorld.prototype["__destroy__"] = BlockWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _BlockWorld__destroy(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
