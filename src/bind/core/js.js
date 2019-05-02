Module['two']['ui'] = Module['two']['ui'] || {};
Module['two'] = Module['two'] || {};
Module['two']['gfx'] = Module['two']['gfx'] || {};
// BulletMedium
function BulletMedium() { throw "cannot construct a BulletMedium, no constructor in IDL" }
BulletMedium.prototype = Object.create(WrapperObject.prototype);
BulletMedium.prototype.constructor = BulletMedium;
BulletMedium.prototype.__class__ = BulletMedium;
BulletMedium.__cache__ = {};
Module['BulletMedium'] = BulletMedium;
BulletMedium.prototype["__destroy__"] = BulletMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_BulletMedium__destroy(self);
};
// BulletShape
function BulletShape() { throw "cannot construct a BulletShape, no constructor in IDL" }
BulletShape.prototype = Object.create(WrapperObject.prototype);
BulletShape.prototype.constructor = BulletShape;
BulletShape.prototype.__class__ = BulletShape;
BulletShape.__cache__ = {};
Module['BulletShape'] = BulletShape;
BulletShape.prototype["__destroy__"] = BulletShape.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_BulletShape__destroy(self);
};
// Camera
function Camera(spatial, lens_distance, near, far) {
    /* spatial <toy::HSpatial> [] */
    /* lens_distance <float> [] */
    /* near <float> [] */
    /* far <float> [] */
    if (spatial === undefined) { this.ptr = _toy_Camera_Camera_0(); getCache(Camera)[this.ptr] = this; return; }
    if (lens_distance === undefined) { this.ptr = _toy_Camera_Camera_1(spatial); getCache(Camera)[this.ptr] = this; return; }
    if (near === undefined) { this.ptr = _toy_Camera_Camera_2(spatial, lens_distance); getCache(Camera)[this.ptr] = this; return; }
    if (far === undefined) { this.ptr = _toy_Camera_Camera_3(spatial, lens_distance, near); getCache(Camera)[this.ptr] = this; return; }
    this.ptr = _toy_Camera_Camera_4(spatial, lens_distance, near, far); getCache(Camera)[this.ptr] = this;
    this.type = Camera;
};
Camera.prototype = Object.create(WrapperObject.prototype);
Camera.prototype.constructor = Camera;
Camera.prototype.__class__ = Camera;
Camera.__cache__ = {};
Module['Camera'] = Camera;
Object.defineProperty(Camera.prototype, "lens_distance", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera__get_lens_distance(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Camera__set_lens_distance(self, value);
    }
});
Object.defineProperty(Camera.prototype, "lens_angle", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera__get_lens_angle(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Camera__set_lens_angle(self, value);
    }
});
Object.defineProperty(Camera.prototype, "near", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera__get_near(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Camera__set_near(self, value);
    }
});
Object.defineProperty(Camera.prototype, "far", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera__get_far(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Camera__set_far(self, value);
    }
});
Object.defineProperty(Camera.prototype, "aspect", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera__get_aspect(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Camera__set_aspect(self, value);
    }
});
Camera.prototype["__destroy__"] = Camera.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Camera__destroy(self);
};
// Collider
function Collider(spatial, movable, collision_shape, medium, group) {
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* collision_shape <CollisionShape> [] */
    if(typeof collision_shape !== "undefined" && collision_shape !== null) { collision_shape = collision_shape.ptr; }
    /* medium <Medium> [] */
    if(typeof medium !== "undefined" && medium !== null) { medium = medium.ptr; }
    /* group <CollisionGroup> [] */
    if (group && typeof group === "object") group = group.ptr;
    if (spatial === undefined) { this.ptr = _toy_Collider_Collider_0(); getCache(Collider)[this.ptr] = this; return; }
    this.ptr = _toy_Collider_Collider_5(spatial, movable, collision_shape, medium, group); getCache(Collider)[this.ptr] = this;
    this.type = Collider;
};
Collider.prototype = Object.create(WrapperObject.prototype);
Collider.prototype.constructor = Collider;
Collider.prototype.__class__ = Collider;
Collider.__cache__ = {};
Module['Collider'] = Collider;
Object.defineProperty(Collider.prototype, "spatial", {
    get: function() {
        var self = this.ptr;
        return _toy_Collider__get_spatial(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <toy::HSpatial> [] */
        _toy_Collider__set_spatial(self, value);
    }
});
Object.defineProperty(Collider.prototype, "movable", {
    get: function() {
        var self = this.ptr;
        return _toy_Collider__get_movable(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <toy::HMovable> [] */
        _toy_Collider__set_movable(self, value);
    }
});
Object.defineProperty(Collider.prototype, "collision_shape", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider__get_collision_shape(self), CollisionShape);
    }});
Object.defineProperty(Collider.prototype, "medium", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider__get_medium(self), Medium);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Medium> [] */
        value = value.ptr;
        _toy_Collider__set_medium(self, value);
    }
});
Object.defineProperty(Collider.prototype, "group", {
    get: function() {
        var self = this.ptr;
        return _toy_Collider__get_group(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <CollisionGroup> [] */
        if (value && typeof value === "object") value = value.ptr;
        _toy_Collider__set_group(self, value);
    }
});
Object.defineProperty(Collider.prototype, "object", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider__get_object(self), ColliderObject);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <ColliderObject> [] */
        value = value.ptr;
        _toy_Collider__set_object(self, value);
    }
});
Object.defineProperty(Collider.prototype, "impl", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider__get_impl(self), ColliderImpl);
    }});
