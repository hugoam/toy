
// Bindings utilities
function WrapperObject() {
}
// Combat
function Combat() {
    var self = this.ptr;
    this.ptr = _Combat_Combat_0(self); getCache(Combat)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _CombatFleet_CombatFleet_0(self); getCache(CombatFleet)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _CombatStar_CombatStar_0(self); getCache(CombatStar)[this.ptr] = this;
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
    var self = this.ptr;
    ensureCache.prepare();
    /* id <mud::Id> [] */
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* race <Race> [] */
    if (race && typeof race === "object") race = race.ptr;
    /* command <int> [] */
    /* commerce <int> [] */
    /* diplomacy <int> [] */
    this.ptr = _Commander_Commander_6(self, id, name, race, command, commerce, diplomacy); getCache(Commander)[this.ptr] = this;
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
    set: function(id) {
        var self = this.ptr;
        /* id <mud::Id> [] */
        _Commander__set_id(self, id);
    }
});
Object.defineProperty(Commander.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Commander__get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _Commander__set_name(self, name);
    }
});
Object.defineProperty(Commander.prototype, "race", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_race(self);
    },
    set: function(race) {
        var self = this.ptr;
        /* race <Race> [] */
        if (race && typeof race === "object") race = race.ptr;
        _Commander__set_race(self, race);
    }
});
Object.defineProperty(Commander.prototype, "command", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_command(self);
    },
    set: function(command) {
        var self = this.ptr;
        /* command <int> [] */
        _Commander__set_command(self, command);
    }
});
Object.defineProperty(Commander.prototype, "commerce", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_commerce(self);
    },
    set: function(commerce) {
        var self = this.ptr;
        /* commerce <int> [] */
        _Commander__set_commerce(self, commerce);
    }
});
Object.defineProperty(Commander.prototype, "diplomacy", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_diplomacy(self);
    },
    set: function(diplomacy) {
        var self = this.ptr;
        /* diplomacy <int> [] */
        _Commander__set_diplomacy(self, diplomacy);
    }
});
Object.defineProperty(Commander.prototype, "reputation", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_reputation(self);
    },
    set: function(reputation) {
        var self = this.ptr;
        /* reputation <int> [] */
        _Commander__set_reputation(self, reputation);
    }
});
Object.defineProperty(Commander.prototype, "victory", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_victory(self);
    },
    set: function(victory) {
        var self = this.ptr;
        /* victory <int> [] */
        _Commander__set_victory(self, victory);
    }
});
Object.defineProperty(Commander.prototype, "capital", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Commander__get_capital(self), Star);
    },
    set: function(capital) {
        var self = this.ptr;
        /* capital <Star> [] */
        capital = capital.ptr;
        _Commander__set_capital(self, capital);
    }
});
Object.defineProperty(Commander.prototype, "regime", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_regime(self);
    },
    set: function(regime) {
        var self = this.ptr;
        /* regime <Regime> [] */
        if (regime && typeof regime === "object") regime = regime.ptr;
        _Commander__set_regime(self, regime);
    }
});
Object.defineProperty(Commander.prototype, "power", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_power(self);
    },
    set: function(power) {
        var self = this.ptr;
        /* power <float> [] */
        _Commander__set_power(self, power);
    }
});
Object.defineProperty(Commander.prototype, "centaures", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_centaures(self);
    },
    set: function(centaures) {
        var self = this.ptr;
        /* centaures <float> [] */
        _Commander__set_centaures(self, centaures);
    }
});
Object.defineProperty(Commander.prototype, "scans", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Commander__get_scans(self), Scans);
    },
    set: function(scans) {
        var self = this.ptr;
        /* scans <Scans> [] */
        scans = scans.ptr;
        _Commander__set_scans(self, scans);
    }
});
Commander.prototype["__destroy__"] = Commander.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Commander__destroy(self);
};
// Construction
function Construction() {
    var self = this.ptr;
    this.ptr = _Construction_Construction_0(self); getCache(Construction)[this.ptr] = this;
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
    var self = this.ptr;
    ensureCache.prepare();
    /* spatial <toy::HSpatial> [] */
    /* galaxy <Galaxy> [] */
    galaxy = galaxy.ptr;
    /* commander <Commander> [] */
    commander = commander.ptr;
    /* coord <uvec2> [] */
    coord = coord.ptr;
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    if (spatial === undefined) { this.ptr = _Fleet_Fleet_0(self); getCache(Fleet)[this.ptr] = this; return; }
    this.ptr = _Fleet_Fleet_5(self, spatial, galaxy, commander, coord, name); getCache(Fleet)[this.ptr] = this;
};
Fleet.prototype = Object.create(WrapperObject.prototype);
Fleet.prototype.constructor = Fleet;
Fleet.prototype.__class__ = Fleet;
Fleet.__cache__ = {};
Module['Fleet'] = Fleet;
Fleet.prototype["order_attack"] = Fleet.prototype.order_attack = function(star) {
    /* star <Star> [] */
    star = star.ptr;
    _Fleet_order_attack_1(star);
};
Fleet.prototype["order_jump"] = Fleet.prototype.order_jump = function(coord, stance) {
    /* coord <vec2> [] */
    coord = coord.ptr;
    /* stance <FleetStance> [] */
    if (stance && typeof stance === "object") stance = stance.ptr;
    _Fleet_order_jump_2(coord, stance);
};
Object.defineProperty(Fleet.prototype, "galaxy", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_galaxy(self), Galaxy);
    },
    set: function(galaxy) {
        var self = this.ptr;
        /* galaxy <Galaxy> [] */
        galaxy = galaxy.ptr;
        _Fleet__set_galaxy(self, galaxy);
    }
});
Object.defineProperty(Fleet.prototype, "commander", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_commander(self), Commander);
    },
    set: function(commander) {
        var self = this.ptr;
        /* commander <Commander> [] */
        commander = commander.ptr;
        _Fleet__set_commander(self, commander);
    }
});
Object.defineProperty(Fleet.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_coord(self), mud::uvec2);
    },
    set: function(coord) {
        var self = this.ptr;
        /* coord <uvec2> [] */
        coord = coord.ptr;
        _Fleet__set_coord(self, coord);
    }
});
Object.defineProperty(Fleet.prototype, "slot", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_slot(self), mud::vec3);
    },
    set: function(slot) {
        var self = this.ptr;
        /* slot <vec3> [] */
        slot = slot.ptr;
        _Fleet__set_slot(self, slot);
    }
});
Object.defineProperty(Fleet.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Fleet__get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _Fleet__set_name(self, name);
    }
});
Object.defineProperty(Fleet.prototype, "experience", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_experience(self);
    },
    set: function(experience) {
        var self = this.ptr;
        /* experience <float> [] */
        _Fleet__set_experience(self, experience);
    }
});
Object.defineProperty(Fleet.prototype, "spatial_power", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_spatial_power(self), SpatialPower);
    },
    set: function(spatial_power) {
        var self = this.ptr;
        /* spatial_power <SpatialPower> [] */
        spatial_power = spatial_power.ptr;
        _Fleet__set_spatial_power(self, spatial_power);
    }
});
Object.defineProperty(Fleet.prototype, "planetary_power", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_planetary_power(self);
    },
    set: function(planetary_power) {
        var self = this.ptr;
        /* planetary_power <float> [] */
        _Fleet__set_planetary_power(self, planetary_power);
    }
});
Object.defineProperty(Fleet.prototype, "speed", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_speed(self);
    },
    set: function(speed) {
        var self = this.ptr;
        /* speed <uint8_t> [] */
        _Fleet__set_speed(self, speed);
    }
});
Object.defineProperty(Fleet.prototype, "scan", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_scan(self);
    },
    set: function(scan) {
        var self = this.ptr;
        /* scan <uint8_t> [] */
        _Fleet__set_scan(self, scan);
    }
});
Object.defineProperty(Fleet.prototype, "upkeep", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_upkeep(self);
    },
    set: function(upkeep) {
        var self = this.ptr;
        /* upkeep <float> [] */
        _Fleet__set_upkeep(self, upkeep);
    }
});
Object.defineProperty(Fleet.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_stance(self);
    },
    set: function(stance) {
        var self = this.ptr;
        /* stance <FleetStance> [] */
        if (stance && typeof stance === "object") stance = stance.ptr;
        _Fleet__set_stance(self, stance);
    }
});
Object.defineProperty(Fleet.prototype, "jump", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_jump(self), Jump);
    },
    set: function(jump) {
        var self = this.ptr;
        /* jump <Jump> [] */
        jump = jump.ptr;
        _Fleet__set_jump(self, jump);
    }
});
Object.defineProperty(Fleet.prototype, "split", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_split(self), Split);
    },
    set: function(split) {
        var self = this.ptr;
        /* split <Split> [] */
        split = split.ptr;
        _Fleet__set_split(self, split);
    }
});
Object.defineProperty(Fleet.prototype, "fought", {
    get: function() {
        var self = this.ptr;
        return !!(_Fleet__get_fought(self));
    },
    set: function(fought) {
        var self = this.ptr;
        /* fought <bool> [] */
        _Fleet__set_fought(self, fought);
    }
});
Object.defineProperty(Fleet.prototype, "ships_updated", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_ships_updated(self);
    },
    set: function(ships_updated) {
        var self = this.ptr;
        /* ships_updated <size_t> [] */
        _Fleet__set_ships_updated(self, ships_updated);
    }
});
Fleet.prototype["__destroy__"] = Fleet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Fleet__destroy(self);
};
// Galaxy
function Galaxy(spatial, size) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* size <uvec2> [] */
    size = size.ptr;
    if (spatial === undefined) { this.ptr = _Galaxy_Galaxy_0(self); getCache(Galaxy)[this.ptr] = this; return; }
    this.ptr = _Galaxy_Galaxy_2(self, spatial, size); getCache(Galaxy)[this.ptr] = this;
};
Galaxy.prototype = Object.create(WrapperObject.prototype);
Galaxy.prototype.constructor = Galaxy;
Galaxy.prototype.__class__ = Galaxy;
Galaxy.__cache__ = {};
Module['Galaxy'] = Galaxy;
Object.defineProperty(Galaxy.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Galaxy__get_size(self), mud::uvec2);
    },
    set: function(size) {
        var self = this.ptr;
        /* size <uvec2> [] */
        size = size.ptr;
        _Galaxy__set_size(self, size);
    }
});
Galaxy.prototype["__destroy__"] = Galaxy.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Galaxy__destroy(self);
};
// Jump
function Jump() {
    var self = this.ptr;
    this.ptr = _Jump_Jump_0(self); getCache(Jump)[this.ptr] = this;
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
    set: function(fleet) {
        var self = this.ptr;
        /* fleet <Fleet> [] */
        fleet = fleet.ptr;
        _Jump__set_fleet(self, fleet);
    }
});
Object.defineProperty(Jump.prototype, "start", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_start(self), mud::uvec2);
    },
    set: function(start) {
        var self = this.ptr;
        /* start <uvec2> [] */
        start = start.ptr;
        _Jump__set_start(self, start);
    }
});
Object.defineProperty(Jump.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_dest(self), mud::uvec2);
    },
    set: function(dest) {
        var self = this.ptr;
        /* dest <uvec2> [] */
        dest = dest.ptr;
        _Jump__set_dest(self, dest);
    }
});
Object.defineProperty(Jump.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Jump__get_stance(self);
    },
    set: function(stance) {
        var self = this.ptr;
        /* stance <FleetStance> [] */
        if (stance && typeof stance === "object") stance = stance.ptr;
        _Jump__set_stance(self, stance);
    }
});
Object.defineProperty(Jump.prototype, "track", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_track(self), Fleet);
    },
    set: function(track) {
        var self = this.ptr;
        /* track <Fleet> [] */
        track = track.ptr;
        _Jump__set_track(self, track);
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
    var self = this.ptr;
    this.ptr = _Scans_Scans_0(self); getCache(Scans)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _Schema_Schema_0(self); getCache(Schema)[this.ptr] = this;
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
    set: function(code) {
        var self = this.ptr;
        /* code <std::string> [] */
        if (code && typeof code === "object") code = code.ptr;
        else code = ensureString(code);
        _Schema__set_code(self, code);
    }
});
Object.defineProperty(Schema.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Schema__get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _Schema__set_name(self, name);
    }
});
Object.defineProperty(Schema.prototype, "conceptor", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Schema__get_conceptor(self));
    },
    set: function(conceptor) {
        var self = this.ptr;
        /* conceptor <std::string> [] */
        if (conceptor && typeof conceptor === "object") conceptor = conceptor.ptr;
        else conceptor = ensureString(conceptor);
        _Schema__set_conceptor(self, conceptor);
    }
});
Object.defineProperty(Schema.prototype, "level", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_level(self);
    },
    set: function(level) {
        var self = this.ptr;
        /* level <uint8_t> [] */
        _Schema__set_level(self, level);
    }
});
Object.defineProperty(Schema.prototype, "cost", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_cost(self);
    },
    set: function(cost) {
        var self = this.ptr;
        /* cost <float> [] */
        _Schema__set_cost(self, cost);
    }
});
Object.defineProperty(Schema.prototype, "minerals", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_minerals(self);
    },
    set: function(minerals) {
        var self = this.ptr;
        /* minerals <float> [] */
        _Schema__set_minerals(self, minerals);
    }
});
Object.defineProperty(Schema.prototype, "andrium", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_andrium(self);
    },
    set: function(andrium) {
        var self = this.ptr;
        /* andrium <float> [] */
        _Schema__set_andrium(self, andrium);
    }
});
Object.defineProperty(Schema.prototype, "resistance", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_resistance(self);
    },
    set: function(resistance) {
        var self = this.ptr;
        /* resistance <float> [] */
        _Schema__set_resistance(self, resistance);
    }
});
Object.defineProperty(Schema.prototype, "speed", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_speed(self);
    },
    set: function(speed) {
        var self = this.ptr;
        /* speed <uint8_t> [] */
        _Schema__set_speed(self, speed);
    }
});
Object.defineProperty(Schema.prototype, "scan", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_scan(self);
    },
    set: function(scan) {
        var self = this.ptr;
        /* scan <uint8_t> [] */
        _Schema__set_scan(self, scan);
    }
});
Object.defineProperty(Schema.prototype, "planetary", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_planetary(self);
    },
    set: function(planetary) {
        var self = this.ptr;
        /* planetary <float> [] */
        _Schema__set_planetary(self, planetary);
    }
});
Object.defineProperty(Schema.prototype, "spatial", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Schema__get_spatial(self), SpatialPower);
    },
    set: function(spatial) {
        var self = this.ptr;
        /* spatial <SpatialPower> [] */
        spatial = spatial.ptr;
        _Schema__set_spatial(self, spatial);
    }
});
Object.defineProperty(Schema.prototype, "upkeep_factor", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_upkeep_factor(self);
    },
    set: function(upkeep_factor) {
        var self = this.ptr;
        /* upkeep_factor <float> [] */
        _Schema__set_upkeep_factor(self, upkeep_factor);
    }
});
Schema.prototype["__destroy__"] = Schema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Schema__destroy(self);
};
// SpatialPower
function SpatialPower() {
    var self = this.ptr;
    this.ptr = _SpatialPower_SpatialPower_0(self); getCache(SpatialPower)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _Split_Split_0(self); getCache(Split)[this.ptr] = this;
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
    set: function(source) {
        var self = this.ptr;
        /* source <Fleet> [] */
        source = source.ptr;
        _Split__set_source(self, source);
    }
});
Object.defineProperty(Split.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Split__get_dest(self), Fleet);
    },
    set: function(dest) {
        var self = this.ptr;
        /* dest <Fleet> [] */
        dest = dest.ptr;
        _Split__set_dest(self, dest);
    }
});
Object.defineProperty(Split.prototype, "code", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Split__get_code(self));
    },
    set: function(code) {
        var self = this.ptr;
        /* code <std::string> [] */
        if (code && typeof code === "object") code = code.ptr;
        else code = ensureString(code);
        _Split__set_code(self, code);
    }
});
Object.defineProperty(Split.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Split__get_stance(self);
    },
    set: function(stance) {
        var self = this.ptr;
        /* stance <FleetStance> [] */
        if (stance && typeof stance === "object") stance = stance.ptr;
        _Split__set_stance(self, stance);
    }
});
Split.prototype["__destroy__"] = Split.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Split__destroy(self);
};
// Star
function Star(spatial, galaxy, coord, name) {
    var self = this.ptr;
    ensureCache.prepare();
    /* spatial <toy::HSpatial> [] */
    /* galaxy <Galaxy> [] */
    galaxy = galaxy.ptr;
    /* coord <uvec2> [] */
    coord = coord.ptr;
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    if (spatial === undefined) { this.ptr = _Star_Star_0(self); getCache(Star)[this.ptr] = this; return; }
    this.ptr = _Star_Star_4(self, spatial, galaxy, coord, name); getCache(Star)[this.ptr] = this;
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
    set: function(galaxy) {
        var self = this.ptr;
        /* galaxy <Galaxy> [] */
        galaxy = galaxy.ptr;
        _Star__set_galaxy(self, galaxy);
    }
});
Object.defineProperty(Star.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Star__get_coord(self), mud::uvec2);
    },
    set: function(coord) {
        var self = this.ptr;
        /* coord <uvec2> [] */
        coord = coord.ptr;
        _Star__set_coord(self, coord);
    }
});
Object.defineProperty(Star.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Star__get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _Star__set_name(self, name);
    }
});
Object.defineProperty(Star.prototype, "stability", {
    get: function() {
        var self = this.ptr;
        return _Star__get_stability(self);
    },
    set: function(stability) {
        var self = this.ptr;
        /* stability <int> [] */
        _Star__set_stability(self, stability);
    }
});
Object.defineProperty(Star.prototype, "revolt", {
    get: function() {
        var self = this.ptr;
        return !!(_Star__get_revolt(self));
    },
    set: function(revolt) {
        var self = this.ptr;
        /* revolt <bool> [] */
        _Star__set_revolt(self, revolt);
    }
});
Object.defineProperty(Star.prototype, "environment", {
    get: function() {
        var self = this.ptr;
        return _Star__get_environment(self);
    },
    set: function(environment) {
        var self = this.ptr;
        /* environment <int> [] */
        _Star__set_environment(self, environment);
    }
});
Object.defineProperty(Star.prototype, "terraformation", {
    get: function() {
        var self = this.ptr;
        return _Star__get_terraformation(self);
    },
    set: function(terraformation) {
        var self = this.ptr;
        /* terraformation <int> [] */
        _Star__set_terraformation(self, terraformation);
    }
});
Object.defineProperty(Star.prototype, "base_population", {
    get: function() {
        var self = this.ptr;
        return _Star__get_base_population(self);
    },
    set: function(base_population) {
        var self = this.ptr;
        /* base_population <int> [] */
        _Star__set_base_population(self, base_population);
    }
});
Object.defineProperty(Star.prototype, "max_population", {
    get: function() {
        var self = this.ptr;
        return _Star__get_max_population(self);
    },
    set: function(max_population) {
        var self = this.ptr;
        /* max_population <int> [] */
        _Star__set_max_population(self, max_population);
    }
});
Object.defineProperty(Star.prototype, "population", {
    get: function() {
        var self = this.ptr;
        return _Star__get_population(self);
    },
    set: function(population) {
        var self = this.ptr;
        /* population <int> [] */
        _Star__set_population(self, population);
    }
});
Object.defineProperty(Star.prototype, "militia", {
    get: function() {
        var self = this.ptr;
        return _Star__get_militia(self);
    },
    set: function(militia) {
        var self = this.ptr;
        /* militia <float> [] */
        _Star__set_militia(self, militia);
    }
});
Object.defineProperty(Star.prototype, "defense", {
    get: function() {
        var self = this.ptr;
        return _Star__get_defense(self);
    },
    set: function(defense) {
        var self = this.ptr;
        /* defense <float> [] */
        _Star__set_defense(self, defense);
    }
});
Object.defineProperty(Star.prototype, "revenue", {
    get: function() {
        var self = this.ptr;
        return _Star__get_revenue(self);
    },
    set: function(revenue) {
        var self = this.ptr;
        /* revenue <float> [] */
        _Star__set_revenue(self, revenue);
    }
});
Object.defineProperty(Star.prototype, "politic", {
    get: function() {
        var self = this.ptr;
        return _Star__get_politic(self);
    },
    set: function(politic) {
        var self = this.ptr;
        /* politic <Politic> [] */
        if (politic && typeof politic === "object") politic = politic.ptr;
        _Star__set_politic(self, politic);
    }
});
Object.defineProperty(Star.prototype, "taxation", {
    get: function() {
        var self = this.ptr;
        return _Star__get_taxation(self);
    },
    set: function(taxation) {
        var self = this.ptr;
        /* taxation <Taxation> [] */
        if (taxation && typeof taxation === "object") taxation = taxation.ptr;
        _Star__set_taxation(self, taxation);
    }
});
Object.defineProperty(Star.prototype, "commander", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Star__get_commander(self), Commander);
    },
    set: function(commander) {
        var self = this.ptr;
        /* commander <Commander> [] */
        commander = commander.ptr;
        _Star__set_commander(self, commander);
    }
});
Object.defineProperty(Star.prototype, "scan", {
    get: function() {
        var self = this.ptr;
        return _Star__get_scan(self);
    },
    set: function(scan) {
        var self = this.ptr;
        /* scan <int> [] */
        _Star__set_scan(self, scan);
    }
});
Star.prototype["__destroy__"] = Star.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Star__destroy(self);
};
// TechDomain
function TechDomain() {
    var self = this.ptr;
    this.ptr = _TechDomain_TechDomain_0(self); getCache(TechDomain)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _Turn_Turn_0(self); getCache(Turn)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _BuildingSchema_BuildingSchema_0(self); getCache(BuildingSchema)[this.ptr] = this;
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
    set: function(commander) {
        var self = this.ptr;
        /* commander <Commander> [] */
        commander = commander.ptr;
        _CommanderBrush__set_commander(self, commander);
    }
});
Object.defineProperty(CommanderBrush.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _CommanderBrush__get_radius(self);
    },
    set: function(radius) {
        var self = this.ptr;
        /* radius <float> [] */
        _CommanderBrush__set_radius(self, radius);
    }
});
CommanderBrush.prototype["__destroy__"] = CommanderBrush.prototype.__destroy__ = function() {
    var self = this.ptr;
    _CommanderBrush__destroy(self);
};
// PlanetaryCombat
function PlanetaryCombat() {
    var self = this.ptr;
    this.ptr = _PlanetaryCombat_PlanetaryCombat_0(self); getCache(PlanetaryCombat)[this.ptr] = this;
};
PlanetaryCombat.prototype = Object.create(WrapperObject.prototype);
PlanetaryCombat.prototype.constructor = PlanetaryCombat;
PlanetaryCombat.prototype.__class__ = PlanetaryCombat;
PlanetaryCombat.__cache__ = {};
Module['PlanetaryCombat'] = PlanetaryCombat;
Object.defineProperty(PlanetaryCombat.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_PlanetaryCombat__get_coord(self), mud::uvec2);
    },
    set: function(coord) {
        var self = this.ptr;
        /* coord <uvec2> [] */
        coord = coord.ptr;
        _PlanetaryCombat__set_coord(self, coord);
    }
});
Object.defineProperty(PlanetaryCombat.prototype, "defense", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_PlanetaryCombat__get_defense(self), CombatStar);
    },
    set: function(defense) {
        var self = this.ptr;
        /* defense <CombatStar> [] */
        defense = defense.ptr;
        _PlanetaryCombat__set_defense(self, defense);
    }
});
PlanetaryCombat.prototype["__destroy__"] = PlanetaryCombat.prototype.__destroy__ = function() {
    var self = this.ptr;
    _PlanetaryCombat__destroy(self);
};
// ShipComponent
function ShipComponent() {
    var self = this.ptr;
    this.ptr = _ShipComponent_ShipComponent_0(self); getCache(ShipComponent)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _ShipEngine_ShipEngine_0(self); getCache(ShipEngine)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _ShipHull_ShipHull_0(self); getCache(ShipHull)[this.ptr] = this;
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
    var self = this.ptr;
    this.ptr = _ShipSchema_ShipSchema_0(self); getCache(ShipSchema)[this.ptr] = this;
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
    set: function(size) {
        var self = this.ptr;
        /* size <uint8_t> [] */
        _ShipSchema__set_size(self, size);
    }
});
Object.defineProperty(ShipSchema.prototype, "class", {
    get: function() {
        var self = this.ptr;
        return _ShipSchema__get_class(self);
    },
    set: function(class) {
        var self = this.ptr;
        /* class <uint8_t> [] */
        _ShipSchema__set_class(self, class);
    }
});
Object.defineProperty(ShipSchema.prototype, "main_weapon", {
    get: function() {
        var self = this.ptr;
        return _ShipSchema__get_main_weapon(self);
    },
    set: function(main_weapon) {
        var self = this.ptr;
        /* main_weapon <WeaponType> [] */
        if (main_weapon && typeof main_weapon === "object") main_weapon = main_weapon.ptr;
        _ShipSchema__set_main_weapon(self, main_weapon);
    }
});
ShipSchema.prototype["__destroy__"] = ShipSchema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _ShipSchema__destroy(self);
};
// SpatialCombat
function SpatialCombat() {
    var self = this.ptr;
    this.ptr = _SpatialCombat_SpatialCombat_0(self); getCache(SpatialCombat)[this.ptr] = this;
};
SpatialCombat.prototype = Object.create(WrapperObject.prototype);
SpatialCombat.prototype.constructor = SpatialCombat;
SpatialCombat.prototype.__class__ = SpatialCombat;
SpatialCombat.__cache__ = {};
Module['SpatialCombat'] = SpatialCombat;
Object.defineProperty(SpatialCombat.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_SpatialCombat__get_coord(self), mud::uvec2);
    },
    set: function(coord) {
        var self = this.ptr;
        /* coord <uvec2> [] */
        coord = coord.ptr;
        _SpatialCombat__set_coord(self, coord);
    }
});
SpatialCombat.prototype["__destroy__"] = SpatialCombat.prototype.__destroy__ = function() {
    var self = this.ptr;
    _SpatialCombat__destroy(self);
};
// Universe
function Universe(name, job_system) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _Universe_Universe_2(self, name, job_system); getCache(Universe)[this.ptr] = this;
};
Universe.prototype = Object.create(WrapperObject.prototype);
Universe.prototype.constructor = Universe;
Universe.prototype.__class__ = Universe;
Universe.__cache__ = {};
Module['Universe'] = Universe;
Object.defineProperty(Universe.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Universe__get_world(self), toy::World);
    }});
