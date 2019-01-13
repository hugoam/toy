
// Bindings utilities
function WrapperObject() {
}
// BulletMedium
function BulletMedium() { throw "cannot construct a BulletMedium, no constructor in IDL" }
BulletMedium.prototype = Object.create(WrapperObject.prototype);
BulletMedium.prototype.constructor = BulletMedium;
BulletMedium.prototype.__class__ = BulletMedium;
BulletMedium.__cache__ = {};
Module['BulletMedium'] = BulletMedium;
BulletMedium.prototype["__destroy__"] = BulletMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_BulletMedium___destroy__(self);
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
    _toy_BulletShape___destroy__(self);
};
// Camera
function Camera(spatial, lens_distance, near, far) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* lens_distance <float> [] */
    /* near <float> [] */
    /* far <float> [] */
    if (spatial === undefined) { this.ptr = _toy_Camera_Camera_0(self); getCache(Camera)[this.ptr] = this; return; }
    if (lens_distance === undefined) { this.ptr = _toy_Camera_Camera_1(self, spatial); getCache(Camera)[this.ptr] = this; return; }
    if (near === undefined) { this.ptr = _toy_Camera_Camera_2(self, spatial, lens_distance); getCache(Camera)[this.ptr] = this; return; }
    if (far === undefined) { this.ptr = _toy_Camera_Camera_3(self, spatial, lens_distance, near); getCache(Camera)[this.ptr] = this; return; }
    this.ptr = _toy_Camera_Camera_4(self, spatial, lens_distance, near, far); getCache(Camera)[this.ptr] = this;
};
Camera.prototype = Object.create(WrapperObject.prototype);
Camera.prototype.constructor = Camera;
Camera.prototype.__class__ = Camera;
Camera.__cache__ = {};
Module['Camera'] = Camera;
Object.defineProperty(Camera.prototype, "lens_distance", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera_get_lens_distance(self);
    },
    set: function(lens_distance) {
        var self = this.ptr;
        /* lens_distance <float> [] */
        _toy_Camera_set_lens_distance(self, lens_distance);
    }
});
Object.defineProperty(Camera.prototype, "lens_angle", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera_get_lens_angle(self);
    },
    set: function(lens_angle) {
        var self = this.ptr;
        /* lens_angle <float> [] */
        _toy_Camera_set_lens_angle(self, lens_angle);
    }
});
Object.defineProperty(Camera.prototype, "near", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera_get_near(self);
    },
    set: function(near) {
        var self = this.ptr;
        /* near <float> [] */
        _toy_Camera_set_near(self, near);
    }
});
Object.defineProperty(Camera.prototype, "far", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera_get_far(self);
    },
    set: function(far) {
        var self = this.ptr;
        /* far <float> [] */
        _toy_Camera_set_far(self, far);
    }
});
Object.defineProperty(Camera.prototype, "aspect", {
    get: function() {
        var self = this.ptr;
        return _toy_Camera_get_aspect(self);
    },
    set: function(aspect) {
        var self = this.ptr;
        /* aspect <float> [] */
        _toy_Camera_set_aspect(self, aspect);
    }
});
Camera.prototype["__destroy__"] = Camera.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Camera___destroy__(self);
};
// Collider
function Collider(spatial, movable, collision_shape, medium, group) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* collision_shape <CollisionShape> [] */
    collision_shape = collision_shape.ptr;
    /* medium <Medium> [] */
    medium = medium.ptr;
    /* group <CollisionGroup> [] */
    if (group && typeof group === "object") group = group.ptr;
    if (spatial === undefined) { this.ptr = _toy_Collider_Collider_0(self); getCache(Collider)[this.ptr] = this; return; }
    this.ptr = _toy_Collider_Collider_5(self, spatial, movable, collision_shape, medium, group); getCache(Collider)[this.ptr] = this;
};
Collider.prototype = Object.create(WrapperObject.prototype);
Collider.prototype.constructor = Collider;
Collider.prototype.__class__ = Collider;
Collider.__cache__ = {};
Module['Collider'] = Collider;
Object.defineProperty(Collider.prototype, "spatial", {
    get: function() {
        var self = this.ptr;
        return _toy_Collider_get_spatial(self);
    },
    set: function(spatial) {
        var self = this.ptr;
        /* spatial <toy::HSpatial> [] */
        _toy_Collider_set_spatial(self, spatial);
    }
});
Object.defineProperty(Collider.prototype, "movable", {
    get: function() {
        var self = this.ptr;
        return _toy_Collider_get_movable(self);
    },
    set: function(movable) {
        var self = this.ptr;
        /* movable <toy::HMovable> [] */
        _toy_Collider_set_movable(self, movable);
    }
});
Object.defineProperty(Collider.prototype, "collision_shape", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider_get_collision_shape(self), toy::CollisionShape);
    }});
