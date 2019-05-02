#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._space;
#else
#include <cstddef>
#include <stl/new.h>
#include <infra/ToString.h>
#include <infra/ToValue.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/infra.meta.h>
#include <meta/jobs.meta.h>
#include <meta/type.meta.h>
#include <meta/tree.meta.h>
#include <meta/pool.meta.h>
#include <meta/refl.meta.h>
#include <meta/ecs.meta.h>
#include <meta/srlz.meta.h>
#include <meta/math.meta.h>
#include <meta/geom.meta.h>
#include <meta/lang.meta.h>
#include <meta/ctx.meta.h>
#include <meta/ui.meta.h>
#include <meta/uio.meta.h>
#include <meta/bgfx.meta.h>
#include <meta/gfx.meta.h>
#include <meta/gfx.ui.meta.h>
#include <meta/frame.meta.h>
#include <meta/util.meta.h>
#include <meta/core.meta.h>
#include <meta/visu.meta.h>
#include <meta/edit.meta.h>
#include <meta/block.meta.h>
#include <meta/shell.meta.h>
#include <meta/_space.meta.h>
#include <meta/_space.conv.h>
#endif

#include <space/Api.h>

using namespace two;

void GameStage__to_string(void* val, string& str) { str = g_enu[type<GameStage>().m_id]->name(uint32_t((*static_cast<GameStage*>(val)))); }
void GameStage__to_value(const string& str, void* val) { (*static_cast<GameStage*>(val)) = GameStage(g_enu[type<GameStage>().m_id]->value(str.c_str())); }
void Race__to_string(void* val, string& str) { str = g_enu[type<Race>().m_id]->name(uint32_t((*static_cast<Race*>(val)))); }
void Race__to_value(const string& str, void* val) { (*static_cast<Race*>(val)) = Race(g_enu[type<Race>().m_id]->value(str.c_str())); }
void Regime__to_string(void* val, string& str) { str = g_enu[type<Regime>().m_id]->name(uint32_t((*static_cast<Regime*>(val)))); }
void Regime__to_value(const string& str, void* val) { (*static_cast<Regime*>(val)) = Regime(g_enu[type<Regime>().m_id]->value(str.c_str())); }
void Politic__to_string(void* val, string& str) { str = g_enu[type<Politic>().m_id]->name(uint32_t((*static_cast<Politic*>(val)))); }
void Politic__to_value(const string& str, void* val) { (*static_cast<Politic*>(val)) = Politic(g_enu[type<Politic>().m_id]->value(str.c_str())); }
void Taxation__to_string(void* val, string& str) { str = g_enu[type<Taxation>().m_id]->name(uint32_t((*static_cast<Taxation*>(val)))); }
void Taxation__to_value(const string& str, void* val) { (*static_cast<Taxation*>(val)) = Taxation(g_enu[type<Taxation>().m_id]->value(str.c_str())); }
void Resource__to_string(void* val, string& str) { str = g_enu[type<Resource>().m_id]->name(uint32_t((*static_cast<Resource*>(val)))); }
void Resource__to_value(const string& str, void* val) { (*static_cast<Resource*>(val)) = Resource(g_enu[type<Resource>().m_id]->value(str.c_str())); }
void FleetSize__to_string(void* val, string& str) { str = g_enu[type<FleetSize>().m_id]->name(uint32_t((*static_cast<FleetSize*>(val)))); }
void FleetSize__to_value(const string& str, void* val) { (*static_cast<FleetSize*>(val)) = FleetSize(g_enu[type<FleetSize>().m_id]->value(str.c_str())); }
void Experience__to_string(void* val, string& str) { str = g_enu[type<Experience>().m_id]->name(uint32_t((*static_cast<Experience*>(val)))); }
void Experience__to_value(const string& str, void* val) { (*static_cast<Experience*>(val)) = Experience(g_enu[type<Experience>().m_id]->value(str.c_str())); }
void FleetStance__to_string(void* val, string& str) { str = g_enu[type<FleetStance>().m_id]->name(uint32_t((*static_cast<FleetStance*>(val)))); }
void FleetStance__to_value(const string& str, void* val) { (*static_cast<FleetStance*>(val)) = FleetStance(g_enu[type<FleetStance>().m_id]->value(str.c_str())); }
void WeaponType__to_string(void* val, string& str) { str = g_enu[type<WeaponType>().m_id]->name(uint32_t((*static_cast<WeaponType*>(val)))); }
void WeaponType__to_value(const string& str, void* val) { (*static_cast<WeaponType*>(val)) = WeaponType(g_enu[type<WeaponType>().m_id]->value(str.c_str())); }
void Technology__to_string(void* val, string& str) { str = g_enu[type<Technology>().m_id]->name(uint32_t((*static_cast<Technology*>(val)))); }
void Technology__to_value(const string& str, void* val) { (*static_cast<Technology*>(val)) = Technology(g_enu[type<Technology>().m_id]->value(str.c_str())); }
void CombatType__to_string(void* val, string& str) { str = g_enu[type<CombatType>().m_id]->name(uint32_t((*static_cast<CombatType*>(val)))); }
void CombatType__to_value(const string& str, void* val) { (*static_cast<CombatType*>(val)) = CombatType(g_enu[type<CombatType>().m_id]->value(str.c_str())); }
size_t stl_vector_HStar__size(void* vec) { return (*static_cast<stl::vector<HStar>*>(vec)).size(); }
void* stl_vector_HStar__at(void* vec, size_t i) { return &(*static_cast<stl::vector<HStar>*>(vec))[i]; }
void stl_vector_HStar__push(void* vec) { (*static_cast<stl::vector<HStar>*>(vec)).emplace_back(); }
void stl_vector_HStar__add(void* vec, void* value) { (*static_cast<stl::vector<HStar>*>(vec)).push_back(*static_cast<HStar*>(value)); }
void stl_vector_HStar__remove(void* vec, void* value) { vector_remove_any((*static_cast<stl::vector<HStar>*>(vec)), *static_cast<HStar*>(value)); }
size_t stl_vector_HFleet__size(void* vec) { return (*static_cast<stl::vector<HFleet>*>(vec)).size(); }
void* stl_vector_HFleet__at(void* vec, size_t i) { return &(*static_cast<stl::vector<HFleet>*>(vec))[i]; }
void stl_vector_HFleet__push(void* vec) { (*static_cast<stl::vector<HFleet>*>(vec)).emplace_back(); }
void stl_vector_HFleet__add(void* vec, void* value) { (*static_cast<stl::vector<HFleet>*>(vec)).push_back(*static_cast<HFleet*>(value)); }
void stl_vector_HFleet__remove(void* vec, void* value) { vector_remove_any((*static_cast<stl::vector<HFleet>*>(vec)), *static_cast<HFleet*>(value)); }
size_t stl_vector_Commander___size(void* vec) { return (*static_cast<stl::vector<Commander*>*>(vec)).size(); }
void* stl_vector_Commander___at(void* vec, size_t i) { return &(*static_cast<stl::vector<Commander*>*>(vec))[i]; }
void stl_vector_Commander___push(void* vec) { (*static_cast<stl::vector<Commander*>*>(vec)).emplace_back(); }
void stl_vector_Commander___add(void* vec, void* value) { (*static_cast<stl::vector<Commander*>*>(vec)).push_back(static_cast<Commander*>(value)); }
void stl_vector_Commander___remove(void* vec, void* value) { vector_remove_any((*static_cast<stl::vector<Commander*>*>(vec)), static_cast<Commander*>(value)); }
size_t stl_vector_CombatFleet__size(void* vec) { return (*static_cast<stl::vector<CombatFleet>*>(vec)).size(); }
void* stl_vector_CombatFleet__at(void* vec, size_t i) { return &(*static_cast<stl::vector<CombatFleet>*>(vec))[i]; }
void stl_vector_CombatFleet__push(void* vec) { (*static_cast<stl::vector<CombatFleet>*>(vec)).emplace_back(); }
void stl_vector_CombatFleet__add(void* vec, void* value) { (*static_cast<stl::vector<CombatFleet>*>(vec)).push_back(*static_cast<CombatFleet*>(value)); }
void stl_vector_CombatFleet__remove(void* vec, void* value) { vector_remove_any((*static_cast<stl::vector<CombatFleet>*>(vec)), *static_cast<CombatFleet*>(value)); }
void two_ComponentHandle_Galaxy__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Galaxy>(  ); }
void two_ComponentHandle_Galaxy__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Galaxy>((*static_cast<two::ComponentHandle<Galaxy>*>(other))); }
void two_ComponentHandle_Star__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Star>(  ); }
void two_ComponentHandle_Star__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Star>((*static_cast<two::ComponentHandle<Star>*>(other))); }
void two_ComponentHandle_Fleet__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Fleet>(  ); }
void two_ComponentHandle_Fleet__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Fleet>((*static_cast<two::ComponentHandle<Fleet>*>(other))); }
void Turn__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Turn(  ); }
void Turn__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Turn((*static_cast<Turn*>(other))); }
void SpatialPower__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) SpatialPower(  ); }
void SpatialPower__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) SpatialPower((*static_cast<SpatialPower*>(other))); }
void Construction__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Construction(  ); }
void Construction__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Construction((*static_cast<Construction*>(other))); }
void Star__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Star(  ); }
void Star__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Star( *static_cast<toy::HSpatial*>(args[0]), *static_cast<Galaxy*>(args[1]), *static_cast<two::uvec2*>(args[2]), *static_cast<stl::string*>(args[3]) ); }
void Jump__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Jump(  ); }
void Jump__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Jump((*static_cast<Jump*>(other))); }
void Split__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Split(  ); }
void Split__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Split((*static_cast<Split*>(other))); }
void Fleet__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Fleet(  ); }
void Fleet__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Fleet( *static_cast<toy::HSpatial*>(args[0]), *static_cast<Galaxy*>(args[1]), *static_cast<Commander*>(args[2]), *static_cast<two::uvec2*>(args[3]), *static_cast<stl::string*>(args[4]) ); }
void Fleet_order_jump(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<Fleet*>(object)).order_jump(*static_cast<two::uvec2*>(args[0]), *static_cast<FleetStance*>(args[1])); }
void Fleet_order_attack(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<Fleet*>(object)).order_attack(*static_cast<Star*>(args[0])); }
void Schema__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Schema(  ); }
void Schema__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Schema((*static_cast<Schema*>(other))); }
void ShipHull__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) ShipHull(  ); }
void ShipHull__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) ShipHull((*static_cast<ShipHull*>(other))); }
void ShipEngine__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) ShipEngine(  ); }
void ShipEngine__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) ShipEngine((*static_cast<ShipEngine*>(other))); }
void ShipComponent__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) ShipComponent(  ); }
void ShipComponent__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) ShipComponent((*static_cast<ShipComponent*>(other))); }
void ShipSchema__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) ShipSchema(  ); }
void ShipSchema__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) ShipSchema((*static_cast<ShipSchema*>(other))); }
void BuildingSchema__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) BuildingSchema(  ); }
void BuildingSchema__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) BuildingSchema((*static_cast<BuildingSchema*>(other))); }
void Scans__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Scans(  ); }
void Scans__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Scans((*static_cast<Scans*>(other))); }
void TechDomain__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) TechDomain(  ); }
void TechDomain__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) TechDomain((*static_cast<TechDomain*>(other))); }
void Commander__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) Commander( *static_cast<uint32_t*>(args[0]), *static_cast<stl::string*>(args[1]), *static_cast<Race*>(args[2]), *static_cast<int*>(args[3]), *static_cast<int*>(args[4]), *static_cast<int*>(args[5]) ); }
void Combat__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Combat(  ); }
void Combat__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Combat((*static_cast<Combat*>(other))); }
void CombatFleet__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) CombatFleet(  ); }
void CombatFleet__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) CombatFleet((*static_cast<CombatFleet*>(other))); }
void CombatStar__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) CombatStar(  ); }
void CombatStar__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) CombatStar((*static_cast<CombatStar*>(other))); }
void PlanetaryCombat__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) PlanetaryCombat(  ); }
void PlanetaryCombat__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) PlanetaryCombat((*static_cast<PlanetaryCombat*>(other))); }
void SpatialCombat__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) SpatialCombat(  ); }
void SpatialCombat__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) SpatialCombat((*static_cast<SpatialCombat*>(other))); }
void Galaxy__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Galaxy(  ); }
void Galaxy__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Galaxy( *static_cast<toy::HSpatial*>(args[0]), *static_cast<two::uvec2*>(args[1]) ); }
void Universe__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) Universe( *static_cast<stl::string*>(args[0]), *static_cast<two::JobSystem*>(args[1]) ); }
void generate_system_0(span<void*> args, void*& result) { (*static_cast<two::ComponentHandle<Star>*>(result)) = generate_system(*static_cast<Galaxy*>(args[0]), *static_cast<two::uvec3*>(args[1]), *static_cast<two::vec3*>(args[2])); }
void generate_fleet_1(span<void*> args, void*& result) { (*static_cast<two::ComponentHandle<Fleet>*>(result)) = generate_fleet(*static_cast<Galaxy*>(args[0]), *static_cast<two::uvec3*>(args[1]), *static_cast<two::vec3*>(args[2])); }
void generate_commander_2(span<void*> args, void*& result) { result = generate_commander(*static_cast<Galaxy*>(args[0]), *static_cast<Star*>(args[1])); }
void assign_system_3(span<void*> args, void*& result) { UNUSED(result);  assign_system(*static_cast<Galaxy*>(args[0]), *static_cast<Star*>(args[1]), *static_cast<stl::vector<Commander*>*>(args[2])); }

