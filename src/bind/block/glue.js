
// Bindings utilities
function WrapperObject() {
}
// Block
function Block(spatial, world_page, parentblock, index, size) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* parentblock <Block> [] */
    /* index <size_t> [] */
    /* size <vec3> [] */
    if (spatial === undefined) { this.ptr = _Block_Block_0(self); getCache(Block)[this.ptr] = this; return; }
    this.ptr = _Block_Block_5(self, spatial, world_page, parentblock, index, size); getCache(Block)[this.ptr] = this;
};
Block.prototype = Object.create(WrapperObject.prototype);
Block.prototype.constructor = Block;
Block.prototype.__class__ = Block;
Block.__cache__ = {};
Module['Block'] = Block;
Block.prototype["chunk"] = Block.prototype.chunk = function(x, y, z, element) {
    /* x <size_t> [] */
    /* y <size_t> [] */
    /* z <size_t> [] */
    /* element <Element> [] */
    _Block_chunk_4(x, y, z, element);
};
Block.prototype["commit"] = Block.prototype.commit = function() {
    _Block_commit_0();
};
Block.prototype["reset"] = Block.prototype.reset = function() {
    _Block_reset_0();
};
Block.prototype["subdivide"] = Block.prototype.subdivide = function() {
    _Block_subdivide_0();
};
Object.defineProperty(Block.prototype, "world_page", {
    get: function() {
        var self = this.ptr;
        return _Block_get_world_page(self);
    },
    set: function(world_page) {
        var self = this.ptr;
        /* world_page <toy::HWorldPage> [] */
        _Block_set_world_page(self, world_page);
    }
});
Object.defineProperty(Block.prototype, "parentblock", {
    get: function() {
        var self = this.ptr;
        return _Block_get_parentblock(self);
    },
    set: function(parentblock) {
        var self = this.ptr;
        /* parentblock <Block> [] */
        _Block_set_parentblock(self, parentblock);
    }
});
Object.defineProperty(Block.prototype, "index", {
    get: function() {
        var self = this.ptr;
        return _Block_get_index(self);
    },
    set: function(index) {
        var self = this.ptr;
        /* index <size_t> [] */
        _Block_set_index(self, index);
    }
});
Object.defineProperty(Block.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return _Block_get_size(self);
    },
    set: function(size) {
        var self = this.ptr;
        /* size <vec3> [] */
        _Block_set_size(self, size);
    }
});
Object.defineProperty(Block.prototype, "updated", {
    get: function() {
        var self = this.ptr;
        return _Block_get_updated(self);
    },
    set: function(updated) {
        var self = this.ptr;
        /* updated <size_t> [] */
        _Block_set_updated(self, updated);
    }
});
Block.prototype["__destroy__"] = Block.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Block___destroy__(self);
};
// Chunk
function Chunk(spatial, block, index, element, size) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* block <Block> [] */
    /* index <size_t> [] */
    /* element <Element> [] */
    /* size <float> [] */
    if (spatial === undefined) { this.ptr = _Chunk_Chunk_0(self); getCache(Chunk)[this.ptr] = this; return; }
    this.ptr = _Chunk_Chunk_5(self, spatial, block, index, element, size); getCache(Chunk)[this.ptr] = this;
};
Chunk.prototype = Object.create(WrapperObject.prototype);
Chunk.prototype.constructor = Chunk;
Chunk.prototype.__class__ = Chunk;
Chunk.__cache__ = {};
Module['Chunk'] = Chunk;
Object.defineProperty(Chunk.prototype, "index", {
    get: function() {
        var self = this.ptr;
        return _Chunk_get_index(self);
    },
    set: function(index) {
        var self = this.ptr;
        /* index <size_t> [] */
        _Chunk_set_index(self, index);
    }
});
Object.defineProperty(Chunk.prototype, "block", {
    get: function() {
        var self = this.ptr;
        return _Chunk_get_block(self);
    },
    set: function(block) {
        var self = this.ptr;
        /* block <Block> [] */
        _Chunk_set_block(self, block);
    }
});
Object.defineProperty(Chunk.prototype, "element", {
    get: function() {
        var self = this.ptr;
        return _Chunk_get_element(self);
    },
    set: function(element) {
        var self = this.ptr;
        /* element <Element> [] */
        _Chunk_set_element(self, element);
    }
});
Object.defineProperty(Chunk.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return _Chunk_get_size(self);
    },
    set: function(size) {
        var self = this.ptr;
        /* size <float> [] */
        _Chunk_set_size(self, size);
    }
});
Chunk.prototype["__destroy__"] = Chunk.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Chunk___destroy__(self);
};
// Element
function Element(name, state, colour) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <const char*> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* state <MatterState> [] */
    /* colour <Colour> [] */
    this.ptr = _Element_Element_3(self, name, state, colour); getCache(Element)[this.ptr] = this;
};
Element.prototype = Object.create(WrapperObject.prototype);
Element.prototype.constructor = Element;
Element.prototype.__class__ = Element;
Element.__cache__ = {};
Module['Element'] = Element;
Object.defineProperty(Element.prototype, "id", {
    get: function() {
        var self = this.ptr;
        return _Element_get_id(self);
    },
    set: function(id) {
        var self = this.ptr;
        /* id <mud::Id> [] */
        _Element_set_id(self, id);
    }
});
Object.defineProperty(Element.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_Element_get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _Element_set_name(self, name);
    }
});
Object.defineProperty(Element.prototype, "state", {
    get: function() {
        var self = this.ptr;
        return _Element_get_state(self);
    },
    set: function(state) {
        var self = this.ptr;
        /* state <MatterState> [] */
        _Element_set_state(self, state);
    }
});
Object.defineProperty(Element.prototype, "colour", {
    get: function() {
        var self = this.ptr;
        return _Element_get_colour(self);
    },
    set: function(colour) {
        var self = this.ptr;
        /* colour <Colour> [] */
        _Element_set_colour(self, colour);
    }
});
Element.prototype["__destroy__"] = Element.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Element___destroy__(self);
};
// Heap
function Heap(spatial, element, radius) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* element <Element> [] */
    /* radius <float> [] */
    if (spatial === undefined) { this.ptr = _Heap_Heap_0(self); getCache(Heap)[this.ptr] = this; return; }
    this.ptr = _Heap_Heap_3(self, spatial, element, radius); getCache(Heap)[this.ptr] = this;
};
Heap.prototype = Object.create(WrapperObject.prototype);
Heap.prototype.constructor = Heap;
Heap.prototype.__class__ = Heap;
Heap.__cache__ = {};
Module['Heap'] = Heap;
Object.defineProperty(Heap.prototype, "element", {
    get: function() {
        var self = this.ptr;
        return _Heap_get_element(self);
    },
    set: function(element) {
        var self = this.ptr;
        /* element <Element> [] */
        _Heap_set_element(self, element);
    }
});
Object.defineProperty(Heap.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _Heap_get_radius(self);
    },
    set: function(radius) {
        var self = this.ptr;
        /* radius <float> [] */
        _Heap_set_radius(self, radius);
    }
});
Heap.prototype["__destroy__"] = Heap.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Heap___destroy__(self);
};
// Sector
function Sector(spatial, world_page, navblock, coordinate, size) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navblock <toy::HNavblock> [] */
    /* coordinate <uvec3> [] */
    /* size <vec3> [] */
    if (spatial === undefined) { this.ptr = _Sector_Sector_0(self); getCache(Sector)[this.ptr] = this; return; }
    this.ptr = _Sector_Sector_5(self, spatial, world_page, navblock, coordinate, size); getCache(Sector)[this.ptr] = this;
};
Sector.prototype = Object.create(WrapperObject.prototype);
Sector.prototype.constructor = Sector;
Sector.prototype.__class__ = Sector;
Sector.__cache__ = {};
Module['Sector'] = Sector;
Object.defineProperty(Sector.prototype, "coordinate", {
    get: function() {
        var self = this.ptr;
        return _Sector_get_coordinate(self);
    },
    set: function(coordinate) {
        var self = this.ptr;
        /* coordinate <uvec3> [] */
        _Sector_set_coordinate(self, coordinate);
    }
});
Object.defineProperty(Sector.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return _Sector_get_size(self);
    },
    set: function(size) {
        var self = this.ptr;
        /* size <vec3> [] */
        _Sector_set_size(self, size);
    }
});
Object.defineProperty(Sector.prototype, "block", {
    get: function() {
        var self = this.ptr;
        return _Sector_get_block(self);
    },
    set: function(block) {
        var self = this.ptr;
        /* block <Block> [] */
        _Sector_set_block(self, block);
    }
});
Sector.prototype["__destroy__"] = Sector.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Sector___destroy__(self);
};
// Tileblock
function Tileblock(spatial, world_page, navblock, size, tile_scale, tileset) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navblock <toy::HNavblock> [] */
    /* size <uvec3> [] */
    /* tile_scale <vec3> [] */
    /* tileset <WaveTileset> [] */
    if (spatial === undefined) { this.ptr = _Tileblock_Tileblock_0(self); getCache(Tileblock)[this.ptr] = this; return; }
    this.ptr = _Tileblock_Tileblock_6(self, spatial, world_page, navblock, size, tile_scale, tileset); getCache(Tileblock)[this.ptr] = this;
};
Tileblock.prototype = Object.create(WrapperObject.prototype);
Tileblock.prototype.constructor = Tileblock;
Tileblock.prototype.__class__ = Tileblock;
Tileblock.__cache__ = {};
Module['Tileblock'] = Tileblock;
Object.defineProperty(Tileblock.prototype, "wfc_block", {
    get: function() {
        var self = this.ptr;
        return _Tileblock_get_wfc_block(self);
    },
    set: function(wfc_block) {
        var self = this.ptr;
        /* wfc_block <WfcBlock> [] */
        _Tileblock_set_wfc_block(self, wfc_block);
    }
});
Object.defineProperty(Tileblock.prototype, "setup", {
    get: function() {
        var self = this.ptr;
        return !!(_Tileblock_get_setup(self));
    },
    set: function(setup) {
        var self = this.ptr;
        /* setup <bool> [] */
        _Tileblock_set_setup(self, setup);
    }
});
Object.defineProperty(Tileblock.prototype, "populated", {
    get: function() {
        var self = this.ptr;
        return !!(_Tileblock_get_populated(self));
    },
    set: function(populated) {
        var self = this.ptr;
        /* populated <bool> [] */
        _Tileblock_set_populated(self, populated);
    }
});
Tileblock.prototype["__destroy__"] = Tileblock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Tileblock___destroy__(self);
};
// Earth
function Earth() {
    var self = this.ptr;
    this.ptr = _Earth_Earth_0(self); getCache(Earth)[this.ptr] = this;
};
Earth.prototype = Object.create(WrapperObject.prototype);
Earth.prototype.constructor = Earth;
Earth.prototype.__class__ = Earth;
Earth.__cache__ = {};
Module['Earth'] = Earth;
Earth.prototype["__destroy__"] = Earth.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Earth___destroy__(self);
};

(function() {
    function setupEnums() {
        // MatterState
        Module['MatterState']['Solid'] = _emscripten_enum_MatterState_Solid();
        Module['MatterState']['Liquid'] = _emscripten_enum_MatterState_Liquid();
        Module['MatterState']['Gas'] = _emscripten_enum_MatterState_Gas();
        Module['MatterState']['Plasma'] = _emscripten_enum_MatterState_Plasma();
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