Object.defineProperty(Collider.prototype, "medium", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider_get_medium(self), toy::Medium);
    },
    set: function(medium) {
        var self = this.ptr;
        /* medium <Medium> [] */
        medium = medium.ptr;
        _toy_Collider_set_medium(self, medium);
    }
});
Object.defineProperty(Collider.prototype, "group", {
    get: function() {
        var self = this.ptr;
        return _toy_Collider_get_group(self);
    },
    set: function(group) {
        var self = this.ptr;
        /* group <CollisionGroup> [] */
        if (group && typeof group === "object") group = group.ptr;
        _toy_Collider_set_group(self, group);
    }
});
Object.defineProperty(Collider.prototype, "object", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider_get_object(self), toy::ColliderObject);
    },
    set: function(object) {
        var self = this.ptr;
        /* object <ColliderObject> [] */
        object = object.ptr;
        _toy_Collider_set_object(self, object);
    }
});
Object.defineProperty(Collider.prototype, "impl", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collider_get_impl(self), toy::ColliderImpl);
    }});
Collider.prototype["__destroy__"] = Collider.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Collider___destroy__(self);
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
    _toy_ColliderImpl___destroy__(self);
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
    _toy_ColliderObject___destroy__(self);
};
// Collision
function Collision() {
    var self = this.ptr;
    this.ptr = _toy_Collision_Collision_0(self); getCache(Collision)[this.ptr] = this;
};
Collision.prototype = Object.create(WrapperObject.prototype);
Collision.prototype.constructor = Collision;
Collision.prototype.__class__ = Collision;
Collision.__cache__ = {};
Module['Collision'] = Collision;
Object.defineProperty(Collision.prototype, "first", {
    get: function() {
        var self = this.ptr;
        return _toy_Collision_get_first(self);
    },
    set: function(first) {
        var self = this.ptr;
        /* first <toy::HCollider> [] */
        _toy_Collision_set_first(self, first);
    }
});
Object.defineProperty(Collision.prototype, "second", {
    get: function() {
        var self = this.ptr;
        return _toy_Collision_get_second(self);
    },
    set: function(second) {
        var self = this.ptr;
        /* second <toy::HCollider> [] */
        _toy_Collision_set_second(self, second);
    }
});
Object.defineProperty(Collision.prototype, "hit_point", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Collision_get_hit_point(self), mud::vec3);
    },
    set: function(hit_point) {
        var self = this.ptr;
        /* hit_point <vec3> [] */
        hit_point = hit_point.ptr;
        _toy_Collision_set_hit_point(self, hit_point);
    }
});
Collision.prototype["__destroy__"] = Collision.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Collision___destroy__(self);
};
// CollisionShape
function CollisionShape(shape, center, margin) {
    var self = this.ptr;
    /* shape <Shape> [] */
    shape = shape.ptr;
    /* center <vec3> [] */
    center = center.ptr;
    /* margin <float> [] */
    if (shape === undefined) { this.ptr = _toy_CollisionShape_CollisionShape_0(self); getCache(CollisionShape)[this.ptr] = this; return; }
    if (center === undefined) { this.ptr = _toy_CollisionShape_CollisionShape_1(self, shape); getCache(CollisionShape)[this.ptr] = this; return; }
    if (margin === undefined) { this.ptr = _toy_CollisionShape_CollisionShape_2(self, shape, center); getCache(CollisionShape)[this.ptr] = this; return; }
    this.ptr = _toy_CollisionShape_CollisionShape_3(self, shape, center, margin); getCache(CollisionShape)[this.ptr] = this;
};
CollisionShape.prototype = Object.create(WrapperObject.prototype);
CollisionShape.prototype.constructor = CollisionShape;
CollisionShape.prototype.__class__ = CollisionShape;
CollisionShape.__cache__ = {};
Module['CollisionShape'] = CollisionShape;
CollisionShape.prototype["__destroy__"] = CollisionShape.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_CollisionShape___destroy__(self);
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
    _toy_ComponentPool___destroy__(self);
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
    _toy_Core___destroy__(self);
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
    _toy_DetourPath___destroy__(self);
};
// Emitter
function Emitter(spatial) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Emitter_Emitter_0(self); getCache(Emitter)[this.ptr] = this; return; }
    this.ptr = _toy_Emitter_Emitter_1(self, spatial); getCache(Emitter)[this.ptr] = this;
};
Emitter.prototype = Object.create(WrapperObject.prototype);
Emitter.prototype.constructor = Emitter;
Emitter.prototype.__class__ = Emitter;
Emitter.__cache__ = {};
Module['Emitter'] = Emitter;
Emitter.prototype["__destroy__"] = Emitter.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Emitter___destroy__(self);
};
// EntityScript
function EntityScript(spatial) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_EntityScript_EntityScript_0(self); getCache(EntityScript)[this.ptr] = this; return; }
    this.ptr = _toy_EntityScript_EntityScript_1(self, spatial); getCache(EntityScript)[this.ptr] = this;
};
EntityScript.prototype = Object.create(WrapperObject.prototype);
EntityScript.prototype.constructor = EntityScript;
EntityScript.prototype.__class__ = EntityScript;
EntityScript.__cache__ = {};
Module['EntityScript'] = EntityScript;
Object.defineProperty(EntityScript.prototype, "logic_script", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_EntityScript_get_logic_script(self), mud::Script);
    },
    set: function(logic_script) {
        var self = this.ptr;
        /* logic_script <Script> [] */
        logic_script = logic_script.ptr;
        _toy_EntityScript_set_logic_script(self, logic_script);
    }
});
Object.defineProperty(EntityScript.prototype, "render_script", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_EntityScript_get_render_script(self), mud::Script);
    },
    set: function(render_script) {
        var self = this.ptr;
        /* render_script <Script> [] */
        render_script = render_script.ptr;
        _toy_EntityScript_set_render_script(self, render_script);
    }
});
EntityScript.prototype["__destroy__"] = EntityScript.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_EntityScript___destroy__(self);
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
        return Pointer_stringify(_toy_Medium_get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _toy_Medium_set_name(self, name);
    }
});
Object.defineProperty(Medium.prototype, "occlusions", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Medium_get_occlusions(self));
    },
    set: function(occlusions) {
        var self = this.ptr;
        /* occlusions <bool> [] */
        _toy_Medium_set_occlusions(self, occlusions);
    }
});
Object.defineProperty(Medium.prototype, "solid", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Medium_get_solid(self));
    },
    set: function(solid) {
        var self = this.ptr;
        /* solid <bool> [] */
        _toy_Medium_set_solid(self, solid);
    }
});
Medium.prototype["__destroy__"] = Medium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Medium___destroy__(self);
};
// Movable
function Movable(spatial) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Movable_Movable_0(self); getCache(Movable)[this.ptr] = this; return; }
    this.ptr = _toy_Movable_Movable_1(self, spatial); getCache(Movable)[this.ptr] = this;
};
Movable.prototype = Object.create(WrapperObject.prototype);
Movable.prototype.constructor = Movable;
Movable.prototype.__class__ = Movable;
Movable.__cache__ = {};
Module['Movable'] = Movable;
Movable.prototype["modify_angular_velocity"] = Movable.prototype.modify_angular_velocity = function(velocity) {
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_modify_angular_velocity_1(velocity);
};
Movable.prototype["modify_linear_velocity"] = Movable.prototype.modify_linear_velocity = function(velocity) {
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_modify_linear_velocity_1(velocity);
};
Movable.prototype["set_angular_velocity"] = Movable.prototype.set_angular_velocity = function(velocity) {
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_set_angular_velocity_1(velocity);
};
Movable.prototype["set_linear_velocity"] = Movable.prototype.set_linear_velocity = function(velocity) {
    /* velocity <vec3> [] */
    velocity = velocity.ptr;
    _toy_Movable_set_linear_velocity_1(velocity);
};
Object.defineProperty(Movable.prototype, "linear_velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Movable_get_linear_velocity(self), mud::vec3);
    },
    set: function(linear_velocity) {
        var self = this.ptr;
        /* linear_velocity <vec3> [] */
        linear_velocity = linear_velocity.ptr;
        _toy_Movable_set_linear_velocity(self, linear_velocity);
    }
});
Object.defineProperty(Movable.prototype, "angular_velocity", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Movable_get_angular_velocity(self), mud::vec3);
    },
    set: function(angular_velocity) {
        var self = this.ptr;
        /* angular_velocity <vec3> [] */
        angular_velocity = angular_velocity.ptr;
        _toy_Movable_set_angular_velocity(self, angular_velocity);
    }
});
Object.defineProperty(Movable.prototype, "moving", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Movable_get_moving(self));
    },
    set: function(moving) {
        var self = this.ptr;
        /* moving <bool> [] */
        _toy_Movable_set_moving(self, moving);
    }
});
Object.defineProperty(Movable.prototype, "previous_position", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Movable_get_previous_position(self), mud::vec3);
    },
    set: function(previous_position) {
        var self = this.ptr;
        /* previous_position <vec3> [] */
        previous_position = previous_position.ptr;
        _toy_Movable_set_previous_position(self, previous_position);
    }
});
Movable.prototype["__destroy__"] = Movable.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Movable___destroy__(self);
};
// Navblock
function Navblock(spatial, world_page, navmesh) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navmesh <Navmesh> [] */
    navmesh = navmesh.ptr;
    if (spatial === undefined) { this.ptr = _toy_Navblock_Navblock_0(self); getCache(Navblock)[this.ptr] = this; return; }
    this.ptr = _toy_Navblock_Navblock_3(self, spatial, world_page, navmesh); getCache(Navblock)[this.ptr] = this;
};
Navblock.prototype = Object.create(WrapperObject.prototype);
Navblock.prototype.constructor = Navblock;
Navblock.prototype.__class__ = Navblock;
Navblock.__cache__ = {};
Module['Navblock'] = Navblock;
Object.defineProperty(Navblock.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Navblock_get_navmesh(self), toy::Navmesh);
    },
    set: function(navmesh) {
        var self = this.ptr;
        /* navmesh <Navmesh> [] */
        navmesh = navmesh.ptr;
        _toy_Navblock_set_navmesh(self, navmesh);
    }
});
Object.defineProperty(Navblock.prototype, "auto_update", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Navblock_get_auto_update(self));
    },
    set: function(auto_update) {
        var self = this.ptr;
        /* auto_update <bool> [] */
        _toy_Navblock_set_auto_update(self, auto_update);
    }
});
Object.defineProperty(Navblock.prototype, "updated", {
    get: function() {
        var self = this.ptr;
        return _toy_Navblock_get_updated(self);
    },
    set: function(updated) {
        var self = this.ptr;
        /* updated <size_t> [] */
        _toy_Navblock_set_updated(self, updated);
    }
});
Navblock.prototype["__destroy__"] = Navblock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Navblock___destroy__(self);
};
// Navmesh
function Navmesh(world) {
    var self = this.ptr;
    /* world <World> [] */
    world = world.ptr;
    this.ptr = _toy_Navmesh_Navmesh_1(self, world); getCache(Navmesh)[this.ptr] = this;
};
Navmesh.prototype = Object.create(WrapperObject.prototype);
Navmesh.prototype.constructor = Navmesh;
Navmesh.prototype.__class__ = Navmesh;
Navmesh.__cache__ = {};
Module['Navmesh'] = Navmesh;
Object.defineProperty(Navmesh.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Navmesh_get_world(self), toy::World);
    }});
