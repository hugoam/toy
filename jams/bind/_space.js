Module['mud'] = Module['mud'] || {};
// Combat
function Combat() {
    this.ptr = _Combat__construct_0(); this.type = Combat; getCache(Combat)[this.ptr] = this;
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
    this.ptr = _CombatFleet__construct_0(); this.type = CombatFleet; getCache(CombatFleet)[this.ptr] = this;
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
    this.ptr = _CombatStar__construct_0(); this.type = CombatStar; getCache(CombatStar)[this.ptr] = this;
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
function Commander(a0, a1, a2, a3, a4, a5) {
    ensureCache.prepare();
    this.ptr = _Commander__construct_6(/*id*/a0, ensureString(/*name*/a1), /*race*/a2, /*command*/a3, /*commerce*/a4, /*diplomacy*/a5); this.type = Commander; getCache(Commander)[this.ptr] = this;
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
        _Commander__set_name(self, ensureString(value));
    }
});
Object.defineProperty(Commander.prototype, "race", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_race(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Commander__set_capital(self, value.ptr);
    }
});
Object.defineProperty(Commander.prototype, "regime", {
    get: function() {
        var self = this.ptr;
        return _Commander__get_regime(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Commander__set_scans(self, value.ptr);
    }
});
Commander.prototype["__destroy__"] = Commander.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Commander__destroy(self);
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
        _CommanderBrush__set_commander(self, value.ptr);
    }
});
Object.defineProperty(CommanderBrush.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _CommanderBrush__get_radius(self);
    },
    set: function(value) {
        var self = this.ptr;
        _CommanderBrush__set_radius(self, value);
    }
});
CommanderBrush.prototype["__destroy__"] = CommanderBrush.prototype.__destroy__ = function() {
    var self = this.ptr;
    _CommanderBrush__destroy(self);
};
// ComponentHandle<Fleet>
function ComponentHandle_Fleet() {
    this.ptr = _mud_ComponentHandle_Fleet__construct_0(); this.type = ComponentHandle_Fleet; getCache(ComponentHandle_Fleet)[this.ptr] = this;
};
ComponentHandle_Fleet.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Fleet.prototype.constructor = ComponentHandle_Fleet;
ComponentHandle_Fleet.prototype.__class__ = ComponentHandle_Fleet;
ComponentHandle_Fleet.__cache__ = {};
Module['mud']['ComponentHandle_Fleet'] = ComponentHandle_Fleet;
ComponentHandle_Fleet.prototype["__destroy__"] = ComponentHandle_Fleet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Fleet__destroy(self);
};
// ComponentHandle<Galaxy>
function ComponentHandle_Galaxy() {
    this.ptr = _mud_ComponentHandle_Galaxy__construct_0(); this.type = ComponentHandle_Galaxy; getCache(ComponentHandle_Galaxy)[this.ptr] = this;
};
ComponentHandle_Galaxy.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Galaxy.prototype.constructor = ComponentHandle_Galaxy;
ComponentHandle_Galaxy.prototype.__class__ = ComponentHandle_Galaxy;
ComponentHandle_Galaxy.__cache__ = {};
Module['mud']['ComponentHandle_Galaxy'] = ComponentHandle_Galaxy;
ComponentHandle_Galaxy.prototype["__destroy__"] = ComponentHandle_Galaxy.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Galaxy__destroy(self);
};
// ComponentHandle<Star>
function ComponentHandle_Star() {
    this.ptr = _mud_ComponentHandle_Star__construct_0(); this.type = ComponentHandle_Star; getCache(ComponentHandle_Star)[this.ptr] = this;
};
ComponentHandle_Star.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Star.prototype.constructor = ComponentHandle_Star;
ComponentHandle_Star.prototype.__class__ = ComponentHandle_Star;
ComponentHandle_Star.__cache__ = {};
Module['mud']['ComponentHandle_Star'] = ComponentHandle_Star;
ComponentHandle_Star.prototype["__destroy__"] = ComponentHandle_Star.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_Star__destroy(self);
};
// Construction
function Construction() {
    this.ptr = _Construction__construct_0(); this.type = Construction; getCache(Construction)[this.ptr] = this;
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
function Fleet(a0, a1, a2, a3, a4) {
    ensureCache.prepare();
    if (a0 === undefined) { this.ptr = _Fleet__construct_0(); this.type = Fleet; getCache(Fleet)[this.ptr] = this; return; }
    this.ptr = _Fleet__construct_5(/*spatial*/a0.ptr, /*galaxy*/a1.ptr, /*commander*/a2.ptr, /*coord*/a3.ptr, ensureString(/*name*/a4)); this.type = Fleet; getCache(Fleet)[this.ptr] = this;
};
Fleet.prototype = Object.create(WrapperObject.prototype);
Fleet.prototype.constructor = Fleet;
Fleet.prototype.__class__ = Fleet;
Fleet.__cache__ = {};
Module['Fleet'] = Fleet;
Fleet.prototype["order_jump"] = Fleet.prototype.order_jump = function(a0, a1) {
    var self = this.ptr;
    _Fleet_order_jump_2(self, /*coord*/a0.ptr, /*stance*/a1);
};
Fleet.prototype["order_attack"] = Fleet.prototype.order_attack = function(a0) {
    var self = this.ptr;
    _Fleet_order_attack_1(self, /*star*/a0.ptr);
};
Object.defineProperty(Fleet.prototype, "galaxy", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_galaxy(self), Galaxy);
    },
    set: function(value) {
        var self = this.ptr;
        _Fleet__set_galaxy(self, value.ptr);
    }
});
Object.defineProperty(Fleet.prototype, "commander", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_commander(self), Commander);
    },
    set: function(value) {
        var self = this.ptr;
        _Fleet__set_commander(self, value.ptr);
    }
});
Object.defineProperty(Fleet.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_coord(self), v2_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _Fleet__set_coord(self, value.ptr);
    }
});
Object.defineProperty(Fleet.prototype, "slot", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_slot(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _Fleet__set_slot(self, value.ptr);
    }
});
Object.defineProperty(Fleet.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Fleet__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Fleet__set_name(self, ensureString(value));
    }
});
Object.defineProperty(Fleet.prototype, "experience", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_experience(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Fleet__set_spatial_power(self, value.ptr);
    }
});
Object.defineProperty(Fleet.prototype, "planetary_power", {
    get: function() {
        var self = this.ptr;
        return _Fleet__get_planetary_power(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Fleet__set_jump(self, value.ptr);
    }
});
Object.defineProperty(Fleet.prototype, "split", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Fleet__get_split(self), Split);
    },
    set: function(value) {
        var self = this.ptr;
        _Fleet__set_split(self, value.ptr);
    }
});
Object.defineProperty(Fleet.prototype, "fought", {
    get: function() {
        var self = this.ptr;
        return !!(_Fleet__get_fought(self));
    },
    set: function(value) {
        var self = this.ptr;
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
        _Fleet__set_ships_updated(self, value);
    }
});
Fleet.prototype["__destroy__"] = Fleet.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Fleet__destroy(self);
};
// Galaxy
function Galaxy(a0, a1) {
    if (a0 === undefined) { this.ptr = _Galaxy__construct_0(); this.type = Galaxy; getCache(Galaxy)[this.ptr] = this; return; }
    this.ptr = _Galaxy__construct_2(/*spatial*/a0.ptr, /*size*/a1.ptr); this.type = Galaxy; getCache(Galaxy)[this.ptr] = this;
};
Galaxy.prototype = Object.create(WrapperObject.prototype);
Galaxy.prototype.constructor = Galaxy;
Galaxy.prototype.__class__ = Galaxy;
Galaxy.__cache__ = {};
Module['Galaxy'] = Galaxy;
Object.defineProperty(Galaxy.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Galaxy__get_size(self), v2_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _Galaxy__set_size(self, value.ptr);
    }
});
Galaxy.prototype["__destroy__"] = Galaxy.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Galaxy__destroy(self);
};
// Jump
function Jump() {
    this.ptr = _Jump__construct_0(); this.type = Jump; getCache(Jump)[this.ptr] = this;
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
        _Jump__set_fleet(self, value.ptr);
    }
});
Object.defineProperty(Jump.prototype, "start", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_start(self), v2_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _Jump__set_start(self, value.ptr);
    }
});
Object.defineProperty(Jump.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Jump__get_dest(self), v2_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _Jump__set_dest(self, value.ptr);
    }
});
Object.defineProperty(Jump.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Jump__get_stance(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Jump__set_track(self, value.ptr);
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
    this.ptr = _Scans__construct_0(); this.type = Scans; getCache(Scans)[this.ptr] = this;
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
    this.ptr = _Schema__construct_0(); this.type = Schema; getCache(Schema)[this.ptr] = this;
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
        _Schema__set_code(self, ensureString(value));
    }
});
Object.defineProperty(Schema.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Schema__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Schema__set_name(self, ensureString(value));
    }
});
Object.defineProperty(Schema.prototype, "conceptor", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Schema__get_conceptor(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Schema__set_conceptor(self, ensureString(value));
    }
});
Object.defineProperty(Schema.prototype, "level", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_level(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Schema__set_spatial(self, value.ptr);
    }
});
Object.defineProperty(Schema.prototype, "upkeep_factor", {
    get: function() {
        var self = this.ptr;
        return _Schema__get_upkeep_factor(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Schema__set_upkeep_factor(self, value);
    }
});
Schema.prototype["__destroy__"] = Schema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Schema__destroy(self);
};
// SpatialPower
function SpatialPower() {
    this.ptr = _SpatialPower__construct_0(); this.type = SpatialPower; getCache(SpatialPower)[this.ptr] = this;
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
    this.ptr = _Split__construct_0(); this.type = Split; getCache(Split)[this.ptr] = this;
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
        _Split__set_source(self, value.ptr);
    }
});
Object.defineProperty(Split.prototype, "dest", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Split__get_dest(self), Fleet);
    },
    set: function(value) {
        var self = this.ptr;
        _Split__set_dest(self, value.ptr);
    }
});
Object.defineProperty(Split.prototype, "code", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Split__get_code(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Split__set_code(self, ensureString(value));
    }
});
Object.defineProperty(Split.prototype, "stance", {
    get: function() {
        var self = this.ptr;
        return _Split__get_stance(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Split__set_stance(self, value);
    }
});
Split.prototype["__destroy__"] = Split.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Split__destroy(self);
};
// Star
function Star(a0, a1, a2, a3) {
    ensureCache.prepare();
    if (a0 === undefined) { this.ptr = _Star__construct_0(); this.type = Star; getCache(Star)[this.ptr] = this; return; }
    this.ptr = _Star__construct_4(/*spatial*/a0.ptr, /*galaxy*/a1.ptr, /*coord*/a2.ptr, ensureString(/*name*/a3)); this.type = Star; getCache(Star)[this.ptr] = this;
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
        _Star__set_galaxy(self, value.ptr);
    }
});
Object.defineProperty(Star.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_Star__get_coord(self), v2_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _Star__set_coord(self, value.ptr);
    }
});
Object.defineProperty(Star.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Star__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        _Star__set_name(self, ensureString(value));
    }
});
Object.defineProperty(Star.prototype, "stability", {
    get: function() {
        var self = this.ptr;
        return _Star__get_stability(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Star__set_revolt(self, value);
    }
});
Object.defineProperty(Star.prototype, "env", {
    get: function() {
        var self = this.ptr;
        return _Star__get_env(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Star__set_env(self, value);
    }
});
Object.defineProperty(Star.prototype, "terraformation", {
    get: function() {
        var self = this.ptr;
        return _Star__get_terraformation(self);
    },
    set: function(value) {
        var self = this.ptr;
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
        _Star__set_commander(self, value.ptr);
    }
});
Object.defineProperty(Star.prototype, "scan", {
    get: function() {
        var self = this.ptr;
        return _Star__get_scan(self);
    },
    set: function(value) {
        var self = this.ptr;
        _Star__set_scan(self, value);
    }
});
Star.prototype["__destroy__"] = Star.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Star__destroy(self);
};
// TechDomain
function TechDomain() {
    this.ptr = _TechDomain__construct_0(); this.type = TechDomain; getCache(TechDomain)[this.ptr] = this;
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
    this.ptr = _Turn__construct_0(); this.type = Turn; getCache(Turn)[this.ptr] = this;
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
// Universe
function Universe(a0, a1) {
    ensureCache.prepare();
    this.ptr = _Universe__construct_2(ensureString(/*name*/a0), /*job_system*/a1.ptr); this.type = Universe; getCache(Universe)[this.ptr] = this;
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
// BuildingSchema
function BuildingSchema() {
    this.ptr = _BuildingSchema__construct_0(); this.type = BuildingSchema; getCache(BuildingSchema)[this.ptr] = this;
};
BuildingSchema.prototype = Object.create(Schema.prototype);
BuildingSchema.prototype.constructor = BuildingSchema;
BuildingSchema.prototype.__class__ = BuildingSchema;
BuildingSchema.__cache__ = {};
Module['BuildingSchema'] = BuildingSchema;
BuildingSchema.prototype["__destroy__"] = BuildingSchema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _BuildingSchema__destroy(self);
};
// PlanetaryCombat
function PlanetaryCombat() {
    this.ptr = _PlanetaryCombat__construct_0(); this.type = PlanetaryCombat; getCache(PlanetaryCombat)[this.ptr] = this;
};
PlanetaryCombat.prototype = Object.create(Combat.prototype);
PlanetaryCombat.prototype.constructor = PlanetaryCombat;
PlanetaryCombat.prototype.__class__ = PlanetaryCombat;
PlanetaryCombat.__cache__ = {};
Module['PlanetaryCombat'] = PlanetaryCombat;
Object.defineProperty(PlanetaryCombat.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_PlanetaryCombat__get_coord(self), v2_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _PlanetaryCombat__set_coord(self, value.ptr);
    }
});
Object.defineProperty(PlanetaryCombat.prototype, "defense", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_PlanetaryCombat__get_defense(self), CombatStar);
    },
    set: function(value) {
        var self = this.ptr;
        _PlanetaryCombat__set_defense(self, value.ptr);
    }
});
PlanetaryCombat.prototype["__destroy__"] = PlanetaryCombat.prototype.__destroy__ = function() {
    var self = this.ptr;
    _PlanetaryCombat__destroy(self);
};
// ShipComponent
function ShipComponent() {
    this.ptr = _ShipComponent__construct_0(); this.type = ShipComponent; getCache(ShipComponent)[this.ptr] = this;
};
ShipComponent.prototype = Object.create(Schema.prototype);
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
    this.ptr = _ShipEngine__construct_0(); this.type = ShipEngine; getCache(ShipEngine)[this.ptr] = this;
};
ShipEngine.prototype = Object.create(Schema.prototype);
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
    this.ptr = _ShipHull__construct_0(); this.type = ShipHull; getCache(ShipHull)[this.ptr] = this;
};
ShipHull.prototype = Object.create(Schema.prototype);
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
    this.ptr = _ShipSchema__construct_0(); this.type = ShipSchema; getCache(ShipSchema)[this.ptr] = this;
};
ShipSchema.prototype = Object.create(Schema.prototype);
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
        _ShipSchema__set_main_weapon(self, value);
    }
});
ShipSchema.prototype["__destroy__"] = ShipSchema.prototype.__destroy__ = function() {
    var self = this.ptr;
    _ShipSchema__destroy(self);
};
// SpatialCombat
function SpatialCombat() {
    this.ptr = _SpatialCombat__construct_0(); this.type = SpatialCombat; getCache(SpatialCombat)[this.ptr] = this;
};
SpatialCombat.prototype = Object.create(Combat.prototype);
SpatialCombat.prototype.constructor = SpatialCombat;
SpatialCombat.prototype.__class__ = SpatialCombat;
SpatialCombat.__cache__ = {};
Module['SpatialCombat'] = SpatialCombat;
Object.defineProperty(SpatialCombat.prototype, "coord", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_SpatialCombat__get_coord(self), v2_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _SpatialCombat__set_coord(self, value.ptr);
    }
});
SpatialCombat.prototype["__destroy__"] = SpatialCombat.prototype.__destroy__ = function() {
    var self = this.ptr;
    _SpatialCombat__destroy(self);
};
Module['generate_system'] = function(a0, a1, a2) {
    return wrapPointer(_generate_system_3(/*galaxy*/a0.ptr, /*coord*/a1.ptr, /*position*/a2.ptr), ComponentHandle_Star);
};
Module['generate_fleet'] = function(a0, a1, a2) {
    return wrapPointer(_generate_fleet_3(/*galaxy*/a0.ptr, /*coord*/a1.ptr, /*position*/a2.ptr), ComponentHandle_Fleet);
};
Module['generate_commander'] = function(a0, a1) {
    return wrapPointer(_generate_commander_2(/*galaxy*/a0.ptr, /*star*/a1.ptr), Commander);
};
Module['HGalaxy'] = ComponentHandle_Galaxy;
Module['HStar'] = ComponentHandle_Star;
Module['HFleet'] = ComponentHandle_Fleet;

(function() {
    function setup() {
        Combat.__type__ = _Combat__type();
        CombatFleet.__type__ = _CombatFleet__type();
        CombatStar.__type__ = _CombatStar__type();
        Commander.__type__ = _Commander__type();
        CommanderBrush.__type__ = _CommanderBrush__type();
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
        Universe.__type__ = _Universe__type();
        BuildingSchema.__type__ = _BuildingSchema__type();
        PlanetaryCombat.__type__ = _PlanetaryCombat__type();
        ShipComponent.__type__ = _ShipComponent__type();
        ShipEngine.__type__ = _ShipEngine__type();
        ShipHull.__type__ = _ShipHull__type();
        ShipSchema.__type__ = _ShipSchema__type();
        SpatialCombat.__type__ = _SpatialCombat__type();
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
        Module['Race']['Count'] = _Race_Count();
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
        Module['WeaponType']['Count'] = _WeaponType_Count();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
