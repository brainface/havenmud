//
// a throne room
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("entrance to the throne room");
  SetLong("Beyond the obsidian door lies the throne room of the great King "
    "Radchek. Tapestries depicting his great scenes of triumph line "
    "the walls, and the floor is covered with polished marble. "
    "The ceiling rises high into the air, and stained glass windows "
    "showing scenes of the hunt are lit with sunlight by some "
    "eldritch means.");
  SetClimate("underground");
  SetAmbientLight(30);
  SetItems( ([
    "throne room" : (:GetLong:),
    ({"tapestry", "tapestries", "wall", "walls"}) :
      "These tapestries, once worth a fortune, are now "
      "so mildewed and decayed as to be worthless.",
    ({"floor", "marble","slab"}) :
      "The floor is made of a single slab of marble, worn and polished "
      "by the passing of many feet.",
    ({"windows", "glass"}) :
      "These windows have been enchanted in such a cunning fashion "
      "that those who were ignorant that they lay buried in the depths "
      "of the earth would remain so.",
    "ceiling" : "Far above, the ceiling lies decorated and painted in"
      " wondrous colours with no discernable pattern.",
    ]) );
  SetItemAdjectives( ([
    "tapestries" : ({"mildewed","decayed", "worthless"}),
    "windows" : ({"stained","glass"}),
    "floor" : ({"marble","polished","worn"}),
    ]) );
  SetSmell( ([
    "default" :
      "The musty smell of mildewed flesh is strong here.",
    ]) );
  SetInventory( ([
    RNQ_NPC + "king" : 1,
    ]) );
  SetExits( ([
    "north" : RNQ_RM + "keep.c",
    ]) );
  SetDoor("north", RNQ_OBJ + "door2.c");
}