Collider.prototype["__destroy__"] = Collider.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Collider__destroy(self);
};
// ColliderImpl
function ColliderImpl() { throw "cannot construct a ColliderImpl, no constructor in IDL" }
ColliderImpl.prototype = Object.create(WrapperObject.prototype);
ColliderImpl.prototype.constructor = ColliderImpl;
ColliderImpl.prototype.__class__ = ColliderImpl;
ColliderImpl.__cache__ = {};
Module['ColliderImpl'] = ColliderImpl;
ColliderImpl.prototype["__destroy__"] = ColliderImpl.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_ColliderImpl__destroy(self);
};
// ColliderObject
function ColliderObject() { throw "cannot construct a ColliderObject, no constructor in IDL" }
ColliderObject.prototype = Object.create(WrapperObject.prototype);
ColliderObject.prototype.constructor = ColliderObject;
ColliderObject.prototype.__class__ = ColliderObject;
ColliderObject.__cache__ = {};
Module['ColliderObject'] = ColliderObject;
ColliderObject.prototype["__destroy__"] = ColliderObject.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_ColliderObject__destroy(self);
};
// Collision
function Collision() {
    this.ptr = _toy_Collision_Collision_0(); getCache(Collision)[this.ptr] = this;
    this.type = Collision;
};
Collision.prototype = Object.create(WrapperObject.prototype);
Collision.prototype.constructor = Collision;
Collision.prototype.__class__ = Collision;
Collision.__cache__ = {};
Module['Collision'] = Collision;
Object.defineProperty(Collision.prototype, "first", {
    get: function() {
        var self = this.ptr;
        return _toy_Collision__get_first(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <toy::HCollider> [] */
        _toy_Collision__set_first(self, value);
    }
});
Object.defineProperty(Collision.prototype, "second", {
    get: function() {
        var self = this.ptr;
        return _toy_Collision__get_second(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <toy::HCollider> [] */
        _toy_Collision__set_second(self, value);
    }
});
Object.defineProperty(Collision.prototype, "hit_point", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collision__get_hit_point(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _toy_Collision__set_hit_point(self, value);
    }
});
Collision.prototype["__destroy__"] = Collision.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Collision__destroy(self);
};
// CollisionShape
function CollisionShape(shape, center, margin) {
    /* shape <Shape> [] */
    if(typeof shape !== "undefined" && shape !== null) { shape = shape.ptr; }
    /* center <vec3> [] */
    if(typeof center !== "undefined" && center !== null) { center = center.ptr; }
    /* margin <float> [] */
    if (shape === undefined) { this.ptr = _toy_CollisionShape_CollisionShape_0(); getCache(CollisionShape)[this.ptr] = this; return; }
    if (center === undefined) { this.ptr = _toy_CollisionShape_CollisionShape_1(shape); getCache(CollisionShape)[this.ptr] = this; return; }
    if (margin === undefined) { this.ptr = _toy_CollisionShape_CollisionShape_2(shape, center); getCache(CollisionShape)[this.ptr] = this; return; }
    this.ptr = _toy_CollisionShape_CollisionShape_3(shape, center, margin); getCache(CollisionShape)[this.ptr] = this;
    this.type = CollisionShape;
};
CollisionShape.prototype = Object.create(WrapperObject.prototype);
CollisionShape.prototype.constructor = CollisionShape;
CollisionShape.prototype.__class__ = CollisionShape;
CollisionShape.__cache__ = {};
Module['CollisionShape'] = CollisionShape;
CollisionShape.prototype["__destroy__"] = CollisionShape.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_CollisionShape__destroy(self);
};
// ComponentPool
function ComponentPool() { throw "cannot construct a ComponentPool, no constructor in IDL" }
ComponentPool.prototype = Object.create(WrapperObject.prototype);
ComponentPool.prototype.constructor = ComponentPool;
ComponentPool.prototype.__class__ = ComponentPool;
ComponentPool.__cache__ = {};
Module['ComponentPool'] = ComponentPool;
ComponentPool.prototype["__destroy__"] = ComponentPool.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_ComponentPool__destroy(self);
};
// Core
function Core() { throw "cannot construct a Core, no constructor in IDL" }
Core.prototype = Object.create(WrapperObject.prototype);
Core.prototype.constructor = Core;
Core.prototype.__class__ = Core;
Core.__cache__ = {};
Module['Core'] = Core;
Core.prototype["__destroy__"] = Core.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Core__destroy(self);
};
// DetourPath
function DetourPath() { throw "cannot construct a DetourPath, no constructor in IDL" }
DetourPath.prototype = Object.create(WrapperObject.prototype);
DetourPath.prototype.constructor = DetourPath;
DetourPath.prototype.__class__ = DetourPath;
DetourPath.__cache__ = {};
Module['DetourPath'] = DetourPath;
DetourPath.prototype["__destroy__"] = DetourPath.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_DetourPath__destroy(self);
};
// Emitter
function Emitter(spatial) {
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Emitter_Emitter_0(); getCache(Emitter)[this.ptr] = this; return; }
    this.ptr = _toy_Emitter_Emitter_1(spatial); getCache(Emitter)[this.ptr] = this;
    this.type = Emitter;
};
Emitter.prototype = Object.create(WrapperObject.prototype);
Emitter.prototype.constructor = Emitter;
Emitter.prototype.__class__ = Emitter;
Emitter.__cache__ = {};
Module['Emitter'] = Emitter;
Emitter.prototype["__destroy__"] = Emitter.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Emitter__destroy(self);
};
// EntityScript
function EntityScript(spatial) {
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_EntityScript_EntityScript_0(); getCache(EntityScript)[this.ptr] = this; return; }
    this.ptr = _toy_EntityScript_EntityScript_1(spatial); getCache(EntityScript)[this.ptr] = this;
    this.type = EntityScript;
};
EntityScript.prototype = Object.create(WrapperObject.prototype);
EntityScript.prototype.constructor = EntityScript;
EntityScript.prototype.__class__ = EntityScript;
EntityScript.__cache__ = {};
Module['EntityScript'] = EntityScript;
Object.defineProperty(EntityScript.prototype, "logic_script", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_EntityScript__get_logic_script(self), Script);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Script> [] */
        value = value.ptr;
        _toy_EntityScript__set_logic_script(self, value);
    }
});
Object.defineProperty(EntityScript.prototype, "render_script", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_EntityScript__get_render_script(self), Script);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Script> [] */
        value = value.ptr;
        _toy_EntityScript__set_render_script(self, value);
    }
});
EntityScript.prototype["__destroy__"] = EntityScript.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_EntityScript__destroy(self);
};
// Medium
function Medium() { throw "cannot construct a Medium, no constructor in IDL" }
Medium.prototype = Object.create(WrapperObject.prototype);
Medium.prototype.constructor = Medium;
Medium.prototype.__class__ = Medium;
Medium.__cache__ = {};
Module['Medium'] = Medium;
Object.defineProperty(Medium.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_toy_Medium__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _toy_Medium__set_name(self, value);
    }
});
Object.defineProperty(Medium.prototype, "occlusions", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Medium__get_occlusions(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Medium__set_occlusions(self, value);
    }
});
Object.defineProperty(Medium.prototype, "solid", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Medium__get_solid(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Medium__set_solid(self, value);
    }
});
Medium.prototype["__destroy__"] = Medium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Medium__destroy(self);
};
// Movable
function Movable(spatial) {
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Movable_Movable_0(); getCache(Movable)[this.ptr] = this; return; }
    this.ptr = _toy_Movable_Movable_1(spatial); getCache(Movable)[this.ptr] = this;
    this.type = Movable;
};
Movable.prototype = Object.create(WrapperObject.prototype);
Movable.prototype.constructor = Movable;
Movable.prototype.__class__ = Movable;
Movable.__cache__ = {};
Module['Movable'] = Movable;
Movable.prototype["set_linear_velocity"] = Movable.prototype.set_linear_velocity = function(self, velocity) {
    var self = this.ptr;
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_set_linear_velocity_1(self, velocity);
};
Movable.prototype["modify_linear_velocity"] = Movable.prototype.modify_linear_velocity = function(self, velocity) {
    var self = this.ptr;
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_modify_linear_velocity_1(self, velocity);
};
Movable.prototype["set_angular_velocity"] = Movable.prototype.set_angular_velocity = function(self, velocity) {
    var self = this.ptr;
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_set_angular_velocity_1(self, velocity);
};
Movable.prototype["modify_angular_velocity"] = Movable.prototype.modify_angular_velocity = function(self, velocity) {
    var self = this.ptr;
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_modify_angular_velocity_1(self, velocity);
};
Object.defineProperty(Movable.prototype, "linear_velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Movable__get_linear_velocity(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _toy_Movable__set_linear_velocity(self, value);
    }
});
Object.defineProperty(Movable.prototype, "angular_velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Movable__get_angular_velocity(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _toy_Movable__set_angular_velocity(self, value);
    }
});
Object.defineProperty(Movable.prototype, "moving", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Movable__get_moving(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Movable__set_moving(self, value);
    }
});
Object.defineProperty(Movable.prototype, "previous_position", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Movable__get_previous_position(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _toy_Movable__set_previous_position(self, value);
    }
});
Movable.prototype["__destroy__"] = Movable.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Movable__destroy(self);
};
// Navblock
function Navblock(spatial, world_page, navmesh) {
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navmesh <Navmesh> [] */
    if(typeof navmesh !== "undefined" && navmesh !== null) { navmesh = navmesh.ptr; }
    if (spatial === undefined) { this.ptr = _toy_Navblock_Navblock_0(); getCache(Navblock)[this.ptr] = this; return; }
    this.ptr = _toy_Navblock_Navblock_3(spatial, world_page, navmesh); getCache(Navblock)[this.ptr] = this;
    this.type = Navblock;
};
Navblock.prototype = Object.create(WrapperObject.prototype);
Navblock.prototype.constructor = Navblock;
Navblock.prototype.__class__ = Navblock;
Navblock.__cache__ = {};
Module['Navblock'] = Navblock;
Object.defineProperty(Navblock.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Navblock__get_navmesh(self), Navmesh);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <Navmesh> [] */
        value = value.ptr;
        _toy_Navblock__set_navmesh(self, value);
    }
});
Object.defineProperty(Navblock.prototype, "auto_update", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Navblock__get_auto_update(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Navblock__set_auto_update(self, value);
    }
});
Object.defineProperty(Navblock.prototype, "updated", {
    get: function() {
        var self = this.ptr;
        return _toy_Navblock__get_updated(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <size_t> [] */
        _toy_Navblock__set_updated(self, value);
    }
});
Navblock.prototype["__destroy__"] = Navblock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Navblock__destroy(self);
};
// Navmesh
function Navmesh(world) {
    /* world <World> [] */
    world = world.ptr;
    this.ptr = _toy_Navmesh_Navmesh_1(world); getCache(Navmesh)[this.ptr] = this;
    this.type = Navmesh;
};
Navmesh.prototype = Object.create(WrapperObject.prototype);
Navmesh.prototype.constructor = Navmesh;
Navmesh.prototype.__class__ = Navmesh;
Navmesh.__cache__ = {};
Module['Navmesh'] = Navmesh;
Object.defineProperty(Navmesh.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Navmesh__get_world(self), World);
    }});
