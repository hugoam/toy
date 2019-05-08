-- toy engine
-- toy example modules

function toy_example(name, deps)
    _G[name] = module(nil, "_" .. name, path.join(TOY_DIR, "example"), name, nil, nil, false, toy.toy)
        
    toy_shell("_" .. name, table.union({ _G[name] }, deps))
end

--toy_example("05_character", { _G["03_materials"] })
--toy_example("15_script", { "01_shapes", "03_materials" })
--toy_example("16_visual_script", { "01_shapes", "03_materials" })
--toy_example("17_proc_gen")
--toy_example("18_pathfinding")
--toy_example("19_multi_viewport")
--toy_example("20_meta", { "01_shapes", "03_materials" })

