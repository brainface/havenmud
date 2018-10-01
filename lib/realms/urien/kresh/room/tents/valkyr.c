/*  The valkyr leader's tent */
#include <lib.h>
#include "../../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetObviousExits("out");
  SetExits( ([
      "out"  : GOBLIN_ROOM + "w_1",
     ]) );
  SetAmbientLight(32);
  SetShort("inside a small tent");
  SetLong("This tent is the home to Kresh's sect of Valkyr warriors. "
          "The tent is fairly spacious with very little in the way of "
          "furnishings.  There are mats lying on the floor which seem "
          "to be a form of training for the newest warriors.");
  SetItems( ([
      ({ "mat", "mats" }) : "These are flat mats which are good for "
                            "tossing people onto.",
      ]) );
  SetInventory( ([
      GOBLIN_NPC + "val_ldr" : 1,
      GOBLIN_NPC + "valk" : random(4),
      GOBLIN_NPC + "jormal" : 1,
      ]) );
  SetProperty("no bump", 1);
  }