Object.defineProperty(Universe.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Universe__get_bullet_world(self), toy::BulletWorld);
    }});
Universe.prototype["__destroy__"] = Universe.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Universe__destroy(self);
};

(function() {
    function setupEnums() {
        // CombatType
        Module['CombatType']['Spatial'] = _CombatType_Spatial();
        Module['CombatType']['Planetary'] = _CombatType_Planetary();
        // Experience
        Module['Experience']['Inexperienced'] = _Experience_Inexperienced();
        Module['Experience']['LittleExperienced'] = _Experience_LittleExperienced();
        Module['Experience']['Experienced'] = _Experience_Experienced();
        Module['Experience']['Superior'] = _Experience_Superior();
        Module['Experience']['Elite'] = _Experience_Elite();
        // FleetSize
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
        Module['FleetStance']['Movement'] = _FleetStance_Movement();
        Module['FleetStance']['SpatialAttack'] = _FleetStance_SpatialAttack();
        Module['FleetStance']['SpatialDefense'] = _FleetStance_SpatialDefense();
        Module['FleetStance']['PlanetaryAttack'] = _FleetStance_PlanetaryAttack();
        Module['FleetStance']['PlanetaryDefense'] = _FleetStance_PlanetaryDefense();
        Module['FleetStance']['Pillage'] = _FleetStance_Pillage();
        // GameStage
        Module['GameStage']['Empire'] = _GameStage_Empire();
        Module['GameStage']['Tactics'] = _GameStage_Tactics();
        Module['GameStage']['TurnReport'] = _GameStage_TurnReport();
        // Politic
        Module['Politic']['Taxes'] = _Politic_Taxes();
        Module['Politic']['Commerce'] = _Politic_Commerce();
        Module['Politic']['Construction'] = _Politic_Construction();
        Module['Politic']['Defense'] = _Politic_Defense();
        Module['Politic']['Pacification'] = _Politic_Pacification();
        // Race
        Module['Race']['Human'] = _Race_Human();
        Module['Race']['Bulvoid'] = _Race_Bulvoid();
        Module['Race']['Techtulon'] = _Race_Techtulon();
        Module['Race']['Rakrarior'] = _Race_Rakrarior();
        Module['Race']['Seigneur'] = _Race_Seigneur();
        Module['Race']['Meton'] = _Race_Meton();
        Module['Race']['Tissinar'] = _Race_Tissinar();
        Module['Race']['Zwiie'] = _Race_Zwiie();
        // Regime
        Module['Regime']['Empire'] = _Regime_Empire();
        Module['Regime']['Dictature'] = _Regime_Dictature();
        Module['Regime']['Democracy'] = _Regime_Democracy();
        Module['Regime']['Theocracy'] = _Regime_Theocracy();
        Module['Regime']['Technocracy'] = _Regime_Technocracy();
        Module['Regime']['Piratery'] = _Regime_Piratery();
        // Resource
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
        Module['Taxation']['None'] = _Taxation_None();
        Module['Taxation']['Light'] = _Taxation_Light();
        Module['Taxation']['Medium'] = _Taxation_Medium();
        Module['Taxation']['Heavy'] = _Taxation_Heavy();
        Module['Taxation']['Heaviest'] = _Taxation_Heaviest();
        Module['Taxation']['Total'] = _Taxation_Total();
        // Technology
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
        Module['WeaponType']['None'] = _WeaponType_None();
        Module['WeaponType']['Ion'] = _WeaponType_Ion();
        Module['WeaponType']['Laser'] = _WeaponType_Laser();
        Module['WeaponType']['Plasma'] = _WeaponType_Plasma();
        Module['WeaponType']['Torpedo'] = _WeaponType_Torpedo();
        Module['WeaponType']['Bomb'] = _WeaponType_Bomb();
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
