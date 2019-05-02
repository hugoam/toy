
#include <space/ex_space.h>
#include <toy/toy.h>

#include <meta/_space.conv.h>
#include <meta/_space.meta.h>
#include <space/Api.h>
#include <shell/Shell.h>

#include <space/Generator.h>
#include <space/Scene.h>
#include <space/Ui.h>

using namespace two;
using namespace toy;

void builtin_buildings(BuildingDatabase& database)
{
	auto add = [&](BuildingSchema schema) { database.m_schemas.push_back(schema); };
	//		code			name									conceptor		level	cost		minerals	resource or andri
	add({	"ARME",			"Usine d'armement",						"-",			1U,		50.00f,		10.f,		0.f		});
	add({	"CENTRECULT",	"Centre culturel",						"-",			1U,		50.00f,		10.f,		0.f		});
	add({	"CHANTIER",		"Chantier naval",						"Galactacorp",	1U,		50.00f,		10.f,		0.f		});
	add({	"CHORDI",		"Chaine d'assemblage d'ordinateurs",	"-",			1U,		50.00f,		10.f,		Resource::Computers });
	add({	"CHROBOT",		"Chaine d'assemblage de robots",		"-",			1U,		50.00f,		10.f,		Resource::Robot		});
	add({	"COLOMBIE",		"Ferme de Colombie",					"-",			1U,		100.00f,	80.f,		Resource::Narcotics	});
	add({	"COUTURE",		"Maison de haute couture",				"-",			1U,		50.00f,		10.f,		0.f		});
	add({	"DISTIL",		"Distillerie",							"-",			1U,		50.00f,		10.f,		Resource::Alcool	});
	add({	"DRESSAGE",		"Centre de dressage",					"-",			1U,		200.00f,	100.f,		Resource::Slaves	});
	add({	"ENRICH",		"Usine d'enrichissement des métaux",	"-",			1U,		50.00f,		10.f,		0.f		});
	add({	"FERME",		"Ferme",								"-",			1U,		50.00f,		10.f,		Resource::Food		});
	add({	"MEDIC",		"Laboratoire médical",					"-",			1U,		50.00f,		10.f,		Resource::Medicine	});
	add({	"MINE",			"Mine de minerai",						"-",			1U,		50.00f,		10.f,		Resource::Minerals	});
	add({	"POSTE",		"Poste commercial orbital",				"-",			1U,		50.00f,		10.f,		0.f		});
	add({	"RAFFIN",		"Raffinerie",							"-",			1U,		50.00f,		10.f,		0.f		});
	add({	"RETRAIT",		"Usine de retraitement du minerai",		"-",			1U,		50.00f,		10.f,		0.f		});
	add({	"SPHERE",		"Sphère de vie",						"-",			1U,		200.00f,	40.f,		0.f		});
	add({	"SYNTHANDRI",	"Usine de synthétisation d'Andrium",	"-",			1U,		50.00f,		10.f,		Resource::Andrium	});
	add({	"USINEPLAST",	"Usine de matériaux plastiques",		"-",			1U,		50.00f,		10.f,		Resource::Plastic	});
	add({	"FLEUR",		"Maison des fleurs",					"-",			2U,		300.00f,	30.f,		0.f		});
	add({	"BOUCITE",		"Boucliers de cités",					"-",			3U,		200.00f,	20.f,		0.f		});
	add({	"RECONV",		"Centre de reconversion",				"-",			3U,		300.00f,	50.f,		0.f		});
	add({	"ACADEMIE",		"Académie navale",						"-",			4U,		800.00f,	300.f,		0.f		});
}

