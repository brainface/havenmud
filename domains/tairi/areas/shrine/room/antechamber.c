#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the antechamber of the shrine");
  SetLong("Here in the antechamber everything is"
          " very orderly. An ornate cloth rug has"
          " been run from the arch to the door of"
          " the sanctuary. Nothing has been hung to"
          " adorn the walls, but great care has"
          " gone into their crafting. They are very"
          " smooth and have a slight shine to them. ");
  SetItems( ([
          ({ "rug"}) :
          "This cloth rug has been laid out in order"
          " to collect the dirt from visitors feet.",
          ({ "wall", "walls" }) :
          "The walls are very smooth with a slight"
          " shine.",
          ({ "sanctuary", "door" }) :
          "The sanctuary is south of here.",
          ]) );
  SetItemAdjectives( ([
          "rug" : ({ "cloth", "ornate" }),
          "wall" : ({ "smooth", "shiny" }),
          ]) );                 
  SetSmell( ([
          "default" : "The smell of burning incense lingers.",
       ]) );
  SetExits( ([
           "south" : SHRINE_ROOM "sanctuary",
           "north" : SHRINE_ROOM "room4",
        ]) );
  SetInventory( ([
        ]) );
}
