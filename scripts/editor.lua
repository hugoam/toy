-- toy engine
-- toy editor application

-- @todo why linking only toy.toy yields compile errors ?
editor = toy_binary("editor", {}, toy.all)

	files {
        path.join(TOY_SRC_DIR, "editor.cpp"),
	}