Object.defineProperty(Navmesh.prototype, "updated", {
    get: function() {
        var self = this.ptr;
        return _toy_Navmesh_get_updated(self);
    },
    set: function(updated) {
        var self = this.ptr;
        /* updated <size_t> [] */
        _toy_Navmesh_set_updated(self, updated);
    }
});
Object.defineProperty(Navmesh.prototype, "dirty", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Navmesh_get_dirty(self));
    },
    set: function(dirty) {
        var self = this.ptr;
        /* dirty <bool> [] */
        _toy_Navmesh_set_dirty(self, dirty);
    }
});
Navmesh.prototype["__destroy__"] = Navmesh.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Navmesh___destroy__(self);
};
// Origin
function Origin(spatial) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Origin_Origin_0(self); getCache(Origin)[this.ptr] = this; return; }
    this.ptr = _toy_Origin_Origin_1(self, spatial); getCache(Origin)[this.ptr] = this;
};
Origin.prototype = Object.create(WrapperObject.prototype);
Origin.prototype.constructor = Origin;
Origin.prototype.__class__ = Origin;
Origin.__cache__ = {};
Module['Origin'] = Origin;
Origin.prototype["__destroy__"] = Origin.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Origin___destroy__(self);
};
// Pathfinder
function Pathfinder(navmesh) {
    var self = this.ptr;
    /* navmesh <Navmesh> [] */
    navmesh = navmesh.ptr;
    this.ptr = _toy_Pathfinder_Pathfinder_1(self, navmesh); getCache(Pathfinder)[this.ptr] = this;
};
Pathfinder.prototype = Object.create(WrapperObject.prototype);
Pathfinder.prototype.constructor = Pathfinder;
Pathfinder.prototype.__class__ = Pathfinder;
Pathfinder.__cache__ = {};
Module['Pathfinder'] = Pathfinder;
Pathfinder.prototype["__destroy__"] = Pathfinder.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Pathfinder___destroy__(self);
};
// PhysicWorld
function PhysicWorld() { throw "cannot construct a PhysicWorld, no constructor in IDL" }
PhysicWorld.prototype = Object.create(WrapperObject.prototype);
PhysicWorld.prototype.constructor = PhysicWorld;
PhysicWorld.prototype.__class__ = PhysicWorld;
PhysicWorld.__cache__ = {};
Module['PhysicWorld'] = PhysicWorld;
PhysicWorld.prototype["ground_point"] = PhysicWorld.prototype.ground_point = function(ray) {
    /* ray <Ray> [] */
    ray = ray.ptr;
    return wrapPointer(_toy_PhysicWorld_ground_point_1(ray), mud::vec3);
};
PhysicWorld.prototype["raycast"] = PhysicWorld.prototype.raycast = function(ray, mask) {
    /* ray <Ray> [] */
    ray = ray.ptr;
    /* mask <short> [] */
    return wrapPointer(_toy_PhysicWorld_raycast_2(ray, mask), toy::Collision);
};
Object.defineProperty(PhysicWorld.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_PhysicWorld_get_world(self), toy::World);
    }});
