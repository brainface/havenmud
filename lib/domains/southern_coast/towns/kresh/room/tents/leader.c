/*  Village Mayor Tent */
#include <lib.h>
#include "../../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetProperty("no bump",1);
  SetShort("inside a regal tent");
  SetObviousExits("out");
  SetExits( ([
     "out" : GOBLIN_ROOM + "m_6",
      ]) );
  SetAmbientLight(40);
  SetLong("The tent seems more regal inside than out.  The area is adorned "
         "with official looking papers and stacks of vital documents. "
         "The tent has what appears to be a crude desk here which "
         "seems very rickety.");
  SetItems( ([
    ({ "paper", "papers" }) : "The papers are scratches of goblin "
                              "writing that give details of the "
                              "dull stats of the village.",
    "desk" : "The desk is covered in papers and is very old.",
  ]) );
  SetInventory( ([
     GOBLIN_NPC + "king" : 1,
     GOBLIN_NPC + "medium" : (random(4) + 2),
     GOBLIN_NPC + "little" : (random(2) + 2),
     GOBLIN_NPC + "bank"   : 1,
    ]) );
 }