Object.defineProperty(Navmesh.prototype, "updated", {
    get: function() {
        var self = this.ptr;
        return _toy_Navmesh__get_updated(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <size_t> [] */
        _toy_Navmesh__set_updated(self, value);
    }
});
Object.defineProperty(Navmesh.prototype, "dirty", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Navmesh__get_dirty(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Navmesh__set_dirty(self, value);
    }
});
Navmesh.prototype["__destroy__"] = Navmesh.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Navmesh__destroy(self);
};
// Origin
function Origin(spatial) {
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Origin_Origin_0(); getCache(Origin)[this.ptr] = this; return; }
    this.ptr = _toy_Origin_Origin_1(spatial); getCache(Origin)[this.ptr] = this;
    this.type = Origin;
};
Origin.prototype = Object.create(WrapperObject.prototype);
Origin.prototype.constructor = Origin;
Origin.prototype.__class__ = Origin;
Origin.__cache__ = {};
Module['Origin'] = Origin;
Origin.prototype["__destroy__"] = Origin.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Origin__destroy(self);
};
// Pathfinder
function Pathfinder(navmesh) {
    /* navmesh <Navmesh> [] */
    navmesh = navmesh.ptr;
    this.ptr = _toy_Pathfinder_Pathfinder_1(navmesh); getCache(Pathfinder)[this.ptr] = this;
    this.type = Pathfinder;
};
Pathfinder.prototype = Object.create(WrapperObject.prototype);
Pathfinder.prototype.constructor = Pathfinder;
Pathfinder.prototype.__class__ = Pathfinder;
Pathfinder.__cache__ = {};
Module['Pathfinder'] = Pathfinder;
Pathfinder.prototype["__destroy__"] = Pathfinder.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Pathfinder__destroy(self);
};
// PhysicWorld
function PhysicWorld() { throw "cannot construct a PhysicWorld, no constructor in IDL" }
PhysicWorld.prototype = Object.create(WrapperObject.prototype);
PhysicWorld.prototype.constructor = PhysicWorld;
PhysicWorld.prototype.__class__ = PhysicWorld;
PhysicWorld.__cache__ = {};
Module['PhysicWorld'] = PhysicWorld;
PhysicWorld.prototype["ground_point"] = PhysicWorld.prototype.ground_point = function(self, ray) {
    var self = this.ptr;
    /* ray <Ray> [] */
    ray = ray.ptr;
    return wrapPointer(_toy_PhysicWorld_ground_point_1(self, ray), vec3);
};
PhysicWorld.prototype["raycast"] = PhysicWorld.prototype.raycast = function(self, ray, mask) {
    var self = this.ptr;
    /* ray <Ray> [] */
    ray = ray.ptr;
    /* mask <short> [] */
    return wrapPointer(_toy_PhysicWorld_raycast_2(self, ray, mask), Collision);
};
Object.defineProperty(PhysicWorld.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_PhysicWorld__get_world(self), World);
    }});
