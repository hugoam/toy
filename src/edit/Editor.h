#pragma once

#include <edit/Forward.h>

namespace toy
{
#if 0
	class EditorApp
	{
	public:
		EditorApp(const string& execPath, const string& resourcePath);
		~EditorApp();

		void init(bool prompt);
		int pump();
		void cleanup();

		void startEditor();

		void loadGame(const string& path);
		void reloadGame();

	protected:
		User m_user;

		object<Shell> m_shell;
		object<Editor> m_editor;
	};
#endif
}
