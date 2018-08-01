-- enemy ia script

--function ia(self)
    function iif(cond, a, b)
        if cond then return a else return b end
    end
    
    if not vec3.__add then
        vec3.__eq = function(a, b) return a.x == b.x and a.y == b.y and a.z == b.z end
        vec3.__add = function(a, b) return vec3(a.x + b.x, a.y + b.y, a.z + b.z) end
        vec3.__sub = function(a, b) return vec3(a.x - b.x, a.y - b.y, a.z - b.z) end
    end
    
    local delta = 1.0
    local c_tick_interval = 0.02
    
    if self.life <= 0.0 then
        self.state = Stance("Die", false)
        return
    end

    if self.target then
        local aim = self:aim()
        if distance(self.target.entity.position, self.entity.position) > 50.0
        or aim.hit and aim.hit ~= self.target.entity 
        or self.target.life <= 0.0 then
            self.target = nil
        end
    end

    if not self.target then
        local vision = self.receptor:scope(VisualMedium.me)
        
        for _, entity in pairs(vision:scope()) do
            target = entity.complex:try_part(Human)
            if target and target.faction ~= self.faction then
                local direction = entity.position - self.entity.position
                
                --local light = spot_attenuation(-direction, self.entity.front(), 30.0, 0.5, 0.9, cos(to_radians(headlight_angle)))
                local light = 1.0
                local visibility = light * iif(target.headlight, 4.0, 0.5)
                if target.life > 0.0 and (visibility > 0.2 or length(direction) < 4.0) then
                    self.target = target
                    self.cooldown = 2.0
                end
            end
        end
    end

    self.cooldown = math.max(0.0, self.cooldown - delta * 0.05)
    if self.target then
        self:stop()

        function x0z(v) return vec3(v.x, 0.0, v.z) end
        self.entity:set_rotation(look_at(x0z(self.entity.position), x0z(self.target.entity.position)))
        
        if self.cooldown == 0.0 then
            self:shoot()
            self.cooldown = 1.0
        end
    else
        function is_walkable(pos)
            local world = self.entity.world.complex:part(PhysicWorld)
            return world:ground_point(to_ray(pos, vec3(0, -1, 0))) ~= vec3(0)
        end
        
        if self.dest == vec3(0) then
            local amplitude = 10.0
            self.dest = self.entity.position + vec3(math.random(-amplitude, amplitude), 0.0, math.random(-amplitude, amplitude))
            if not is_walkable(self.dest) then
                self.dest = vec3(0)
            end
        end

        if self.dest ~= vec3(0) then
            if steer_2d(self.movable, self.dest, 3.0, delta * c_tick_interval, 1.0) then
                self:stop()
            else
                self.state = Stance(iif(self.walk, "Walk", "RunAim"), true)
                self.movable:set_linear_velocity(self.movable.linear_velocity - vec3(0, 1, 0))
            end
        end
    end
    
--end