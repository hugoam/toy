
#include <edit/Types.h>
#include <edit/Editor.h>

namespace toy
{
#if 0
	/*EditorUser& EditorCore::connect(const string& name, EditorApp& frontApp)
	{
		if(m_users.find(name) == m_users.end())
			m_users[name] = oconstruct<EditorUser>(*this, frontApp);

		return *m_users[name];
	}*/

	template <> Type& type<Shell>() { static Type ty("Shell"); return ty; }

	EditorApp::EditorApp(const string& execPath, const string& resourcePath)
		: m_user(0, "admin")
		, m_shell(oconstruct<Shell>(execPath, resourcePath))
		, m_editor(nullptr)
	{
		System::instance().loadModules({ &toyobj::module(), &toymath::module(), &toyutil::module(), &toycore::module(),
										 &toyui::module(), &toygfx::module(), &toyvisu::module(), &toyedit::module(),
										 &toyblock::module(), &toygen::module() });
	}

	EditorApp::~EditorApp()
	{}

	void EditorApp::init(bool prompt)
	{
		m_shell->initVisu(m_user, prompt);
		this->startEditor();
	}

	void EditorApp::loadGame(const string& path)
	{
		m_shell->loadGame(path, false);
		m_editor->editWorld(*m_shell->m_game.m_world);
	}

	void EditorApp::reloadGame()
	{
		m_editor->closeWorld();
		World& world = m_shell->reloadGame();
		m_editor->editWorld(world);
	}

	void EditorApp::startEditor()
	{
		printf("Starting Editor\n");

		m_editor = oconstruct<Editor>(m_user, *m_shell->m_visuSystem);

		//m_editorUi = &m_shell->m_rootDevice->emplace<DEditor>(*m_editor, *m_shell->m_visuSystem);
		
		/*m_editor->actionGroup("File").m_actions["Load Game"] = [this] {

			DModal& modal = m_editorUi->rootDevice().emplace<DModal>();
			DQuery& query = modal.emplace<DQuery>("Game Module Path", var(string()));
			modal.m_callback = [this, &query] { this->loadGame(val<string>(query.m_value)); };

		};*/

		m_editor->actionGroup("File").m_actions["New World"] = [this] { m_shell->generateWorld(); };

		m_editor->actionGroup("File").m_actions["Save World"] = [this] { m_shell->saveWorld(); };

		m_editor->actionGroup("File").m_actions["Reload Game"] = [this] { this->reloadGame(); };

		m_editor->actionGroup("File").m_actions["Dump Memory Usage"] = [this] { System::instance().dumpMemoryUsage(); };

		m_editor->actionGroup("File").m_actions["Start"] = [this] { m_shell->launchGame(); };
	}
#endif
}