PhysicWorld.prototype["__destroy__"] = PhysicWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_PhysicWorld___destroy__(self);
};
// Receptor
function Receptor(spatial) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    if (spatial === undefined) { this.ptr = _toy_Receptor_Receptor_0(self); getCache(Receptor)[this.ptr] = this; return; }
    this.ptr = _toy_Receptor_Receptor_1(self, spatial); getCache(Receptor)[this.ptr] = this;
};
Receptor.prototype = Object.create(WrapperObject.prototype);
Receptor.prototype.constructor = Receptor;
Receptor.prototype.__class__ = Receptor;
Receptor.__cache__ = {};
Module['Receptor'] = Receptor;
Receptor.prototype["scope"] = Receptor.prototype.scope = function(medium) {
    /* medium <Medium> [] */
    medium = medium.ptr;
    return wrapPointer(_toy_Receptor_scope_1(medium), toy::ReceptorScope);
};
Receptor.prototype["__destroy__"] = Receptor.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Receptor___destroy__(self);
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
        return _toy_Solid_get_spatial(self);
    },
    set: function(spatial) {
        var self = this.ptr;
        /* spatial <toy::HSpatial> [] */
        _toy_Solid_set_spatial(self, spatial);
    }
});
Object.defineProperty(Solid.prototype, "static", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_Solid_get_static(self));
    },
    set: function(static) {
        var self = this.ptr;
        /* static <bool> [] */
        _toy_Solid_set_static(self, static);
    }
});
Object.defineProperty(Solid.prototype, "mass", {
    get: function() {
        var self = this.ptr;
        return _toy_Solid_get_mass(self);
    },
    set: function(mass) {
        var self = this.ptr;
        /* mass <float> [] */
        _toy_Solid_set_mass(self, mass);
    }
});
Solid.prototype["__destroy__"] = Solid.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Solid___destroy__(self);
};
// SolidImpl
function SolidImpl() { throw "cannot construct a SolidImpl, no constructor in IDL" }
SolidImpl.prototype = Object.create(WrapperObject.prototype);
SolidImpl.prototype.constructor = SolidImpl;
SolidImpl.prototype.__class__ = SolidImpl;
SolidImpl.__cache__ = {};
Module['SolidImpl'] = SolidImpl;
SolidImpl.prototype["angular_velocity"] = SolidImpl.prototype.angular_velocity = function() {
    return wrapPointer(_toy_SolidImpl_angular_velocity_0(), mud::vec3);
};
SolidImpl.prototype["impulse"] = SolidImpl.prototype.impulse = function(force, point) {
    /* force <vec3> [] */
    force = force.ptr;
    /* point <vec3> [] */
    point = point.ptr;
    _toy_SolidImpl_impulse_2(force, point);
};
SolidImpl.prototype["linear_velocity"] = SolidImpl.prototype.linear_velocity = function() {
    return wrapPointer(_toy_SolidImpl_linear_velocity_0(), mud::vec3);
};
SolidImpl.prototype["set_angular_factor"] = SolidImpl.prototype.set_angular_factor = function(factor) {
    /* factor <vec3> [] */
    factor = factor.ptr;
    _toy_SolidImpl_set_angular_factor_1(factor);
};
SolidImpl.prototype["set_angular_velocity"] = SolidImpl.prototype.set_angular_velocity = function(torque) {
    /* torque <vec3> [] */
    torque = torque.ptr;
    _toy_SolidImpl_set_angular_velocity_1(torque);
};
SolidImpl.prototype["set_linear_velocity"] = SolidImpl.prototype.set_linear_velocity = function(force) {
    /* force <vec3> [] */
    force = force.ptr;
    _toy_SolidImpl_set_linear_velocity_1(force);
};
SolidImpl.prototype["__destroy__"] = SolidImpl.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_SolidImpl___destroy__(self);
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
    _toy_User___destroy__(self);
};
// Waypoint
function Waypoint(parent) {
    var self = this.ptr;
    /* parent <toy::HSpatial> [] */
    if (parent === undefined) { this.ptr = _toy_Waypoint_Waypoint_0(self); getCache(Waypoint)[this.ptr] = this; return; }
    this.ptr = _toy_Waypoint_Waypoint_1(self, parent); getCache(Waypoint)[this.ptr] = this;
};
Waypoint.prototype = Object.create(WrapperObject.prototype);
Waypoint.prototype.constructor = Waypoint;
Waypoint.prototype.__class__ = Waypoint;
Waypoint.__cache__ = {};
Module['Waypoint'] = Waypoint;
Waypoint.prototype["__destroy__"] = Waypoint.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Waypoint___destroy__(self);
};
// World
function World(id, complex, name, job_system) {
    var self = this.ptr;
    ensureCache.prepare();
    /* id <mud::Id> [] */
    /* complex <Complex> [] */
    complex = complex.ptr;
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _toy_World_World_4(self, id, complex, name, job_system); getCache(World)[this.ptr] = this;
};
World.prototype = Object.create(WrapperObject.prototype);
World.prototype.constructor = World;
World.prototype.__class__ = World;
World.__cache__ = {};
Module['World'] = World;
Object.defineProperty(World.prototype, "id", {
    get: function() {
        var self = this.ptr;
        return _toy_World_get_id(self);
    },
    set: function(id) {
        var self = this.ptr;
        /* id <mud::Id> [] */
        _toy_World_set_id(self, id);
    }
});
Object.defineProperty(World.prototype, "complex", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_World_get_complex(self), mud::Complex);
    }});
