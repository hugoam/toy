-- toy engine
-- toy jam example applications

function uses_jam()
    includedirs {
        path.join(TOY_DIR, "example"),
        path.join(MUD_DIR, "example"),
    }
end

toy.all = table.union(mud.mud, toy.toy)

minimal     = mud_module(nil, "_minimal",   path.join(TOY_DIR, "jams"), "minimal",  nil, nil, uses_jam, toy.all)
space       = mud_module(nil, "_space",     path.join(TOY_DIR, "jams"), "space",    nil, nil, uses_jam, toy.all)
platform    = mud_module(nil, "_platform",  path.join(TOY_DIR, "jams"), "platform", nil, nil, uses_jam, toy.all)
blocks      = mud_module(nil, "_blocks",    path.join(TOY_DIR, "jams"), "blocks",   nil, nil, uses_jam, toy.all)
script      = mud_module(nil, "_wren",      path.join(TOY_DIR, "jams"), "wren",     nil, nil, uses_jam, toy.all)

function preload_example_folder(name)
    configuration { "asmjs" }
        linkoptions {
            "--preload-file ../../../data/examples/" .. name .. "@data/",
        }
    
    configuration {}
end

function jam_project(name, modules, folders)
    toy_shell("ex_" .. name, modules)
    --toy_dll("ex_" .. name, modules)
    
    preload_example_folder("ex_" .. name)
    
    for _, f in pairs(folders or {}) do
        preload_example_folder(f)
    end
end

jam_project("minimal",  { minimal })
jam_project("space",    { space })
jam_project("platform", { platform }, { "05_character", "17_wfc" })
jam_project("blocks",   { blocks, _G["05_character"] })
jam_project("wren",     { script })
