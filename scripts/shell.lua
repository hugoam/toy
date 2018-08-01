-- toy engine
-- toy shell application

project "shell"
	kind "ConsoleApp"
    
	files {
        path.join(TOY_SRC_DIR, "shell.cpp"),
	}

    uses_toy()
    toy_binary("shell")