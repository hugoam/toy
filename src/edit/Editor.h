#pragma once

#include <edit/Forward.h>

using namespace mud; namespace toy
{
#if 0
	class EditorApp : public NonCopy
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

		object_ptr<Shell> m_shell;
		object_ptr<Editor> m_editor;
	};
#endif
}
