Module['boids'] = Module['boids'] || {};
// Position
function Position() {
    
    this.__ptr = _boids_Position__construct_0(); getCache(Position)[this.__ptr] = this;
};
Position.prototype = Object.create(WrapperObject.prototype);
Position.prototype.constructor = Position;
Position.prototype.__class = Position;
Position.__cache = {};
Module['boids']['Position'] = Position;
Position.prototype["__destroy"] = Position.prototype.__destroy = function() {
    _boids_Position__destroy(this.__ptr);
};
// Heading
function Heading() {
    
    this.__ptr = _boids_Heading__construct_0(); getCache(Heading)[this.__ptr] = this;
};
Heading.prototype = Object.create(WrapperObject.prototype);
Heading.prototype.constructor = Heading;
Heading.prototype.__class = Heading;
Heading.__cache = {};
Module['boids']['Heading'] = Heading;
Heading.prototype["__destroy"] = Heading.prototype.__destroy = function() {
    _boids_Heading__destroy(this.__ptr);
};
// Rotation
function Rotation() {
    
    this.__ptr = _boids_Rotation__construct_0(); getCache(Rotation)[this.__ptr] = this;
};
Rotation.prototype = Object.create(WrapperObject.prototype);
Rotation.prototype.constructor = Rotation;
Rotation.prototype.__class = Rotation;
Rotation.__cache = {};
Module['boids']['Rotation'] = Rotation;
Rotation.prototype["__destroy"] = Rotation.prototype.__destroy = function() {
    _boids_Rotation__destroy(this.__ptr);
};
// MoveSpeed
function MoveSpeed() {
    
    this.__ptr = _boids_MoveSpeed__construct_0(); getCache(MoveSpeed)[this.__ptr] = this;
};
MoveSpeed.prototype = Object.create(WrapperObject.prototype);
MoveSpeed.prototype.constructor = MoveSpeed;
MoveSpeed.prototype.__class = MoveSpeed;
MoveSpeed.__cache = {};
Module['boids']['MoveSpeed'] = MoveSpeed;
MoveSpeed.prototype["__destroy"] = MoveSpeed.prototype.__destroy = function() {
    _boids_MoveSpeed__destroy(this.__ptr);
};
// Transform4
function Transform4() {
    
    this.__ptr = _boids_Transform4__construct_0(); getCache(Transform4)[this.__ptr] = this;
};
Transform4.prototype = Object.create(WrapperObject.prototype);
Transform4.prototype.constructor = Transform4;
Transform4.prototype.__class = Transform4;
Transform4.__cache = {};
Module['boids']['Transform4'] = Transform4;
Transform4.prototype["__destroy"] = Transform4.prototype.__destroy = function() {
    _boids_Transform4__destroy(this.__ptr);
};
// Boid
function Boid() {
    
    this.__ptr = _boids_Boid__construct_0(); getCache(Boid)[this.__ptr] = this;
};
Boid.prototype = Object.create(WrapperObject.prototype);
Boid.prototype.constructor = Boid;
Boid.prototype.__class = Boid;
Boid.__cache = {};
Module['boids']['Boid'] = Boid;
Boid.prototype["__destroy"] = Boid.prototype.__destroy = function() {
    _boids_Boid__destroy(this.__ptr);
};
// BoidTarget
function BoidTarget() {
    
    this.__ptr = _boids_BoidTarget__construct_0(); getCache(BoidTarget)[this.__ptr] = this;
};
BoidTarget.prototype = Object.create(WrapperObject.prototype);
BoidTarget.prototype.constructor = BoidTarget;
BoidTarget.prototype.__class = BoidTarget;
BoidTarget.__cache = {};
Module['boids']['BoidTarget'] = BoidTarget;
BoidTarget.prototype["__destroy"] = BoidTarget.prototype.__destroy = function() {
    _boids_BoidTarget__destroy(this.__ptr);
};
// BoidObstacle
function BoidObstacle() {
    
    this.__ptr = _boids_BoidObstacle__construct_0(); getCache(BoidObstacle)[this.__ptr] = this;
};
BoidObstacle.prototype = Object.create(WrapperObject.prototype);
BoidObstacle.prototype.constructor = BoidObstacle;
BoidObstacle.prototype.__class = BoidObstacle;
BoidObstacle.__cache = {};
Module['boids']['BoidObstacle'] = BoidObstacle;
BoidObstacle.prototype["__destroy"] = BoidObstacle.prototype.__destroy = function() {
    _boids_BoidObstacle__destroy(this.__ptr);
};
// MoveForward
function MoveForward() {
    
    this.__ptr = _boids_MoveForward__construct_0(); getCache(MoveForward)[this.__ptr] = this;
};
MoveForward.prototype = Object.create(WrapperObject.prototype);
MoveForward.prototype.constructor = MoveForward;
MoveForward.prototype.__class = MoveForward;
MoveForward.__cache = {};
Module['boids']['MoveForward'] = MoveForward;
MoveForward.prototype["__destroy"] = MoveForward.prototype.__destroy = function() {
    _boids_MoveForward__destroy(this.__ptr);
};
// Player
function Player() { throw "cannot construct a Player, no constructor in IDL" }
Player.prototype = Object.create(WrapperObject.prototype);
Player.prototype.constructor = Player;
Player.prototype.__class = Player;
Player.__cache = {};
Module['boids']['Player'] = Player;
Player.prototype["__destroy"] = Player.prototype.__destroy = function() {
    _boids_Player__destroy(this.__ptr);
};
Module['boids']['vec3'] = v4_float;

(function() {
    function setup() {
        Position.prototype.__type = _boids_Position__type();
        Heading.prototype.__type = _boids_Heading__type();
        Rotation.prototype.__type = _boids_Rotation__type();
        MoveSpeed.prototype.__type = _boids_MoveSpeed__type();
        Transform4.prototype.__type = _boids_Transform4__type();
        Boid.prototype.__type = _boids_Boid__type();
        BoidTarget.prototype.__type = _boids_BoidTarget__type();
        BoidObstacle.prototype.__type = _boids_BoidObstacle__type();
        MoveForward.prototype.__type = _boids_MoveForward__type();
        Player.prototype.__type = _boids_Player__type();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