PhysicWorld.prototype["__destroy__"] = PhysicWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_PhysicWorld__destroy(self);
};
// Receptor
function Receptor(spatial) {
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Receptor_Receptor_0(); getCache(Receptor)[this.ptr] = this; return; }
    this.ptr = _toy_Receptor_Receptor_1(spatial); getCache(Receptor)[this.ptr] = this;
    this.type = Receptor;
};
Receptor.prototype = Object.create(WrapperObject.prototype);
Receptor.prototype.constructor = Receptor;
Receptor.prototype.__class__ = Receptor;
Receptor.__cache__ = {};
Module['Receptor'] = Receptor;
Receptor.prototype["scope"] = Receptor.prototype.scope = function(self, medium) {
    var self = this.ptr;
    /* medium <Medium> [] */
    medium = medium.ptr;
    return wrapPointer(_toy_Receptor_scope_1(self, medium), ReceptorScope);
};
Receptor.prototype["__destroy__"] = Receptor.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Receptor__destroy(self);
};
// Solid
function Solid() { throw "cannot construct a Solid, no constructor in IDL" }
Solid.prototype = Object.create(WrapperObject.prototype);
Solid.prototype.constructor = Solid;
Solid.prototype.__class__ = Solid;
Solid.__cache__ = {};
Module['Solid'] = Solid;
Object.defineProperty(Solid.prototype, "spatial", {
    get: function() {
        var self = this.ptr;
        return _toy_Solid__get_spatial(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <toy::HSpatial> [] */
        _toy_Solid__set_spatial(self, value);
    }
});
Object.defineProperty(Solid.prototype, "static", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Solid__get_static(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_Solid__set_static(self, value);
    }
});
Object.defineProperty(Solid.prototype, "mass", {
    get: function() {
        var self = this.ptr;
        return _toy_Solid__get_mass(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Solid__set_mass(self, value);
    }
});
Solid.prototype["__destroy__"] = Solid.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Solid__destroy(self);
};
// SolidImpl
function SolidImpl() { throw "cannot construct a SolidImpl, no constructor in IDL" }
SolidImpl.prototype = Object.create(WrapperObject.prototype);
SolidImpl.prototype.constructor = SolidImpl;
SolidImpl.prototype.__class__ = SolidImpl;
SolidImpl.__cache__ = {};
Module['SolidImpl'] = SolidImpl;
SolidImpl.prototype["linear_velocity"] = SolidImpl.prototype.linear_velocity = function(self) {
    var self = this.ptr;
    return wrapPointer(_toy_SolidImpl_linear_velocity_0(self), vec3);
};
SolidImpl.prototype["angular_velocity"] = SolidImpl.prototype.angular_velocity = function(self) {
    var self = this.ptr;
    return wrapPointer(_toy_SolidImpl_angular_velocity_0(self), vec3);
};
SolidImpl.prototype["set_linear_velocity"] = SolidImpl.prototype.set_linear_velocity = function(self, force) {
    var self = this.ptr;
    /* force <vec3> [] */
    force = force.ptr;
    _toy_SolidImpl_set_linear_velocity_1(self, force);
};
SolidImpl.prototype["set_angular_velocity"] = SolidImpl.prototype.set_angular_velocity = function(self, torque) {
    var self = this.ptr;
    /* torque <vec3> [] */
    torque = torque.ptr;
    _toy_SolidImpl_set_angular_velocity_1(self, torque);
};
SolidImpl.prototype["set_angular_factor"] = SolidImpl.prototype.set_angular_factor = function(self, factor) {
    var self = this.ptr;
    /* factor <vec3> [] */
    factor = factor.ptr;
    _toy_SolidImpl_set_angular_factor_1(self, factor);
};
SolidImpl.prototype["impulse"] = SolidImpl.prototype.impulse = function(self, force, point) {
    var self = this.ptr;
    /* force <vec3> [] */
    force = force.ptr;
    /* point <vec3> [] */
    point = point.ptr;
    _toy_SolidImpl_impulse_2(self, force, point);
};
SolidImpl.prototype["__destroy__"] = SolidImpl.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_SolidImpl__destroy(self);
};
// User
function User() { throw "cannot construct a User, no constructor in IDL" }
User.prototype = Object.create(WrapperObject.prototype);
User.prototype.constructor = User;
User.prototype.__class__ = User;
User.__cache__ = {};
Module['User'] = User;
User.prototype["__destroy__"] = User.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_User__destroy(self);
};
// Waypoint
function Waypoint(parent) {
    /* parent <toy::HSpatial> [] */
    if (parent === undefined) { this.ptr = _toy_Waypoint_Waypoint_0(); getCache(Waypoint)[this.ptr] = this; return; }
    this.ptr = _toy_Waypoint_Waypoint_1(parent); getCache(Waypoint)[this.ptr] = this;
    this.type = Waypoint;
};
Waypoint.prototype = Object.create(WrapperObject.prototype);
Waypoint.prototype.constructor = Waypoint;
Waypoint.prototype.__class__ = Waypoint;
Waypoint.__cache__ = {};
Module['Waypoint'] = Waypoint;
Waypoint.prototype["__destroy__"] = Waypoint.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Waypoint__destroy(self);
};
// World
function World(id, complex, name, job_system) {
    ensureCache.prepare();
    /* id <uint32_t> [] */
    /* complex <Complex> [] */
    complex = complex.ptr;
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _toy_World_World_4(id, complex, name, job_system); getCache(World)[this.ptr] = this;
    this.type = World;
};
World.prototype = Object.create(WrapperObject.prototype);
World.prototype.constructor = World;
World.prototype.__class__ = World;
World.__cache__ = {};
Module['World'] = World;
Object.defineProperty(World.prototype, "id", {
    get: function() {
        var self = this.ptr;
        return _toy_World__get_id(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <uint32_t> [] */
        _toy_World__set_id(self, value);
    }
});
Object.defineProperty(World.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_toy_World__get_name(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <string> [] */
        if (value && typeof value === "object") value = value.ptr;
        else value = ensureString(value);
        _toy_World__set_name(self, value);
    }
});
Object.defineProperty(World.prototype, "origin", {
    get: function() {
        var self = this.ptr;
        return _toy_World__get_origin(self);
    }});
