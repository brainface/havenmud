#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "down" : "tavern",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("above the Tavern");
  SetLong("The center of the room houses a square metal table"
          " with four chairs, one on each side. The walls are"
          " bare except a small portrait on the northern wall."
          " The floor is extremely clean and slightly glossy."
          " A stairwell on the western wall leads back down to"
          " the common room of the tavern.");
  SetItems( ([
     "portrait" : "The portrait is of a regal looking gnome"
                  " with a small red fedora hat atop his head."
                  " He has a sly smile upon his face.",
     ({ "wall", "walls" }) : "The walls are bare except for"
                  " a small portrait on the northern wall and"
                  " a stairwell on the western wall.",
     "floor" :    "The floor is extremely clean and slightly"
                  " glossy as though it has been recently waxed.",
     ({ "stairwell", "stairs" }) :  "On the western wall a"
                  " stairwell leads back down to the common"
                  " room of the tavern.",
     ({ "table", "chairs" }) : "The table is made of some dark"
                  " metal. It looks extremely strudy and well"
                  " built. The surface of the top of the table"
                  " has been polished so that it gives a slight"
                  " reflection. The chairs are also made of metal"
                  " and have been treated with the same polish and"
                  " give off a slight reflection.",
     ]) );
  SetItemAdjectives( ([
     "portrait" : "small",
     "wall" : "bare",
     "floor" : "clean",
     "table" : ({ "square", "metal" })
     ]) );
  SetInventory( ([
    UNDER_NPC "rogue" : 1,
    ]) );
}
