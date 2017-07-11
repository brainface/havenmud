//Illura@haven
//i5
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("at the edge of the oil ocean");
  SetLong(
    "The mucky, rust-brown oil sands slurp hungrily at whatever stubborn vegetation "
    "is left so close to the great Oil Ocean that oozes just to the west. The main "
    "road and the only remaining trees are on the eastern horizon, but here, wide "
    "swaths of sludge and viscous bitumen cover the ground, several inches deep in "
    "places. A fifty-foot tall column stands here. The column is inscribed with "
    "many symbols."
  );
  SetExits( ([
    "southeast" : OIL_ROOM "/j6",
    "west" : OIL_ROOM "/h5",
  ]) );
  SetItems( ([
    ({"sand", "sands", "oil", "sludge", "bitumen", "swarth","ground", "ooze"}) : 
    "The oil ocean has spread here, covering the warm sands with a "
    "disgusting ooze.",
    ({"vegetation", "blade", "blades", "grass"}) : 
    "A few blades of grass poke through the thick ooze, but no trees "
    "can grow here.",
    ({"ocean", "horizon", "western horizon","sea"}) : 
    "The Ruined Sea lies to the west through the Great Oil Ocean.",
    ({"road", "horizon", "eastern horizon", "waste"}) : 
    "The road lies to the east towards the foothills of the Western Waste.",
    ({"column", "symbol", "symbols"}) : 
    "The symbols read in many languages, some of which you have never "
    "seen. They all, however, speak of dangerous shifts in the oil and "
    "even more dangerous monsters that lurk within it. The column has "
    "clearly sunk over time, obscuring some of the symbols.",
    ({"tree", "trees", "hill", "hills", "foothill" ,"foothills"}) :
    "The only trees that can be seen are in the foothills to the east.",
  ]) );
  SetItemAdjectives( ([
    "vegetation" : ({"stubborn", "few", "blades", "blades of"}),
    "ocean" : ({"great", "oil", "ruined", "west" }),
    "road" : ({"main", "east", "eastern", "western", }),
    "sand" : ({ "warm", "mucky", "rusty", "brown", "oily", "rust-brown","wide",
                "swarth of", "rust", "viscous", "disgusting", "thick"}),
    "column" : ({"fifty", "foot", "fifty-foot", "tall", "many"}),
    "tree" : ({"only", "foot"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "lizard" : 2,
  ]) );
  SetListen( ([
    "default" : "You can hear the oil popping and shifting in the ground.",
  ]) );
  SetSmell( ([
    "default" : "The air is thick and heady with the scent of bitumen.",
  ]) );
}