Object.defineProperty(World.prototype, "unworld", {
    get: function() {
        var self = this.ptr;
        return _toy_World__get_unworld(self);
    }});
World.prototype["__destroy__"] = World.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_World__destroy(self);
};
// WorldClock
function WorldClock() { throw "cannot construct a WorldClock, no constructor in IDL" }
WorldClock.prototype = Object.create(WrapperObject.prototype);
WorldClock.prototype.constructor = WorldClock;
WorldClock.prototype.__class__ = WorldClock;
WorldClock.__cache__ = {};
Module['WorldClock'] = WorldClock;
WorldClock.prototype["__destroy__"] = WorldClock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_WorldClock__destroy(self);
};
// WorldPage
function WorldPage(spatial, open, extents) {
    /* spatial <toy::HSpatial> [] */
    /* open <bool> [] */
    /* extents <vec3> [] */
    if(typeof extents !== "undefined" && extents !== null) { extents = extents.ptr; }
    if (spatial === undefined) { this.ptr = _toy_WorldPage_WorldPage_0(); getCache(WorldPage)[this.ptr] = this; return; }
    this.ptr = _toy_WorldPage_WorldPage_3(spatial, open, extents); getCache(WorldPage)[this.ptr] = this;
    this.type = WorldPage;
};
WorldPage.prototype = Object.create(WrapperObject.prototype);
WorldPage.prototype.constructor = WorldPage;
WorldPage.prototype.__class__ = WorldPage;
WorldPage.__cache__ = {};
Module['WorldPage'] = WorldPage;
WorldPage.prototype["update_geometry"] = WorldPage.prototype.update_geometry = function(self, tick) {
    var self = this.ptr;
    /* tick <size_t> [] */
    _toy_WorldPage_update_geometry_1(self, tick);
};
WorldPage.prototype["ground_point"] = WorldPage.prototype.ground_point = function(self, position, relative, outputPoint) {
    var self = this.ptr;
    /* position <vec3> [] */
    position = position.ptr;
    /* relative <bool> [] */
    /* outputPoint <vec3> [] */
    outputPoint = outputPoint.ptr;
    _toy_WorldPage_ground_point_3(self, position, relative, outputPoint);
};
WorldPage.prototype["raycast_ground"] = WorldPage.prototype.raycast_ground = function(self, from, to, ground_point) {
    var self = this.ptr;
    /* from <vec3> [] */
    from = from.ptr;
    /* to <vec3> [] */
    to = to.ptr;
    /* ground_point <vec3> [] */
    ground_point = ground_point.ptr;
    _toy_WorldPage_raycast_ground_3(self, from, to, ground_point);
};
Object.defineProperty(WorldPage.prototype, "open", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_WorldPage__get_open(self));
    },
    set: function(value) {
        var self = this.ptr;
        /* value <bool> [] */
        _toy_WorldPage__set_open(self, value);
    }
});
Object.defineProperty(WorldPage.prototype, "extents", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_WorldPage__get_extents(self), vec3);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <vec3> [] */
        value = value.ptr;
        _toy_WorldPage__set_extents(self, value);
    }
});
Object.defineProperty(WorldPage.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_WorldPage__get_world(self), World);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <World> [] */
        value = value.ptr;
        _toy_WorldPage__set_world(self, value);
    }
});
Object.defineProperty(WorldPage.prototype, "last_rebuilt", {
    get: function() {
        var self = this.ptr;
        return _toy_WorldPage__get_last_rebuilt(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <size_t> [] */
        _toy_WorldPage__set_last_rebuilt(self, value);
    }
});
WorldPage.prototype["__destroy__"] = WorldPage.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_WorldPage__destroy(self);
};
// BulletCollider
function BulletCollider() { throw "cannot construct a BulletCollider, no constructor in IDL" }
BulletCollider.prototype = Object.create(WrapperObject.prototype);
BulletCollider.prototype.constructor = BulletCollider;
BulletCollider.prototype.__class__ = BulletCollider;
BulletCollider.__cache__ = {};
Module['BulletCollider'] = BulletCollider;
BulletCollider.prototype["__destroy__"] = BulletCollider.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_BulletCollider__destroy(self);
};
// BulletSolid
function BulletSolid() { throw "cannot construct a BulletSolid, no constructor in IDL" }
BulletSolid.prototype = Object.create(WrapperObject.prototype);
BulletSolid.prototype.constructor = BulletSolid;
BulletSolid.prototype.__class__ = BulletSolid;
BulletSolid.__cache__ = {};
Module['BulletSolid'] = BulletSolid;
BulletSolid.prototype["__destroy__"] = BulletSolid.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_BulletSolid__destroy(self);
};
// BulletWorld
function BulletWorld(world) {
    /* world <World> [] */
    world = world.ptr;
    this.ptr = _toy_BulletWorld_BulletWorld_1(world); getCache(BulletWorld)[this.ptr] = this;
    this.type = BulletWorld;
};
BulletWorld.prototype = Object.create(WrapperObject.prototype);
BulletWorld.prototype.constructor = BulletWorld;
BulletWorld.prototype.__class__ = BulletWorld;
BulletWorld.__cache__ = {};
Module['BulletWorld'] = BulletWorld;
BulletWorld.prototype["__destroy__"] = BulletWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_BulletWorld__destroy(self);
};
// DefaultWorld
function DefaultWorld(name, job_system) {
    ensureCache.prepare();
    /* name <string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _toy_DefaultWorld_DefaultWorld_2(name, job_system); getCache(DefaultWorld)[this.ptr] = this;
    this.type = DefaultWorld;
};
DefaultWorld.prototype = Object.create(WrapperObject.prototype);
DefaultWorld.prototype.constructor = DefaultWorld;
DefaultWorld.prototype.__class__ = DefaultWorld;
DefaultWorld.__cache__ = {};
Module['DefaultWorld'] = DefaultWorld;
Object.defineProperty(DefaultWorld.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_DefaultWorld__get_world(self), World);
    }});
Object.defineProperty(DefaultWorld.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_DefaultWorld__get_bullet_world(self), BulletWorld);
    }});
Object.defineProperty(DefaultWorld.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_DefaultWorld__get_navmesh(self), Navmesh);
    }});
DefaultWorld.prototype["__destroy__"] = DefaultWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_DefaultWorld__destroy(self);
};
// EmitterScope
function EmitterScope() { throw "cannot construct a EmitterScope, no constructor in IDL" }
EmitterScope.prototype = Object.create(WrapperObject.prototype);
EmitterScope.prototype.constructor = EmitterScope;
EmitterScope.prototype.__class__ = EmitterScope;
EmitterScope.__cache__ = {};
Module['EmitterScope'] = EmitterScope;
EmitterScope.prototype["__destroy__"] = EmitterScope.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_EmitterScope__destroy(self);
};
// NavmeshShape
function NavmeshShape(navmesh) {
    /* navmesh <Navmesh> [] */
    navmesh = navmesh.ptr;
    this.ptr = _toy_NavmeshShape_NavmeshShape_1(navmesh); getCache(NavmeshShape)[this.ptr] = this;
    this.type = NavmeshShape;
};
NavmeshShape.prototype = Object.create(WrapperObject.prototype);
NavmeshShape.prototype.constructor = NavmeshShape;
NavmeshShape.prototype.__class__ = NavmeshShape;
NavmeshShape.__cache__ = {};
Module['NavmeshShape'] = NavmeshShape;
NavmeshShape.prototype["__destroy__"] = NavmeshShape.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_NavmeshShape__destroy(self);
};
// Obstacle
function Obstacle(spatial, movable, medium, shape, throughput) {
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* medium <Medium> [] */
    medium = medium.ptr;
    /* shape <CollisionShape> [] */
    shape = shape.ptr;
    /* throughput <float> [] */
    this.ptr = _toy_Obstacle_Obstacle_5(spatial, movable, medium, shape, throughput); getCache(Obstacle)[this.ptr] = this;
    this.type = Obstacle;
};
Obstacle.prototype = Object.create(WrapperObject.prototype);
Obstacle.prototype.constructor = Obstacle;
Obstacle.prototype.__class__ = Obstacle;
Obstacle.__cache__ = {};
Module['Obstacle'] = Obstacle;
Object.defineProperty(Obstacle.prototype, "shape", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Obstacle__get_shape(self), CollisionShape);
    }});
