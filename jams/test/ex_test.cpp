
#include <test/ex_test.h>
#include <toy/toy.h>

#include <test/Api.h>

#include <meta/infra.meta.h>
#include <meta/jobs.meta.h>
#include <meta/type.meta.h>
#include <meta/tree.meta.h>
#include <meta/pool.meta.h>
#include <meta/refl.meta.h>
#include <meta/ecs.meta.h>
#include <meta/srlz.meta.h>
#include <meta/math.meta.h>
#include <meta/geom.meta.h>
#include <meta/lang.meta.h>
#include <meta/ctx.meta.h>
#include <meta/ui.meta.h>
#include <meta/uio.meta.h>
#include <meta/tool.meta.h>
#include <meta/bgfx.meta.h>
#include <meta/gfx.meta.h>
#include <meta/gfx.ui.meta.h>
#include <meta/frame.meta.h>
#include <meta/core.meta.h>
#include <meta/visu.meta.h>
#include <meta/edit.meta.h>
#include <meta/block.meta.h>
#include <meta/shell.meta.h>

#include <meta/_test.meta.h>

#include <stl/string.hpp>

using namespace two;
using namespace toy;

namespace test
{
#ifdef TWO_PLATFORM_EMSCRIPTEN
static Shell* g_app = nullptr;
static size_t g_frame = 0U;
static size_t g_iterations = 0U;
static void iterate()
{
	g_app->pump();
	if(g_iterations > 0 && g_frame++ > g_iterations)
		emscripten_cancel_main_loop();
}
#endif

Shell::Shell(const string& resource_path, int argc, char *argv[])
	: m_exec_path(exec_path(argc, argv))
	, m_resource_path(resource_path)
	, m_gfx(resource_path)
{
	System::instance().load_modules({ &two_infra::m(), &two_type::m(), &two_pool::m(), &two_refl::m(), &two_ecs::m(), &two_tree::m() });
	System::instance().load_modules({ &two_srlz::m(), &two_math::m(), &two_geom::m(), &two_lang::m() });
	System::instance().load_modules({ &two_ctx::m(), &two_ui::m(), &two_gfx::m(), &two_gfx_ui::m(), &two_tool::m() });

	// @todo this should be automatically done by math module
	register_math_conversions();

	declare_gfx_edit();

	this->init();
}

Shell::~Shell()
{}

void Shell::run(const function<void(Shell&)>& func, size_t iterations)
{
	m_pump = func;

#ifdef TWO_PLATFORM_EMSCRIPTEN
	g_app = this;
	g_iterations = iterations;
	emscripten_set_main_loop(iterate, 0, 1);
#else
	size_t frame = 0;
	while(pump() && (iterations == 0 || frame++ < iterations));
#endif
}

bool Shell::pump()
{
	bool pursue = m_gfx.begin_frame();
	m_pump(*this);
	m_gfx.end_frame();
	return pursue;
}

void Shell::init()
{
	m_context = construct<GfxWindow>(m_gfx, "two EditorCore", uvec2(1600, 900), false);
	GfxWindow& context = as<GfxWindow>(*m_context);

	m_gfx.init_pipeline(pipeline_pbr);
}


Viewer::Viewer(GfxWindow& context, Scene& scene, const vec4& rect)
	: m_scene(&scene)
	, m_context(context)
	, m_camera()
	, m_viewport(m_camera, scene)
	, m_position(rect.pos)
	, m_size(rect.size)
{
	//m_viewport.m_rect = uvec4(vec4(m_position, m_size));

	//m_viewport.m_render = [&](Render& render) {};

	//m_custom_draw = [&](const Frame& frame, const vec4& rect, VgRenderer& renderer) { UNUSED(frame); renderer.draw_frame(frame, rect); this->blit(renderer); };

	//m_viewports.push_back(&m_viewport);

	//this->take_focus();
}

Viewer::Viewer(GfxWindow& context, Scene& scene)
	: Viewer(context, scene, { 0.f, 0.f, float(context.m_size.x), float(context.m_size.y) })
{}

Viewer::~Viewer()
{
	//remove(m_viewports, &m_viewport);
}

void Viewer::resize()
{
	//m_viewport.m_rect = uvec4(vec4(m_position, m_size));
}

SceneViewer::SceneViewer(GfxWindow& context, const vec4& rect)
	: Scene(context.m_gfx)
	, Viewer(context, *this, rect)
{}

SceneViewer::SceneViewer(GfxWindow& context)
	: Scene(context.m_gfx)
	, Viewer(context, *this)
{}

void ex_test(Shell& app)
{
	UNUSED(app);
	SceneViewer viewer = { app.m_gfx.context() };
	Gnode& scene = viewer.m_scene->begin();

	static vec3 position = vec3(0.f);
	static vec3 speed = vec3(0.f);

	Gnode& node = gfx::node(scene, position);
	gfx::shape(node, Cube(), Symbol::wire(Colour::Red));
}
}
#ifdef _EX_TEST_EXE
int main(int argc, char *argv[])
{
	test::Shell app(TOY_RESOURCE_PATH, argc, argv);
	
	app.run(test::ex_test);
}
#endif
