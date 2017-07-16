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
    "east" : LUMBER_ROOM "room1",
        ]) );
 SetShort("an abandoned lumber camp");
  SetLong(
    "A half constructed lumber barn sits against the tree line. "
    "What appears to be dried blood stains the half completed door frame. "
    "Under a large oak tree is a small knapsack that is partially shedded. "
    );
  SetSmell("It smells of decay here.");
  SetListen("A strange tapping sound can be heard."); 
  SetItems( ([
            ({"blood"}) :
            "Dried blood in the shape of a handprint. ",
            ({"knapsack"}) :
            "The knapsack is almost completely shredded "
            "and contains nothing of value.",
            ({"tree"}) :
            "A huge old oak tree towers above you. ",
            ({"barn"}) :
            "Broken and barely constructed, this barn is in bad shape. ",
                ]) );
  SetInventory( ([
    LUMBER_NPC + "wolf":3,
  ]) );
}
