Module['two'] = Module['two'] || {};
// ComponentHandle<Galaxy>
function ComponentHandle_Galaxy() {
    
    this.__ptr = _two_ComponentHandle_Galaxy__construct_0(); getCache(ComponentHandle_Galaxy)[this.__ptr] = this;
};
ComponentHandle_Galaxy.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Galaxy.prototype.constructor = ComponentHandle_Galaxy;
ComponentHandle_Galaxy.prototype.__class = ComponentHandle_Galaxy;
ComponentHandle_Galaxy.__cache = {};
Module['two']['ComponentHandle_Galaxy'] = ComponentHandle_Galaxy;
ComponentHandle_Galaxy.prototype["__destroy"] = ComponentHandle_Galaxy.prototype.__destroy = function() {
    _two_ComponentHandle_Galaxy__destroy(this.__ptr);
};
// ComponentHandle<Star>
function ComponentHandle_Star() {
    
    this.__ptr = _two_ComponentHandle_Star__construct_0(); getCache(ComponentHandle_Star)[this.__ptr] = this;
};
ComponentHandle_Star.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Star.prototype.constructor = ComponentHandle_Star;
ComponentHandle_Star.prototype.__class = ComponentHandle_Star;
ComponentHandle_Star.__cache = {};
Module['two']['ComponentHandle_Star'] = ComponentHandle_Star;
ComponentHandle_Star.prototype["__destroy"] = ComponentHandle_Star.prototype.__destroy = function() {
    _two_ComponentHandle_Star__destroy(this.__ptr);
};
// ComponentHandle<Fleet>
function ComponentHandle_Fleet() {
    
    this.__ptr = _two_ComponentHandle_Fleet__construct_0(); getCache(ComponentHandle_Fleet)[this.__ptr] = this;
};
ComponentHandle_Fleet.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_Fleet.prototype.constructor = ComponentHandle_Fleet;
ComponentHandle_Fleet.prototype.__class = ComponentHandle_Fleet;
ComponentHandle_Fleet.__cache = {};
Module['two']['ComponentHandle_Fleet'] = ComponentHandle_Fleet;
ComponentHandle_Fleet.prototype["__destroy"] = ComponentHandle_Fleet.prototype.__destroy = function() {
    _two_ComponentHandle_Fleet__destroy(this.__ptr);
};
// Turn
function Turn() {
    
    this.__ptr = _Turn__construct_0(); getCache(Turn)[this.__ptr] = this;
};
Turn.prototype = Object.create(WrapperObject.prototype);
Turn.prototype.constructor = Turn;
Turn.prototype.__class = Turn;
Turn.__cache = {};
Module['Turn'] = Turn;
Turn.prototype["__destroy"] = Turn.prototype.__destroy = function() {
    _Turn__destroy(this.__ptr);
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
// SpatialPower
function SpatialPower() {
    
    this.__ptr = _SpatialPower__construct_0(); getCache(SpatialPower)[this.__ptr] = this;
};
SpatialPower.prototype = Object.create(WrapperObject.prototype);
SpatialPower.prototype.constructor = SpatialPower;
SpatialPower.prototype.__class = SpatialPower;
SpatialPower.__cache = {};
Module['SpatialPower'] = SpatialPower;
SpatialPower.prototype["__destroy"] = SpatialPower.prototype.__destroy = function() {
    _SpatialPower__destroy(this.__ptr);
};
// Construction
function Construction() {
    
    this.__ptr = _Construction__construct_0(); getCache(Construction)[this.__ptr] = this;
};
Construction.prototype = Object.create(WrapperObject.prototype);
Construction.prototype.constructor = Construction;
Construction.prototype.__class = Construction;
Construction.__cache = {};
Module['Construction'] = Construction;
Construction.prototype["__destroy"] = Construction.prototype.__destroy = function() {
    _Construction__destroy(this.__ptr);
};
// Star
function Star(a0, a1, a2, a3) {
    ensureCache.prepare();
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Star(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, Galaxy)) throw Error('Star(1:galaxy): expected Galaxy'); if (!checkClass(a2, v2_uint)) throw Error('Star(2:coord): expected v2<uint>'); if (typeof a3 !== 'string') throw Error('Star(3:name): expected string'); }
    if (a0 === undefined) { this.__ptr = _Star__construct_0(); getCache(Star)[this.__ptr] = this; }
    else { this.__ptr = _Star__construct_4(/*spatial*/a0.__ptr, /*galaxy*/a1.__ptr, /*coord*/a2.__ptr, ensureString(/*name*/a3)); getCache(Star)[this.__ptr] = this; }
};
Star.prototype = Object.create(WrapperObject.prototype);
Star.prototype.constructor = Star;
Star.prototype.__class = Star;
Star.__cache = {};
Module['Star'] = Star;
Object.defineProperty(Star.prototype, "galaxy", {
    get: function() {
        return wrapPointer(_Star__get_galaxy(this.__ptr), Galaxy);
    },
    set: function(value) {
        if (!checkClass(value, Galaxy)) throw Error('Star.galaxy: expected Galaxy');
        _Star__set_galaxy(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Star.prototype, "coord", {
    get: function() {
        return wrapPointer(_Star__get_coord(this.__ptr), v2_uint);
    },
    set: function(value) {
        if (!checkClass(value, v2_uint)) throw Error('Star.coord: expected v2<uint>');
        _Star__set_coord(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Star.prototype, "name", {
    get: function() {
        return UTF8ToString(_Star__get_name(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Star.name: expected string');
        _Star__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Star.prototype, "stability", {
    get: function() {
        return _Star__get_stability(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.stability: expected integer');
        _Star__set_stability(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "revolt", {
    get: function() {
        return !!(_Star__get_revolt(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Star.revolt: expected boolean');
        _Star__set_revolt(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "env", {
    get: function() {
        return _Star__get_env(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.env: expected integer');
        _Star__set_env(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "terraformation", {
    get: function() {
        return _Star__get_terraformation(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.terraformation: expected integer');
        _Star__set_terraformation(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "base_population", {
    get: function() {
        return _Star__get_base_population(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.base_population: expected integer');
        _Star__set_base_population(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "max_population", {
    get: function() {
        return _Star__get_max_population(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.max_population: expected integer');
        _Star__set_max_population(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "population", {
    get: function() {
        return _Star__get_population(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.population: expected integer');
        _Star__set_population(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "militia", {
    get: function() {
        return _Star__get_militia(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.militia: expected number');
        _Star__set_militia(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "defense", {
    get: function() {
        return _Star__get_defense(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.defense: expected number');
        _Star__set_defense(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "revenue", {
    get: function() {
        return _Star__get_revenue(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.revenue: expected number');
        _Star__set_revenue(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "politic", {
    get: function() {
        return _Star__get_politic(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.politic: expected integer');
        _Star__set_politic(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "taxation", {
    get: function() {
        return _Star__get_taxation(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.taxation: expected integer');
        _Star__set_taxation(this.__ptr, value);
    }
});
Object.defineProperty(Star.prototype, "commander", {
    get: function() {
        return wrapPointer(_Star__get_commander(this.__ptr), Commander);
    },
    set: function(value) {
        if (!checkClass(value, Commander)) throw Error('Star.commander: expected Commander');
        _Star__set_commander(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Star.prototype, "scan", {
    get: function() {
        return _Star__get_scan(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Star.scan: expected integer');
        _Star__set_scan(this.__ptr, value);
    }
});
Star.prototype["__destroy"] = Star.prototype.__destroy = function() {
    _Star__destroy(this.__ptr);
};
// Jump
function Jump() {
    
    this.__ptr = _Jump__construct_0(); getCache(Jump)[this.__ptr] = this;
};
Jump.prototype = Object.create(WrapperObject.prototype);
Jump.prototype.constructor = Jump;
Jump.prototype.__class = Jump;
Jump.__cache = {};
Module['Jump'] = Jump;
Object.defineProperty(Jump.prototype, "fleet", {
    get: function() {
        return wrapPointer(_Jump__get_fleet(this.__ptr), Fleet);
    },
    set: function(value) {
        if (!checkClass(value, Fleet)) throw Error('Jump.fleet: expected Fleet');
        _Jump__set_fleet(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Jump.prototype, "start", {
    get: function() {
        return wrapPointer(_Jump__get_start(this.__ptr), v2_uint);
    },
    set: function(value) {
        if (!checkClass(value, v2_uint)) throw Error('Jump.start: expected v2<uint>');
        _Jump__set_start(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Jump.prototype, "dest", {
    get: function() {
        return wrapPointer(_Jump__get_dest(this.__ptr), v2_uint);
    },
    set: function(value) {
        if (!checkClass(value, v2_uint)) throw Error('Jump.dest: expected v2<uint>');
        _Jump__set_dest(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Jump.prototype, "stance", {
    get: function() {
        return _Jump__get_stance(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Jump.stance: expected integer');
        _Jump__set_stance(this.__ptr, value);
    }
});
Object.defineProperty(Jump.prototype, "track", {
    get: function() {
        return wrapPointer(_Jump__get_track(this.__ptr), Fleet);
    },
    set: function(value) {
        if (!checkClass(value, Fleet)) throw Error('Jump.track: expected Fleet');
        _Jump__set_track(this.__ptr, value.__ptr);
    }
});
Jump.prototype["__destroy"] = Jump.prototype.__destroy = function() {
    _Jump__destroy(this.__ptr);
};
// Split
function Split() {
    
    this.__ptr = _Split__construct_0(); getCache(Split)[this.__ptr] = this;
};
Split.prototype = Object.create(WrapperObject.prototype);
Split.prototype.constructor = Split;
Split.prototype.__class = Split;
Split.__cache = {};
Module['Split'] = Split;
Object.defineProperty(Split.prototype, "source", {
    get: function() {
        return wrapPointer(_Split__get_source(this.__ptr), Fleet);
    },
    set: function(value) {
        if (!checkClass(value, Fleet)) throw Error('Split.source: expected Fleet');
        _Split__set_source(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Split.prototype, "dest", {
    get: function() {
        return wrapPointer(_Split__get_dest(this.__ptr), Fleet);
    },
    set: function(value) {
        if (!checkClass(value, Fleet)) throw Error('Split.dest: expected Fleet');
        _Split__set_dest(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Split.prototype, "code", {
    get: function() {
        return UTF8ToString(_Split__get_code(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Split.code: expected string');
        _Split__set_code(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Split.prototype, "stance", {
    get: function() {
        return _Split__get_stance(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Split.stance: expected integer');
        _Split__set_stance(this.__ptr, value);
    }
});
Split.prototype["__destroy"] = Split.prototype.__destroy = function() {
    _Split__destroy(this.__ptr);
};
// Fleet
function Fleet(a0, a1, a2, a3, a4) {
    ensureCache.prepare();
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Fleet(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, Galaxy)) throw Error('Fleet(1:galaxy): expected Galaxy'); if (!checkClass(a2, Commander)) throw Error('Fleet(2:commander): expected Commander'); if (!checkClass(a3, v2_uint)) throw Error('Fleet(3:coord): expected v2<uint>'); if (typeof a4 !== 'string') throw Error('Fleet(4:name): expected string'); }
    if (a0 === undefined) { this.__ptr = _Fleet__construct_0(); getCache(Fleet)[this.__ptr] = this; }
    else { this.__ptr = _Fleet__construct_5(/*spatial*/a0.__ptr, /*galaxy*/a1.__ptr, /*commander*/a2.__ptr, /*coord*/a3.__ptr, ensureString(/*name*/a4)); getCache(Fleet)[this.__ptr] = this; }
};
Fleet.prototype = Object.create(WrapperObject.prototype);
Fleet.prototype.constructor = Fleet;
Fleet.prototype.__class = Fleet;
Fleet.__cache = {};
Module['Fleet'] = Fleet;
Fleet.prototype["order_jump"] = Fleet.prototype.order_jump = function(a0, a1) {
    if (!checkClass(a0, v2_uint)) throw Error('order_jump(0:coord): expected v2<uint>'); if (typeof a1 !== 'number') throw Error('order_jump(1:stance): expected integer');
    _Fleet_order_jump_2(this.__ptr, /*coord*/a0.__ptr, /*stance*/a1);
};
Fleet.prototype["order_attack"] = Fleet.prototype.order_attack = function(a0) {
    if (!checkClass(a0, Star)) throw Error('order_attack(0:star): expected Star');
    _Fleet_order_attack_1(this.__ptr, /*star*/a0.__ptr);
};
Object.defineProperty(Fleet.prototype, "galaxy", {
    get: function() {
        return wrapPointer(_Fleet__get_galaxy(this.__ptr), Galaxy);
    },
    set: function(value) {
        if (!checkClass(value, Galaxy)) throw Error('Fleet.galaxy: expected Galaxy');
        _Fleet__set_galaxy(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Fleet.prototype, "commander", {
    get: function() {
        return wrapPointer(_Fleet__get_commander(this.__ptr), Commander);
    },
    set: function(value) {
        if (!checkClass(value, Commander)) throw Error('Fleet.commander: expected Commander');
        _Fleet__set_commander(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Fleet.prototype, "coord", {
    get: function() {
        return wrapPointer(_Fleet__get_coord(this.__ptr), v2_uint);
    },
    set: function(value) {
        if (!checkClass(value, v2_uint)) throw Error('Fleet.coord: expected v2<uint>');
        _Fleet__set_coord(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Fleet.prototype, "slot", {
    get: function() {
        return wrapPointer(_Fleet__get_slot(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Fleet.slot: expected v3<float>');
        _Fleet__set_slot(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Fleet.prototype, "name", {
    get: function() {
        return UTF8ToString(_Fleet__get_name(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Fleet.name: expected string');
        _Fleet__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Fleet.prototype, "experience", {
    get: function() {
        return _Fleet__get_experience(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Fleet.experience: expected number');
        _Fleet__set_experience(this.__ptr, value);
    }
});
Object.defineProperty(Fleet.prototype, "spatial_power", {
    get: function() {
        return wrapPointer(_Fleet__get_spatial_power(this.__ptr), SpatialPower);
    },
    set: function(value) {
        if (!checkClass(value, SpatialPower)) throw Error('Fleet.spatial_power: expected SpatialPower');
        _Fleet__set_spatial_power(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Fleet.prototype, "planetary_power", {
    get: function() {
        return _Fleet__get_planetary_power(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Fleet.planetary_power: expected number');
        _Fleet__set_planetary_power(this.__ptr, value);
    }
});
Object.defineProperty(Fleet.prototype, "speed", {
    get: function() {
        return _Fleet__get_speed(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Fleet.speed: expected integer');
        _Fleet__set_speed(this.__ptr, value);
    }
});
Object.defineProperty(Fleet.prototype, "scan", {
    get: function() {
        return _Fleet__get_scan(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Fleet.scan: expected integer');
        _Fleet__set_scan(this.__ptr, value);
    }
});
Object.defineProperty(Fleet.prototype, "upkeep", {
    get: function() {
        return _Fleet__get_upkeep(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Fleet.upkeep: expected number');
        _Fleet__set_upkeep(this.__ptr, value);
    }
});
Object.defineProperty(Fleet.prototype, "stance", {
    get: function() {
        return _Fleet__get_stance(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Fleet.stance: expected integer');
        _Fleet__set_stance(this.__ptr, value);
    }
});
Object.defineProperty(Fleet.prototype, "jump", {
    get: function() {
        return wrapPointer(_Fleet__get_jump(this.__ptr), Jump);
    },
    set: function(value) {
        if (!checkClass(value, Jump)) throw Error('Fleet.jump: expected Jump');
        _Fleet__set_jump(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Fleet.prototype, "split", {
    get: function() {
        return wrapPointer(_Fleet__get_split(this.__ptr), Split);
    },
    set: function(value) {
        if (!checkClass(value, Split)) throw Error('Fleet.split: expected Split');
        _Fleet__set_split(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Fleet.prototype, "fought", {
    get: function() {
        return !!(_Fleet__get_fought(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Fleet.fought: expected boolean');
        _Fleet__set_fought(this.__ptr, value);
    }
});
Object.defineProperty(Fleet.prototype, "ships_updated", {
    get: function() {
        return _Fleet__get_ships_updated(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Fleet.ships_updated: expected integer');
        _Fleet__set_ships_updated(this.__ptr, value);
    }
});
Fleet.prototype["__destroy"] = Fleet.prototype.__destroy = function() {
    _Fleet__destroy(this.__ptr);
};
// Schema
function Schema() {
    
    this.__ptr = _Schema__construct_0(); getCache(Schema)[this.__ptr] = this;
};
Schema.prototype = Object.create(WrapperObject.prototype);
Schema.prototype.constructor = Schema;
Schema.prototype.__class = Schema;
Schema.__cache = {};
Module['Schema'] = Schema;
Object.defineProperty(Schema.prototype, "code", {
    get: function() {
        return UTF8ToString(_Schema__get_code(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Schema.code: expected string');
        _Schema__set_code(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Schema.prototype, "name", {
    get: function() {
        return UTF8ToString(_Schema__get_name(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Schema.name: expected string');
        _Schema__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Schema.prototype, "conceptor", {
    get: function() {
        return UTF8ToString(_Schema__get_conceptor(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Schema.conceptor: expected string');
        _Schema__set_conceptor(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Schema.prototype, "level", {
    get: function() {
        return _Schema__get_level(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.level: expected integer');
        _Schema__set_level(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "cost", {
    get: function() {
        return _Schema__get_cost(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.cost: expected number');
        _Schema__set_cost(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "minerals", {
    get: function() {
        return _Schema__get_minerals(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.minerals: expected number');
        _Schema__set_minerals(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "andrium", {
    get: function() {
        return _Schema__get_andrium(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.andrium: expected number');
        _Schema__set_andrium(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "resistance", {
    get: function() {
        return _Schema__get_resistance(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.resistance: expected number');
        _Schema__set_resistance(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "speed", {
    get: function() {
        return _Schema__get_speed(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.speed: expected integer');
        _Schema__set_speed(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "scan", {
    get: function() {
        return _Schema__get_scan(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.scan: expected integer');
        _Schema__set_scan(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "planetary", {
    get: function() {
        return _Schema__get_planetary(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.planetary: expected number');
        _Schema__set_planetary(this.__ptr, value);
    }
});
Object.defineProperty(Schema.prototype, "spatial", {
    get: function() {
        return wrapPointer(_Schema__get_spatial(this.__ptr), SpatialPower);
    },
    set: function(value) {
        if (!checkClass(value, SpatialPower)) throw Error('Schema.spatial: expected SpatialPower');
        _Schema__set_spatial(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Schema.prototype, "upkeep_factor", {
    get: function() {
        return _Schema__get_upkeep_factor(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Schema.upkeep_factor: expected number');
        _Schema__set_upkeep_factor(this.__ptr, value);
    }
});
Schema.prototype["__destroy"] = Schema.prototype.__destroy = function() {
    _Schema__destroy(this.__ptr);
};
// ShipHull
function ShipHull() {
    
    this.__ptr = _ShipHull__construct_0(); getCache(ShipHull)[this.__ptr] = this;
};
ShipHull.prototype = Object.create(Schema.prototype);
ShipHull.prototype.constructor = ShipHull;
ShipHull.prototype.__class = ShipHull;
ShipHull.__base = Schema;
ShipHull.__cache = {};
Module['ShipHull'] = ShipHull;
ShipHull.prototype["__destroy"] = ShipHull.prototype.__destroy = function() {
    _ShipHull__destroy(this.__ptr);
};
// ShipEngine
function ShipEngine() {
    
    this.__ptr = _ShipEngine__construct_0(); getCache(ShipEngine)[this.__ptr] = this;
};
ShipEngine.prototype = Object.create(Schema.prototype);
ShipEngine.prototype.constructor = ShipEngine;
ShipEngine.prototype.__class = ShipEngine;
ShipEngine.__base = Schema;
ShipEngine.__cache = {};
Module['ShipEngine'] = ShipEngine;
ShipEngine.prototype["__destroy"] = ShipEngine.prototype.__destroy = function() {
    _ShipEngine__destroy(this.__ptr);
};
// ShipComponent
function ShipComponent() {
    
    this.__ptr = _ShipComponent__construct_0(); getCache(ShipComponent)[this.__ptr] = this;
};
ShipComponent.prototype = Object.create(Schema.prototype);
ShipComponent.prototype.constructor = ShipComponent;
ShipComponent.prototype.__class = ShipComponent;
ShipComponent.__base = Schema;
ShipComponent.__cache = {};
Module['ShipComponent'] = ShipComponent;
ShipComponent.prototype["__destroy"] = ShipComponent.prototype.__destroy = function() {
    _ShipComponent__destroy(this.__ptr);
};
// ShipSchema
function ShipSchema() {
    
    this.__ptr = _ShipSchema__construct_0(); getCache(ShipSchema)[this.__ptr] = this;
};
ShipSchema.prototype = Object.create(Schema.prototype);
ShipSchema.prototype.constructor = ShipSchema;
ShipSchema.prototype.__class = ShipSchema;
ShipSchema.__base = Schema;
ShipSchema.__cache = {};
Module['ShipSchema'] = ShipSchema;
Object.defineProperty(ShipSchema.prototype, "size", {
    get: function() {
        return _ShipSchema__get_size(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('ShipSchema.size: expected integer');
        _ShipSchema__set_size(this.__ptr, value);
    }
});
Object.defineProperty(ShipSchema.prototype, "class", {
    get: function() {
        return _ShipSchema__get_class(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('ShipSchema.class: expected integer');
        _ShipSchema__set_class(this.__ptr, value);
    }
});
Object.defineProperty(ShipSchema.prototype, "main_weapon", {
    get: function() {
        return _ShipSchema__get_main_weapon(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('ShipSchema.main_weapon: expected integer');
        _ShipSchema__set_main_weapon(this.__ptr, value);
    }
});
ShipSchema.prototype["__destroy"] = ShipSchema.prototype.__destroy = function() {
    _ShipSchema__destroy(this.__ptr);
};
// BuildingSchema
function BuildingSchema() {
    
    this.__ptr = _BuildingSchema__construct_0(); getCache(BuildingSchema)[this.__ptr] = this;
};
BuildingSchema.prototype = Object.create(Schema.prototype);
BuildingSchema.prototype.constructor = BuildingSchema;
BuildingSchema.prototype.__class = BuildingSchema;
BuildingSchema.__base = Schema;
BuildingSchema.__cache = {};
Module['BuildingSchema'] = BuildingSchema;
BuildingSchema.prototype["__destroy"] = BuildingSchema.prototype.__destroy = function() {
    _BuildingSchema__destroy(this.__ptr);
};
// Scans
function Scans() {
    
    this.__ptr = _Scans__construct_0(); getCache(Scans)[this.__ptr] = this;
};
Scans.prototype = Object.create(WrapperObject.prototype);
Scans.prototype.constructor = Scans;
Scans.prototype.__class = Scans;
Scans.__cache = {};
Module['Scans'] = Scans;
Scans.prototype["__destroy"] = Scans.prototype.__destroy = function() {
    _Scans__destroy(this.__ptr);
};
// TechDomain
function TechDomain() {
    
    this.__ptr = _TechDomain__construct_0(); getCache(TechDomain)[this.__ptr] = this;
};
TechDomain.prototype = Object.create(WrapperObject.prototype);
TechDomain.prototype.constructor = TechDomain;
TechDomain.prototype.__class = TechDomain;
TechDomain.__cache = {};
Module['TechDomain'] = TechDomain;
TechDomain.prototype["__destroy"] = TechDomain.prototype.__destroy = function() {
    _TechDomain__destroy(this.__ptr);
};
// Commander
function Commander(a0, a1, a2, a3, a4, a5) {
    ensureCache.prepare();
    if (typeof a0 !== 'number') throw Error('Commander(0:id): expected integer'); if (typeof a1 !== 'string') throw Error('Commander(1:name): expected string'); if (typeof a2 !== 'number') throw Error('Commander(2:race): expected integer'); if (typeof a3 !== 'number') throw Error('Commander(3:command): expected integer'); if (typeof a4 !== 'number') throw Error('Commander(4:commerce): expected integer'); if (typeof a5 !== 'number') throw Error('Commander(5:diplomacy): expected integer');
    this.__ptr = _Commander__construct_6(/*id*/a0, ensureString(/*name*/a1), /*race*/a2, /*command*/a3, /*commerce*/a4, /*diplomacy*/a5); getCache(Commander)[this.__ptr] = this;
};
Commander.prototype = Object.create(WrapperObject.prototype);
Commander.prototype.constructor = Commander;
Commander.prototype.__class = Commander;
Commander.__cache = {};
Module['Commander'] = Commander;
Object.defineProperty(Commander.prototype, "id", {
    get: function() {
        return _Commander__get_id(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.id: expected integer');
        _Commander__set_id(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "name", {
    get: function() {
        return UTF8ToString(_Commander__get_name(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Commander.name: expected string');
        _Commander__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Commander.prototype, "race", {
    get: function() {
        return _Commander__get_race(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.race: expected integer');
        _Commander__set_race(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "command", {
    get: function() {
        return _Commander__get_command(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.command: expected integer');
        _Commander__set_command(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "commerce", {
    get: function() {
        return _Commander__get_commerce(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.commerce: expected integer');
        _Commander__set_commerce(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "diplomacy", {
    get: function() {
        return _Commander__get_diplomacy(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.diplomacy: expected integer');
        _Commander__set_diplomacy(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "reputation", {
    get: function() {
        return _Commander__get_reputation(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.reputation: expected integer');
        _Commander__set_reputation(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "victory", {
    get: function() {
        return _Commander__get_victory(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.victory: expected integer');
        _Commander__set_victory(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "capital", {
    get: function() {
        return wrapPointer(_Commander__get_capital(this.__ptr), Star);
    },
    set: function(value) {
        if (!checkClass(value, Star)) throw Error('Commander.capital: expected Star');
        _Commander__set_capital(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Commander.prototype, "regime", {
    get: function() {
        return _Commander__get_regime(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.regime: expected integer');
        _Commander__set_regime(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "power", {
    get: function() {
        return _Commander__get_power(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.power: expected number');
        _Commander__set_power(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "centaures", {
    get: function() {
        return _Commander__get_centaures(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Commander.centaures: expected number');
        _Commander__set_centaures(this.__ptr, value);
    }
});
Object.defineProperty(Commander.prototype, "scans", {
    get: function() {
        return wrapPointer(_Commander__get_scans(this.__ptr), Scans);
    },
    set: function(value) {
        if (!checkClass(value, Scans)) throw Error('Commander.scans: expected Scans');
        _Commander__set_scans(this.__ptr, value.__ptr);
    }
});
Commander.prototype["__destroy"] = Commander.prototype.__destroy = function() {
    _Commander__destroy(this.__ptr);
};
// Combat
function Combat() {
    
    this.__ptr = _Combat__construct_0(); getCache(Combat)[this.__ptr] = this;
};
Combat.prototype = Object.create(WrapperObject.prototype);
Combat.prototype.constructor = Combat;
Combat.prototype.__class = Combat;
Combat.__cache = {};
Module['Combat'] = Combat;
Combat.prototype["__destroy"] = Combat.prototype.__destroy = function() {
    _Combat__destroy(this.__ptr);
};
// CombatFleet
function CombatFleet() {
    
    this.__ptr = _CombatFleet__construct_0(); getCache(CombatFleet)[this.__ptr] = this;
};
CombatFleet.prototype = Object.create(WrapperObject.prototype);
CombatFleet.prototype.constructor = CombatFleet;
CombatFleet.prototype.__class = CombatFleet;
CombatFleet.__cache = {};
Module['CombatFleet'] = CombatFleet;
Object.defineProperty(CombatFleet.prototype, "fleet", {
    get: function() {
        return wrapPointer(_CombatFleet__get_fleet(this.__ptr), Fleet);
    },
    set: function(value) {
        if (!checkClass(value, Fleet)) throw Error('CombatFleet.fleet: expected Fleet');
        _CombatFleet__set_fleet(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(CombatFleet.prototype, "damage", {
    get: function() {
        return _CombatFleet__get_damage(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('CombatFleet.damage: expected number');
        _CombatFleet__set_damage(this.__ptr, value);
    }
});
CombatFleet.prototype["__destroy"] = CombatFleet.prototype.__destroy = function() {
    _CombatFleet__destroy(this.__ptr);
};
// CombatStar
function CombatStar() {
    
    this.__ptr = _CombatStar__construct_0(); getCache(CombatStar)[this.__ptr] = this;
};
CombatStar.prototype = Object.create(WrapperObject.prototype);
CombatStar.prototype.constructor = CombatStar;
CombatStar.prototype.__class = CombatStar;
CombatStar.__cache = {};
Module['CombatStar'] = CombatStar;
CombatStar.prototype["__destroy"] = CombatStar.prototype.__destroy = function() {
    _CombatStar__destroy(this.__ptr);
};
// PlanetaryCombat
function PlanetaryCombat() {
    
    this.__ptr = _PlanetaryCombat__construct_0(); getCache(PlanetaryCombat)[this.__ptr] = this;
};
PlanetaryCombat.prototype = Object.create(Combat.prototype);
PlanetaryCombat.prototype.constructor = PlanetaryCombat;
PlanetaryCombat.prototype.__class = PlanetaryCombat;
PlanetaryCombat.__base = Combat;
PlanetaryCombat.__cache = {};
Module['PlanetaryCombat'] = PlanetaryCombat;
Object.defineProperty(PlanetaryCombat.prototype, "coord", {
    get: function() {
        return wrapPointer(_PlanetaryCombat__get_coord(this.__ptr), v2_uint);
    },
    set: function(value) {
        if (!checkClass(value, v2_uint)) throw Error('PlanetaryCombat.coord: expected v2<uint>');
        _PlanetaryCombat__set_coord(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(PlanetaryCombat.prototype, "defense", {
    get: function() {
        return wrapPointer(_PlanetaryCombat__get_defense(this.__ptr), CombatStar);
    },
    set: function(value) {
        if (!checkClass(value, CombatStar)) throw Error('PlanetaryCombat.defense: expected CombatStar');
        _PlanetaryCombat__set_defense(this.__ptr, value.__ptr);
    }
});
PlanetaryCombat.prototype["__destroy"] = PlanetaryCombat.prototype.__destroy = function() {
    _PlanetaryCombat__destroy(this.__ptr);
};
// SpatialCombat
function SpatialCombat() {
    
    this.__ptr = _SpatialCombat__construct_0(); getCache(SpatialCombat)[this.__ptr] = this;
};
SpatialCombat.prototype = Object.create(Combat.prototype);
SpatialCombat.prototype.constructor = SpatialCombat;
SpatialCombat.prototype.__class = SpatialCombat;
SpatialCombat.__base = Combat;
SpatialCombat.__cache = {};
Module['SpatialCombat'] = SpatialCombat;
Object.defineProperty(SpatialCombat.prototype, "coord", {
    get: function() {
        return wrapPointer(_SpatialCombat__get_coord(this.__ptr), v2_uint);
    },
    set: function(value) {
        if (!checkClass(value, v2_uint)) throw Error('SpatialCombat.coord: expected v2<uint>');
        _SpatialCombat__set_coord(this.__ptr, value.__ptr);
    }
});
SpatialCombat.prototype["__destroy"] = SpatialCombat.prototype.__destroy = function() {
    _SpatialCombat__destroy(this.__ptr);
};
// Galaxy
function Galaxy(a0, a1) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Galaxy(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, v2_uint)) throw Error('Galaxy(1:size): expected v2<uint>'); }
    if (a0 === undefined) { this.__ptr = _Galaxy__construct_0(); getCache(Galaxy)[this.__ptr] = this; }
    else { this.__ptr = _Galaxy__construct_2(/*spatial*/a0.__ptr, /*size*/a1.__ptr); getCache(Galaxy)[this.__ptr] = this; }
};
Galaxy.prototype = Object.create(WrapperObject.prototype);
Galaxy.prototype.constructor = Galaxy;
Galaxy.prototype.__class = Galaxy;
Galaxy.__cache = {};
Module['Galaxy'] = Galaxy;
Object.defineProperty(Galaxy.prototype, "size", {
    get: function() {
        return wrapPointer(_Galaxy__get_size(this.__ptr), v2_uint);
    },
    set: function(value) {
        if (!checkClass(value, v2_uint)) throw Error('Galaxy.size: expected v2<uint>');
        _Galaxy__set_size(this.__ptr, value.__ptr);
    }
});
Galaxy.prototype["__destroy"] = Galaxy.prototype.__destroy = function() {
    _Galaxy__destroy(this.__ptr);
};
// Universe
function Universe(a0, a1) {
    ensureCache.prepare();
    if (typeof a0 !== 'string') throw Error('Universe(0:name): expected string'); if (!checkClass(a1, JobSystem)) throw Error('Universe(1:job_system): expected JobSystem');
    this.__ptr = _Universe__construct_2(ensureString(/*name*/a0), /*job_system*/a1.__ptr); getCache(Universe)[this.__ptr] = this;
};
Universe.prototype = Object.create(Complex.prototype);
Universe.prototype.constructor = Universe;
Universe.prototype.__class = Universe;
Universe.__base = Complex;
Universe.__cache = {};
Module['Universe'] = Universe;
Object.defineProperty(Universe.prototype, "world", {
    get: function() {
        return wrapPointer(_Universe__get_world(this.__ptr), World);
    }});
Object.defineProperty(Universe.prototype, "bullet_world", {
    get: function() {
        return wrapPointer(_Universe__get_bullet_world(this.__ptr), BulletWorld);
    }});
Universe.prototype["__destroy"] = Universe.prototype.__destroy = function() {
    _Universe__destroy(this.__ptr);
};
// CommanderBrush
function CommanderBrush() { throw "cannot construct a CommanderBrush, no constructor in IDL" }
CommanderBrush.prototype = Object.create(Brush.prototype);
CommanderBrush.prototype.constructor = CommanderBrush;
CommanderBrush.prototype.__class = CommanderBrush;
CommanderBrush.__base = Brush;
CommanderBrush.__cache = {};
Module['CommanderBrush'] = CommanderBrush;
Object.defineProperty(CommanderBrush.prototype, "commander", {
    get: function() {
        return wrapPointer(_CommanderBrush__get_commander(this.__ptr), Commander);
    },
    set: function(value) {
        if (!checkClass(value, Commander)) throw Error('CommanderBrush.commander: expected Commander');
        _CommanderBrush__set_commander(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(CommanderBrush.prototype, "radius", {
    get: function() {
        return _CommanderBrush__get_radius(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('CommanderBrush.radius: expected number');
        _CommanderBrush__set_radius(this.__ptr, value);
    }
});
CommanderBrush.prototype["__destroy"] = CommanderBrush.prototype.__destroy = function() {
    _CommanderBrush__destroy(this.__ptr);
};
Module['generate_system'] = function(a0, a1, a2) {
    if (!checkClass(a0, Galaxy)) throw Error('generate_system(0:galaxy): expected Galaxy'); if (!checkClass(a1, v3_uint)) throw Error('generate_system(1:coord): expected v3<uint>'); if (!checkClass(a2, v3_float)) throw Error('generate_system(2:position): expected v3<float>');
    return wrapPointer(_generate_system_3(/*galaxy*/a0.__ptr, /*coord*/a1.__ptr, /*position*/a2.__ptr), ComponentHandle_Star);
};
Module['generate_fleet'] = function(a0, a1, a2) {
    if (!checkClass(a0, Galaxy)) throw Error('generate_fleet(0:galaxy): expected Galaxy'); if (!checkClass(a1, v3_uint)) throw Error('generate_fleet(1:coord): expected v3<uint>'); if (!checkClass(a2, v3_float)) throw Error('generate_fleet(2:position): expected v3<float>');
    return wrapPointer(_generate_fleet_3(/*galaxy*/a0.__ptr, /*coord*/a1.__ptr, /*position*/a2.__ptr), ComponentHandle_Fleet);
};
Module['generate_commander'] = function(a0, a1) {
    if (!checkClass(a0, Galaxy)) throw Error('generate_commander(0:galaxy): expected Galaxy'); if (!checkClass(a1, Star)) throw Error('generate_commander(1:star): expected Star');
    return wrapPointer(_generate_commander_2(/*galaxy*/a0.__ptr, /*star*/a1.__ptr), Commander);
};
Module['HGalaxy'] = ComponentHandle_Galaxy;
Module['HStar'] = ComponentHandle_Star;
Module['HFleet'] = ComponentHandle_Fleet;

(function() {
    function setup() {
        Turn.prototype.__type = _Turn__type();
        Player.prototype.__type = _Player__type();
        SpatialPower.prototype.__type = _SpatialPower__type();
        Construction.prototype.__type = _Construction__type();
        Star.prototype.__type = _Star__type();
        Jump.prototype.__type = _Jump__type();
        Split.prototype.__type = _Split__type();
        Fleet.prototype.__type = _Fleet__type();
        Schema.prototype.__type = _Schema__type();
        ShipHull.prototype.__type = _ShipHull__type();
        ShipEngine.prototype.__type = _ShipEngine__type();
        ShipComponent.prototype.__type = _ShipComponent__type();
        ShipSchema.prototype.__type = _ShipSchema__type();
        BuildingSchema.prototype.__type = _BuildingSchema__type();
        Scans.prototype.__type = _Scans__type();
        TechDomain.prototype.__type = _TechDomain__type();
        Commander.prototype.__type = _Commander__type();
        Combat.prototype.__type = _Combat__type();
        CombatFleet.prototype.__type = _CombatFleet__type();
        CombatStar.prototype.__type = _CombatStar__type();
        PlanetaryCombat.prototype.__type = _PlanetaryCombat__type();
        SpatialCombat.prototype.__type = _SpatialCombat__type();
        Galaxy.prototype.__type = _Galaxy__type();
        Universe.prototype.__type = _Universe__type();
        CommanderBrush.prototype.__type = _CommanderBrush__type();
        // GameStage
        Module['GameStage'] = Module['GameStage'] || {};
        Module['GameStage']['Empire'] = _GameStage_Empire();
        Module['GameStage']['Tactics'] = _GameStage_Tactics();
        Module['GameStage']['TurnReport'] = _GameStage_TurnReport();
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
        // Politic
        Module['Politic'] = Module['Politic'] || {};
        Module['Politic']['Taxes'] = _Politic_Taxes();
        Module['Politic']['Commerce'] = _Politic_Commerce();
        Module['Politic']['Construction'] = _Politic_Construction();
        Module['Politic']['Defense'] = _Politic_Defense();
        Module['Politic']['Pacification'] = _Politic_Pacification();
        // Taxation
        Module['Taxation'] = Module['Taxation'] || {};
        Module['Taxation']['None'] = _Taxation_None();
        Module['Taxation']['Light'] = _Taxation_Light();
        Module['Taxation']['Medium'] = _Taxation_Medium();
        Module['Taxation']['Heavy'] = _Taxation_Heavy();
        Module['Taxation']['Heaviest'] = _Taxation_Heaviest();
        Module['Taxation']['Total'] = _Taxation_Total();
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
        // Experience
        Module['Experience'] = Module['Experience'] || {};
        Module['Experience']['Inexperienced'] = _Experience_Inexperienced();
        Module['Experience']['LittleExperienced'] = _Experience_LittleExperienced();
        Module['Experience']['Experienced'] = _Experience_Experienced();
        Module['Experience']['Superior'] = _Experience_Superior();
        Module['Experience']['Elite'] = _Experience_Elite();
        // FleetStance
        Module['FleetStance'] = Module['FleetStance'] || {};
        Module['FleetStance']['Movement'] = _FleetStance_Movement();
        Module['FleetStance']['SpatialAttack'] = _FleetStance_SpatialAttack();
        Module['FleetStance']['SpatialDefense'] = _FleetStance_SpatialDefense();
        Module['FleetStance']['PlanetaryAttack'] = _FleetStance_PlanetaryAttack();
        Module['FleetStance']['PlanetaryDefense'] = _FleetStance_PlanetaryDefense();
        Module['FleetStance']['Pillage'] = _FleetStance_Pillage();
        // WeaponType
        Module['WeaponType'] = Module['WeaponType'] || {};
        Module['WeaponType']['None'] = _WeaponType_None();
        Module['WeaponType']['Ion'] = _WeaponType_Ion();
        Module['WeaponType']['Laser'] = _WeaponType_Laser();
        Module['WeaponType']['Plasma'] = _WeaponType_Plasma();
        Module['WeaponType']['Torpedo'] = _WeaponType_Torpedo();
        Module['WeaponType']['Bomb'] = _WeaponType_Bomb();
        Module['WeaponType']['Count'] = _WeaponType_Count();
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
        // CombatType
        Module['CombatType'] = Module['CombatType'] || {};
        Module['CombatType']['Spatial'] = _CombatType_Spatial();
        Module['CombatType']['Planetary'] = _CombatType_Planetary();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