Object.defineProperty(World.prototype, "name", {
    get: function() {
        var self = this.ptr;
        return Pointer_stringify(_toy_World_get_name(self));
    },
    set: function(name) {
        var self = this.ptr;
        /* name <std::string> [] */
        if (name && typeof name === "object") name = name.ptr;
        else name = ensureString(name);
        _toy_World_set_name(self, name);
    }
});
Object.defineProperty(World.prototype, "origin", {
    get: function() {
        var self = this.ptr;
        return _toy_World_get_origin(self);
    }});
Object.defineProperty(World.prototype, "unworld", {
    get: function() {
        var self = this.ptr;
        return _toy_World_get_unworld(self);
    }});
World.prototype["__destroy__"] = World.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_World___destroy__(self);
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
    _toy_WorldClock___destroy__(self);
};
// WorldPage
function WorldPage(spatial, open, extents) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* open <bool> [] */
    /* extents <vec3> [] */
    extents = extents.ptr;
    if (spatial === undefined) { this.ptr = _toy_WorldPage_WorldPage_0(self); getCache(WorldPage)[this.ptr] = this; return; }
    this.ptr = _toy_WorldPage_WorldPage_3(self, spatial, open, extents); getCache(WorldPage)[this.ptr] = this;
};
WorldPage.prototype = Object.create(WrapperObject.prototype);
WorldPage.prototype.constructor = WorldPage;
WorldPage.prototype.__class__ = WorldPage;
WorldPage.__cache__ = {};
Module['WorldPage'] = WorldPage;
WorldPage.prototype["build_geometry"] = WorldPage.prototype.build_geometry = function(spatial) {
    /* spatial <Spatial> [] */
    spatial = spatial.ptr;
    _toy_WorldPage_build_geometry_1(spatial);
};
WorldPage.prototype["ground_point"] = WorldPage.prototype.ground_point = function(position, relative, outputPoint) {
    /* position <vec3> [] */
    position = position.ptr;
    /* relative <bool> [] */
    /* outputPoint <vec3> [] */
    outputPoint = outputPoint.ptr;
    _toy_WorldPage_ground_point_3(position, relative, outputPoint);
};
WorldPage.prototype["raycast_ground"] = WorldPage.prototype.raycast_ground = function(from, to, ground_point) {
    /* from <vec3> [] */
    from = from.ptr;
    /* to <vec3> [] */
    to = to.ptr;
    /* ground_point <vec3> [] */
    ground_point = ground_point.ptr;
    _toy_WorldPage_raycast_ground_3(from, to, ground_point);
};
WorldPage.prototype["update_geometry"] = WorldPage.prototype.update_geometry = function() {
    _toy_WorldPage_update_geometry_0();
};
Object.defineProperty(WorldPage.prototype, "open", {
    get: function() {
        var self = this.ptr;
        return !!(_toy_WorldPage_get_open(self));
    },
    set: function(open) {
        var self = this.ptr;
        /* open <bool> [] */
        _toy_WorldPage_set_open(self, open);
    }
});
Object.defineProperty(WorldPage.prototype, "extents", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_WorldPage_get_extents(self), mud::vec3);
    },
    set: function(extents) {
        var self = this.ptr;
        /* extents <vec3> [] */
        extents = extents.ptr;
        _toy_WorldPage_set_extents(self, extents);
    }
});
Object.defineProperty(WorldPage.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_WorldPage_get_world(self), toy::World);
    },
    set: function(world) {
        var self = this.ptr;
        /* world <World> [] */
        world = world.ptr;
        _toy_WorldPage_set_world(self, world);
    }
});
Object.defineProperty(WorldPage.prototype, "last_rebuilt", {
    get: function() {
        var self = this.ptr;
        return _toy_WorldPage_get_last_rebuilt(self);
    },
    set: function(last_rebuilt) {
        var self = this.ptr;
        /* last_rebuilt <size_t> [] */
        _toy_WorldPage_set_last_rebuilt(self, last_rebuilt);
    }
});
WorldPage.prototype["__destroy__"] = WorldPage.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_WorldPage___destroy__(self);
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
    _toy_BulletCollider___destroy__(self);
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
    _toy_BulletSolid___destroy__(self);
};
// BulletWorld
function BulletWorld(world) {
    var self = this.ptr;
    /* world <World> [] */
    world = world.ptr;
    this.ptr = _toy_BulletWorld_BulletWorld_1(self, world); getCache(BulletWorld)[this.ptr] = this;
};
BulletWorld.prototype = Object.create(WrapperObject.prototype);
BulletWorld.prototype.constructor = BulletWorld;
BulletWorld.prototype.__class__ = BulletWorld;
BulletWorld.__cache__ = {};
Module['BulletWorld'] = BulletWorld;
BulletWorld.prototype["__destroy__"] = BulletWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_BulletWorld___destroy__(self);
};
// DefaultWorld
function DefaultWorld(name, job_system) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* job_system <JobSystem> [] */
    job_system = job_system.ptr;
    this.ptr = _toy_DefaultWorld_DefaultWorld_2(self, name, job_system); getCache(DefaultWorld)[this.ptr] = this;
};
DefaultWorld.prototype = Object.create(WrapperObject.prototype);
DefaultWorld.prototype.constructor = DefaultWorld;
DefaultWorld.prototype.__class__ = DefaultWorld;
DefaultWorld.__cache__ = {};
Module['DefaultWorld'] = DefaultWorld;
Object.defineProperty(DefaultWorld.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_DefaultWorld_get_world(self), toy::World);
    }});