void builtin_ships(ShipDatabase& database)
{
	auto add = [&](ShipSchema schema) { database.m_schemas.push_back(schema); };
	//	  size  code		name									conceptor		level	cost		minerals	andri	resistance	speed	scan	planetary	spatial														weapons
	add({ 1U,   "SONDE",	"Sonde standard",						"Galactacorp",	1U,		19.00f,		25.00f,		0.f,	1.00f,		9U,		15U,	0.00f,		{} });
	add({ 1U,	"BOM",		"Bombardier standard",					"Galactacorp",	1U,		19.00f,		25.00f,		0.f,	1.00f,		8U,		0U,		6.00f,		{} });
	add({ 1U,	"CAR",		"Cargo standard",						"Galactacorp",	1U,		43.00f,		41.00f,		0.f,	1.00f,		8U,		0U,		0.00f,		{} });
	add({ 1U,	"CHA",		"Chasseur standard",					"Galactacorp",	1U,		11.00f,		25.00f,		0.f,	1.00f,		8U,		0U,		1.00f,		{ 10.f, 8.f, 6.f, 4.f, 2.f, 0.f, 0.f, 0.f },				{ 0, 0, 2, 0, 0 } });
	add({ 1U,	"CHABOM",	"Chasseur-bombardier standard",			"Galactacorp",	1U,		15.00f,		25.00f,		0.f,	1.00f,		8U,		0U,		3.50f,		{ 5.f, 4.f, 3.f, 2.f, 1.f, 0.f, 0.f, 0.f },					{ 0, 0, 1, 0, 0 } });
	add({ 1U,	"COLO",		"Colonisateur",							"Galactacorp",	1U,		3.00f,		21.00f,		0.f,	1.00f,		8U,		0U,		6.00f,		{}  });
	add({ 2U,	"COR",		"Corvette standard",					"Galactacorp",	1U,		87.00f,		69.00f,		0.f,	4.00f,		7U,		0U,		4.00f,		{ 10.f, 8.f, 9.f, 13.f, 20.f, 24.f, 27.f, 30.f },			{ 0, 0, 2, 2, 2 } });
	add({ 2U,	"FREGIMP",	"Corvette standard",					"Galactacorp",	1U,		369.00f,	104.00f,	0.f,	10.00f,		7U,		4U,		16.00f,		{ 50.f, 46.f, 50.f, 62.f, 82.f, 52.f, 36.f, 26.f },			{ 0, 0, 10, 10, 0 } });
	add({ 2U,	"SBOM",		"Super-bombardier standard",			"Galactacorp",	1U,		53.00f,		63.00f,		0.f,	2.00f,		7U,		0U,		18.00f,		{} });
	add({ 2U,	"STA",		"Station spatiale Rakrarior",			"n/a",			1U,		1206.00f,	295.00f,	0.f,	22.00f,		7U,		4U,		110.50f,	{ 100.f, 103.f, 152.f, 247.f, 388.f, 322.f, 276.f, 253.f } });
	add({ 3U,	"CRO",		"Croiseur standard",					"Galactacorp",	2U,		408.00f,	194.00f,	0.f,	14.00f,		7U,		4U,		13.00f,		{ 10.f, 16.f, 32.f, 58.f, 94.f, 64.f, 42.f, 28.f } });
	add({ 3U,	"DES",		"Destroyer standard",					"Galactacorp",	2U,		308.00f,	192.00f,	0.f,	10.00f,		7U,		4U,		11.00f,		{ 30.f, 32.f, 43.f, 63.f, 92.f, 56.f, 33.f, 18.f } });
	add({ 3U,	"FREG",		"Fregate standard",						"Galactacorp",	2U,		296.00f,	192.00f,	0.f,	10.00f,		7U,		4U,		11.00f,		{ 50.f, 44.f, 43.f, 47.f, 56.f, 32.f, 21.f, 14.f } });
	add({ 4U,	"SCRO",		"Supercroiseur standard",				"Galactacorp",	2U,		766.00f,	461.00f,	0.f,	20.00f,		6U,		4U,		58.50f,		{ 30.f, 39.f, 69.f, 120.f, 192.f, 138.f, 99.f, 75.f } });
	add({ 7U,	"STA2",		"Station Spatiale Rakrarior Evolution", "n/a",			2U,		1300.00f,	920.00f,	0.f,	29.80f,		11U,	10U,	110.50f,	{ 310.f, 315.f, 455.f, 731.f, 1142.f, 945.f, 809.f, 742.f } });
}
