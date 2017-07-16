/*  Lamrani Temple, East Hallway, Second room */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;

static void create() { 
  ::create();
  SetProperty("lower plane", 1);
  SetClimate("indoors");
  SetShort("along the east hallway");
  SetAmbientLight(35);
  SetExits( ([
    "east" : TEMPLE_ROOM + "e3",
    "north" : TEMPLE_ROOM + "e1",
    ]) );
  SetSmell( ([
      "default" : "The smell of incense is faint here.",
    ]) );
  SetListen( ([
    "default" : "The sounds of chanting are distant from here.",
    ]) );
  SetLong("This section of the hallway contains a turn, leading "
          "from the east to the north. Symbols of kindness and "
          "warmth line the walls, and the cold marble floor "
          "continues without stopping.");
  SetItems( ([
      ({ "symbol", "symbols" }) : "The symbols have lost their "
                                 "look of death, focusing instead on "
                                 "warmth and kindness.",
    "floor" : "The marble floor is polished to a shine.",
    ]) );
  SetItemAdjectives( ([
    "floor" : ({ "cold", "marble" }),
    ]) );
  SetInventory( ([
    TEMPLE_NPC "lamrani1" : 1,
    ]) );
 }