Object.defineProperty(DefaultWorld.prototype, "bullet_world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_DefaultWorld_get_bullet_world(self), toy::BulletWorld);
    }});
Object.defineProperty(DefaultWorld.prototype, "navmesh", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_DefaultWorld_get_navmesh(self), toy::Navmesh);
    }});
DefaultWorld.prototype["__destroy__"] = DefaultWorld.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_DefaultWorld___destroy__(self);
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
    _toy_PhysicScope___destroy__(self);
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
    _toy_EmitterScope___destroy__(self);
};
// NavmeshShape
function NavmeshShape(navmesh) {
    var self = this.ptr;
    /* navmesh <Navmesh> [] */
    navmesh = navmesh.ptr;
    this.ptr = _toy_NavmeshShape_NavmeshShape_1(self, navmesh); getCache(NavmeshShape)[this.ptr] = this;
};
NavmeshShape.prototype = Object.create(WrapperObject.prototype);
NavmeshShape.prototype.constructor = NavmeshShape;
NavmeshShape.prototype.__class__ = NavmeshShape;
NavmeshShape.__cache__ = {};
Module['NavmeshShape'] = NavmeshShape;
NavmeshShape.prototype["__destroy__"] = NavmeshShape.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_NavmeshShape___destroy__(self);
};
// Obstacle
function Obstacle(spatial, movable, medium, shape, throughput) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* movable <toy::HMovable> [] */
    /* medium <Medium> [] */
    medium = medium.ptr;
    /* shape <CollisionShape> [] */
    shape = shape.ptr;
    /* throughput <float> [] */
    this.ptr = _toy_Obstacle_Obstacle_5(self, spatial, movable, medium, shape, throughput); getCache(Obstacle)[this.ptr] = this;
};
Obstacle.prototype = Object.create(WrapperObject.prototype);
Obstacle.prototype.constructor = Obstacle;
Obstacle.prototype.__class__ = Obstacle;
Obstacle.__cache__ = {};
Module['Obstacle'] = Obstacle;
Object.defineProperty(Obstacle.prototype, "shape", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Obstacle_get_shape(self), toy::CollisionShape);
    }});
