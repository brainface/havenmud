#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside a crypt");
  SetAmbientLight(12);
  SetClimate("indoors");
  SetObviousExits("out");
  SetExits( ([
    "out" : NEWBIE_ROOM + "/field5",
   ]) );
  SetInventory( ([
    NEWBIE_NPC + "/wraith" : 1,
   ]) );
  SetLong("The crypt is a large, hollowed area built out of mortar and \n"
          "which holds a chill regardless of the outside temperature. \n"
          "The walls are engraved with the deeds of the dead buried within \n"
          "this tomb.  The floor is covered in dust of ages, as no living \n"
          "creature has left a mark upon it.");
  SetItems( ([
   ({ "wall", "walls" }) : "The walls are stone and mortar and "
                            "covered in writing.",
  ({ "deed", "deeds" }) : "This is writing engraved on the walls.",
  ({ "writing" }) : "These are words on the walls.",
   ({ "mortar", "stone" }) : "The mortar and stone are part of the design "
                              "of the walls.  They are covered in writing.",
    ({ "floor", "dust" }) : "The floor is covered in thick, normal dust.",
    ]) );
  SetRead( ([
  "writing" :
        "These are simply tales of long dead heros.",
  "wall" :
     "These are simply tales of long dead heros.",
  "deed" :
     "These are simply tales of long dead heros.",
    ]) );
  SetSmell( ([
     "default" : "Fallen dust clogs the air.",
    ]) );
  SetListen( ([
     "default" : "The crypt is deathly quiet.",
    ]) );
 }
