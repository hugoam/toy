#pragma once

#ifndef MUD_MODULES
#include <meta/space/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void _space_meta(Module& m)
    {
    UNUSED(m);
    
    // Base Types
    
    // Enums
    {
        static Meta meta = { type<CombatType>(), &namspc({}), "CombatType", sizeof(CombatType), TypeClass::Enum };
        static Enum enu = { type<CombatType>(),
            true,
            { "Spatial", "Planetary" },
            { 0, 1 },
            { var(CombatType::Spatial), var(CombatType::Planetary) }
        };
        meta_enum<CombatType>();
    }
    {
        static Meta meta = { type<Experience>(), &namspc({}), "Experience", sizeof(Experience), TypeClass::Enum };
        static Enum enu = { type<Experience>(),
            true,
            { "Inexperienced", "LittleExperienced", "Experienced", "Superior", "Elite" },
            { 0, 1, 2, 3, 4 },
            { var(Experience::Inexperienced), var(Experience::LittleExperienced), var(Experience::Experienced), var(Experience::Superior), var(Experience::Elite) }
        };
        meta_enum<Experience>();
    }
    {
        static Meta meta = { type<FleetSize>(), &namspc({}), "FleetSize", sizeof(FleetSize), TypeClass::Enum };
        static Enum enu = { type<FleetSize>(),
            true,
            { "Ridicule", "Minuscule", "Tiny", "Small", "Medium", "Respectable", "Grand", "HighGrand", "Colossal", "Titanesque", "Cyclopean", "Divine", "Count" },
            { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
            { var(FleetSize::Ridicule), var(FleetSize::Minuscule), var(FleetSize::Tiny), var(FleetSize::Small), var(FleetSize::Medium), var(FleetSize::Respectable), var(FleetSize::Grand), var(FleetSize::HighGrand), var(FleetSize::Colossal), var(FleetSize::Titanesque), var(FleetSize::Cyclopean), var(FleetSize::Divine), var(FleetSize::Count) }
        };
        meta_enum<FleetSize>();
    }
    {
        static Meta meta = { type<FleetStance>(), &namspc({}), "FleetStance", sizeof(FleetStance), TypeClass::Enum };
        static Enum enu = { type<FleetStance>(),
            true,
            { "Movement", "SpatialAttack", "SpatialDefense", "PlanetaryAttack", "PlanetaryDefense", "Pillage" },
            { 0, 1, 2, 3, 4, 5 },
            { var(FleetStance::Movement), var(FleetStance::SpatialAttack), var(FleetStance::SpatialDefense), var(FleetStance::PlanetaryAttack), var(FleetStance::PlanetaryDefense), var(FleetStance::Pillage) }
        };
        meta_enum<FleetStance>();
    }
    {
        static Meta meta = { type<GameStage>(), &namspc({}), "GameStage", sizeof(GameStage), TypeClass::Enum };
        static Enum enu = { type<GameStage>(),
            true,
            { "Empire", "Tactics", "TurnReport" },
            { 0, 1, 2 },
            { var(GameStage::Empire), var(GameStage::Tactics), var(GameStage::TurnReport) }
        };
        meta_enum<GameStage>();
    }
    {
        static Meta meta = { type<Politic>(), &namspc({}), "Politic", sizeof(Politic), TypeClass::Enum };
        static Enum enu = { type<Politic>(),
            true,
            { "Taxes", "Commerce", "Construction", "Defense", "Pacification" },
            { 0, 1, 2, 3, 4 },
            { var(Politic::Taxes), var(Politic::Commerce), var(Politic::Construction), var(Politic::Defense), var(Politic::Pacification) }
        };
        meta_enum<Politic>();
    }
    {
        static Meta meta = { type<Race>(), &namspc({}), "Race", sizeof(Race), TypeClass::Enum };
        static Enum enu = { type<Race>(),
            true,
            { "Human", "Bulvoid", "Techtulon", "Rakrarior", "Seigneur", "Meton", "Tissinar", "Zwiie" },
            { 0, 1, 2, 3, 4, 5, 6, 7 },
            { var(Race::Human), var(Race::Bulvoid), var(Race::Techtulon), var(Race::Rakrarior), var(Race::Seigneur), var(Race::Meton), var(Race::Tissinar), var(Race::Zwiie) }
        };
        meta_enum<Race>();
    }
    {
        static Meta meta = { type<Regime>(), &namspc({}), "Regime", sizeof(Regime), TypeClass::Enum };
        static Enum enu = { type<Regime>(),
            true,
            { "Empire", "Dictature", "Democracy", "Theocracy", "Technocracy", "Piratery" },
            { 0, 1, 2, 3, 4, 5 },
            { var(Regime::Empire), var(Regime::Dictature), var(Regime::Democracy), var(Regime::Theocracy), var(Regime::Technocracy), var(Regime::Piratery) }
        };
        meta_enum<Regime>();
    }
    {
        static Meta meta = { type<Resource>(), &namspc({}), "Resource", sizeof(Resource), TypeClass::Enum };
        static Enum enu = { type<Resource>(),
            true,
            { "None", "Minerals", "Andrium", "Alcool", "Slaves", "Narcotics", "Food", "Medicine", "Computers", "Plastic", "Robot", "Count" },
            { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
            { var(Resource::None), var(Resource::Minerals), var(Resource::Andrium), var(Resource::Alcool), var(Resource::Slaves), var(Resource::Narcotics), var(Resource::Food), var(Resource::Medicine), var(Resource::Computers), var(Resource::Plastic), var(Resource::Robot), var(Resource::Count) }
        };
        meta_enum<Resource>();
    }
    {
        static Meta meta = { type<Taxation>(), &namspc({}), "Taxation", sizeof(Taxation), TypeClass::Enum };
        static Enum enu = { type<Taxation>(),
            true,
            { "None", "Light", "Medium", "Heavy", "Heaviest", "Total" },
            { 0, 1, 2, 3, 4, 5 },
            { var(Taxation::None), var(Taxation::Light), var(Taxation::Medium), var(Taxation::Heavy), var(Taxation::Heaviest), var(Taxation::Total) }
        };
        meta_enum<Taxation>();
    }
    {
        static Meta meta = { type<Technology>(), &namspc({}), "Technology", sizeof(Technology), TypeClass::Enum };
        static Enum enu = { type<Technology>(),
            true,
            { "Engines", "EcoEnergy", "Scanners", "PlanetaryShields", "SpatialShields", "LaserPlasmaIons", "Torpedoes", "Bombs", "HullArmor", "Mining", "Terraforming", "Construction", "Piloting", "Commerce", "Personnel", "Administration", "CyberCommand", "CyberCommerce", "CyberDiplomacy", "Count" },
            { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 },
            { var(Technology::Engines), var(Technology::EcoEnergy), var(Technology::Scanners), var(Technology::PlanetaryShields), var(Technology::SpatialShields), var(Technology::LaserPlasmaIons), var(Technology::Torpedoes), var(Technology::Bombs), var(Technology::HullArmor), var(Technology::Mining), var(Technology::Terraforming), var(Technology::Construction), var(Technology::Piloting), var(Technology::Commerce), var(Technology::Personnel), var(Technology::Administration), var(Technology::CyberCommand), var(Technology::CyberCommerce), var(Technology::CyberDiplomacy), var(Technology::Count) }
        };
        meta_enum<Technology>();
    }
    {
        static Meta meta = { type<WeaponType>(), &namspc({}), "WeaponType", sizeof(WeaponType), TypeClass::Enum };
        static Enum enu = { type<WeaponType>(),
            true,
            { "None", "Ion", "Laser", "Plasma", "Torpedo", "Bomb" },
            { 0, 1, 2, 3, 4, 5 },
            { var(WeaponType::None), var(WeaponType::Ion), var(WeaponType::Laser), var(WeaponType::Plasma), var(WeaponType::Torpedo), var(WeaponType::Bomb) }
        };
        meta_enum<WeaponType>();
    }
    
    // Sequences
    {
        static Meta meta = { type<vector<CombatFleet>>(), &namspc({}), "vector<CombatFleet>", sizeof(vector<CombatFleet>), TypeClass::Sequence };
        static Class cls = { type<vector<CombatFleet>>() };
        cls.m_content = &type<CombatFleet>();
        meta_vector<vector<CombatFleet>, CombatFleet>();
    }
    {
        static Meta meta = { type<vector<Commander*>>(), &namspc({}), "vector<Commander*>", sizeof(vector<Commander*>), TypeClass::Sequence };
        static Class cls = { type<vector<Commander*>>() };
        cls.m_content = &type<Commander>();
        meta_vector<vector<Commander*>, Commander*>();
    }
    
    // Combat
    {
        static Meta meta = { type<Combat>(), &namspc({}), "Combat", sizeof(Combat), TypeClass::Struct };
        static Class cls = { type<Combat>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Combat>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Combat>(ref)) Combat(  ); }, {} }
            },
            // copy constructor
            {
                { type<Combat>(), [](Ref ref, Ref other) { new(&val<Combat>(ref)) Combat(val<Combat>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Combat>();
    }
    // CombatFleet
    {
        static Meta meta = { type<CombatFleet>(), &namspc({}), "CombatFleet", sizeof(CombatFleet), TypeClass::Struct };
        static Class cls = { type<CombatFleet>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<CombatFleet>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<CombatFleet>(ref)) CombatFleet(  ); }, {} }
            },
            // copy constructor
            {
                { type<CombatFleet>(), [](Ref ref, Ref other) { new(&val<CombatFleet>(ref)) CombatFleet(val<CombatFleet>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<CombatFleet>();
    }
    // CombatStar
    {
        static Meta meta = { type<CombatStar>(), &namspc({}), "CombatStar", sizeof(CombatStar), TypeClass::Struct };
        static Class cls = { type<CombatStar>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<CombatStar>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<CombatStar>(ref)) CombatStar(  ); }, {} }
            },
            // copy constructor
            {
                { type<CombatStar>(), [](Ref ref, Ref other) { new(&val<CombatStar>(ref)) CombatStar(val<CombatStar>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<CombatStar>();
    }
    // Commander
    {
        static Meta meta = { type<Commander>(), &namspc({}), "Commander", sizeof(Commander), TypeClass::Object };
        static Class cls = { type<Commander>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Commander>(), [](Ref ref, array<Var> args) { new(&val<Commander>(ref)) Commander( val<uint32_t>(args[0]), val<string>(args[1]), val<Race>(args[2]), val<int>(args[3]), val<int>(args[4]), val<int>(args[5]) ); }, { { "id", var(uint32_t()) }, { "name", var(string()) }, { "race", var(Race()) }, { "command", var(int()) }, { "commerce", var(int()) }, { "diplomacy", var(int()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Commander>(), member_address(&Commander::m_id), type<uint32_t>(), "id", var(uint32_t()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_name), type<string>(), "name", var(string()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_race), type<Race>(), "race", var(Race()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_command), type<int>(), "command", var(int()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_commerce), type<int>(), "commerce", var(int()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_diplomacy), type<int>(), "diplomacy", var(int()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_reputation), type<int>(), "reputation", var(int()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_victory), type<int>(), "victory", var(int()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_stars), type<vector<HStar>>(), "stars", var(vector<HStar>()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_fleets), type<vector<HFleet>>(), "fleets", var(vector<HFleet>()), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_capital), type<Star>(), "capital", Ref(type<Star>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Commander>(), member_address(&Commander::m_regime), type<Regime>(), "regime", var(Regime::Empire), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_power), type<float>(), "power", var(float(0.f)), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_centaures), type<float>(), "centaures", var(float(0.f)), Member::Value, nullptr },
                { type<Commander>(), member_address(&Commander::m_scans), type<Scans>(), "scans", var(Scans()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<Commander>();
        meta_class<Commander>();
    }
    // Construction
    {
        static Meta meta = { type<Construction>(), &namspc({}), "Construction", sizeof(Construction), TypeClass::Struct };
        static Class cls = { type<Construction>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Construction>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Construction>(ref)) Construction(  ); }, {} }
            },
            // copy constructor
            {
                { type<Construction>(), [](Ref ref, Ref other) { new(&val<Construction>(ref)) Construction(val<Construction>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Construction>();
    }
    // Fleet
    {
        static Meta meta = { type<Fleet>(), &namspc({}), "Fleet", sizeof(Fleet), TypeClass::Object };
        static Class cls = { type<Fleet>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Fleet>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Fleet>(ref)) Fleet(  ); }, {} },
                { type<Fleet>(), [](Ref ref, array<Var> args) { new(&val<Fleet>(ref)) Fleet( val<toy::HSpatial>(args[0]), val<Galaxy>(args[1]), val<Commander>(args[2]), val<mud::uvec2>(args[3]), val<string>(args[4]) ); }, { { "spatial", var(toy::HSpatial()) }, { "galaxy", Ref(type<Galaxy>()) }, { "commander", Ref(type<Commander>()) }, { "coord", var(mud::uvec2()) }, { "name", var(string()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Fleet>(), member_address(&Fleet::m_galaxy), type<Galaxy>(), "galaxy", Ref(type<Galaxy>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Fleet>(), member_address(&Fleet::m_commander), type<Commander>(), "commander", Ref(type<Commander>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Fleet>(), member_address(&Fleet::m_coord), type<mud::uvec2>(), "coord", var(mud::uvec2()), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_slot), type<mud::vec3>(), "slot", var(mud::vec3()), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_name), type<string>(), "name", var(string()), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_experience), type<float>(), "experience", var(float(0.f)), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_spatial_power), type<SpatialPower>(), "spatial_power", var(SpatialPower{}), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_planetary_power), type<float>(), "planetary_power", var(float(0.f)), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_speed), type<uint8_t>(), "speed", var(uint8_t(0)), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_scan), type<uint8_t>(), "scan", var(uint8_t(0)), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_upkeep), type<float>(), "upkeep", var(float(0.f)), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_stance), type<FleetStance>(), "stance", var(FleetStance::Movement), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_jump), type<Jump>(), "jump", var(Jump()), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_split), type<Split>(), "split", var(Split()), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_fought), type<bool>(), "fought", var(bool(false)), Member::Value, nullptr },
                { type<Fleet>(), member_address(&Fleet::m_ships_updated), type<size_t>(), "ships_updated", var(size_t(0)), Member::Value, nullptr }
            },
            // methods
            {
                { type<Fleet>(), "order_jump", member_address<void(Fleet::*)(mud::uvec2, FleetStance)>(&Fleet::order_jump), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<Fleet>(object).order_jump(val<mud::uvec2>(args[0]), val<FleetStance>(args[1])); }, { { "coord", var(mud::uvec2()) }, { "stance", var(FleetStance()) } }, Var() },
                { type<Fleet>(), "order_attack", member_address<void(Fleet::*)(Star&)>(&Fleet::order_attack), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<Fleet>(object).order_attack(val<Star>(args[0])); }, { { "star", Ref(type<Star>()) } }, Var() }
            },
            // static members
            {
            }
        };
        init_pool<Fleet>();
        meta_class<Fleet>();
    }
    // Galaxy
    {
        static Meta meta = { type<Galaxy>(), &namspc({}), "Galaxy", sizeof(Galaxy), TypeClass::Object };
        static Class cls = { type<Galaxy>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Galaxy>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Galaxy>(ref)) Galaxy(  ); }, {} },
                { type<Galaxy>(), [](Ref ref, array<Var> args) { new(&val<Galaxy>(ref)) Galaxy( val<toy::HSpatial>(args[0]), val<mud::uvec2>(args[1]) ); }, { { "spatial", var(toy::HSpatial()) }, { "size", var(mud::uvec2()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Galaxy>(), member_address(&Galaxy::m_stars), type<vector<HStar>>(), "stars", var(vector<HStar>()), Member::Value, nullptr },
                { type<Galaxy>(), member_address(&Galaxy::m_fleets), type<vector<HFleet>>(), "fleets", var(vector<HFleet>()), Member::Value, nullptr },
                { type<Galaxy>(), member_address(&Galaxy::m_commanders), type<vector<Commander*>>(), "commanders", var(vector<Commander*>()), Member::Value, nullptr },
                { type<Galaxy>(), member_address(&Galaxy::m_size), type<mud::uvec2>(), "size", var(mud::uvec2()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<Galaxy>();
        meta_class<Galaxy>();
    }
    // Jump
    {
        static Meta meta = { type<Jump>(), &namspc({}), "Jump", sizeof(Jump), TypeClass::Struct };
        static Class cls = { type<Jump>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Jump>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Jump>(ref)) Jump(  ); }, {} }
            },
            // copy constructor
            {
                { type<Jump>(), [](Ref ref, Ref other) { new(&val<Jump>(ref)) Jump(val<Jump>(other)); } }
            },
            // members
            {
                { type<Jump>(), member_address(&Jump::m_fleet), type<Fleet>(), "fleet", Ref(type<Fleet>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Jump>(), member_address(&Jump::m_start), type<mud::uvec2>(), "start", var(mud::uvec2()), Member::Value, nullptr },
                { type<Jump>(), member_address(&Jump::m_dest), type<mud::uvec2>(), "dest", var(mud::uvec2()), Member::Value, nullptr },
                { type<Jump>(), member_address(&Jump::m_stance), type<FleetStance>(), "stance", var(FleetStance()), Member::Value, nullptr },
                { type<Jump>(), member_address(&Jump::m_track), type<Fleet>(), "track", Ref(type<Fleet>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Jump>();
    }
    // Player
    {
        static Meta meta = { type<Player>(), &namspc({}), "Player", sizeof(Player), TypeClass::Object };
        static Class cls = { type<Player>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Player>();
    }
    // Scans
    {
        static Meta meta = { type<Scans>(), &namspc({}), "Scans", sizeof(Scans), TypeClass::Struct };
        static Class cls = { type<Scans>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Scans>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Scans>(ref)) Scans(  ); }, {} }
            },
            // copy constructor
            {
                { type<Scans>(), [](Ref ref, Ref other) { new(&val<Scans>(ref)) Scans(val<Scans>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Scans>();
    }
    // Schema
    {
        static Meta meta = { type<Schema>(), &namspc({}), "Schema", sizeof(Schema), TypeClass::Struct };
        static Class cls = { type<Schema>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Schema>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Schema>(ref)) Schema(  ); }, {} }
            },
            // copy constructor
            {
                { type<Schema>(), [](Ref ref, Ref other) { new(&val<Schema>(ref)) Schema(val<Schema>(other)); } }
            },
            // members
            {
                { type<Schema>(), member_address(&Schema::m_code), type<string>(), "code", var(string()), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_name), type<string>(), "name", var(string()), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_conceptor), type<string>(), "conceptor", var(string()), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_level), type<uint8_t>(), "level", var(uint8_t(1)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_cost), type<float>(), "cost", var(float(0.f)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_minerals), type<float>(), "minerals", var(float(0.f)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_andrium), type<float>(), "andrium", var(float(0.f)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_resistance), type<float>(), "resistance", var(float(0.f)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_speed), type<uint8_t>(), "speed", var(uint8_t(0)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_scan), type<uint8_t>(), "scan", var(uint8_t(0)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_planetary), type<float>(), "planetary", var(float(0.f)), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_spatial), type<SpatialPower>(), "spatial", var(SpatialPower{}), Member::Value, nullptr },
                { type<Schema>(), member_address(&Schema::m_upkeep_factor), type<float>(), "upkeep_factor", var(float(1.f)), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Schema>();
    }
    // SpatialPower
    {
        static Meta meta = { type<SpatialPower>(), &namspc({}), "SpatialPower", sizeof(SpatialPower), TypeClass::Struct };
        static Class cls = { type<SpatialPower>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<SpatialPower>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<SpatialPower>(ref)) SpatialPower(  ); }, {} }
            },
            // copy constructor
            {
                { type<SpatialPower>(), [](Ref ref, Ref other) { new(&val<SpatialPower>(ref)) SpatialPower(val<SpatialPower>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<SpatialPower>();
    }
    // Split
    {
        static Meta meta = { type<Split>(), &namspc({}), "Split", sizeof(Split), TypeClass::Struct };
        static Class cls = { type<Split>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Split>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Split>(ref)) Split(  ); }, {} }
            },
            // copy constructor
            {
                { type<Split>(), [](Ref ref, Ref other) { new(&val<Split>(ref)) Split(val<Split>(other)); } }
            },
            // members
            {
                { type<Split>(), member_address(&Split::m_source), type<Fleet>(), "source", Ref(type<Fleet>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Split>(), member_address(&Split::m_dest), type<Fleet>(), "dest", Ref(type<Fleet>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Split>(), member_address(&Split::m_code), type<string>(), "code", var(string()), Member::Value, nullptr },
                { type<Split>(), member_address(&Split::m_stance), type<FleetStance>(), "stance", var(FleetStance()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Split>();
    }
    // Star
    {
        static Meta meta = { type<Star>(), &namspc({}), "Star", sizeof(Star), TypeClass::Object };
        static Class cls = { type<Star>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Star>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Star>(ref)) Star(  ); }, {} },
                { type<Star>(), [](Ref ref, array<Var> args) { new(&val<Star>(ref)) Star( val<toy::HSpatial>(args[0]), val<Galaxy>(args[1]), val<mud::uvec2>(args[2]), val<string>(args[3]) ); }, { { "spatial", var(toy::HSpatial()) }, { "galaxy", Ref(type<Galaxy>()) }, { "coord", var(mud::uvec2()) }, { "name", var(string()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Star>(), member_address(&Star::m_galaxy), type<Galaxy>(), "galaxy", Ref(type<Galaxy>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Star>(), member_address(&Star::m_coord), type<mud::uvec2>(), "coord", var(mud::uvec2()), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_name), type<string>(), "name", var(string()), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_stability), type<int>(), "stability", var(int(100)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_revolt), type<bool>(), "revolt", var(bool(false)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_environment), type<int>(), "environment", var(int(10)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_terraformation), type<int>(), "terraformation", var(int(0)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_base_population), type<int>(), "base_population", var(int(0)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_max_population), type<int>(), "max_population", var(int(0)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_population), type<int>(), "population", var(int(0)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_militia), type<float>(), "militia", var(float(0.1f)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_defense), type<float>(), "defense", var(float(0.f)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_revenue), type<float>(), "revenue", var(float(0.f)), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_politic), type<Politic>(), "politic", var(Politic::Taxes), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_taxation), type<Taxation>(), "taxation", var(Taxation::Medium), Member::Value, nullptr },
                { type<Star>(), member_address(&Star::m_commander), type<Commander>(), "commander", Ref(type<Commander>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Star>(), member_address(&Star::m_scan), type<int>(), "scan", var(int(0)), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<Star>();
        meta_class<Star>();
    }
    // TechDomain
    {
        static Meta meta = { type<TechDomain>(), &namspc({}), "TechDomain", sizeof(TechDomain), TypeClass::Struct };
        static Class cls = { type<TechDomain>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<TechDomain>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<TechDomain>(ref)) TechDomain(  ); }, {} }
            },
            // copy constructor
            {
                { type<TechDomain>(), [](Ref ref, Ref other) { new(&val<TechDomain>(ref)) TechDomain(val<TechDomain>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<TechDomain>();
    }
    // Turn
    {
        static Meta meta = { type<Turn>(), &namspc({}), "Turn", sizeof(Turn), TypeClass::Struct };
        static Class cls = { type<Turn>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Turn>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Turn>(ref)) Turn(  ); }, {} }
            },
            // copy constructor
            {
                { type<Turn>(), [](Ref ref, Ref other) { new(&val<Turn>(ref)) Turn(val<Turn>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Turn>();
    }
    // BuildingSchema
    {
        static Meta meta = { type<BuildingSchema>(), &namspc({}), "BuildingSchema", sizeof(BuildingSchema), TypeClass::Struct };
        static Class cls = { type<BuildingSchema>(),
            // bases
            { &type<Schema>() },
            { base_offset<BuildingSchema, Schema>() },
            // constructors
            {
                { type<BuildingSchema>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<BuildingSchema>(ref)) BuildingSchema(  ); }, {} }
            },
            // copy constructor
            {
                { type<BuildingSchema>(), [](Ref ref, Ref other) { new(&val<BuildingSchema>(ref)) BuildingSchema(val<BuildingSchema>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<BuildingSchema>();
    }
    // CommanderBrush
    {
        static Meta meta = { type<CommanderBrush>(), &namspc({}), "CommanderBrush", sizeof(CommanderBrush), TypeClass::Object };
        static Class cls = { type<CommanderBrush>(),
            // bases
            { &type<mud::Brush>() },
            { base_offset<CommanderBrush, mud::Brush>() },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
                { type<CommanderBrush>(), member_address(&CommanderBrush::m_commander), type<Commander>(), "commander", Ref(type<Commander>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<CommanderBrush>(), member_address(&CommanderBrush::m_radius), type<float>(), "radius", var(float()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<CommanderBrush>();
    }
    // mud::ComponentHandle<Fleet>
    {
        static Meta meta = { type<mud::ComponentHandle<Fleet>>(), &namspc({ "mud" }), "ComponentHandle<Fleet>", sizeof(mud::ComponentHandle<Fleet>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Fleet>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Fleet>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Fleet>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Fleet>>(ref)) mud::ComponentHandle<Fleet>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Fleet>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Fleet>>(ref)) mud::ComponentHandle<Fleet>(val<mud::ComponentHandle<Fleet>>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<mud::ComponentHandle<Fleet>>();
    }
    // mud::ComponentHandle<Galaxy>
    {
        static Meta meta = { type<mud::ComponentHandle<Galaxy>>(), &namspc({ "mud" }), "ComponentHandle<Galaxy>", sizeof(mud::ComponentHandle<Galaxy>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Galaxy>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Galaxy>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Galaxy>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Galaxy>>(ref)) mud::ComponentHandle<Galaxy>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Galaxy>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Galaxy>>(ref)) mud::ComponentHandle<Galaxy>(val<mud::ComponentHandle<Galaxy>>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<mud::ComponentHandle<Galaxy>>();
    }
    // mud::ComponentHandle<Star>
    {
        static Meta meta = { type<mud::ComponentHandle<Star>>(), &namspc({ "mud" }), "ComponentHandle<Star>", sizeof(mud::ComponentHandle<Star>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Star>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Star>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Star>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Star>>(ref)) mud::ComponentHandle<Star>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Star>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Star>>(ref)) mud::ComponentHandle<Star>(val<mud::ComponentHandle<Star>>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<mud::ComponentHandle<Star>>();
    }
    // PlanetaryCombat
    {
        static Meta meta = { type<PlanetaryCombat>(), &namspc({}), "PlanetaryCombat", sizeof(PlanetaryCombat), TypeClass::Struct };
        static Class cls = { type<PlanetaryCombat>(),
            // bases
            { &type<Combat>() },
            { base_offset<PlanetaryCombat, Combat>() },
            // constructors
            {
                { type<PlanetaryCombat>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<PlanetaryCombat>(ref)) PlanetaryCombat(  ); }, {} }
            },
            // copy constructor
            {
                { type<PlanetaryCombat>(), [](Ref ref, Ref other) { new(&val<PlanetaryCombat>(ref)) PlanetaryCombat(val<PlanetaryCombat>(other)); } }
            },
            // members
            {
                { type<PlanetaryCombat>(), member_address(&PlanetaryCombat::m_coord), type<mud::uvec2>(), "coord", var(mud::uvec2()), Member::Value, nullptr },
                { type<PlanetaryCombat>(), member_address(&PlanetaryCombat::m_attack), type<vector<CombatFleet>>(), "attack", var(vector<CombatFleet>()), Member::Value, nullptr },
                { type<PlanetaryCombat>(), member_address(&PlanetaryCombat::m_defense), type<CombatStar>(), "defense", var(CombatStar()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<PlanetaryCombat>();
    }
    // ShipComponent
    {
        static Meta meta = { type<ShipComponent>(), &namspc({}), "ShipComponent", sizeof(ShipComponent), TypeClass::Struct };
        static Class cls = { type<ShipComponent>(),
            // bases
            { &type<Schema>() },
            { base_offset<ShipComponent, Schema>() },
            // constructors
            {
                { type<ShipComponent>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<ShipComponent>(ref)) ShipComponent(  ); }, {} }
            },
            // copy constructor
            {
                { type<ShipComponent>(), [](Ref ref, Ref other) { new(&val<ShipComponent>(ref)) ShipComponent(val<ShipComponent>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<ShipComponent>();
    }
    // ShipEngine
    {
        static Meta meta = { type<ShipEngine>(), &namspc({}), "ShipEngine", sizeof(ShipEngine), TypeClass::Struct };
        static Class cls = { type<ShipEngine>(),
            // bases
            { &type<Schema>() },
            { base_offset<ShipEngine, Schema>() },
            // constructors
            {
                { type<ShipEngine>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<ShipEngine>(ref)) ShipEngine(  ); }, {} }
            },
            // copy constructor
            {
                { type<ShipEngine>(), [](Ref ref, Ref other) { new(&val<ShipEngine>(ref)) ShipEngine(val<ShipEngine>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<ShipEngine>();
    }
    // ShipHull
    {
        static Meta meta = { type<ShipHull>(), &namspc({}), "ShipHull", sizeof(ShipHull), TypeClass::Struct };
        static Class cls = { type<ShipHull>(),
            // bases
            { &type<Schema>() },
            { base_offset<ShipHull, Schema>() },
            // constructors
            {
                { type<ShipHull>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<ShipHull>(ref)) ShipHull(  ); }, {} }
            },
            // copy constructor
            {
                { type<ShipHull>(), [](Ref ref, Ref other) { new(&val<ShipHull>(ref)) ShipHull(val<ShipHull>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<ShipHull>();
    }
    // ShipSchema
    {
        static Meta meta = { type<ShipSchema>(), &namspc({}), "ShipSchema", sizeof(ShipSchema), TypeClass::Struct };
        static Class cls = { type<ShipSchema>(),
            // bases
            { &type<Schema>() },
            { base_offset<ShipSchema, Schema>() },
            // constructors
            {
                { type<ShipSchema>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<ShipSchema>(ref)) ShipSchema(  ); }, {} }
            },
            // copy constructor
            {
                { type<ShipSchema>(), [](Ref ref, Ref other) { new(&val<ShipSchema>(ref)) ShipSchema(val<ShipSchema>(other)); } }
            },
            // members
            {
                { type<ShipSchema>(), member_address(&ShipSchema::m_size), type<uint8_t>(), "size", var(uint8_t()), Member::Value, nullptr },
                { type<ShipSchema>(), member_address(&ShipSchema::m_class), type<uint8_t>(), "class", var(uint8_t()), Member::Value, nullptr },
                { type<ShipSchema>(), member_address(&ShipSchema::m_main_weapon), type<WeaponType>(), "main_weapon", var(WeaponType::None), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<ShipSchema>();
    }
    // SpatialCombat
    {
        static Meta meta = { type<SpatialCombat>(), &namspc({}), "SpatialCombat", sizeof(SpatialCombat), TypeClass::Struct };
        static Class cls = { type<SpatialCombat>(),
            // bases
            { &type<Combat>() },
            { base_offset<SpatialCombat, Combat>() },
            // constructors
            {
                { type<SpatialCombat>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<SpatialCombat>(ref)) SpatialCombat(  ); }, {} }
            },
            // copy constructor
            {
                { type<SpatialCombat>(), [](Ref ref, Ref other) { new(&val<SpatialCombat>(ref)) SpatialCombat(val<SpatialCombat>(other)); } }
            },
            // members
            {
                { type<SpatialCombat>(), member_address(&SpatialCombat::m_coord), type<mud::uvec2>(), "coord", var(mud::uvec2()), Member::Value, nullptr },
                { type<SpatialCombat>(), member_address(&SpatialCombat::m_attack), type<vector<CombatFleet>>(), "attack", var(vector<CombatFleet>()), Member::Value, nullptr },
                { type<SpatialCombat>(), member_address(&SpatialCombat::m_defense), type<vector<CombatFleet>>(), "defense", var(vector<CombatFleet>()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<SpatialCombat>();
    }
    // Universe
    {
        static Meta meta = { type<Universe>(), &namspc({}), "Universe", sizeof(Universe), TypeClass::Object };
        static Class cls = { type<Universe>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<Universe, mud::Complex>() },
            // constructors
            {
                { type<Universe>(), [](Ref ref, array<Var> args) { new(&val<Universe>(ref)) Universe( val<string>(args[0]), val<mud::JobSystem>(args[1]) ); }, { { "name", var(string()) }, { "job_system", Ref(type<mud::JobSystem>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Universe>(), member_address(&Universe::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::NonMutable, nullptr },
                { type<Universe>(), member_address(&Universe::m_bullet_world), type<toy::BulletWorld>(), "bullet_world", Ref(type<toy::BulletWorld>()), Member::Flags(Member::NonMutable|Member::Component), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<Universe>();
        meta_class<Universe>();
    }
        m.m_types.push_back(&type<Combat>());
        m.m_types.push_back(&type<CombatFleet>());
        m.m_types.push_back(&type<CombatStar>());
        m.m_types.push_back(&type<CombatType>());
        m.m_types.push_back(&type<Commander>());
        m.m_types.push_back(&type<Construction>());
        m.m_types.push_back(&type<Experience>());
        m.m_types.push_back(&type<Fleet>());
        m.m_types.push_back(&type<FleetSize>());
        m.m_types.push_back(&type<FleetStance>());
        m.m_types.push_back(&type<Galaxy>());
        m.m_types.push_back(&type<GameStage>());
        m.m_types.push_back(&type<Jump>());
        m.m_types.push_back(&type<Player>());
        m.m_types.push_back(&type<Politic>());
        m.m_types.push_back(&type<Race>());
        m.m_types.push_back(&type<Regime>());
        m.m_types.push_back(&type<Resource>());
        m.m_types.push_back(&type<Scans>());
        m.m_types.push_back(&type<Schema>());
        m.m_types.push_back(&type<SpatialPower>());
        m.m_types.push_back(&type<Split>());
        m.m_types.push_back(&type<Star>());
        m.m_types.push_back(&type<Taxation>());
        m.m_types.push_back(&type<TechDomain>());
        m.m_types.push_back(&type<Technology>());
        m.m_types.push_back(&type<Turn>());
        m.m_types.push_back(&type<WeaponType>());
        m.m_types.push_back(&type<vector<CombatFleet>>());
        m.m_types.push_back(&type<vector<Commander*>>());
        m.m_types.push_back(&type<BuildingSchema>());
        m.m_types.push_back(&type<CommanderBrush>());
        m.m_types.push_back(&type<mud::ComponentHandle<Fleet>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Galaxy>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Star>>());
        m.m_types.push_back(&type<PlanetaryCombat>());
        m.m_types.push_back(&type<ShipComponent>());
        m.m_types.push_back(&type<ShipEngine>());
        m.m_types.push_back(&type<ShipHull>());
        m.m_types.push_back(&type<ShipSchema>());
        m.m_types.push_back(&type<SpatialCombat>());
        m.m_types.push_back(&type<Universe>());
        {
            auto func = [](array<Var> args, Var& result) {  val<HStar>(result) = generate_system(val<Galaxy>(args[0]), val<mud::uvec3>(args[1]), val<mud::vec3>(args[2])); };
            vector<Param> params = { { "galaxy", Ref(type<Galaxy>()) }, { "coord", var(mud::uvec3()) }, { "position", var(mud::vec3()) } };
            static Function f = { &namspc({}), "generate_system", funcptr<HStar(*)(Galaxy&, const mud::uvec3&, const mud::vec3&)>(&generate_system), func, params, var(HStar()) };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) {  val<HFleet>(result) = generate_fleet(val<Galaxy>(args[0]), val<mud::uvec3>(args[1]), val<mud::vec3>(args[2])); };
            vector<Param> params = { { "galaxy", Ref(type<Galaxy>()) }, { "coord", var(mud::uvec3()) }, { "position", var(mud::vec3()) } };
            static Function f = { &namspc({}), "generate_fleet", funcptr<HFleet(*)(Galaxy&, const mud::uvec3&, const mud::vec3&)>(&generate_fleet), func, params, var(HFleet()) };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) {  result = Ref(generate_commander(val<Galaxy>(args[0]), val<Star>(args[1]))); };
            vector<Param> params = { { "galaxy", Ref(type<Galaxy>()) }, { "star", Ref(type<Star>()) } };
            static Function f = { &namspc({}), "generate_commander", funcptr<Commander*(*)(Galaxy&, Star&)>(&generate_commander), func, params, Ref(type<Commander>()) };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  assign_system(val<Galaxy>(args[0]), val<Star>(args[1]), val<vector<Commander*>>(args[2])); };
            vector<Param> params = { { "galaxy", Ref(type<Galaxy>()) }, { "star", Ref(type<Star>()) }, { "commanders", var(vector<Commander*>()) } };
            static Function f = { &namspc({}), "assign_system", funcptr<void(*)(Galaxy&, Star&, vector<Commander*>)>(&assign_system), func, params, Var() };
            m.m_functions.push_back(&f);
        }
    }
}
