//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <test/Forward.h>
#include <toy/toy.h>

using namespace two;
using namespace toy;

namespace test
{
class Shell
{
public:
	Shell(const string& resource_path, int argc, char *argv[]);
	~Shell();

	void init();
	void run(const function<void(Shell&)>& func, size_t iterations = 0U);
	bool pump();

public:
	string m_exec_path;
	string m_resource_path;

	GfxSystem m_gfx;
	object<Context> m_context;

	function<void(Shell&)> m_pump;
};

class Viewer
{
public:
	Viewer(GfxWindow& context, Scene& scene, const vec4& rect);
	Viewer(GfxWindow& context, Scene& scene);
	~Viewer();

	attr_ Scene* m_scene;
	GfxWindow& m_context;

	two::Camera m_camera;
	attr_ Viewport m_viewport;

	attr_ vec2 m_position;
	attr_ vec2 m_size;

	void resize();
	vec4 query_size();
};

class SceneViewer : public Scene, public Viewer
{
public:
	SceneViewer(GfxWindow& context, const vec4& rect);
	SceneViewer(GfxWindow& context);
};

}