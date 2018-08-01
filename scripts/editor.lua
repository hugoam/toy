-- toy engine
-- toy editor application

editor = toy_binary("editor", {}, toy.toy)

	files {
        path.join(TOY_SRC_DIR, "editor.cpp"),
	}
