Module['stl'] = Module['stl'] || {};
Module['mud'] = Module['mud'] || {};
// Block
function Block(a0, a1, a2, a3, a4) {
    if (a0 === undefined) { this.ptr = _toy_Block__construct_0(); this.type = Block; getCache(Block)[this.ptr] = this; return; }
    this.ptr = _toy_Block__construct_5(/*spatial*/a0.ptr, /*world_page*/a1.ptr, /*parentblock*/a2.ptr, /*index*/a3, /*size*/a4.ptr); this.type = Block; getCache(Block)[this.ptr] = this;
};
Block.prototype = Object.create(WrapperObject.prototype);
Block.prototype.constructor = Block;
Block.prototype.__class__ = Block;
Block.__cache__ = {};
Module['Block'] = Block;
Block.prototype["subdivide"] = Block.prototype.subdivide = function() {
    var self = this.ptr;
    _toy_Block_subdivide_0(self);
};
Block.prototype["reset"] = Block.prototype.reset = function() {
    var self = this.ptr;
    _toy_Block_reset_0(self);
};
Block.prototype["chunk"] = Block.prototype.chunk = function(a0, a1, a2, a3) {
    var self = this.ptr;
    _toy_Block_chunk_4(self, /*x*/a0, /*y*/a1, /*z*/a2, /*element*/a3.ptr);
};
Block.prototype["commit"] = Block.prototype.commit = function() {
    var self = this.ptr;
    _toy_Block_commit_0(self);
};
Object.defineProperty(Block.prototype, "world_page", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Block__get_world_page(self), ComponentHandle_toy_WorldPage);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Block__set_world_page(self, value.ptr);
    }
});
Object.defineProperty(Block.prototype, "parentblock", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Block__get_parentblock(self), Block);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Block__set_parentblock(self, value.ptr);
    }
});
Object.defineProperty(Block.prototype, "index", {
    get: function() {
        var self = this.ptr;
        return _toy_Block__get_index(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Block__set_index(self, value);
    }
});
Object.defineProperty(Block.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Block__get_size(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Block__set_size(self, value.ptr);
    }
});
Object.defineProperty(Block.prototype, "updated", {
    get: function() {
        var self = this.ptr;
        return _toy_Block__get_updated(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Block__set_updated(self, value);
    }
});
Block.prototype["__destroy__"] = Block.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Block__destroy(self);
};
// Chunk
function Chunk(a0, a1, a2, a3, a4) {
    if (a0 === undefined) { this.ptr = _toy_Chunk__construct_0(); this.type = Chunk; getCache(Chunk)[this.ptr] = this; return; }
    this.ptr = _toy_Chunk__construct_5(/*spatial*/a0.ptr, /*block*/a1.ptr, /*index*/a2, /*element*/a3.ptr, /*size*/a4); this.type = Chunk; getCache(Chunk)[this.ptr] = this;
};
Chunk.prototype = Object.create(WrapperObject.prototype);
Chunk.prototype.constructor = Chunk;
Chunk.prototype.__class__ = Chunk;
Chunk.__cache__ = {};
Module['Chunk'] = Chunk;
Object.defineProperty(Chunk.prototype, "index", {
    get: function() {
        var self = this.ptr;
        return _toy_Chunk__get_index(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Chunk__set_index(self, value);
    }
});
Object.defineProperty(Chunk.prototype, "block", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Chunk__get_block(self), Block);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Chunk__set_block(self, value.ptr);
    }
});
Object.defineProperty(Chunk.prototype, "element", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Chunk__get_element(self), Element);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Chunk__set_element(self, value.ptr);
    }
});
Object.defineProperty(Chunk.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return _toy_Chunk__get_size(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Chunk__set_size(self, value);
    }
});
Chunk.prototype["__destroy__"] = Chunk.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Chunk__destroy(self);
};
// ComponentHandle<toy::Block>
function ComponentHandle_toy_Block() {
    this.ptr = _mud_ComponentHandle_toy_Block__construct_0(); this.type = ComponentHandle_toy_Block; getCache(ComponentHandle_toy_Block)[this.ptr] = this;
};
ComponentHandle_toy_Block.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Block.prototype.constructor = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.prototype.__class__ = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.__cache__ = {};
Module['mud']['ComponentHandle_toy_Block'] = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.prototype["__destroy__"] = ComponentHandle_toy_Block.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_toy_Block__destroy(self);
};
// ComponentHandle<toy::Chunk>
function ComponentHandle_toy_Chunk() {
    this.ptr = _mud_ComponentHandle_toy_Chunk__construct_0(); this.type = ComponentHandle_toy_Chunk; getCache(ComponentHandle_toy_Chunk)[this.ptr] = this;
};
ComponentHandle_toy_Chunk.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Chunk.prototype.constructor = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.prototype.__class__ = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.__cache__ = {};
Module['mud']['ComponentHandle_toy_Chunk'] = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.prototype["__destroy__"] = ComponentHandle_toy_Chunk.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_toy_Chunk__destroy(self);
};
// ComponentHandle<toy::Heap>
function ComponentHandle_toy_Heap() {
    this.ptr = _mud_ComponentHandle_toy_Heap__construct_0(); this.type = ComponentHandle_toy_Heap; getCache(ComponentHandle_toy_Heap)[this.ptr] = this;
};
ComponentHandle_toy_Heap.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Heap.prototype.constructor = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.prototype.__class__ = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.__cache__ = {};
Module['mud']['ComponentHandle_toy_Heap'] = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.prototype["__destroy__"] = ComponentHandle_toy_Heap.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_toy_Heap__destroy(self);
};
// ComponentHandle<toy::Sector>
function ComponentHandle_toy_Sector() {
    this.ptr = _mud_ComponentHandle_toy_Sector__construct_0(); this.type = ComponentHandle_toy_Sector; getCache(ComponentHandle_toy_Sector)[this.ptr] = this;
};
ComponentHandle_toy_Sector.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Sector.prototype.constructor = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.prototype.__class__ = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.__cache__ = {};
Module['mud']['ComponentHandle_toy_Sector'] = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.prototype["__destroy__"] = ComponentHandle_toy_Sector.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_toy_Sector__destroy(self);
};
// ComponentHandle<toy::Tileblock>
function ComponentHandle_toy_Tileblock() {
    this.ptr = _mud_ComponentHandle_toy_Tileblock__construct_0(); this.type = ComponentHandle_toy_Tileblock; getCache(ComponentHandle_toy_Tileblock)[this.ptr] = this;
};
ComponentHandle_toy_Tileblock.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Tileblock.prototype.constructor = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.prototype.__class__ = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.__cache__ = {};
Module['mud']['ComponentHandle_toy_Tileblock'] = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.prototype["__destroy__"] = ComponentHandle_toy_Tileblock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _mud_ComponentHandle_toy_Tileblock__destroy(self);
};
// Element
function Element(a0, a1, a2) {
    ensureCache.prepare();
    this.ptr = _toy_Element__construct_3(ensureString(/*name*/a0), /*state*/a1, /*colour*/a2.ptr); this.type = Element; getCache(Element)[this.ptr] = this;
};
Element.prototype = Object.create(WrapperObject.prototype);
Element.prototype.constructor = Element;
Element.prototype.__class__ = Element;
Element.__cache__ = {};
Module['Element'] = Element;
Object.defineProperty(Element.prototype, "id", {
    get: function() {
        var self = this.ptr;
        return _toy_Element__get_id(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Element__set_id(self, value);
    }
});
Object.defineProperty(Element.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_toy_Element__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Element__set_name(self, ensureString(value));
    }
});
Object.defineProperty(Element.prototype, "state", {
    get: function() {
        var self = this.ptr;
        return _toy_Element__get_state(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Element__set_state(self, value);
    }
});
Object.defineProperty(Element.prototype, "colour", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Element__get_colour(self), Colour);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Element__set_colour(self, value.ptr);
    }
});
Element.prototype["__destroy__"] = Element.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Element__destroy(self);
};
// Heap
function Heap(a0, a1, a2) {
    if (a0 === undefined) { this.ptr = _toy_Heap__construct_0(); this.type = Heap; getCache(Heap)[this.ptr] = this; return; }
    this.ptr = _toy_Heap__construct_3(/*spatial*/a0.ptr, /*element*/a1.ptr, /*radius*/a2); this.type = Heap; getCache(Heap)[this.ptr] = this;
};
Heap.prototype = Object.create(WrapperObject.prototype);
Heap.prototype.constructor = Heap;
Heap.prototype.__class__ = Heap;
Heap.__cache__ = {};
Module['Heap'] = Heap;
Object.defineProperty(Heap.prototype, "element", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Heap__get_element(self), Element);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Heap__set_element(self, value.ptr);
    }
});
Object.defineProperty(Heap.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _toy_Heap__get_radius(self);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Heap__set_radius(self, value);
    }
});
Heap.prototype["__destroy__"] = Heap.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Heap__destroy(self);
};
// Sector
function Sector(a0, a1, a2, a3, a4) {
    if (a0 === undefined) { this.ptr = _toy_Sector__construct_0(); this.type = Sector; getCache(Sector)[this.ptr] = this; return; }
    this.ptr = _toy_Sector__construct_5(/*spatial*/a0.ptr, /*world_page*/a1.ptr, /*navblock*/a2.ptr, /*coordinate*/a3.ptr, /*size*/a4.ptr); this.type = Sector; getCache(Sector)[this.ptr] = this;
};
Sector.prototype = Object.create(WrapperObject.prototype);
Sector.prototype.constructor = Sector;
Sector.prototype.__class__ = Sector;
Sector.__cache__ = {};
Module['Sector'] = Sector;
Object.defineProperty(Sector.prototype, "coordinate", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Sector__get_coordinate(self), v3_uint);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Sector__set_coordinate(self, value.ptr);
    }
});
Object.defineProperty(Sector.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Sector__get_size(self), v3_float);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Sector__set_size(self, value.ptr);
    }
});
Object.defineProperty(Sector.prototype, "block", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Sector__get_block(self), Block);
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Sector__set_block(self, value.ptr);
    }
});
Sector.prototype["__destroy__"] = Sector.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Sector__destroy(self);
};
// Tileblock
function Tileblock(a0, a1, a2, a3, a4, a5) {
    if (a0 === undefined) { this.ptr = _toy_Tileblock__construct_0(); this.type = Tileblock; getCache(Tileblock)[this.ptr] = this; return; }
    this.ptr = _toy_Tileblock__construct_6(/*spatial*/a0.ptr, /*world_page*/a1.ptr, /*navblock*/a2.ptr, /*size*/a3.ptr, /*tile_scale*/a4.ptr, /*tileset*/a5.ptr); this.type = Tileblock; getCache(Tileblock)[this.ptr] = this;
};
Tileblock.prototype = Object.create(WrapperObject.prototype);
Tileblock.prototype.constructor = Tileblock;
Tileblock.prototype.__class__ = Tileblock;
Tileblock.__cache__ = {};
Module['Tileblock'] = Tileblock;
Object.defineProperty(Tileblock.prototype, "wfc_block", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Tileblock__get_wfc_block(self), WfcBlock);
    }});
