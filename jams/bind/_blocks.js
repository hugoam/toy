Module['mud'] = Module['mud'] || {};
// BlockWorld
function BlockWorld(a0, a1) {
    ensureCache.prepare();
    this.ptr = _BlockWorld__construct_2(ensureString(/*name*/a0), /*job_system*/a1.ptr); this.type = BlockWorld; getCache(BlockWorld)[this.ptr] = this;
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
        return wrapPointer(_BlockWorld__get_block_subdiv(self), v3_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _BlockWorld__set_block_subdiv(self, value.ptr);
    }
});
Object.defineProperty(BlockWorld.prototype, "tile_scale", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_tile_scale(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _BlockWorld__set_tile_scale(self, value.ptr);
    }
});
Object.defineProperty(BlockWorld.prototype, "block_size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_block_size(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _BlockWorld__set_block_size(self, value.ptr);
    }
});
Object.defineProperty(BlockWorld.prototype, "world_size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_BlockWorld__get_world_size(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _BlockWorld__set_world_size(self, value.ptr);
    }
});
BlockWorld.prototype["__destroy__"] = BlockWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _BlockWorld__destroy(self);
};
// Camp
function Camp(a0, a1, a2) {
    if (a0 === undefined) { this.ptr = _Camp__construct_0(); this.type = Camp; getCache(Camp)[this.ptr] = this; return; }
    this.ptr = _Camp__construct_3(/*spatial*/a0.ptr, /*position*/a1.ptr, /*faction*/a2.ptr); this.type = Camp; getCache(Camp)[this.ptr] = this;
};
Camp.prototype = Object.create(WrapperObject.prototype);
Camp.prototype.constructor = Camp;
Camp.prototype.__class__ = Camp;
Camp.__cache__ = {};
Module['Camp'] = Camp;
Object.defineProperty(Camp.prototype, "position", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Camp__get_position(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Camp__set_position(self, value.ptr);
    }
});
Object.defineProperty(Camp.prototype, "faction", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Camp__get_faction(self), Faction);
    },
    set: function(value) {
        var self = this.ptr;
        _Camp__set_faction(self, value.ptr);
    }
});
Camp.prototype["__destroy__"] = Camp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Camp__destroy(self);
};
// ComponentHandle<Camp>
function ComponentHandle_Camp() {
    this.ptr = _mud_ComponentHandle_Camp__construct_0(); this.type = ComponentHandle_Camp; getCache(ComponentHandle_Camp)[this.ptr] = this;
};
ComponentHandle_Camp.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Camp.prototype.constructor = ComponentHandle_Camp;
ComponentHandle_Camp.prototype.__class__ = ComponentHandle_Camp;
ComponentHandle_Camp.__cache__ = {};
Module['mud']['ComponentHandle_Camp'] = ComponentHandle_Camp;
ComponentHandle_Camp.prototype["__destroy__"] = ComponentHandle_Camp.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Camp__destroy(self);
};
// ComponentHandle<Shield>
function ComponentHandle_Shield() {
    this.ptr = _mud_ComponentHandle_Shield__construct_0(); this.type = ComponentHandle_Shield; getCache(ComponentHandle_Shield)[this.ptr] = this;
};
ComponentHandle_Shield.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Shield.prototype.constructor = ComponentHandle_Shield;
ComponentHandle_Shield.prototype.__class__ = ComponentHandle_Shield;
ComponentHandle_Shield.__cache__ = {};
Module['mud']['ComponentHandle_Shield'] = ComponentHandle_Shield;
ComponentHandle_Shield.prototype["__destroy__"] = ComponentHandle_Shield.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Shield__destroy(self);
};
// ComponentHandle<Slug>
function ComponentHandle_Slug() {
    this.ptr = _mud_ComponentHandle_Slug__construct_0(); this.type = ComponentHandle_Slug; getCache(ComponentHandle_Slug)[this.ptr] = this;
};
ComponentHandle_Slug.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Slug.prototype.constructor = ComponentHandle_Slug;
ComponentHandle_Slug.prototype.__class__ = ComponentHandle_Slug;
ComponentHandle_Slug.__cache__ = {};
Module['mud']['ComponentHandle_Slug'] = ComponentHandle_Slug;
ComponentHandle_Slug.prototype["__destroy__"] = ComponentHandle_Slug.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Slug__destroy(self);
};
// ComponentHandle<Tank>
function ComponentHandle_Tank() {
    this.ptr = _mud_ComponentHandle_Tank__construct_0(); this.type = ComponentHandle_Tank; getCache(ComponentHandle_Tank)[this.ptr] = this;
};
ComponentHandle_Tank.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Tank.prototype.constructor = ComponentHandle_Tank;
ComponentHandle_Tank.prototype.__class__ = ComponentHandle_Tank;
ComponentHandle_Tank.__cache__ = {};
Module['mud']['ComponentHandle_Tank'] = ComponentHandle_Tank;
ComponentHandle_Tank.prototype["__destroy__"] = ComponentHandle_Tank.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Tank__destroy(self);
};
// Faction
function Faction(a0, a1) {
    this.ptr = _Faction__construct_2(/*id*/a0, /*colour*/a1.ptr); this.type = Faction; getCache(Faction)[this.ptr] = this;
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
        _Faction__set_colour(self, value.ptr);
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
function Shield(a0, a1, a2, a3) {
    if (a0 === undefined) { this.ptr = _Shield__construct_0(); this.type = Shield; getCache(Shield)[this.ptr] = this; return; }
    this.ptr = _Shield__construct_4(/*spatial*/a0.ptr, /*emitter*/a1.ptr, /*faction*/a2.ptr, /*radius*/a3); this.type = Shield; getCache(Shield)[this.ptr] = this;
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
        _Shield__set_faction(self, value.ptr);
    }
});
Object.defineProperty(Shield.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _Shield__get_radius(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        return wrapPointer(_Slug__get_source(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Slug__set_source(self, value.ptr);
    }
});
Object.defineProperty(Slug.prototype, "velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Slug__get_velocity(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Slug__set_velocity(self, value.ptr);
    }
});
Object.defineProperty(Slug.prototype, "power", {
    get: function() {
        var self = this.ptr;
        return _Slug__get_power(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Slug__set_power(self, value);
    }
});
Slug.prototype["__destroy__"] = Slug.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Slug__destroy(self);
};
// Tank
function Tank(a0, a1, a2, a3, a4) {
    if (a0 === undefined) { this.ptr = _Tank__construct_0(); this.type = Tank; getCache(Tank)[this.ptr] = this; return; }
    this.ptr = _Tank__construct_5(/*spatial*/a0.ptr, /*movable*/a1.ptr, /*emitter*/a2.ptr, /*receptor*/a3.ptr, /*faction*/a4.ptr); this.type = Tank; getCache(Tank)[this.ptr] = this;
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
Module['HCamp'] = ComponentHandle_Camp;
Module['HShield'] = ComponentHandle_Shield;
Module['HSlug'] = ComponentHandle_Slug;
Module['HTank'] = ComponentHandle_Tank;

(function() {
    function setup() {
        BlockWorld.__type__ = _BlockWorld__type();
        Camp.__type__ = _Camp__type();
        Faction.__type__ = _Faction__type();
        Player.__type__ = _Player__type();
        Shield.__type__ = _Shield__type();
        Slug.__type__ = _Slug__type();
        Tank.__type__ = _Tank__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