Object.defineProperty(Obstacle.prototype, "throughput", {
    get: function() {
        var self = this.ptr;
        return _toy_Obstacle_get_throughput(self);
    },
    set: function(throughput) {
        var self = this.ptr;
        /* throughput <float> [] */
        _toy_Obstacle_set_throughput(self, throughput);
    }
});
Obstacle.prototype["__destroy__"] = Obstacle.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Obstacle___destroy__(self);
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
    _toy_ReceptorScope___destroy__(self);
};
// SolidMedium
function SolidMedium() {
    var self = this.ptr;
    this.ptr = _toy_SolidMedium_SolidMedium_0(self); getCache(SolidMedium)[this.ptr] = this;
};
SolidMedium.prototype = Object.create(WrapperObject.prototype);
SolidMedium.prototype.constructor = SolidMedium;
SolidMedium.prototype.__class__ = SolidMedium;
SolidMedium.__cache__ = {};
Module['SolidMedium'] = SolidMedium;
SolidMedium.prototype["__destroy__"] = SolidMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_SolidMedium___destroy__(self);
};
// SoundMedium
function SoundMedium() {
    var self = this.ptr;
    this.ptr = _toy_SoundMedium_SoundMedium_0(self); getCache(SoundMedium)[this.ptr] = this;
};
SoundMedium.prototype = Object.create(WrapperObject.prototype);
SoundMedium.prototype.constructor = SoundMedium;
SoundMedium.prototype.__class__ = SoundMedium;
SoundMedium.__cache__ = {};
Module['SoundMedium'] = SoundMedium;
SoundMedium.prototype["__destroy__"] = SoundMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_SoundMedium___destroy__(self);
};
// Spatial
function Spatial(parent, position, rotation) {
    var self = this.ptr;
    /* parent <toy::HSpatial> [] */
    /* position <vec3> [] */
    position = position.ptr;
    /* rotation <quat> [] */
    rotation = rotation.ptr;
    if (parent === undefined) { this.ptr = _toy_Spatial_Spatial_0(self); getCache(Spatial)[this.ptr] = this; return; }
    this.ptr = _toy_Spatial_Spatial_3(self, parent, position, rotation); getCache(Spatial)[this.ptr] = this;
};
Spatial.prototype = Object.create(WrapperObject.prototype);
Spatial.prototype.constructor = Spatial;
Spatial.prototype.__class__ = Spatial;
Spatial.__cache__ = {};
Module['Spatial'] = Spatial;
Spatial.prototype["set_position"] = Spatial.prototype.set_position = function(position) {
    /* position <vec3> [] */
    position = position.ptr;
    _toy_Spatial_set_position_1(position);
};
Spatial.prototype["set_rotation"] = Spatial.prototype.set_rotation = function(rotation) {
    /* rotation <quat> [] */
    rotation = rotation.ptr;
    _toy_Spatial_set_rotation_1(rotation);
};
Object.defineProperty(Spatial.prototype, "world", {
    get: function() {
        var self = this.ptr;
        return wrapPointer(_toy_Spatial_get_world(self), toy::World);
    },
    set: function(world) {
        var self = this.ptr;
        /* world <World> [] */
        world = world.ptr;
        _toy_Spatial_set_world(self, world);
    }
});
Object.defineProperty(Spatial.prototype, "parent", {
    get: function() {
        var self = this.ptr;
        return _toy_Spatial_get_parent(self);
    },
    set: function(parent) {
        var self = this.ptr;
        /* parent <toy::HSpatial> [] */
        _toy_Spatial_set_parent(self, parent);
    }
});
Spatial.prototype["__destroy__"] = Spatial.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_Spatial___destroy__(self);
};
// VisualMedium
function VisualMedium() {
    var self = this.ptr;
    this.ptr = _toy_VisualMedium_VisualMedium_0(self); getCache(VisualMedium)[this.ptr] = this;
};
VisualMedium.prototype = Object.create(WrapperObject.prototype);
VisualMedium.prototype.constructor = VisualMedium;
VisualMedium.prototype.__class__ = VisualMedium;
VisualMedium.__cache__ = {};
Module['VisualMedium'] = VisualMedium;
VisualMedium.prototype["__destroy__"] = VisualMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_VisualMedium___destroy__(self);
};
// WorldMedium
function WorldMedium() {
    var self = this.ptr;
    this.ptr = _toy_WorldMedium_WorldMedium_0(self); getCache(WorldMedium)[this.ptr] = this;
};
WorldMedium.prototype = Object.create(WrapperObject.prototype);
WorldMedium.prototype.constructor = WorldMedium;
WorldMedium.prototype.__class__ = WorldMedium;
WorldMedium.__cache__ = {};
Module['WorldMedium'] = WorldMedium;
WorldMedium.prototype["__destroy__"] = WorldMedium.prototype.__destroy__ = function() {
    var self = this.ptr;
    _toy_WorldMedium___destroy__(self);
};

(function() {
    function setupEnums() {
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
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