namespace two
{
	void _space_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	{
		Type& t = type<GameStage>();
		static Meta meta = { t, &namspc({}), "GameStage", sizeof(GameStage), TypeClass::Enum };
		static cstring ids[] = { "Empire", "Tactics", "TurnReport" };
		static uint32_t values[] = { 0, 1, 2 };
		static GameStage vars[] = { GameStage::Empire, GameStage::Tactics, GameStage::TurnReport};
		static void* refs[] = { &vars[0], &vars[1], &vars[2]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { GameStage__to_string,
		                           GameStage__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<Race>();
		static Meta meta = { t, &namspc({}), "Race", sizeof(Race), TypeClass::Enum };
		static cstring ids[] = { "Human", "Bulvoid", "Techtulon", "Rakrarior", "Seigneur", "Meton", "Tissinar", "Zwiie", "Count" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		static Race vars[] = { Race::Human, Race::Bulvoid, Race::Techtulon, Race::Rakrarior, Race::Seigneur, Race::Meton, Race::Tissinar, Race::Zwiie, Race::Count};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5], &vars[6], &vars[7], &vars[8]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Race__to_string,
		                           Race__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<Regime>();
		static Meta meta = { t, &namspc({}), "Regime", sizeof(Regime), TypeClass::Enum };
		static cstring ids[] = { "Empire", "Dictature", "Democracy", "Theocracy", "Technocracy", "Piratery" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5 };
		static Regime vars[] = { Regime::Empire, Regime::Dictature, Regime::Democracy, Regime::Theocracy, Regime::Technocracy, Regime::Piratery};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Regime__to_string,
		                           Regime__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<Politic>();
		static Meta meta = { t, &namspc({}), "Politic", sizeof(Politic), TypeClass::Enum };
		static cstring ids[] = { "Taxes", "Commerce", "Construction", "Defense", "Pacification" };
		static uint32_t values[] = { 0, 1, 2, 3, 4 };
		static Politic vars[] = { Politic::Taxes, Politic::Commerce, Politic::Construction, Politic::Defense, Politic::Pacification};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Politic__to_string,
		                           Politic__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<Taxation>();
		static Meta meta = { t, &namspc({}), "Taxation", sizeof(Taxation), TypeClass::Enum };
		static cstring ids[] = { "None", "Light", "Medium", "Heavy", "Heaviest", "Total" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5 };
		static Taxation vars[] = { Taxation::None, Taxation::Light, Taxation::Medium, Taxation::Heavy, Taxation::Heaviest, Taxation::Total};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Taxation__to_string,
		                           Taxation__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<Resource>();
		static Meta meta = { t, &namspc({}), "Resource", sizeof(Resource), TypeClass::Enum };
		static cstring ids[] = { "None", "Minerals", "Andrium", "Alcool", "Slaves", "Narcotics", "Food", "Medicine", "Computers", "Plastic", "Robot", "Count" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		static Resource vars[] = { Resource::None, Resource::Minerals, Resource::Andrium, Resource::Alcool, Resource::Slaves, Resource::Narcotics, Resource::Food, Resource::Medicine, Resource::Computers, Resource::Plastic, Resource::Robot, Resource::Count};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5], &vars[6], &vars[7], &vars[8], &vars[9], &vars[10], &vars[11]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Resource__to_string,
		                           Resource__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<FleetSize>();
		static Meta meta = { t, &namspc({}), "FleetSize", sizeof(FleetSize), TypeClass::Enum };
		static cstring ids[] = { "Ridicule", "Minuscule", "Tiny", "Small", "Medium", "Respectable", "Grand", "HighGrand", "Colossal", "Titanesque", "Cyclopean", "Divine", "Count" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		static FleetSize vars[] = { FleetSize::Ridicule, FleetSize::Minuscule, FleetSize::Tiny, FleetSize::Small, FleetSize::Medium, FleetSize::Respectable, FleetSize::Grand, FleetSize::HighGrand, FleetSize::Colossal, FleetSize::Titanesque, FleetSize::Cyclopean, FleetSize::Divine, FleetSize::Count};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5], &vars[6], &vars[7], &vars[8], &vars[9], &vars[10], &vars[11], &vars[12]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { FleetSize__to_string,
		                           FleetSize__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<Experience>();
		static Meta meta = { t, &namspc({}), "Experience", sizeof(Experience), TypeClass::Enum };
		static cstring ids[] = { "Inexperienced", "LittleExperienced", "Experienced", "Superior", "Elite" };
		static uint32_t values[] = { 0, 1, 2, 3, 4 };
		static Experience vars[] = { Experience::Inexperienced, Experience::LittleExperienced, Experience::Experienced, Experience::Superior, Experience::Elite};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Experience__to_string,
		                           Experience__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<FleetStance>();
		static Meta meta = { t, &namspc({}), "FleetStance", sizeof(FleetStance), TypeClass::Enum };
		static cstring ids[] = { "Movement", "SpatialAttack", "SpatialDefense", "PlanetaryAttack", "PlanetaryDefense", "Pillage" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5 };
		static FleetStance vars[] = { FleetStance::Movement, FleetStance::SpatialAttack, FleetStance::SpatialDefense, FleetStance::PlanetaryAttack, FleetStance::PlanetaryDefense, FleetStance::Pillage};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { FleetStance__to_string,
		                           FleetStance__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<WeaponType>();
		static Meta meta = { t, &namspc({}), "WeaponType", sizeof(WeaponType), TypeClass::Enum };
		static cstring ids[] = { "None", "Ion", "Laser", "Plasma", "Torpedo", "Bomb", "Count" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5, 6 };
		static WeaponType vars[] = { WeaponType::None, WeaponType::Ion, WeaponType::Laser, WeaponType::Plasma, WeaponType::Torpedo, WeaponType::Bomb, WeaponType::Count};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5], &vars[6]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { WeaponType__to_string,
		                           WeaponType__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<Technology>();
		static Meta meta = { t, &namspc({}), "Technology", sizeof(Technology), TypeClass::Enum };
		static cstring ids[] = { "Engines", "EcoEnergy", "Scanners", "PlanetaryShields", "SpatialShields", "LaserPlasmaIons", "Torpedoes", "Bombs", "HullArmor", "Mining", "Terraforming", "Construction", "Piloting", "Commerce", "Personnel", "Administration", "CyberCommand", "CyberCommerce", "CyberDiplomacy", "Count" };
		static uint32_t values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
		static Technology vars[] = { Technology::Engines, Technology::EcoEnergy, Technology::Scanners, Technology::PlanetaryShields, Technology::SpatialShields, Technology::LaserPlasmaIons, Technology::Torpedoes, Technology::Bombs, Technology::HullArmor, Technology::Mining, Technology::Terraforming, Technology::Construction, Technology::Piloting, Technology::Commerce, Technology::Personnel, Technology::Administration, Technology::CyberCommand, Technology::CyberCommerce, Technology::CyberDiplomacy, Technology::Count};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5], &vars[6], &vars[7], &vars[8], &vars[9], &vars[10], &vars[11], &vars[12], &vars[13], &vars[14], &vars[15], &vars[16], &vars[17], &vars[18], &vars[19]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Technology__to_string,
		                           Technology__to_value };
		g_convert[t.m_id] = &convert;
	}
	{
		Type& t = type<CombatType>();
		static Meta meta = { t, &namspc({}), "CombatType", sizeof(CombatType), TypeClass::Enum };
		static cstring ids[] = { "Spatial", "Planetary" };
		static uint32_t values[] = { 0, 1 };
		static CombatType vars[] = { CombatType::Spatial, CombatType::Planetary};
		static void* refs[] = { &vars[0], &vars[1]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { CombatType__to_string,
		                           CombatType__to_value };
		g_convert[t.m_id] = &convert;
	}
	
	// Sequences
	{
		Type& t = type<stl::vector<HStar>>();
		static Meta meta = { t, &namspc({}), "stl::vector<HStar>", sizeof(stl::vector<HStar>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<HStar>(),
		                             stl_vector_HStar__size,
		                             stl_vector_HStar__at};
		g_iterable[t.m_id] = &iterable;
		static Sequence sequence = { stl_vector_HStar__push,
		                             stl_vector_HStar__add,
		                             stl_vector_HStar__remove };
		g_sequence[t.m_id] = &sequence;
	}
	{
		Type& t = type<stl::vector<HFleet>>();
		static Meta meta = { t, &namspc({}), "stl::vector<HFleet>", sizeof(stl::vector<HFleet>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<HFleet>(),
		                             stl_vector_HFleet__size,
		                             stl_vector_HFleet__at};
		g_iterable[t.m_id] = &iterable;
		static Sequence sequence = { stl_vector_HFleet__push,
		                             stl_vector_HFleet__add,
		                             stl_vector_HFleet__remove };
		g_sequence[t.m_id] = &sequence;
	}
	{
		Type& t = type<stl::vector<Commander*>>();
		static Meta meta = { t, &namspc({}), "stl::vector<Commander*>", sizeof(stl::vector<Commander*>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<Commander>(),
		                             stl_vector_Commander___size,
		                             stl_vector_Commander___at};
		g_iterable[t.m_id] = &iterable;
		static Sequence sequence = { stl_vector_Commander___push,
		                             stl_vector_Commander___add,
		                             stl_vector_Commander___remove };
		g_sequence[t.m_id] = &sequence;
	}
	{
		Type& t = type<stl::vector<CombatFleet>>();
		static Meta meta = { t, &namspc({}), "stl::vector<CombatFleet>", sizeof(stl::vector<CombatFleet>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<CombatFleet>(),
		                             stl_vector_CombatFleet__size,
		                             stl_vector_CombatFleet__at};
		g_iterable[t.m_id] = &iterable;
		static Sequence sequence = { stl_vector_CombatFleet__push,
		                             stl_vector_CombatFleet__add,
		                             stl_vector_CombatFleet__remove };
		g_sequence[t.m_id] = &sequence;
	}
	
	// two::ComponentHandle<Galaxy>
	{
		Type& t = type<two::ComponentHandle<Galaxy>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<Galaxy>", sizeof(two::ComponentHandle<Galaxy>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_Galaxy__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_Galaxy__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<Star>
	{
		Type& t = type<two::ComponentHandle<Star>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<Star>", sizeof(two::ComponentHandle<Star>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_Star__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_Star__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<Fleet>
	{
		Type& t = type<two::ComponentHandle<Fleet>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<Fleet>", sizeof(two::ComponentHandle<Fleet>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_Fleet__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_Fleet__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// Turn
	{
		Type& t = type<Turn>();
		static Meta meta = { t, &namspc({}), "Turn", sizeof(Turn), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Turn__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Turn__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// Player
	{
		Type& t = type<Player>();
		static Meta meta = { t, &namspc({}), "Player", sizeof(Player), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// SpatialPower
	{
		Type& t = type<SpatialPower>();
		static Meta meta = { t, &namspc({}), "SpatialPower", sizeof(SpatialPower), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, SpatialPower__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, SpatialPower__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// Construction
	{
		Type& t = type<Construction>();
		static Meta meta = { t, &namspc({}), "Construction", sizeof(Construction), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Construction__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Construction__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// Star
	{
		Type& t = type<Star>();
		static Meta meta = { t, &namspc({}), "Star", sizeof(Star), TypeClass::Object };
		// bases
		// defaults
		static int stability_default = 100;
		static bool revolt_default = false;
		static int env_default = 10;
		static int terraformation_default = 0;
		static int base_population_default = 0;
		static int max_population_default = 0;
		static int population_default = 0;
		static float militia_default = 0.1f;
		static float defense_default = 0.f;
		static float revenue_default = 0.f;
		static Politic politic_default = Politic::Taxes;
		static Taxation taxation_default = Taxation::Medium;
		static Commander* commander_default = nullptr;
		static int scan_default = 0;
		// constructors
		static Constructor constructors[] = {
			{ t, Star__construct_0, {} },
			{ t, Star__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "galaxy", type<Galaxy>(),  }, { "coord", type<two::uvec2>(),  }, { "name", type<stl::string>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Star, m_galaxy), type<Galaxy>(), "galaxy", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Star, m_coord), type<two::uvec2>(), "coord", nullptr, Member::Value, nullptr },
			{ t, offsetof(Star, m_name), type<stl::string>(), "name", nullptr, Member::Value, nullptr },
			{ t, offsetof(Star, m_stability), type<int>(), "stability", &stability_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_revolt), type<bool>(), "revolt", &revolt_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_env), type<int>(), "env", &env_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_terraformation), type<int>(), "terraformation", &terraformation_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_base_population), type<int>(), "base_population", &base_population_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_max_population), type<int>(), "max_population", &max_population_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_population), type<int>(), "population", &population_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_militia), type<float>(), "militia", &militia_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_defense), type<float>(), "defense", &defense_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_revenue), type<float>(), "revenue", &revenue_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_politic), type<Politic>(), "politic", &politic_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_taxation), type<Taxation>(), "taxation", &taxation_default, Member::Value, nullptr },
			{ t, offsetof(Star, m_commander), type<Commander>(), "commander", commander_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Star, m_scan), type<int>(), "scan", &scan_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// Jump
	{
		Type& t = type<Jump>();
		static Meta meta = { t, &namspc({}), "Jump", sizeof(Jump), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Jump__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Jump__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(Jump, m_fleet), type<Fleet>(), "fleet", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Jump, m_start), type<two::uvec2>(), "start", nullptr, Member::Value, nullptr },
			{ t, offsetof(Jump, m_dest), type<two::uvec2>(), "dest", nullptr, Member::Value, nullptr },
			{ t, offsetof(Jump, m_stance), type<FleetStance>(), "stance", nullptr, Member::Value, nullptr },
			{ t, offsetof(Jump, m_track), type<Fleet>(), "track", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
	}
	// Split
	{
		Type& t = type<Split>();
		static Meta meta = { t, &namspc({}), "Split", sizeof(Split), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Split__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Split__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(Split, m_source), type<Fleet>(), "source", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Split, m_dest), type<Fleet>(), "dest", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Split, m_code), type<stl::string>(), "code", nullptr, Member::Value, nullptr },
			{ t, offsetof(Split, m_stance), type<FleetStance>(), "stance", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
	}
	// Fleet
	{
		Type& t = type<Fleet>();
		static Meta meta = { t, &namspc({}), "Fleet", sizeof(Fleet), TypeClass::Object };
		// bases
		// defaults
		static Galaxy* galaxy_default = nullptr;
		static Commander* commander_default = nullptr;
		static float experience_default = 0.f;
		static SpatialPower spatial_power_default = {};
		static float planetary_power_default = 0.f;
		static uint8_t speed_default = 0;
		static uint8_t scan_default = 0;
		static float upkeep_default = 0.f;
		static FleetStance stance_default = FleetStance::Movement;
		static bool fought_default = false;
		static size_t ships_updated_default = 0;
		// constructors
		static Constructor constructors[] = {
			{ t, Fleet__construct_0, {} },
			{ t, Fleet__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "galaxy", type<Galaxy>(),  }, { "commander", type<Commander>(),  }, { "coord", type<two::uvec2>(),  }, { "name", type<stl::string>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Fleet, m_galaxy), type<Galaxy>(), "galaxy", galaxy_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Fleet, m_commander), type<Commander>(), "commander", commander_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Fleet, m_coord), type<two::uvec2>(), "coord", nullptr, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_slot), type<two::vec3>(), "slot", nullptr, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_name), type<stl::string>(), "name", nullptr, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_experience), type<float>(), "experience", &experience_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_spatial_power), type<SpatialPower>(), "spatial_power", &spatial_power_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_planetary_power), type<float>(), "planetary_power", &planetary_power_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_speed), type<uint8_t>(), "speed", &speed_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_scan), type<uint8_t>(), "scan", &scan_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_upkeep), type<float>(), "upkeep", &upkeep_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_stance), type<FleetStance>(), "stance", &stance_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_jump), type<Jump>(), "jump", nullptr, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_split), type<Split>(), "split", nullptr, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_fought), type<bool>(), "fought", &fought_default, Member::Value, nullptr },
			{ t, offsetof(Fleet, m_ships_updated), type<size_t>(), "ships_updated", &ships_updated_default, Member::Value, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "order_jump", Address(), Fleet_order_jump, { { "coord", type<two::uvec2>(),  }, { "stance", type<FleetStance>(),  } }, g_qvoid },
			{ t, "order_attack", Address(), Fleet_order_attack, { { "star", type<Star>(),  } }, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, methods, {}, };
	}
	// Schema
	{
		Type& t = type<Schema>();
		static Meta meta = { t, &namspc({}), "Schema", sizeof(Schema), TypeClass::Struct };
		// bases
		// defaults
		static uint8_t level_default = 1;
		static float cost_default = 0.f;
		static float minerals_default = 0.f;
		static float andrium_default = 0.f;
		static float resistance_default = 0.f;
		static uint8_t speed_default = 0;
		static uint8_t scan_default = 0;
		static float planetary_default = 0.f;
		static SpatialPower spatial_default = {};
		static float upkeep_factor_default = 1.f;
		// constructors
		static Constructor constructors[] = {
			{ t, Schema__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Schema__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(Schema, m_code), type<stl::string>(), "code", nullptr, Member::Value, nullptr },
			{ t, offsetof(Schema, m_name), type<stl::string>(), "name", nullptr, Member::Value, nullptr },
			{ t, offsetof(Schema, m_conceptor), type<stl::string>(), "conceptor", nullptr, Member::Value, nullptr },
			{ t, offsetof(Schema, m_level), type<uint8_t>(), "level", &level_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_cost), type<float>(), "cost", &cost_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_minerals), type<float>(), "minerals", &minerals_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_andrium), type<float>(), "andrium", &andrium_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_resistance), type<float>(), "resistance", &resistance_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_speed), type<uint8_t>(), "speed", &speed_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_scan), type<uint8_t>(), "scan", &scan_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_planetary), type<float>(), "planetary", &planetary_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_spatial), type<SpatialPower>(), "spatial", &spatial_default, Member::Value, nullptr },
			{ t, offsetof(Schema, m_upkeep_factor), type<float>(), "upkeep_factor", &upkeep_factor_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
	}
	// ShipHull
	{
		Type& t = type<ShipHull>();
		static Meta meta = { t, &namspc({}), "ShipHull", sizeof(ShipHull), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<Schema>() };
		static size_t bases_offsets[] = { base_offset<ShipHull, Schema>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, ShipHull__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, ShipHull__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// ShipEngine
	{
		Type& t = type<ShipEngine>();
		static Meta meta = { t, &namspc({}), "ShipEngine", sizeof(ShipEngine), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<Schema>() };
		static size_t bases_offsets[] = { base_offset<ShipEngine, Schema>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, ShipEngine__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, ShipEngine__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// ShipComponent
	{
		Type& t = type<ShipComponent>();
		static Meta meta = { t, &namspc({}), "ShipComponent", sizeof(ShipComponent), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<Schema>() };
		static size_t bases_offsets[] = { base_offset<ShipComponent, Schema>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, ShipComponent__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, ShipComponent__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// ShipSchema
	{
		Type& t = type<ShipSchema>();
		static Meta meta = { t, &namspc({}), "ShipSchema", sizeof(ShipSchema), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<Schema>() };
		static size_t bases_offsets[] = { base_offset<ShipSchema, Schema>() };
		// defaults
		static WeaponType main_weapon_default = WeaponType::None;
		// constructors
		static Constructor constructors[] = {
			{ t, ShipSchema__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, ShipSchema__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(ShipSchema, m_size), type<uint8_t>(), "size", nullptr, Member::Value, nullptr },
			{ t, offsetof(ShipSchema, m_class), type<uint8_t>(), "class", nullptr, Member::Value, nullptr },
			{ t, offsetof(ShipSchema, m_main_weapon), type<WeaponType>(), "main_weapon", &main_weapon_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, members, {}, {}, };
	}
	// BuildingSchema
	{
		Type& t = type<BuildingSchema>();
		static Meta meta = { t, &namspc({}), "BuildingSchema", sizeof(BuildingSchema), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<Schema>() };
		static size_t bases_offsets[] = { base_offset<BuildingSchema, Schema>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, BuildingSchema__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, BuildingSchema__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// Scans
	{
		Type& t = type<Scans>();
		static Meta meta = { t, &namspc({}), "Scans", sizeof(Scans), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Scans__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Scans__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// TechDomain
	{
		Type& t = type<TechDomain>();
		static Meta meta = { t, &namspc({}), "TechDomain", sizeof(TechDomain), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, TechDomain__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, TechDomain__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// Commander
	{
		Type& t = type<Commander>();
		static Meta meta = { t, &namspc({}), "Commander", sizeof(Commander), TypeClass::Object };
		// bases
		// defaults
		static Star* capital_default = nullptr;
		static Regime regime_default = Regime::Empire;
		static float power_default = 0.f;
		static float centaures_default = 0.f;
		// constructors
		static Constructor constructors[] = {
			{ t, Commander__construct_0, { { "id", type<uint32_t>(),  }, { "name", type<stl::string>(),  }, { "race", type<Race>(),  }, { "command", type<int>(),  }, { "commerce", type<int>(),  }, { "diplomacy", type<int>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Commander, m_id), type<uint32_t>(), "id", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_name), type<stl::string>(), "name", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_race), type<Race>(), "race", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_command), type<int>(), "command", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_commerce), type<int>(), "commerce", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_diplomacy), type<int>(), "diplomacy", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_reputation), type<int>(), "reputation", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_victory), type<int>(), "victory", nullptr, Member::Value, nullptr },
			{ t, offsetof(Commander, m_stars), type<stl::vector<HStar>>(), "stars", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(Commander, m_fleets), type<stl::vector<HFleet>>(), "fleets", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(Commander, m_capital), type<Star>(), "capital", capital_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Commander, m_regime), type<Regime>(), "regime", &regime_default, Member::Value, nullptr },
			{ t, offsetof(Commander, m_power), type<float>(), "power", &power_default, Member::Value, nullptr },
			{ t, offsetof(Commander, m_centaures), type<float>(), "centaures", &centaures_default, Member::Value, nullptr },
			{ t, offsetof(Commander, m_scans), type<Scans>(), "scans", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// Combat
	{
		Type& t = type<Combat>();
		static Meta meta = { t, &namspc({}), "Combat", sizeof(Combat), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Combat__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Combat__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// CombatFleet
	{
		Type& t = type<CombatFleet>();
		static Meta meta = { t, &namspc({}), "CombatFleet", sizeof(CombatFleet), TypeClass::Struct };
		// bases
		// defaults
		static float damage_default = 0.f;
		// constructors
		static Constructor constructors[] = {
			{ t, CombatFleet__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, CombatFleet__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(CombatFleet, m_fleet), type<Fleet>(), "fleet", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(CombatFleet, m_damage), type<float>(), "damage", &damage_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
	}
	// CombatStar
	{
		Type& t = type<CombatStar>();
		static Meta meta = { t, &namspc({}), "CombatStar", sizeof(CombatStar), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, CombatStar__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, CombatStar__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// PlanetaryCombat
	{
		Type& t = type<PlanetaryCombat>();
		static Meta meta = { t, &namspc({}), "PlanetaryCombat", sizeof(PlanetaryCombat), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<Combat>() };
		static size_t bases_offsets[] = { base_offset<PlanetaryCombat, Combat>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, PlanetaryCombat__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, PlanetaryCombat__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(PlanetaryCombat, m_coord), type<two::uvec2>(), "coord", nullptr, Member::Value, nullptr },
			{ t, offsetof(PlanetaryCombat, m_attack), type<stl::vector<CombatFleet>>(), "attack", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(PlanetaryCombat, m_defense), type<CombatStar>(), "defense", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, members, {}, {}, };
	}
	// SpatialCombat
	{
		Type& t = type<SpatialCombat>();
		static Meta meta = { t, &namspc({}), "SpatialCombat", sizeof(SpatialCombat), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<Combat>() };
		static size_t bases_offsets[] = { base_offset<SpatialCombat, Combat>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, SpatialCombat__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, SpatialCombat__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(SpatialCombat, m_coord), type<two::uvec2>(), "coord", nullptr, Member::Value, nullptr },
			{ t, offsetof(SpatialCombat, m_attack), type<stl::vector<CombatFleet>>(), "attack", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(SpatialCombat, m_defense), type<stl::vector<CombatFleet>>(), "defense", nullptr, Member::NonMutable, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, members, {}, {}, };
	}
	// Galaxy
	{
		Type& t = type<Galaxy>();
		static Meta meta = { t, &namspc({}), "Galaxy", sizeof(Galaxy), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Galaxy__construct_0, {} },
			{ t, Galaxy__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "size", type<two::uvec2>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Galaxy, m_stars), type<stl::vector<HStar>>(), "stars", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(Galaxy, m_fleets), type<stl::vector<HFleet>>(), "fleets", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(Galaxy, m_commanders), type<stl::vector<Commander*>>(), "commanders", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(Galaxy, m_size), type<two::uvec2>(), "size", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// Universe
	{
		Type& t = type<Universe>();
		static Meta meta = { t, &namspc({}), "Universe", sizeof(Universe), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Complex>() };
		static size_t bases_offsets[] = { base_offset<Universe, two::Complex>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Universe__construct_0, { { "name", type<stl::string>(),  }, { "job_system", type<two::JobSystem>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Universe, m_world), type<toy::World>(), "world", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(Universe, m_bullet_world), type<toy::BulletWorld>(), "bullet_world", nullptr, Member::Flags(Member::NonMutable|Member::Component), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, members, {}, {}, };
	}
	// CommanderBrush
	{
		Type& t = type<CommanderBrush>();
		static Meta meta = { t, &namspc({}), "CommanderBrush", sizeof(CommanderBrush), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Brush>() };
		static size_t bases_offsets[] = { base_offset<CommanderBrush, two::Brush>() };
		// defaults
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(CommanderBrush, m_commander), type<Commander>(), "commander", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(CommanderBrush, m_radius), type<float>(), "radius", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, members, {}, {}, };
	}
	
	{
		Type& t = type<two::ComponentHandle<Galaxy>>();
		static Alias alias = { &t, &namspc({}), "HGalaxy" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<Star>>();
		static Alias alias = { &t, &namspc({}), "HStar" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<Fleet>>();
		static Alias alias = { &t, &namspc({}), "HFleet" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<two::ComponentHandle<Galaxy>>());
		m.m_types.push_back(&type<two::ComponentHandle<Star>>());
		m.m_types.push_back(&type<two::ComponentHandle<Fleet>>());
		m.m_types.push_back(&type<HGalaxy>());
		m.m_types.push_back(&type<HStar>());
		m.m_types.push_back(&type<HFleet>());
		m.m_types.push_back(&type<stl::vector<HStar>>());
		m.m_types.push_back(&type<stl::vector<HFleet>>());
		m.m_types.push_back(&type<stl::vector<Commander*>>());
		m.m_types.push_back(&type<stl::vector<CombatFleet>>());
		m.m_types.push_back(&type<GameStage>());
		m.m_types.push_back(&type<Race>());
		m.m_types.push_back(&type<Regime>());
		m.m_types.push_back(&type<Politic>());
		m.m_types.push_back(&type<Taxation>());
		m.m_types.push_back(&type<Resource>());
		m.m_types.push_back(&type<FleetSize>());
		m.m_types.push_back(&type<Experience>());
		m.m_types.push_back(&type<FleetStance>());
		m.m_types.push_back(&type<WeaponType>());
		m.m_types.push_back(&type<Technology>());
		m.m_types.push_back(&type<CombatType>());
		m.m_types.push_back(&type<Turn>());
		m.m_types.push_back(&type<Player>());
		m.m_types.push_back(&type<SpatialPower>());
		m.m_types.push_back(&type<Construction>());
		m.m_types.push_back(&type<Star>());
		m.m_types.push_back(&type<Jump>());
		m.m_types.push_back(&type<Split>());
		m.m_types.push_back(&type<Fleet>());
		m.m_types.push_back(&type<Schema>());
		m.m_types.push_back(&type<ShipHull>());
		m.m_types.push_back(&type<ShipEngine>());
		m.m_types.push_back(&type<ShipComponent>());
		m.m_types.push_back(&type<ShipSchema>());
		m.m_types.push_back(&type<BuildingSchema>());
		m.m_types.push_back(&type<Scans>());
		m.m_types.push_back(&type<TechDomain>());
		m.m_types.push_back(&type<Commander>());
		m.m_types.push_back(&type<Combat>());
		m.m_types.push_back(&type<CombatFleet>());
		m.m_types.push_back(&type<CombatStar>());
		m.m_types.push_back(&type<PlanetaryCombat>());
		m.m_types.push_back(&type<SpatialCombat>());
		m.m_types.push_back(&type<Galaxy>());
		m.m_types.push_back(&type<Universe>());
		m.m_types.push_back(&type<CommanderBrush>());
		{
			static Function f = { &namspc({}), "generate_system", funcptr<HStar(*)(Galaxy&, const two::uvec3&, const two::vec3&)>(generate_system), generate_system_0, { { "galaxy", type<Galaxy>(),  }, { "coord", type<two::uvec3>(),  }, { "position", type<two::vec3>(),  } }, { &type<HStar>(), QualType::None } };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({}), "generate_fleet", funcptr<HFleet(*)(Galaxy&, const two::uvec3&, const two::vec3&)>(generate_fleet), generate_fleet_1, { { "galaxy", type<Galaxy>(),  }, { "coord", type<two::uvec3>(),  }, { "position", type<two::vec3>(),  } }, { &type<HFleet>(), QualType::None } };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({}), "generate_commander", funcptr<Commander*(*)(Galaxy&, Star&)>(generate_commander), generate_commander_2, { { "galaxy", type<Galaxy>(),  }, { "star", type<Star>(),  } }, { &type<Commander>(), QualType::None } };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({}), "assign_system", funcptr<void(*)(Galaxy&, Star&, stl::vector<Commander*>)>(assign_system), assign_system_3, { { "galaxy", type<Galaxy>(),  }, { "star", type<Star>(),  }, { "commanders", type<stl::vector<Commander*>>(),  } }, g_qvoid };
			m.m_functions.push_back(&f);
		}
	}
}

_space::_space()
	: Module("_space", { &two_infra::m(), &two_jobs::m(), &two_type::m(), &two_tree::m(), &two_pool::m(), &two_refl::m(), &two_ecs::m(), &two_srlz::m(), &two_math::m(), &two_geom::m(), &two_lang::m(), &two_ctx::m(), &two_ui::m(), &two_uio::m(), &two_bgfx::m(), &two_gfx::m(), &two_gfx_ui::m(), &two_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{
	// setup reflection meta data
	_space_meta(*this);
}

#ifdef _SPACE_MODULE
extern "C"
Module& getModule()
{
	return _space::m();
}
#endif
