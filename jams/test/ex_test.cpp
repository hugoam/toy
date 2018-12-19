
#include <test/ex_test.h>
#include <toy/toy.h>

#include <test/Api.h>
#include <meta/test/Module.h>

namespace test
{
#ifdef MUD_PLATFORM_EMSCRIPTEN
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

string exec_path(int argc, char *argv[])
{
#ifdef _WIN32
	UNUSED(argc);
	string exec_path = argv[0];
	string exec_dir(exec_path.begin(), exec_path.begin() + exec_path.rfind('\\'));
#else
	UNUSED(argc); UNUSED(argv);
	string exec_dir = "./";
#endif
	return exec_dir;
}

Shell::Shell(array<cstring> resource_paths, int argc, char *argv[])
	: m_exec_path(exec_path(argc, argv))
	, m_resource_path(resource_paths[0])
	, m_gfx_system(resource_paths)
{
	System::instance().load_modules({ &mud_infra::m(), &mud_type::m(), &mud_pool::m(), &mud_refl::m(), &mud_proto::m(), &mud_tree::m() });
	System::instance().load_modules({ &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_noise::m(), &mud_wfc::m(), &mud_fract::m(), &mud_lang::m() });
	System::instance().load_modules({ &mud_ctx::m(), &mud_ui::m(), &mud_gfx::m(), &mud_gfx_pbr::m(), &mud_gfx_obj::m(), &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_tool::m() });

	// @todo this should be automatically done by math module
	register_math_conversions();

	declare_gfx_edit();

	this->init();
}

Shell::~Shell()
{}

void Shell::run(const std::function<void(Shell&)>& func, size_t iterations)
{
	m_pump = func;

#ifdef MUD_PLATFORM_EMSCRIPTEN
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
	m_pump(*this);
	m_gfx_system.begin_frame();
	return m_gfx_system.next_frame();
}

void Shell::init()
{
	m_context = m_gfx_system.create_context("mud EditorCore", 1600, 900, false);
	GfxContext& context = as<GfxContext>(*m_context);

	//pipeline_minimal(m_gfx_system, *m_gfx_system.m_pipeline);
	pipeline_pbr(m_gfx_system, *m_gfx_system.m_pipeline);
	m_gfx_system.init_pipeline();
}


Viewer::Viewer(GfxContext& context, Scene& scene, const vec4& rect)
	: m_scene(&scene)
	, m_context(context)
	, m_camera()
	, m_viewport(m_camera, scene)
	, m_position(rect_offset(rect))
	, m_size(rect_size(rect))
{
	m_viewport.m_get_size = [&] { return uvec4(this->query_size()); };
	m_viewport.m_render = [&](Render& render) {};

	//m_custom_draw = [&](const Frame& frame, const vec4& rect, VgRenderer& renderer) { UNUSED(frame); renderer.draw_frame(frame, rect); this->blit(renderer); };

	m_context.m_viewports.push_back(&m_viewport);

	//this->take_focus();
}

Viewer::Viewer(GfxContext& context, Scene& scene)
	: Viewer(context, scene, { 0.f, 0.f, float(context.m_width), float(context.m_height) })
{}

Viewer::~Viewer()
{
	vector_remove(m_context.m_viewports, &m_viewport);
}

vec4 Viewer::query_size()
{
	return { m_position, m_size };
}

void Viewer::resize()
{
	m_viewport.m_rect = uvec4(this->query_size());
}

SceneViewer::SceneViewer(GfxContext& context, const vec4& rect)
	: Scene(context.m_gfx_system)
	, Viewer(context, *this, rect)
{}

SceneViewer::SceneViewer(GfxContext& context)
	: Scene(context.m_gfx_system)
	, Viewer(context, *this)
{}

void ex_test(Shell& app)
{
	UNUSED(app);
	SceneViewer viewer = { app.m_gfx_system.context() };
	Gnode& scene = viewer.m_scene->begin();

	static vec3 position = Zero3;
	static vec3 speed = Zero3;

	Gnode& node = gfx::node(scene, {}, position);
	gfx::shape(node, Cube(), Symbol::wire(Colour::Red));
}
}
#ifdef _EX_TEST_EXE
int main(int argc, char *argv[])
{
	test::Shell app(carray<cstring, 1>{ TOY_RESOURCE_PATH }, argc, argv);
	
	app.run(test::ex_test);
}
#endif
