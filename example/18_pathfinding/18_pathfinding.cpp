
#include <18_pathfinding/18_pathfinding.h>

#include <toy/toy.h>

#if 0
void paint_bone(Gnode& parent, Skeleton& skeleton, Bone& bone)
{
	if(bone.m_parent != -1)
		gfx::node(parent).m_position = bxmul(skeleton.m_bones[bone.m_parent].m_pose, bone.m_position);
	else
		gfx::node(parent).m_position = bone.m_position;
	gfx::shape(parent, Circle(0.05f), Symbol());
}

void paint_skeleton(Gnode& parent, Skeleton& skeleton)
{
	for(Bone& bone : skeleton.m_bones)
		paint_bone(parent, skeleton, bone);
}

void paint_waypoint(Gnode& parent, const vec3& waypoint)
{
	gfx::node(parent, {}, waypoint);
	gfx::shape(parent, Circle(0.05f), Symbol());
}

void paint_path(Gnode& parent, const vec3& position, DetourPath& path)
{
	gfx::node(parent);
	const vec3* previous = nullptr;
	for(const vec3& waypoint : path.m_path)
	{
		paint_waypoint(parent, waypoint);
		if(previous)
			gfx::shape(parent, Line(*previous, waypoint), Symbol());
		previous = &waypoint;
	}
}

void face(Node3& node, vec3 direction)
{
	float angle = atan2(direction.x, direction.z);
	quat q = { cosf(angle / 2.f), 0.f, 1.f * sinf(angle / 2.f), 0.f };
	node.m_orientation = q;
}

void paint_direction(Gnode& parent, Movable& movable)
{
	Node3& node = gfx::node(parent);
	face(node, movable.m_acceleration);
	node.m_scale = vec3(length(movable.m_acceleration));
	node.m_position = movable.m_entity.absolutePosition();
	//node.m_scale = Unit3;
	gfx::shape(parent, Line(Zero3, -Z3), Symbol(Colour::Red));
}

void paint_beam(Gnode& parent, const vec3& direction)
{
	quat rotation = rotation(Y3, normalize(direction));
	gfx::node(parent, {}, parent.m_parent->m_attach->m_position + Y3 * 1.f, rotation);
	gfx::particles(parent, "particle.ktx", shoot_particles(parent));
}

void paint_human(Gnode& parent, Human& human)
{
	//if(human.m_manoeuvrable.m_path)
	//	paint_path(parent, human.m_entity.absolutePosition(), *human.m_manoeuvrable.m_path);

	paint_direction(parent, human.m_movable);

	//if(human.m_shooting)
	//	paint_beam(parent, human.m_shooting->m_position - human.m_entity.m_position);
}

#endif

void ex_18_pathfinding_pump(Shell& shell, Game& game)
{
#if 0
	// human action switching code

	m_counter += 1.f;
	if(m_counter >= m_next_change && (!m_current_movement || m_current_movement->done()))
	{
		const string actions[4] = { "Idle", "Walk", "Shoot", "Run"/*, "WalkFight" */ };
		size_t action = random_integer(size_t(0), size_t(2));
		m_states.push_back({ actions[action], 1.f });
		m_counter = 0.f;
		m_shooting = nullptr;
		m_next_change = random_scalar(3.f, 10.f);

		if(m_states.back().m_action == "Walk")
		{
			vec3 position = { random_scalar(5.f, 100.f), 0.f, random_scalar(5.f, 100.f) };

			vec3 ground_point = m_entity.m_world.part<PhysicWorld>().groundPoint(Ray{ position + Y3 * 100.f, position - Y3 * 100.f, -Y3, Y3 });

			Entity& waypoint = m_entity.m_world.origin().constructNested<OWaypoint>(ground_point);
			m_current_movement = &m_actor.execute(nullptr, Walk::def(), waypoint);
		}

		if(m_states.back().m_action == "Shoot")
		{
			std::vector<Human*> targets;

			for(Ref object : indexed_objects(type<Entity>()))
				if(object)
				{
					Entity& entity = val<Entity>(object);
					if(isa<Human>(entity))
						targets.push_back(&entity.part<Human>());
				}

			size_t index = random_integer(size_t(0U), targets.size() - 1);
			m_shooting = &targets[index]->m_entity;
		}
	}
#endif
}

void ex_18_pathfinding_start(Shell& shell, Game& game)
{
	game.m_world = &GlobalPool::me().pool<DefaultWorld>().construct("Arcadia").m_world;
}

