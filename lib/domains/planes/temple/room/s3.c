/*  Lamrani Temple, Southern Hallway, Room 3 */
/*   An incense burning prayer room */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetProperty("lower plane", 1);
  SetShort("a prayer room in the temple");
  SetExits( ([
     "east" : TEMPLE_ROOM "s1",
    ]) );
  SetSmell( ([
      "default" : "Incense is being burned in this room very heavily.",
    ]) );
  SetListen( ([
    "default" : "Chanting can be heard from the southern chamber.",
    ]) );
  SetLong("This chamber seems to be dedicated to burning incense "
          "for the souls of the dead. Arranged along the walls are "
          "various sized burners and urns for incense and ashes. The "
          "cold marble floor seems to draw attention to the hallway "
          "outside the chamber, as if protecting it from outsiders.");
  SetItems( ([
    "floor" : "The floor is highly polished and leads east.",
    ({ "urn", "urns" }) : "The urns seem to hold ashes of some kind.",
    ({ "ash", "ashes" }) : "It is hard to tell if these are ashes from "
                           "a living creature or the incense.",
    ({ "burner", "burners" }) : "The burners hold the incense while "
                               "it is being burnt.",
    ({ "incense" }) : "The incense around the room is in various states "
                      "of burning.",
  ({ "wall", "walls" }) : "The walls are arranged with burners and urns.",
    ]) );
  SetItemAdjectives( ([
    "floor" : ({ "cold", "marble" }),
    ]) );
 }
