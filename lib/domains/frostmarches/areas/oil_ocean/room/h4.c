//Illura@haven
//h4
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the great oil ocean");
  SetLong(
    "The oil ocean's black, irregular surface extends in all "
    "directions from here, dotted with pools of stale ocean "
    "water and sticky tarballs. The ooze creeps viscously "
    "in one direction, then another, almost with silent "
    "purpose. The way east is impassable quicksand."
  );
  SetExits( ([
    "north" : OIL_ROOM "/h3",
    "south" : OIL_ROOM "/h5",
    "west" : OIL_ROOM "/g4",
  ]) );
  SetItems( ([
    ({"oil", "ooze", "oils", "surface", "sand"}) : 
    "The oil ocean is composed of shifting dark sand and swirling "
    "oils, layered with water from the true ocean to the far west.",
    ({"ocean", "water", "surface", "aquifer", "pool", "pools"}) : 
    "Water has seeped in from the underground aquifer in some places, "
    "but mostly the water is saline, carried by the wind from the western sea.",
    ({"ball", "balls", "tar", "tarballs", "mark", "marks"}) : 
    "Some of the oil has coagulated with the water to form sticky "
    "tarballs. Mostly, they are round, but some of them display bite "
    "marks, as though something has been chewing on them. They don't "
    "look edible to you.",
    ({"quicksand", "hill", "hills", "foothill", "foothills", "waste"}) : 
    "To the east through the impassable quicksand, the foothills of the "
    "Western Waste can be seen ",
    ({"sea"}) : 
    "In the distance to the west, the Ruined Sea can be seen.",
  ]) );
  SetItemAdjectives( ([
    "ocean" : ({"great", "oil", "black", "stale", "ocean", "true", "underground", 
                "saline", "pool of", "pools of"}),
    "ball" : ({"sticky", "tar", "round", "coagulated", "bite"}),
    "oil" : ({"swirling", "black", "dark", "shifting"}),
    "sea" : ({"western", "ruined"}),
    "quicksand" : ({"impassable", "foot", "western"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "oilhorse" : 3,
    OIL_NPC + "octopus" : 2,
  ]) );
  SetListen( ([
    "default" : "The only sound is the deadly slow shift of the ooze.",
  ]) );
  SetSmell( ([
    "default" : "The air stinks of sun-lit tar and stale water.",
  ]) );
}