Object.defineProperty(Obstacle.prototype, "throughput", {
    get: function() {
        var self = this.ptr;
        return _toy_Obstacle__get_throughput(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <float> [] */
        _toy_Obstacle__set_throughput(self, value);
    }
});
Obstacle.prototype["__destroy__"] = Obstacle.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Obstacle__destroy(self);
};
// PhysicScope
function PhysicScope() { throw "cannot construct a PhysicScope, no constructor in IDL" }
PhysicScope.prototype = Object.create(WrapperObject.prototype);
PhysicScope.prototype.constructor = PhysicScope;
PhysicScope.prototype.__class__ = PhysicScope;
PhysicScope.__cache__ = {};
Module['PhysicScope'] = PhysicScope;
PhysicScope.prototype["__destroy__"] = PhysicScope.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_PhysicScope__destroy(self);
};
// ReceptorScope
function ReceptorScope() { throw "cannot construct a ReceptorScope, no constructor in IDL" }
ReceptorScope.prototype = Object.create(WrapperObject.prototype);
ReceptorScope.prototype.constructor = ReceptorScope;
ReceptorScope.prototype.__class__ = ReceptorScope;
ReceptorScope.__cache__ = {};
Module['ReceptorScope'] = ReceptorScope;
ReceptorScope.prototype["__destroy__"] = ReceptorScope.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_ReceptorScope__destroy(self);
};
// SolidMedium
function SolidMedium() {
    this.ptr = _toy_SolidMedium_SolidMedium_0(); getCache(SolidMedium)[this.ptr] = this;
    this.type = SolidMedium;
};
SolidMedium.prototype = Object.create(WrapperObject.prototype);
SolidMedium.prototype.constructor = SolidMedium;
SolidMedium.prototype.__class__ = SolidMedium;
SolidMedium.__cache__ = {};
Module['SolidMedium'] = SolidMedium;
SolidMedium.prototype["__destroy__"] = SolidMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_SolidMedium__destroy(self);
};
// SoundMedium
function SoundMedium() {
    this.ptr = _toy_SoundMedium_SoundMedium_0(); getCache(SoundMedium)[this.ptr] = this;
    this.type = SoundMedium;
};
SoundMedium.prototype = Object.create(WrapperObject.prototype);
SoundMedium.prototype.constructor = SoundMedium;
SoundMedium.prototype.__class__ = SoundMedium;
SoundMedium.__cache__ = {};
Module['SoundMedium'] = SoundMedium;
SoundMedium.prototype["__destroy__"] = SoundMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_SoundMedium__destroy(self);
};
// Spatial
function Spatial(parent, position, rotation) {
    /* parent <toy::HSpatial> [] */
    /* position <vec3> [] */
    if(typeof position !== "undefined" && position !== null) { position = position.ptr; }
    /* rotation <quat> [] */
    if(typeof rotation !== "undefined" && rotation !== null) { rotation = rotation.ptr; }
    if (parent === undefined) { this.ptr = _toy_Spatial_Spatial_0(); getCache(Spatial)[this.ptr] = this; return; }
    this.ptr = _toy_Spatial_Spatial_3(parent, position, rotation); getCache(Spatial)[this.ptr] = this;
    this.type = Spatial;
};
Spatial.prototype = Object.create(WrapperObject.prototype);
Spatial.prototype.constructor = Spatial;
Spatial.prototype.__class__ = Spatial;
Spatial.__cache__ = {};
Module['Spatial'] = Spatial;
Spatial.prototype["set_position"] = Spatial.prototype.set_position = function(self, position) {
    var self = this.ptr;
    /* position <vec3> [] */
    position = position.ptr;
    _toy_Spatial_set_position_1(self, position);
};
Spatial.prototype["set_rotation"] = Spatial.prototype.set_rotation = function(self, rotation) {
    var self = this.ptr;
    /* rotation <quat> [] */
    rotation = rotation.ptr;
    _toy_Spatial_set_rotation_1(self, rotation);
};
Object.defineProperty(Spatial.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Spatial__get_world(self), World);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <World> [] */
        value = value.ptr;
        _toy_Spatial__set_world(self, value);
    }
});
Object.defineProperty(Spatial.prototype, "parent", {
    get: function() {
        var self = this.ptr;
        return _toy_Spatial__get_parent(self);
    },
    set: function(value) {
        var self = this.ptr;
        /* value <toy::HSpatial> [] */
        _toy_Spatial__set_parent(self, value);
    }
});
Spatial.prototype["__destroy__"] = Spatial.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Spatial__destroy(self);
};
// VisualMedium
function VisualMedium() {
    this.ptr = _toy_VisualMedium_VisualMedium_0(); getCache(VisualMedium)[this.ptr] = this;
    this.type = VisualMedium;
};
VisualMedium.prototype = Object.create(WrapperObject.prototype);
VisualMedium.prototype.constructor = VisualMedium;
VisualMedium.prototype.__class__ = VisualMedium;
VisualMedium.__cache__ = {};
Module['VisualMedium'] = VisualMedium;
VisualMedium.prototype["__destroy__"] = VisualMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_VisualMedium__destroy(self);
};
// WorldMedium
function WorldMedium() {
    this.ptr = _toy_WorldMedium_WorldMedium_0(); getCache(WorldMedium)[this.ptr] = this;
    this.type = WorldMedium;
};
WorldMedium.prototype = Object.create(WrapperObject.prototype);
WorldMedium.prototype.constructor = WorldMedium;
WorldMedium.prototype.__class__ = WorldMedium;
WorldMedium.__cache__ = {};
Module['WorldMedium'] = WorldMedium;
WorldMedium.prototype["__destroy__"] = WorldMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_WorldMedium__destroy(self);
};
Module['move_2d'] = function(spatial, movable, target, velocity, time_step, margin) {
    var self = this.ptr;
    /* spatial <Spatial> [] */
    spatial = spatial.ptr;
    /* movable <Movable> [] */
    movable = movable.ptr;
    /* target <vec3> [] */
    target = target.ptr;
    /* velocity <float> [] */
    /* time_step <float> [] */
    /* margin <float> [] */
    if (margin === undefined) { return !!(_toy_move_2d_5(spatial, movable, target, velocity, time_step)); }
    return !!(_toy_move_2d_6(spatial, movable, target, velocity, time_step, margin));
};
Module['steer_2d'] = function(spatial, movable, target, velocity, time_step, margin) {
    var self = this.ptr;
    /* spatial <Spatial> [] */
    spatial = spatial.ptr;
    /* movable <Movable> [] */
    movable = movable.ptr;
    /* target <vec3> [] */
    target = target.ptr;
    /* velocity <float> [] */
    /* time_step <float> [] */
    /* margin <float> [] */
    if (margin === undefined) { return !!(_toy_steer_2d_5(spatial, movable, target, velocity, time_step)); }
    return !!(_toy_steer_2d_6(spatial, movable, target, velocity, time_step, margin));
};

