//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <test/Forward.h>
#include <toy/toy.h>

using namespace mud;
using namespace toy;

namespace test
{
class Shell : public NonCopy
{
public:
	Shell(array<cstring> resource_paths, int argc, char *argv[]);
	~Shell();

	void init();
	void run(const std::function<void(Shell&)>& func, size_t iterations = 0U);
	bool pump();

public:
	string m_exec_path;
	string m_resource_path;

	GfxSystem m_gfx_system;
	object_ptr<Context> m_context;

	std::function<void(Shell&)> m_pump;
};

class Viewer
{
public:
	Viewer(GfxContext& context, Scene& scene, const vec4& rect);
	Viewer(GfxContext& context, Scene& scene);
	~Viewer();

	attr_ Scene* m_scene;
	GfxContext& m_context;

	mud::Camera m_camera;
	attr_ Viewport m_viewport;

	attr_ vec2 m_position;
	attr_ vec2 m_size;

	void resize();
	vec4 query_size();
};

class SceneViewer : public Scene, public Viewer
{
public:
	SceneViewer(GfxContext& context, const vec4& rect);
	SceneViewer(GfxContext& context);
};

}