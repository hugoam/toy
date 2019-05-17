//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <geom/Shape/ProcShape.h>
#include <core/Forward.h>
#include <core/Spatial/Spatial.h>
#include <core/WorldPage/WorldPage.h>
#include <core/Navmesh/rcTileMesh.h>
#include <core/Navmesh/NavGeom.h>

namespace toy
{
	TOY_CORE_EXPORT uint32_t navmesh_num_vertices(const Navmesh& navmesh);
	
	TOY_CORE_EXPORT ShapeSize size_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh);
	TOY_CORE_EXPORT void draw_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh, MeshAdapter& writer);

	TOY_CORE_EXPORT ShapeSize size_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh);
	TOY_CORE_EXPORT void draw_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh, MeshAdapter& writer);

	class refl_ TOY_CORE_EXPORT Navmesh : public rcTileMesh
    {
    public:
		constr_ Navmesh(World& world);
		~Navmesh();

		attr_ World& m_world;
		attr_ size_t m_updated = 0;
		attr_ bool m_dirty = false;

		void update_block(Navblock& navblock);

		void next_frame(size_t tick, size_t delta);

		void load();
		void build();

		void save(const char* path);
		void load(const char* path);

	private:
		dtNavMesh* _load(const char* path);
		void _save(const char* path, const dtNavMesh* mesh);
    };

	class refl_ TOY_CORE_EXPORT Navblock
	{
	public:
		constr_ Navblock() {}
		constr_ Navblock(HSpatial spatial, HWorldPage world_page, Navmesh& navmesh);
		~Navblock();

		comp_ HSpatial m_spatial;
		comp_ HWorldPage m_world_page;

		attr_ Navmesh* m_navmesh = nullptr;

		attr_ bool m_auto_update = false;
		attr_ size_t m_updated = 0;

		void next_frame(const Spatial& spatial, const WorldPage& world_page, size_t tick, size_t delta);
	};

	class refl_ TOY_CORE_EXPORT NavmeshShape : public Shape
	{
	public:
		constr_ NavmeshShape(Navmesh& navmesh);

		Navmesh& m_navmesh;

		virtual object<Shape> clone() const;
	};
}
