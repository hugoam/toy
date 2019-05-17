Module['two']['ui'] = Module['two']['ui'] || {};
Module['boids'] = Module['boids'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
Module['toy'] = Module['toy'] || {};
// Combat
function Combat() {
    this.ptr = _Combat_Combat_0(); getCache(Combat)[this.ptr] = this;
    this.type = Combat;
};
Combat.prototype = Object.create(WrapperObject.prototype);
Combat.prototype.constructor = Combat;
Combat.prototype.__class__ = Combat;
Combat.__cache__ = {};
Module['Combat'] = Combat;
Combat.prototype["__destroy__"] = Combat.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Combat__destroy(self);
};
// CombatFleet
function CombatFleet() {
    this.ptr = _CombatFleet_CombatFleet_0(); getCache(CombatFleet)[this.ptr] = this;
    this.type = CombatFleet;
};
CombatFleet.prototype = Object.create(WrapperObject.prototype);
CombatFleet.prototype.constructor = CombatFleet;
CombatFleet.prototype.__class__ = CombatFleet;
CombatFleet.__cache__ = {};
Module['CombatFleet'] = CombatFleet;
CombatFleet.prototype["__destroy__"] = CombatFleet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _CombatFleet__destroy(self);
};
// CombatStar
function CombatStar() {
    this.ptr = _CombatStar_CombatStar_0(); getCache(CombatStar)[this.ptr] = this;
    this.type = CombatStar;
};
CombatStar.prototype = Object.create(WrapperObject.prototype);
CombatStar.prototype.constructor = CombatStar;
CombatStar.prototype.__class__ = CombatStar;
CombatStar.__cache__ = {};
Module['CombatStar'] = CombatStar;
CombatStar.prototype["__destroy__"] = CombatStar.prototype.__destroy__ = function() {
    var self = this.ptr;
    _CombatStar__destroy(self);
};
// Commander
function Commander(id, name, race, command, commerce, diplomacy) {
    ensureCache.prepare();
    /* id <uint32_t> [] */
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* race <Race> [] */
    if (race && typeof race === "object") race = race.ptr;
    /* command <int> [] */
    /* commerce <int> [] */
    /* diplomacy <int> [] */
    this.ptr = _Commander_Commander_6(id, name, race, command, commerce, diplomacy); getCache(Commander)[this.ptr] = this;
    this.type = Commander;
};
Commander.prototype = Object.create(WrapperObject.prototype);
Commander.prototype.constructor = Commander;
Commander.prototype.__class__ = Commander;
Commander.__cache__ = {};
Module['Commander'] = Commander;
Object.defineProperty(Commander.prototype, "id", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_id(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint32_t> [] */
        _Commander__set_id(self, value);
    }
});
Object.defineProperty(Commander.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Commander__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Commander__set_name(self, value);
    }
});
Object.defineProperty(Commander.prototype, "race", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_race(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Race> [] */
        if (value && typeof value === "object") value = value.ptr;
        _Commander__set_race(self, value);
    }
});
Object.defineProperty(Commander.prototype, "command", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_command(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Commander__set_command(self, value);
    }
});
Object.defineProperty(Commander.prototype, "commerce", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_commerce(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Commander__set_commerce(self, value);
    }
});
Object.defineProperty(Commander.prototype, "diplomacy", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_diplomacy(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Commander__set_diplomacy(self, value);
    }
});
Object.defineProperty(Commander.prototype, "reputation", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_reputation(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Commander__set_reputation(self, value);
    }
});
Object.defineProperty(Commander.prototype, "victory", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_victory(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Commander__set_victory(self, value);
    }
});
Object.defineProperty(Commander.prototype, "capital", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Commander__get_capital(self), Star);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Star> [] */
        value = value.ptr;
        _Commander__set_capital(self, value);
    }
});
Object.defineProperty(Commander.prototype, "regime", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_regime(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Regime> [] */
        if (value && typeof value === "object") value = value.ptr;
        _Commander__set_regime(self, value);
    }
});
Object.defineProperty(Commander.prototype, "power", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_power(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Commander__set_power(self, value);
    }
});
Object.defineProperty(Commander.prototype, "centaures", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_centaures(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Commander__set_centaures(self, value);
    }
});
Object.defineProperty(Commander.prototype, "scans", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Commander__get_scans(self), Scans);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Scans> [] */
        value = value.ptr;
        _Commander__set_scans(self, value);
    }
});
Commander.prototype["__destroy__"] = Commander.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Commander__destroy(self);
};
// Construction
function Construction() {
    this.ptr = _Construction_Construction_0(); getCache(Construction)[this.ptr] = this;
    this.type = Construction;
};
Construction.prototype = Object.create(WrapperObject.prototype);
Construction.prototype.constructor = Construction;
Construction.prototype.__class__ = Construction;
Construction.__cache__ = {};
Module['Construction'] = Construction;
Construction.prototype["__destroy__"] = Construction.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Construction__destroy(self);
};
// Fleet
function Fleet(spatial, galaxy, commander, coord, name) {
    ensureCache.prepare();
    /* spatial <toy::HSpatial> [] */
    /* galaxy <Galaxy> [] */
    if(typeof galaxy !== "undefined" && galaxy !== null) { galaxy = galaxy.ptr; }
    /* commander <Commander> [] */
    if(typeof commander !== "undefined" && commander !== null) { commander = commander.ptr; }
    /* coord <uvec2> [] */
    if(typeof coord !== "undefined" && coord !== null) { coord = coord.ptr; }
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    if (spatial === undefined) { this.ptr = _Fleet_Fleet_0(); getCache(Fleet)[this.ptr] = this; return; }
    this.ptr = _Fleet_Fleet_5(spatial, galaxy, commander, coord, name); getCache(Fleet)[this.ptr] = this;
    this.type = Fleet;
};
Fleet.prototype = Object.create(WrapperObject.prototype);
Fleet.prototype.constructor = Fleet;
Fleet.prototype.__class__ = Fleet;
Fleet.__cache__ = {};
Module['Fleet'] = Fleet;
Fleet.prototype["order_jump"] = Fleet.prototype.order_jump = function(self, coord, stance) {
    var self = this.ptr;
    /* coord <uvec2> [] */
    coord = coord.ptr;
    /* stance <FleetStance> [] */
    if (stance && typeof stance === "object") stance = stance.ptr;
    _Fleet_order_jump_2(self, coord, stance);
};
Fleet.prototype["order_attack"] = Fleet.prototype.order_attack = function(self, star) {
    var self = this.ptr;
    /* star <Star> [] */
    star = star.ptr;
    _Fleet_order_attack_1(self, star);
};
Object.defineProperty(Fleet.prototype, "galaxy", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_galaxy(self), Galaxy);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Galaxy> [] */
        value = value.ptr;
        _Fleet__set_galaxy(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "commander", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_commander(self), Commander);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Commander> [] */
        value = value.ptr;
        _Fleet__set_commander(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_coord(self), uvec2);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec2> [] */
        value = value.ptr;
        _Fleet__set_coord(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "slot", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_slot(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _Fleet__set_slot(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Fleet__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Fleet__set_name(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "experience", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_experience(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Fleet__set_experience(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "spatial_power", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_spatial_power(self), SpatialPower);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <SpatialPower> [] */
        value = value.ptr;
        _Fleet__set_spatial_power(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "planetary_power", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_planetary_power(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Fleet__set_planetary_power(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "speed", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_speed(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint8_t> [] */
        _Fleet__set_speed(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "scan", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_scan(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint8_t> [] */
        _Fleet__set_scan(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "upkeep", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_upkeep(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Fleet__set_upkeep(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_stance(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <FleetStance> [] */
        if (value && typeof value === "object") value = value.ptr;
        _Fleet__set_stance(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "jump", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_jump(self), Jump);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Jump> [] */
        value = value.ptr;
        _Fleet__set_jump(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "split", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_split(self), Split);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Split> [] */
        value = value.ptr;
        _Fleet__set_split(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "fought", {
    get: function() {
        var self = this.ptr;
        return !!(_Fleet__get_fought(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _Fleet__set_fought(self, value);
    }
});
Object.defineProperty(Fleet.prototype, "ships_updated", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_ships_updated(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <size_t> [] */
        _Fleet__set_ships_updated(self, value);
    }
});
Fleet.prototype["__destroy__"] = Fleet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Fleet__destroy(self);
};
// Galaxy
function Galaxy(spatial, size) {
    /* spatial <toy::HSpatial> [] */
    /* size <uvec2> [] */
    if(typeof size !== "undefined" && size !== null) { size = size.ptr; }
    if (spatial === undefined) { this.ptr = _Galaxy_Galaxy_0(); getCache(Galaxy)[this.ptr] = this; return; }
    this.ptr = _Galaxy_Galaxy_2(spatial, size); getCache(Galaxy)[this.ptr] = this;
    this.type = Galaxy;
};
Galaxy.prototype = Object.create(WrapperObject.prototype);
Galaxy.prototype.constructor = Galaxy;
Galaxy.prototype.__class__ = Galaxy;
Galaxy.__cache__ = {};
Module['Galaxy'] = Galaxy;
Object.defineProperty(Galaxy.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Galaxy__get_size(self), uvec2);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec2> [] */
        value = value.ptr;
        _Galaxy__set_size(self, value);
    }
});
Galaxy.prototype["__destroy__"] = Galaxy.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Galaxy__destroy(self);
};
// Jump
function Jump() {
    this.ptr = _Jump_Jump_0(); getCache(Jump)[this.ptr] = this;
    this.type = Jump;
};
Jump.prototype = Object.create(WrapperObject.prototype);
Jump.prototype.constructor = Jump;
Jump.prototype.__class__ = Jump;
Jump.__cache__ = {};
Module['Jump'] = Jump;
Object.defineProperty(Jump.prototype, "fleet", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_fleet(self), Fleet);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Fleet> [] */
        value = value.ptr;
        _Jump__set_fleet(self, value);
    }
});
Object.defineProperty(Jump.prototype, "start", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_start(self), uvec2);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec2> [] */
        value = value.ptr;
        _Jump__set_start(self, value);
    }
});
Object.defineProperty(Jump.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_dest(self), uvec2);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec2> [] */
        value = value.ptr;
        _Jump__set_dest(self, value);
    }
});
Object.defineProperty(Jump.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Jump__get_stance(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <FleetStance> [] */
        if (value && typeof value === "object") value = value.ptr;
        _Jump__set_stance(self, value);
    }
});
Object.defineProperty(Jump.prototype, "track", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_track(self), Fleet);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Fleet> [] */
        value = value.ptr;
        _Jump__set_track(self, value);
    }
});
Jump.prototype["__destroy__"] = Jump.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Jump__destroy(self);
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
// Scans
function Scans() {
    this.ptr = _Scans_Scans_0(); getCache(Scans)[this.ptr] = this;
    this.type = Scans;
};
Scans.prototype = Object.create(WrapperObject.prototype);
Scans.prototype.constructor = Scans;
Scans.prototype.__class__ = Scans;
Scans.__cache__ = {};
Module['Scans'] = Scans;
Scans.prototype["__destroy__"] = Scans.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Scans__destroy(self);
};
// Schema
function Schema() {
    this.ptr = _Schema_Schema_0(); getCache(Schema)[this.ptr] = this;
    this.type = Schema;
};
Schema.prototype = Object.create(WrapperObject.prototype);
Schema.prototype.constructor = Schema;
Schema.prototype.__class__ = Schema;
Schema.__cache__ = {};
Module['Schema'] = Schema;
Object.defineProperty(Schema.prototype, "code", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Schema__get_code(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Schema__set_code(self, value);
    }
});
Object.defineProperty(Schema.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Schema__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Schema__set_name(self, value);
    }
});
Object.defineProperty(Schema.prototype, "conceptor", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Schema__get_conceptor(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Schema__set_conceptor(self, value);
    }
});
Object.defineProperty(Schema.prototype, "level", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_level(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint8_t> [] */
        _Schema__set_level(self, value);
    }
});
Object.defineProperty(Schema.prototype, "cost", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_cost(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Schema__set_cost(self, value);
    }
});
Object.defineProperty(Schema.prototype, "minerals", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_minerals(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Schema__set_minerals(self, value);
    }
});
Object.defineProperty(Schema.prototype, "andrium", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_andrium(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Schema__set_andrium(self, value);
    }
});
Object.defineProperty(Schema.prototype, "resistance", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_resistance(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Schema__set_resistance(self, value);
    }
});
Object.defineProperty(Schema.prototype, "speed", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_speed(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint8_t> [] */
        _Schema__set_speed(self, value);
    }
});
Object.defineProperty(Schema.prototype, "scan", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_scan(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint8_t> [] */
        _Schema__set_scan(self, value);
    }
});
Object.defineProperty(Schema.prototype, "planetary", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_planetary(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Schema__set_planetary(self, value);
    }
});
Object.defineProperty(Schema.prototype, "spatial", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Schema__get_spatial(self), SpatialPower);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <SpatialPower> [] */
        value = value.ptr;
        _Schema__set_spatial(self, value);
    }
});
Object.defineProperty(Schema.prototype, "upkeep_factor", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_upkeep_factor(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Schema__set_upkeep_factor(self, value);
    }
});
Schema.prototype["__destroy__"] = Schema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Schema__destroy(self);
};
// SpatialPower
function SpatialPower() {
    this.ptr = _SpatialPower_SpatialPower_0(); getCache(SpatialPower)[this.ptr] = this;
    this.type = SpatialPower;
};
SpatialPower.prototype = Object.create(WrapperObject.prototype);
SpatialPower.prototype.constructor = SpatialPower;
SpatialPower.prototype.__class__ = SpatialPower;
SpatialPower.__cache__ = {};
Module['SpatialPower'] = SpatialPower;
SpatialPower.prototype["__destroy__"] = SpatialPower.prototype.__destroy__ = function() {
    var self = this.ptr;
    _SpatialPower__destroy(self);
};
// Split
function Split() {
    this.ptr = _Split_Split_0(); getCache(Split)[this.ptr] = this;
    this.type = Split;
};
Split.prototype = Object.create(WrapperObject.prototype);
Split.prototype.constructor = Split;
Split.prototype.__class__ = Split;
Split.__cache__ = {};
Module['Split'] = Split;
Object.defineProperty(Split.prototype, "source", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Split__get_source(self), Fleet);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Fleet> [] */
        value = value.ptr;
        _Split__set_source(self, value);
    }
});
Object.defineProperty(Split.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Split__get_dest(self), Fleet);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Fleet> [] */
        value = value.ptr;
        _Split__set_dest(self, value);
    }
});
Object.defineProperty(Split.prototype, "code", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Split__get_code(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Split__set_code(self, value);
    }
});
Object.defineProperty(Split.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Split__get_stance(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <FleetStance> [] */
        if (value && typeof value === "object") value = value.ptr;
        _Split__set_stance(self, value);
    }
});
Split.prototype["__destroy__"] = Split.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Split__destroy(self);
};
// Star
function Star(spatial, galaxy, coord, name) {
    ensureCache.prepare();
    /* spatial <toy::HSpatial> [] */
    /* galaxy <Galaxy> [] */
    if(typeof galaxy !== "undefined" && galaxy !== null) { galaxy = galaxy.ptr; }
    /* coord <uvec2> [] */
    if(typeof coord !== "undefined" && coord !== null) { coord = coord.ptr; }
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    if (spatial === undefined) { this.ptr = _Star_Star_0(); getCache(Star)[this.ptr] = this; return; }
    this.ptr = _Star_Star_4(spatial, galaxy, coord, name); getCache(Star)[this.ptr] = this;
    this.type = Star;
};
Star.prototype = Object.create(WrapperObject.prototype);
Star.prototype.constructor = Star;
Star.prototype.__class__ = Star;
Star.__cache__ = {};
Module['Star'] = Star;
Object.defineProperty(Star.prototype, "galaxy", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Star__get_galaxy(self), Galaxy);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Galaxy> [] */
        value = value.ptr;
        _Star__set_galaxy(self, value);
    }
});
Object.defineProperty(Star.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Star__get_coord(self), uvec2);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec2> [] */
        value = value.ptr;
        _Star__set_coord(self, value);
    }
});
Object.defineProperty(Star.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Star__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _Star__set_name(self, value);
    }
});
Object.defineProperty(Star.prototype, "stability", {
    get: function() {
        var self = this.ptr;
        return _Star__get_stability(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Star__set_stability(self, value);
    }
});
Object.defineProperty(Star.prototype, "revolt", {
    get: function() {
        var self = this.ptr;
        return !!(_Star__get_revolt(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _Star__set_revolt(self, value);
    }
});
Object.defineProperty(Star.prototype, "environment", {
    get: function() {
        var self = this.ptr;
        return _Star__get_environment(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Star__set_environment(self, value);
    }
});
Object.defineProperty(Star.prototype, "terraformation", {
    get: function() {
        var self = this.ptr;
        return _Star__get_terraformation(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Star__set_terraformation(self, value);
    }
});
Object.defineProperty(Star.prototype, "base_population", {
    get: function() {
        var self = this.ptr;
        return _Star__get_base_population(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Star__set_base_population(self, value);
    }
});
Object.defineProperty(Star.prototype, "max_population", {
    get: function() {
        var self = this.ptr;
        return _Star__get_max_population(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Star__set_max_population(self, value);
    }
});
Object.defineProperty(Star.prototype, "population", {
    get: function() {
        var self = this.ptr;
        return _Star__get_population(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Star__set_population(self, value);
    }
});
Object.defineProperty(Star.prototype, "militia", {
    get: function() {
        var self = this.ptr;
        return _Star__get_militia(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Star__set_militia(self, value);
    }
});
Object.defineProperty(Star.prototype, "defense", {
    get: function() {
        var self = this.ptr;
        return _Star__get_defense(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Star__set_defense(self, value);
    }
});
Object.defineProperty(Star.prototype, "revenue", {
    get: function() {
        var self = this.ptr;
        return _Star__get_revenue(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _Star__set_revenue(self, value);
    }
});
Object.defineProperty(Star.prototype, "politic", {
    get: function() {
        var self = this.ptr;
        return _Star__get_politic(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Politic> [] */
        if (value && typeof value === "object") value = value.ptr;
        _Star__set_politic(self, value);
    }
});
Object.defineProperty(Star.prototype, "taxation", {
    get: function() {
        var self = this.ptr;
        return _Star__get_taxation(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Taxation> [] */
        if (value && typeof value === "object") value = value.ptr;
        _Star__set_taxation(self, value);
    }
});
Object.defineProperty(Star.prototype, "commander", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Star__get_commander(self), Commander);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Commander> [] */
        value = value.ptr;
        _Star__set_commander(self, value);
    }
});
Object.defineProperty(Star.prototype, "scan", {
    get: function() {
        var self = this.ptr;
        return _Star__get_scan(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <int> [] */
        _Star__set_scan(self, value);
    }
});
Star.prototype["__destroy__"] = Star.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Star__destroy(self);
};
// TechDomain
function TechDomain() {
    this.ptr = _TechDomain_TechDomain_0(); getCache(TechDomain)[this.ptr] = this;
    this.type = TechDomain;
};
TechDomain.prototype = Object.create(WrapperObject.prototype);
TechDomain.prototype.constructor = TechDomain;
TechDomain.prototype.__class__ = TechDomain;
TechDomain.__cache__ = {};
Module['TechDomain'] = TechDomain;
TechDomain.prototype["__destroy__"] = TechDomain.prototype.__destroy__ = function() {
    var self = this.ptr;
    _TechDomain__destroy(self);
};
// Turn
function Turn() {
    this.ptr = _Turn_Turn_0(); getCache(Turn)[this.ptr] = this;
    this.type = Turn;
};
Turn.prototype = Object.create(WrapperObject.prototype);
Turn.prototype.constructor = Turn;
Turn.prototype.__class__ = Turn;
Turn.__cache__ = {};
Module['Turn'] = Turn;
Turn.prototype["__destroy__"] = Turn.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Turn__destroy(self);
};
// BuildingSchema
function BuildingSchema() {
    this.ptr = _BuildingSchema_BuildingSchema_0(); getCache(BuildingSchema)[this.ptr] = this;
    this.type = BuildingSchema;
};
BuildingSchema.prototype = Object.create(WrapperObject.prototype);
BuildingSchema.prototype.constructor = BuildingSchema;
BuildingSchema.prototype.__class__ = BuildingSchema;
BuildingSchema.__cache__ = {};
Module['BuildingSchema'] = BuildingSchema;
BuildingSchema.prototype["__destroy__"] = BuildingSchema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _BuildingSchema__destroy(self);
};
// CommanderBrush
function CommanderBrush() { throw "cannot construct a CommanderBrush, no constructor in IDL" }
CommanderBrush.prototype = Object.create(WrapperObject.prototype);
CommanderBrush.prototype.constructor = CommanderBrush;
CommanderBrush.prototype.__class__ = CommanderBrush;
CommanderBrush.__cache__ = {};
Module['CommanderBrush'] = CommanderBrush;
Object.defineProperty(CommanderBrush.prototype, "commander", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_CommanderBrush__get_commander(self), Commander);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Commander> [] */
        value = value.ptr;
        _CommanderBrush__set_commander(self, value);
    }
});
Object.defineProperty(CommanderBrush.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _CommanderBrush__get_radius(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _CommanderBrush__set_radius(self, value);
    }
});
CommanderBrush.prototype["__destroy__"] = CommanderBrush.prototype.__destroy__ = function() {
    var self = this.ptr;
    _CommanderBrush__destroy(self);
};
// PlanetaryCombat
function PlanetaryCombat() {
    this.ptr = _PlanetaryCombat_PlanetaryCombat_0(); getCache(PlanetaryCombat)[this.ptr] = this;
    this.type = PlanetaryCombat;
};
PlanetaryCombat.prototype = Object.create(WrapperObject.prototype);
PlanetaryCombat.prototype.constructor = PlanetaryCombat;
PlanetaryCombat.prototype.__class__ = PlanetaryCombat;
PlanetaryCombat.__cache__ = {};
Module['PlanetaryCombat'] = PlanetaryCombat;
Object.defineProperty(PlanetaryCombat.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_PlanetaryCombat__get_coord(self), uvec2);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec2> [] */
        value = value.ptr;
        _PlanetaryCombat__set_coord(self, value);
    }
});
Object.defineProperty(PlanetaryCombat.prototype, "defense", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_PlanetaryCombat__get_defense(self), CombatStar);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <CombatStar> [] */
        value = value.ptr;
        _PlanetaryCombat__set_defense(self, value);
    }
});
PlanetaryCombat.prototype["__destroy__"] = PlanetaryCombat.prototype.__destroy__ = function() {
    var self = this.ptr;
    _PlanetaryCombat__destroy(self);
};
// ShipComponent
function ShipComponent() {
    this.ptr = _ShipComponent_ShipComponent_0(); getCache(ShipComponent)[this.ptr] = this;
    this.type = ShipComponent;
};
ShipComponent.prototype = Object.create(WrapperObject.prototype);
ShipComponent.prototype.constructor = ShipComponent;
ShipComponent.prototype.__class__ = ShipComponent;
ShipComponent.__cache__ = {};
Module['ShipComponent'] = ShipComponent;
ShipComponent.prototype["__destroy__"] = ShipComponent.prototype.__destroy__ = function() {
    var self = this.ptr;
    _ShipComponent__destroy(self);
};
// ShipEngine
function ShipEngine() {
    this.ptr = _ShipEngine_ShipEngine_0(); getCache(ShipEngine)[this.ptr] = this;
    this.type = ShipEngine;
};
ShipEngine.prototype = Object.create(WrapperObject.prototype);
ShipEngine.prototype.constructor = ShipEngine;
ShipEngine.prototype.__class__ = ShipEngine;
ShipEngine.__cache__ = {};
Module['ShipEngine'] = ShipEngine;
ShipEngine.prototype["__destroy__"] = ShipEngine.prototype.__destroy__ = function() {
    var self = this.ptr;
    _ShipEngine__destroy(self);
};
// ShipHull
function ShipHull() {
    this.ptr = _ShipHull_ShipHull_0(); getCache(ShipHull)[this.ptr] = this;
    this.type = ShipHull;
};
ShipHull.prototype = Object.create(WrapperObject.prototype);
ShipHull.prototype.constructor = ShipHull;
ShipHull.prototype.__class__ = ShipHull;
ShipHull.__cache__ = {};
Module['ShipHull'] = ShipHull;
ShipHull.prototype["__destroy__"] = ShipHull.prototype.__destroy__ = function() {
    var self = this.ptr;
    _ShipHull__destroy(self);
};
// ShipSchema
function ShipSchema() {
    this.ptr = _ShipSchema_ShipSchema_0(); getCache(ShipSchema)[this.ptr] = this;
    this.type = ShipSchema;
};
ShipSchema.prototype = Object.create(WrapperObject.prototype);
ShipSchema.prototype.constructor = ShipSchema;
ShipSchema.prototype.__class__ = ShipSchema;
ShipSchema.__cache__ = {};
Module['ShipSchema'] = ShipSchema;
Object.defineProperty(ShipSchema.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return _ShipSchema__get_size(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint8_t> [] */
        _ShipSchema__set_size(self, value);
    }
});
Object.defineProperty(ShipSchema.prototype, "class", {
    get: function() {
        var self = this.ptr;
        return _ShipSchema__get_class(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint8_t> [] */
        _ShipSchema__set_class(self, value);
    }
});
Object.defineProperty(ShipSchema.prototype, "main_weapon", {
    get: function() {
        var self = this.ptr;
        return _ShipSchema__get_main_weapon(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <WeaponType> [] */
        if (value && typeof value === "object") value = value.ptr;
        _ShipSchema__set_main_weapon(self, value);
    }
});
ShipSchema.prototype["__destroy__"] = ShipSchema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _ShipSchema__destroy(self);
};
// SpatialCombat
function SpatialCombat() {
    this.ptr = _SpatialCombat_SpatialCombat_0(); getCache(SpatialCombat)[this.ptr] = this;
    this.type = SpatialCombat;
};
SpatialCombat.prototype = Object.create(WrapperObject.prototype);
SpatialCombat.prototype.constructor = SpatialCombat;
SpatialCombat.prototype.__class__ = SpatialCombat;
SpatialCombat.__cache__ = {};
Module['SpatialCombat'] = SpatialCombat;
Object.defineProperty(SpatialCombat.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_SpatialCombat__get_coord(self), uvec2);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec2> [] */
        value = value.ptr;
        _SpatialCombat__set_coord(self, value);
    }
});
SpatialCombat.prototype["__destroy__"] = SpatialCombat.prototype.__destroy__ = function() {
    var self = this.ptr;
    _SpatialCombat__destroy(self);
};
// Universe
function Universe(name, job_system) {
    ensureCache.prepare();
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _Universe_Universe_2(name, job_system); getCache(Universe)[this.ptr] = this;
    this.type = Universe;
};
Universe.prototype = Object.create(WrapperObject.prototype);
Universe.prototype.constructor = Universe;
Universe.prototype.__class__ = Universe;
Universe.__cache__ = {};
Module['Universe'] = Universe;
Object.defineProperty(Universe.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Universe__get_world(self), World);
    }});