Object.defineProperty(Tileblock.prototype, "setup", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Tileblock__get_setup(self));
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Tileblock__set_setup(self, value);
    }
});
Object.defineProperty(Tileblock.prototype, "populated", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Tileblock__get_populated(self));
    },
    set: function(value) {
        var self = this.ptr;
        _toy_Tileblock__set_populated(self, value);
    }
});
Tileblock.prototype["__destroy__"] = Tileblock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Tileblock__destroy(self);
};
// Earth
function Earth() {
    this.ptr = _toy_Earth__construct_0(); this.type = Earth; getCache(Earth)[this.ptr] = this;
};
Earth.prototype = Object.create(Element.prototype);
Earth.prototype.constructor = Earth;
Earth.prototype.__class__ = Earth;
Earth.__cache__ = {};
Module['Earth'] = Earth;
Earth.prototype["__destroy__"] = Earth.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Earth__destroy(self);
};
Module['paint_block_height'] = function(a0, a1, a2) {
    _toy_paint_block_height_3(/*block*/a0.ptr, /*image*/a1.ptr, /*element*/a2.ptr);
};
Module['generate_block'] = function(a0, a1, a2, a3, a4, a5, a6) {
    if (a6 === undefined) { return wrapPointer(_toy_generate_block_6(/*gfx_system*/a0.ptr, /*tileset*/a1.ptr, /*origin*/a2.ptr, /*coord*/a3.ptr, /*block_subdiv*/a4.ptr, /*tile_scale*/a5.ptr), ComponentHandle_toy_Tileblock); }
    return wrapPointer(_toy_generate_block_7(/*gfx_system*/a0.ptr, /*tileset*/a1.ptr, /*origin*/a2.ptr, /*coord*/a3.ptr, /*block_subdiv*/a4.ptr, /*tile_scale*/a5.ptr, /*from_file*/a6), ComponentHandle_toy_Tileblock);
};
Module['build_block_geometry'] = function(a0, a1, a2) {
    _toy_build_block_geometry_3(/*scene*/a0.ptr, /*page*/a1.ptr, /*block*/a2.ptr);
};
Module['HBlock'] = ComponentHandle_toy_Block;
Module['HChunk'] = ComponentHandle_toy_Chunk;
Module['HHeap'] = ComponentHandle_toy_Heap;
Module['HSector'] = ComponentHandle_toy_Sector;
Module['HTileblock'] = ComponentHandle_toy_Tileblock;

(function() {
    function setup() {
        Block.__type__ = _toy_Block__type();
        Chunk.__type__ = _toy_Chunk__type();
        Element.__type__ = _toy_Element__type();
        Heap.__type__ = _toy_Heap__type();
        Sector.__type__ = _toy_Sector__type();
        Tileblock.__type__ = _toy_Tileblock__type();
        Earth.__type__ = _toy_Earth__type();
        // MatterState
        Module['MatterState'] = Module['MatterState'] || {};
        Module['MatterState']['Solid'] = _toy_MatterState_Solid();
        Module['MatterState']['Liquid'] = _toy_MatterState_Liquid();
        Module['MatterState']['Gas'] = _toy_MatterState_Gas();
        Module['MatterState']['Plasma'] = _toy_MatterState_Plasma();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
