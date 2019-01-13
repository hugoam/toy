
// Bindings utilities
function WrapperObject() {
}
// Boid
function Boid() {
    var self = this.ptr;
    this.ptr = _boids_Boid_Boid_0(self); getCache(Boid)[this.ptr] = this;
};
Boid.prototype = Object.create(WrapperObject.prototype);
Boid.prototype.constructor = Boid;
Boid.prototype.__class__ = Boid;
Boid.__cache__ = {};
Module['Boid'] = Boid;
Boid.prototype["__destroy__"] = Boid.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Boid___destroy__(self);
};
// BoidObstacle
function BoidObstacle() {
    var self = this.ptr;
    this.ptr = _boids_BoidObstacle_BoidObstacle_0(self); getCache(BoidObstacle)[this.ptr] = this;
};
BoidObstacle.prototype = Object.create(WrapperObject.prototype);
BoidObstacle.prototype.constructor = BoidObstacle;
BoidObstacle.prototype.__class__ = BoidObstacle;
BoidObstacle.__cache__ = {};
Module['BoidObstacle'] = BoidObstacle;
BoidObstacle.prototype["__destroy__"] = BoidObstacle.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_BoidObstacle___destroy__(self);
};
// BoidTarget
function BoidTarget() {
    var self = this.ptr;
    this.ptr = _boids_BoidTarget_BoidTarget_0(self); getCache(BoidTarget)[this.ptr] = this;
};
BoidTarget.prototype = Object.create(WrapperObject.prototype);
BoidTarget.prototype.constructor = BoidTarget;
BoidTarget.prototype.__class__ = BoidTarget;
BoidTarget.__cache__ = {};
Module['BoidTarget'] = BoidTarget;
BoidTarget.prototype["__destroy__"] = BoidTarget.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_BoidTarget___destroy__(self);
};
// Heading
function Heading() {
    var self = this.ptr;
    this.ptr = _boids_Heading_Heading_0(self); getCache(Heading)[this.ptr] = this;
};
Heading.prototype = Object.create(WrapperObject.prototype);
Heading.prototype.constructor = Heading;
Heading.prototype.__class__ = Heading;
Heading.__cache__ = {};
Module['Heading'] = Heading;
Heading.prototype["__destroy__"] = Heading.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Heading___destroy__(self);
};
// MoveForward
function MoveForward() {
    var self = this.ptr;
    this.ptr = _boids_MoveForward_MoveForward_0(self); getCache(MoveForward)[this.ptr] = this;
};
MoveForward.prototype = Object.create(WrapperObject.prototype);
MoveForward.prototype.constructor = MoveForward;
MoveForward.prototype.__class__ = MoveForward;
MoveForward.__cache__ = {};
Module['MoveForward'] = MoveForward;
MoveForward.prototype["__destroy__"] = MoveForward.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_MoveForward___destroy__(self);
};
// MoveSpeed
function MoveSpeed() {
    var self = this.ptr;
    this.ptr = _boids_MoveSpeed_MoveSpeed_0(self); getCache(MoveSpeed)[this.ptr] = this;
};
MoveSpeed.prototype = Object.create(WrapperObject.prototype);
MoveSpeed.prototype.constructor = MoveSpeed;
MoveSpeed.prototype.__class__ = MoveSpeed;
MoveSpeed.__cache__ = {};
Module['MoveSpeed'] = MoveSpeed;
MoveSpeed.prototype["__destroy__"] = MoveSpeed.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_MoveSpeed___destroy__(self);
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
    _boids_Player___destroy__(self);
};
// Position
function Position() {
    var self = this.ptr;
    this.ptr = _boids_Position_Position_0(self); getCache(Position)[this.ptr] = this;
};
Position.prototype = Object.create(WrapperObject.prototype);
Position.prototype.constructor = Position;
Position.prototype.__class__ = Position;
Position.__cache__ = {};
Module['Position'] = Position;
Position.prototype["__destroy__"] = Position.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Position___destroy__(self);
};
// Rotation
function Rotation() {
    var self = this.ptr;
    this.ptr = _boids_Rotation_Rotation_0(self); getCache(Rotation)[this.ptr] = this;
};
Rotation.prototype = Object.create(WrapperObject.prototype);
Rotation.prototype.constructor = Rotation;
Rotation.prototype.__class__ = Rotation;
Rotation.__cache__ = {};
Module['Rotation'] = Rotation;
Rotation.prototype["__destroy__"] = Rotation.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Rotation___destroy__(self);
};
// Transform4
function Transform4() {
    var self = this.ptr;
    this.ptr = _boids_Transform4_Transform4_0(self); getCache(Transform4)[this.ptr] = this;
};
Transform4.prototype = Object.create(WrapperObject.prototype);
Transform4.prototype.constructor = Transform4;
Transform4.prototype.__class__ = Transform4;
Transform4.__cache__ = {};
Module['Transform4'] = Transform4;
Transform4.prototype["__destroy__"] = Transform4.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Transform4___destroy__(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
