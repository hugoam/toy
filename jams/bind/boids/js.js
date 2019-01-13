
// Bindings utilities
function WrapperObject() {
}
// Boid
function Boid() {
    this.ptr = _boids_Boid_Boid_0(); getCache(Boid)[this.ptr] = this;
};
Boid.prototype = Object.create(WrapperObject.prototype);
Boid.prototype.constructor = Boid;
Boid.prototype.__class__ = Boid;
Boid.__cache__ = {};
Module['Boid'] = Boid;
Boid.prototype["__destroy__"] = Boid.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Boid__destroy(self);
};
// BoidObstacle
function BoidObstacle() {
    this.ptr = _boids_BoidObstacle_BoidObstacle_0(); getCache(BoidObstacle)[this.ptr] = this;
};
BoidObstacle.prototype = Object.create(WrapperObject.prototype);
BoidObstacle.prototype.constructor = BoidObstacle;
BoidObstacle.prototype.__class__ = BoidObstacle;
BoidObstacle.__cache__ = {};
Module['BoidObstacle'] = BoidObstacle;
BoidObstacle.prototype["__destroy__"] = BoidObstacle.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_BoidObstacle__destroy(self);
};
// BoidTarget
function BoidTarget() {
    this.ptr = _boids_BoidTarget_BoidTarget_0(); getCache(BoidTarget)[this.ptr] = this;
};
BoidTarget.prototype = Object.create(WrapperObject.prototype);
BoidTarget.prototype.constructor = BoidTarget;
BoidTarget.prototype.__class__ = BoidTarget;
BoidTarget.__cache__ = {};
Module['BoidTarget'] = BoidTarget;
BoidTarget.prototype["__destroy__"] = BoidTarget.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_BoidTarget__destroy(self);
};
// Heading
function Heading() {
    this.ptr = _boids_Heading_Heading_0(); getCache(Heading)[this.ptr] = this;
};
Heading.prototype = Object.create(WrapperObject.prototype);
Heading.prototype.constructor = Heading;
Heading.prototype.__class__ = Heading;
Heading.__cache__ = {};
Module['Heading'] = Heading;
Heading.prototype["__destroy__"] = Heading.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Heading__destroy(self);
};
// MoveForward
function MoveForward() {
    this.ptr = _boids_MoveForward_MoveForward_0(); getCache(MoveForward)[this.ptr] = this;
};
MoveForward.prototype = Object.create(WrapperObject.prototype);
MoveForward.prototype.constructor = MoveForward;
MoveForward.prototype.__class__ = MoveForward;
MoveForward.__cache__ = {};
Module['MoveForward'] = MoveForward;
MoveForward.prototype["__destroy__"] = MoveForward.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_MoveForward__destroy(self);
};
// MoveSpeed
function MoveSpeed() {
    this.ptr = _boids_MoveSpeed_MoveSpeed_0(); getCache(MoveSpeed)[this.ptr] = this;
};
MoveSpeed.prototype = Object.create(WrapperObject.prototype);
MoveSpeed.prototype.constructor = MoveSpeed;
MoveSpeed.prototype.__class__ = MoveSpeed;
MoveSpeed.__cache__ = {};
Module['MoveSpeed'] = MoveSpeed;
MoveSpeed.prototype["__destroy__"] = MoveSpeed.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_MoveSpeed__destroy(self);
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
    _boids_Player__destroy(self);
};
// Position
function Position() {
    this.ptr = _boids_Position_Position_0(); getCache(Position)[this.ptr] = this;
};
Position.prototype = Object.create(WrapperObject.prototype);
Position.prototype.constructor = Position;
Position.prototype.__class__ = Position;
Position.__cache__ = {};
Module['Position'] = Position;
Position.prototype["__destroy__"] = Position.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Position__destroy(self);
};
// Rotation
function Rotation() {
    this.ptr = _boids_Rotation_Rotation_0(); getCache(Rotation)[this.ptr] = this;
};
Rotation.prototype = Object.create(WrapperObject.prototype);
Rotation.prototype.constructor = Rotation;
Rotation.prototype.__class__ = Rotation;
Rotation.__cache__ = {};
Module['Rotation'] = Rotation;
Rotation.prototype["__destroy__"] = Rotation.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Rotation__destroy(self);
};
// Transform4
function Transform4() {
    this.ptr = _boids_Transform4_Transform4_0(); getCache(Transform4)[this.ptr] = this;
};
Transform4.prototype = Object.create(WrapperObject.prototype);
Transform4.prototype.constructor = Transform4;
Transform4.prototype.__class__ = Transform4;
Transform4.__cache__ = {};
Module['Transform4'] = Transform4;
Transform4.prototype["__destroy__"] = Transform4.prototype.__destroy__ = function() {
    var self = this.ptr;
    _boids_Transform4__destroy(self);
};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();