Object.defineProperty(Universe.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Universe__get_bullet_world(self), BulletWorld);
    }});
Universe.prototype["__destroy__"] = Universe.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Universe__destroy(self);
};
Module['generate_system'] = function(galaxy, coord, position) {
    var self = this.ptr;
    /* galaxy <Galaxy> [] */
    galaxy = galaxy.ptr;
    /* coord <uvec3> [] */
    coord = coord.ptr;
    /* position <vec3> [] */
    position = position.ptr;
    return __generate_system_3(galaxy, coord, position);
};
Module['generate_fleet'] = function(galaxy, coord, position) {
    var self = this.ptr;
    /* galaxy <Galaxy> [] */
    galaxy = galaxy.ptr;
    /* coord <uvec3> [] */
    coord = coord.ptr;
    /* position <vec3> [] */
    position = position.ptr;
    return __generate_fleet_3(galaxy, coord, position);
};
Module['generate_commander'] = function(galaxy, star) {
    var self = this.ptr;
    /* galaxy <Galaxy> [] */
    galaxy = galaxy.ptr;
    /* star <Star> [] */
    star = star.ptr;
    return wrapPointer(__generate_commander_2(galaxy, star), Commander);
};

(function() {
    function setup() {
        Combat.__type__ = _Combat__type();
        CombatFleet.__type__ = _CombatFleet__type();
        CombatStar.__type__ = _CombatStar__type();
        Commander.__type__ = _Commander__type();
        Construction.__type__ = _Construction__type();
        Fleet.__type__ = _Fleet__type();
        Galaxy.__type__ = _Galaxy__type();
        Jump.__type__ = _Jump__type();
        Player.__type__ = _Player__type();
        Scans.__type__ = _Scans__type();
        Schema.__type__ = _Schema__type();
        SpatialPower.__type__ = _SpatialPower__type();
        Split.__type__ = _Split__type();
        Star.__type__ = _Star__type();
        TechDomain.__type__ = _TechDomain__type();
        Turn.__type__ = _Turn__type();
        BuildingSchema.__type__ = _BuildingSchema__type();
        CommanderBrush.__type__ = _CommanderBrush__type();
        PlanetaryCombat.__type__ = _PlanetaryCombat__type();
        ShipComponent.__type__ = _ShipComponent__type();
        ShipEngine.__type__ = _ShipEngine__type();
        ShipHull.__type__ = _ShipHull__type();
        ShipSchema.__type__ = _ShipSchema__type();
        SpatialCombat.__type__ = _SpatialCombat__type();
        Universe.__type__ = _Universe__type();
        // CombatType
        Module['CombatType'] = Module['CombatType'] || {};
        Module['CombatType']['Spatial'] = _CombatType_Spatial();
        Module['CombatType']['Planetary'] = _CombatType_Planetary();
        // Experience
        Module['Experience'] = Module['Experience'] || {};
        Module['Experience']['Inexperienced'] = _Experience_Inexperienced();
        Module['Experience']['LittleExperienced'] = _Experience_LittleExperienced();
        Module['Experience']['Experienced'] = _Experience_Experienced();
        Module['Experience']['Superior'] = _Experience_Superior();
        Module['Experience']['Elite'] = _Experience_Elite();
        // FleetSize
        Module['FleetSize'] = Module['FleetSize'] || {};
        Module['FleetSize']['Ridicule'] = _FleetSize_Ridicule();
        Module['FleetSize']['Minuscule'] = _FleetSize_Minuscule();
        Module['FleetSize']['Tiny'] = _FleetSize_Tiny();
        Module['FleetSize']['Small'] = _FleetSize_Small();
        Module['FleetSize']['Medium'] = _FleetSize_Medium();
        Module['FleetSize']['Respectable'] = _FleetSize_Respectable();
        Module['FleetSize']['Grand'] = _FleetSize_Grand();
        Module['FleetSize']['HighGrand'] = _FleetSize_HighGrand();
        Module['FleetSize']['Colossal'] = _FleetSize_Colossal();
        Module['FleetSize']['Titanesque'] = _FleetSize_Titanesque();
        Module['FleetSize']['Cyclopean'] = _FleetSize_Cyclopean();
        Module['FleetSize']['Divine'] = _FleetSize_Divine();
        Module['FleetSize']['Count'] = _FleetSize_Count();
        // FleetStance
        Module['FleetStance'] = Module['FleetStance'] || {};
        Module['FleetStance']['Movement'] = _FleetStance_Movement();
        Module['FleetStance']['SpatialAttack'] = _FleetStance_SpatialAttack();
        Module['FleetStance']['SpatialDefense'] = _FleetStance_SpatialDefense();
        Module['FleetStance']['PlanetaryAttack'] = _FleetStance_PlanetaryAttack();
        Module['FleetStance']['PlanetaryDefense'] = _FleetStance_PlanetaryDefense();
        Module['FleetStance']['Pillage'] = _FleetStance_Pillage();
        // GameStage
        Module['GameStage'] = Module['GameStage'] || {};
        Module['GameStage']['Empire'] = _GameStage_Empire();
        Module['GameStage']['Tactics'] = _GameStage_Tactics();
        Module['GameStage']['TurnReport'] = _GameStage_TurnReport();
        // Politic
        Module['Politic'] = Module['Politic'] || {};
        Module['Politic']['Taxes'] = _Politic_Taxes();
        Module['Politic']['Commerce'] = _Politic_Commerce();
        Module['Politic']['Construction'] = _Politic_Construction();
        Module['Politic']['Defense'] = _Politic_Defense();
        Module['Politic']['Pacification'] = _Politic_Pacification();
        // Race
        Module['Race'] = Module['Race'] || {};
        Module['Race']['Human'] = _Race_Human();
        Module['Race']['Bulvoid'] = _Race_Bulvoid();
        Module['Race']['Techtulon'] = _Race_Techtulon();
        Module['Race']['Rakrarior'] = _Race_Rakrarior();
        Module['Race']['Seigneur'] = _Race_Seigneur();
        Module['Race']['Meton'] = _Race_Meton();
        Module['Race']['Tissinar'] = _Race_Tissinar();
        Module['Race']['Zwiie'] = _Race_Zwiie();
        // Regime
        Module['Regime'] = Module['Regime'] || {};
        Module['Regime']['Empire'] = _Regime_Empire();
        Module['Regime']['Dictature'] = _Regime_Dictature();
        Module['Regime']['Democracy'] = _Regime_Democracy();
        Module['Regime']['Theocracy'] = _Regime_Theocracy();
        Module['Regime']['Technocracy'] = _Regime_Technocracy();
        Module['Regime']['Piratery'] = _Regime_Piratery();
        // Resource
        Module['Resource'] = Module['Resource'] || {};
        Module['Resource']['None'] = _Resource_None();
        Module['Resource']['Minerals'] = _Resource_Minerals();
        Module['Resource']['Andrium'] = _Resource_Andrium();
        Module['Resource']['Alcool'] = _Resource_Alcool();
        Module['Resource']['Slaves'] = _Resource_Slaves();
        Module['Resource']['Narcotics'] = _Resource_Narcotics();
        Module['Resource']['Food'] = _Resource_Food();
        Module['Resource']['Medicine'] = _Resource_Medicine();
        Module['Resource']['Computers'] = _Resource_Computers();
        Module['Resource']['Plastic'] = _Resource_Plastic();
        Module['Resource']['Robot'] = _Resource_Robot();
        Module['Resource']['Count'] = _Resource_Count();
        // Taxation
        Module['Taxation'] = Module['Taxation'] || {};
        Module['Taxation']['None'] = _Taxation_None();
        Module['Taxation']['Light'] = _Taxation_Light();
        Module['Taxation']['Medium'] = _Taxation_Medium();
        Module['Taxation']['Heavy'] = _Taxation_Heavy();
        Module['Taxation']['Heaviest'] = _Taxation_Heaviest();
        Module['Taxation']['Total'] = _Taxation_Total();
        // Technology
        Module['Technology'] = Module['Technology'] || {};
        Module['Technology']['Engines'] = _Technology_Engines();
        Module['Technology']['EcoEnergy'] = _Technology_EcoEnergy();
        Module['Technology']['Scanners'] = _Technology_Scanners();
        Module['Technology']['PlanetaryShields'] = _Technology_PlanetaryShields();
        Module['Technology']['SpatialShields'] = _Technology_SpatialShields();
        Module['Technology']['LaserPlasmaIons'] = _Technology_LaserPlasmaIons();
        Module['Technology']['Torpedoes'] = _Technology_Torpedoes();
        Module['Technology']['Bombs'] = _Technology_Bombs();
        Module['Technology']['HullArmor'] = _Technology_HullArmor();
        Module['Technology']['Mining'] = _Technology_Mining();
        Module['Technology']['Terraforming'] = _Technology_Terraforming();
        Module['Technology']['Construction'] = _Technology_Construction();
        Module['Technology']['Piloting'] = _Technology_Piloting();
        Module['Technology']['Commerce'] = _Technology_Commerce();
        Module['Technology']['Personnel'] = _Technology_Personnel();
        Module['Technology']['Administration'] = _Technology_Administration();
        Module['Technology']['CyberCommand'] = _Technology_CyberCommand();
        Module['Technology']['CyberCommerce'] = _Technology_CyberCommerce();
        Module['Technology']['CyberDiplomacy'] = _Technology_CyberDiplomacy();
        Module['Technology']['Count'] = _Technology_Count();
        // WeaponType
        Module['WeaponType'] = Module['WeaponType'] || {};
        Module['WeaponType']['None'] = _WeaponType_None();
        Module['WeaponType']['Ion'] = _WeaponType_Ion();
        Module['WeaponType']['Laser'] = _WeaponType_Laser();
        Module['WeaponType']['Plasma'] = _WeaponType_Plasma();
        Module['WeaponType']['Torpedo'] = _WeaponType_Torpedo();
        Module['WeaponType']['Bomb'] = _WeaponType_Bomb();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