(function() {
    function setup() {
        BulletMedium.__type__ = _toy_BulletMedium__type();
        BulletShape.__type__ = _toy_BulletShape__type();
        Camera.__type__ = _toy_Camera__type();
        Collider.__type__ = _toy_Collider__type();
        ColliderImpl.__type__ = _toy_ColliderImpl__type();
        ColliderObject.__type__ = _toy_ColliderObject__type();
        Collision.__type__ = _toy_Collision__type();
        CollisionShape.__type__ = _toy_CollisionShape__type();
        ComponentPool.__type__ = _toy_ComponentPool__type();
        Core.__type__ = _toy_Core__type();
        DetourPath.__type__ = _toy_DetourPath__type();
        Emitter.__type__ = _toy_Emitter__type();
        EntityScript.__type__ = _toy_EntityScript__type();
        Medium.__type__ = _toy_Medium__type();
        Movable.__type__ = _toy_Movable__type();
        Navblock.__type__ = _toy_Navblock__type();
        Navmesh.__type__ = _toy_Navmesh__type();
        Origin.__type__ = _toy_Origin__type();
        Pathfinder.__type__ = _toy_Pathfinder__type();
        PhysicWorld.__type__ = _toy_PhysicWorld__type();
        Receptor.__type__ = _toy_Receptor__type();
        Solid.__type__ = _toy_Solid__type();
        SolidImpl.__type__ = _toy_SolidImpl__type();
        User.__type__ = _toy_User__type();
        Waypoint.__type__ = _toy_Waypoint__type();
        World.__type__ = _toy_World__type();
        WorldClock.__type__ = _toy_WorldClock__type();
        WorldPage.__type__ = _toy_WorldPage__type();
        BulletCollider.__type__ = _toy_BulletCollider__type();
        BulletSolid.__type__ = _toy_BulletSolid__type();
        BulletWorld.__type__ = _toy_BulletWorld__type();
        DefaultWorld.__type__ = _toy_DefaultWorld__type();
        EmitterScope.__type__ = _toy_EmitterScope__type();
        NavmeshShape.__type__ = _toy_NavmeshShape__type();
        Obstacle.__type__ = _toy_Obstacle__type();
        PhysicScope.__type__ = _toy_PhysicScope__type();
        ReceptorScope.__type__ = _toy_ReceptorScope__type();
        SolidMedium.__type__ = _toy_SolidMedium__type();
        SoundMedium.__type__ = _toy_SoundMedium__type();
        Spatial.__type__ = _toy_Spatial__type();
        VisualMedium.__type__ = _toy_VisualMedium__type();
        WorldMedium.__type__ = _toy_WorldMedium__type();
        // CollisionGroup
        Module['CM_NOMASK'] = _toy_CollisionGroup_CM_NOMASK();
        Module['CM_OBJECT'] = _toy_CollisionGroup_CM_OBJECT();
        Module['CM_SOLID'] = _toy_CollisionGroup_CM_SOLID();
        Module['CM_GROUND'] = _toy_CollisionGroup_CM_GROUND();
        Module['CM_AREA'] = _toy_CollisionGroup_CM_AREA();
        Module['CM_BUFFER'] = _toy_CollisionGroup_CM_BUFFER();
        Module['CM_LIGHT'] = _toy_CollisionGroup_CM_LIGHT();
        Module['CM_LIGHTREFLECTOR'] = _toy_CollisionGroup_CM_LIGHTREFLECTOR();
        Module['CM_SOURCE'] = _toy_CollisionGroup_CM_SOURCE();
        Module['CM_RECEPTOR'] = _toy_CollisionGroup_CM_RECEPTOR();
        Module['CM_OBSTACLE'] = _toy_CollisionGroup_CM_OBSTACLE();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
