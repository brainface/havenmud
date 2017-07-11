 //Lanikai@Haven
//6-21-09
#include <lib.h>
#include <domains.h>
#include "../lumber.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetExits( ([
    "north"  : "/domains/averath/virtual/averathroad/-4,0",
    "east" : LUMBER_ROOM + "room2",
    "west" : LUMBER_ROOM + "room3",

    ]) );
  SetShort("an abandoned lumber camp");
  SetLong(
    "The lumber camp appears as though it was abandoned in a hurry. "
    "A rusty axe remains embedded in a stump. "
    "Near the tree line an abandoned saw lies in the grass surrounded "
    "by what appears to be an old pile of sawdust.  "
    "Knee high brush has grown throughout the camp; small animals "
    "scurry through the safety of the tall grass back into the forest. "
    "Something is carved into a nearby hewn plank. "
    );
  SetSmell("It smells of old sawdust here.");
  SetListen("The silence of the clearing seems out of place."); 
  SetItems( ([
            ({"axe"}) :
            "A large axe with a worn handle "
            "rust covers the blade and it seems stuck in the stump.",
	    ({"brush"}) :
            "Brush that has since grown over the formerly well manicured "
            "camp grounds.",
            ({"stump"}) :
            "Marred by many gashes, this stump appears to "
            " have been used to split wood. ",
            ({"saw"}) :
            "The saw sits in a bed of old saw dust and is almost "
            "entirely encased in rust.",
            ({"plank"}) :
            "The carving in the plank reads 'Ceci n'est pas une maison...",
            ({"pile", "sawdust", "dust"}) :
            "This pile of sawdust contains nothing. ",
            ({"animals"}) :
            "Small animals dart back an forth through the grass too fast for you to identify. ",
            ({"tree line"}) :
            "The forest is just outside this empty camp. ",
    ]) );
  SetInventory( ([
    LUMBER_NPC + "wolf":2,
    LUMBER_NPC + "weasel":1,
  ]) );
}
