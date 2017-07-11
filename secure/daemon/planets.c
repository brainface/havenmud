/* Daemon to track planets */
#include <lib.h>
#include <save.h>
#include <std.h>
inherit LIB_DAEMON;

mapping Grid = ([]);
mapping Planets = ([]);

void LoadGrid();
void SaveGrid();
object CheckPlanet(int, int, int);


static void create() {
	::create();
	Grid = ([]);
	Planets = ([]);
  LoadGrid();
  SaveGrid();
}

void LoadGrid() {
	unguarded( (: restore_object, SAVE_PLANETS :) );
}

void SaveGrid() {
	unguarded( (: save_object, SAVE_PLANETS :) );
}

object *CheckPlanets(int x, int y, int z) {
	if (Grid[(x + "," + y + "," + z)]) {
		return distinct_array(Grid[(x + "," + y + "," + z)]);
	}
	return ({});
}

mapping AddPlanet(string location, string file, string name) {
	if (!Grid[location]) Grid[location] = ({ });
	Grid[location] = distinct_array(Grid[location] + ({ STD_PLANETS + file }));
	if (!sizeof(Planets)) Planets = ([]);
	Planets[name] = location;
	SaveGrid();
	return Grid;
}

mapping DeletePlanet(string location, string file) {
	Grid[location] -= ({ file });
	map_delete(Planets, file->GetName());
	if (!sizeof(Grid[location])) map_delete(Grid, location);
	SaveGrid();
	return Grid;
}

string GetPlanetLocation(string planet) {
	return Planets[planet];
}
