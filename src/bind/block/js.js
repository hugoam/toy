Module['two']['ui'] = Module['two']['ui'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
// Block
function Block(spatial, world_page, parentblock, index, size) {
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* parentblock <Block> [] */
    if(typeof parentblock !== "undefined" && parentblock !== null) { parentblock = parentblock.ptr; }
    /* index <size_t> [] */
    /* size <vec3> [] */
    if(typeof size !== "undefined" && size !== null) { size = size.ptr; }
    if (spatial === undefined) { this.ptr = _toy_Block_Block_0(); getCache(Block)[this.ptr] = this; return; }
    this.ptr = _toy_Block_Block_5(spatial, world_page, parentblock, index, size); getCache(Block)[this.ptr] = this;
    this.type = Block;
};
Block.prototype = Object.create(WrapperObject.prototype);
Block.prototype.constructor = Block;
Block.prototype.__class__ = Block;
Block.__cache__ = {};
Module['Block'] = Block;
Block.prototype["subdivide"] = Block.prototype.subdivide = function(self) {
    var self = this.ptr;
    _toy_Block_subdivide_0(self);
};
Block.prototype["reset"] = Block.prototype.reset = function(self) {
    var self = this.ptr;
    _toy_Block_reset_0(self);
};
Block.prototype["chunk"] = Block.prototype.chunk = function(self, x, y, z, element) {
    var self = this.ptr;
    /* x <size_t> [] */
    /* y <size_t> [] */
    /* z <size_t> [] */
    /* element <Element> [] */
    element = element.ptr;
    _toy_Block_chunk_4(self, x, y, z, element);
};
Block.prototype["commit"] = Block.prototype.commit = function(self) {
    var self = this.ptr;
    _toy_Block_commit_0(self);
};
Object.defineProperty(Block.prototype, "world_page", {
    get: function() {
        var self = this.ptr;
        return _toy_Block__get_world_page(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <toy::HWorldPage> [] */
        _toy_Block__set_world_page(self, value);
    }
});
Object.defineProperty(Block.prototype, "parentblock", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Block__get_parentblock(self), Block);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Block> [] */
        value = value.ptr;
        _toy_Block__set_parentblock(self, value);
    }
});
Object.defineProperty(Block.prototype, "index", {
    get: function() {
        var self = this.ptr;
        return _toy_Block__get_index(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <size_t> [] */
        _toy_Block__set_index(self, value);
    }
});
Object.defineProperty(Block.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Block__get_size(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _toy_Block__set_size(self, value);
    }
});
Object.defineProperty(Block.prototype, "updated", {
    get: function() {
        var self = this.ptr;
        return _toy_Block__get_updated(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <size_t> [] */
        _toy_Block__set_updated(self, value);
    }
});
Block.prototype["__destroy__"] = Block.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Block__destroy(self);
};
// Chunk
function Chunk(spatial, block, index, element, size) {
    /* spatial <toy::HSpatial> [] */
    /* block <Block> [] */
    if(typeof block !== "undefined" && block !== null) { block = block.ptr; }
    /* index <size_t> [] */
    /* element <Element> [] */
    if(typeof element !== "undefined" && element !== null) { element = element.ptr; }
    /* size <float> [] */
    if (spatial === undefined) { this.ptr = _toy_Chunk_Chunk_0(); getCache(Chunk)[this.ptr] = this; return; }
    this.ptr = _toy_Chunk_Chunk_5(spatial, block, index, element, size); getCache(Chunk)[this.ptr] = this;
    this.type = Chunk;
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
        /* value <size_t> [] */
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
        /* value <Block> [] */
        value = value.ptr;
        _toy_Chunk__set_block(self, value);
    }
});
Object.defineProperty(Chunk.prototype, "element", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Chunk__get_element(self), Element);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Element> [] */
        value = value.ptr;
        _toy_Chunk__set_element(self, value);
    }
});
Object.defineProperty(Chunk.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return _toy_Chunk__get_size(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Chunk__set_size(self, value);
    }
});
Chunk.prototype["__destroy__"] = Chunk.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Chunk__destroy(self);
};
// Element
function Element(name, state, colour) {
    ensureCache.prepare();
    /* name <const char*> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* state <MatterState> [] */
    if (state && typeof state === "object") state = state.ptr;
    /* colour <Colour> [] */
    colour = colour.ptr;
    this.ptr = _toy_Element_Element_3(name, state, colour); getCache(Element)[this.ptr] = this;
    this.type = Element;
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
        /* value <uint32_t> [] */
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
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _toy_Element__set_name(self, value);
    }
});
Object.defineProperty(Element.prototype, "state", {
    get: function() {
        var self = this.ptr;
        return _toy_Element__get_state(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <MatterState> [] */
        if (value && typeof value === "object") value = value.ptr;
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
        /* value <Colour> [] */
        value = value.ptr;
        _toy_Element__set_colour(self, value);
    }
});
Element.prototype["__destroy__"] = Element.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Element__destroy(self);
};
// Heap
function Heap(spatial, element, radius) {
    /* spatial <toy::HSpatial> [] */
    /* element <Element> [] */
    if(typeof element !== "undefined" && element !== null) { element = element.ptr; }
    /* radius <float> [] */
    if (spatial === undefined) { this.ptr = _toy_Heap_Heap_0(); getCache(Heap)[this.ptr] = this; return; }
    this.ptr = _toy_Heap_Heap_3(spatial, element, radius); getCache(Heap)[this.ptr] = this;
    this.type = Heap;
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
        /* value <Element> [] */
        value = value.ptr;
        _toy_Heap__set_element(self, value);
    }
});
Object.defineProperty(Heap.prototype, "radius", {
    get: function() {
        var self = this.ptr;
        return _toy_Heap__get_radius(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Heap__set_radius(self, value);
    }
});
Heap.prototype["__destroy__"] = Heap.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Heap__destroy(self);
};
// Sector
function Sector(spatial, world_page, navblock, coordinate, size) {
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navblock <toy::HNavblock> [] */
    /* coordinate <uvec3> [] */
    if(typeof coordinate !== "undefined" && coordinate !== null) { coordinate = coordinate.ptr; }
    /* size <vec3> [] */
    if(typeof size !== "undefined" && size !== null) { size = size.ptr; }
    if (spatial === undefined) { this.ptr = _toy_Sector_Sector_0(); getCache(Sector)[this.ptr] = this; return; }
    this.ptr = _toy_Sector_Sector_5(spatial, world_page, navblock, coordinate, size); getCache(Sector)[this.ptr] = this;
    this.type = Sector;
};
Sector.prototype = Object.create(WrapperObject.prototype);
Sector.prototype.constructor = Sector;
Sector.prototype.__class__ = Sector;
Sector.__cache__ = {};
Module['Sector'] = Sector;
Object.defineProperty(Sector.prototype, "coordinate", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Sector__get_coordinate(self), uvec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uvec3> [] */
        value = value.ptr;
        _toy_Sector__set_coordinate(self, value);
    }
});
Object.defineProperty(Sector.prototype, "size", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Sector__get_size(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _toy_Sector__set_size(self, value);
    }
});
Object.defineProperty(Sector.prototype, "block", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Sector__get_block(self), Block);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Block> [] */
        value = value.ptr;
        _toy_Sector__set_block(self, value);
    }
});
Sector.prototype["__destroy__"] = Sector.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Sector__destroy(self);
};
// Tileblock
function Tileblock(spatial, world_page, navblock, size, tile_scale, tileset) {
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navblock <toy::HNavblock> [] */
    /* size <uvec3> [] */
    if(typeof size !== "undefined" && size !== null) { size = size.ptr; }
    /* tile_scale <vec3> [] */
    if(typeof tile_scale !== "undefined" && tile_scale !== null) { tile_scale = tile_scale.ptr; }
    /* tileset <WaveTileset> [] */
    if(typeof tileset !== "undefined" && tileset !== null) { tileset = tileset.ptr; }
    if (spatial === undefined) { this.ptr = _toy_Tileblock_Tileblock_0(); getCache(Tileblock)[this.ptr] = this; return; }
    this.ptr = _toy_Tileblock_Tileblock_6(spatial, world_page, navblock, size, tile_scale, tileset); getCache(Tileblock)[this.ptr] = this;
    this.type = Tileblock;
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
        /* value <bool> [] */
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
        /* value <bool> [] */
        _toy_Tileblock__set_populated(self, value);
    }
});
Tileblock.prototype["__destroy__"] = Tileblock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Tileblock__destroy(self);
};
// Earth
function Earth() {
    this.ptr = _toy_Earth_Earth_0(); getCache(Earth)[this.ptr] = this;
    this.type = Earth;
};
Earth.prototype = Object.create(WrapperObject.prototype);
Earth.prototype.constructor = Earth;
Earth.prototype.__class__ = Earth;
Earth.__cache__ = {};
Module['Earth'] = Earth;
Earth.prototype["__destroy__"] = Earth.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Earth__destroy(self);
};
Module['paint_block_height'] = function(block, image, element) {
    var self = this.ptr;
    /* block <Block> [] */
    block = block.ptr;
    /* image <Image256> [] */
    image = image.ptr;
    /* element <Element> [] */
    element = element.ptr;
    _toy_paint_block_height_3(block, image, element);
};
Module['generate_block'] = function(gfx_system, tileset, origin, coord, block_subdiv, tile_scale, from_file) {
    var self = this.ptr;
    /* gfx_system <GfxSystem> [] */
    gfx_system = gfx_system.ptr;
    /* tileset <WaveTileset> [] */
    tileset = tileset.ptr;
    /* origin <toy::HSpatial> [] */
    /* coord <ivec2> [] */
    coord = coord.ptr;
    /* block_subdiv <uvec3> [] */
    block_subdiv = block_subdiv.ptr;
    /* tile_scale <vec3> [] */
    tile_scale = tile_scale.ptr;
    /* from_file <bool> [] */
    if (from_file === undefined) { return _toy_generate_block_6(gfx_system, tileset, origin, coord, block_subdiv, tile_scale); }
    return _toy_generate_block_7(gfx_system, tileset, origin, coord, block_subdiv, tile_scale, from_file);
};
Module['build_block_geometry'] = function(scene, page, block) {
    var self = this.ptr;
    /* scene <Scene> [] */
    scene = scene.ptr;
    /* page <WorldPage> [] */
    page = page.ptr;
    /* block <Tileblock> [] */
    block = block.ptr;
    _toy_build_block_geometry_3(scene, page, block);
};

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
