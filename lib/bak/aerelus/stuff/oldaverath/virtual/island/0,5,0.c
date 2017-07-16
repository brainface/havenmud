/* This is a small bazaar.
   0,5,0.c
   Coded by Kilik */

#include <lib.h>
#include <domains.h>
#include "/domains/averath/areas/bazaar/bazaar.h"
inherit AVERATH_LIB;

static void create() {
  ::create(0,5,0);
  SetShort("a small bazaar");
  SetLong("This is a small bazaar in the middle of the plains of Averath. "
          "A table is here with four posts around it that support a "
          "canvas covering for the table. Open air relieves the "
          "stench of fish with a cool breeze. Wares line the table on all "
          "sides. The grass is scarce here as if the area around "
          "the table has been trampled.");
  SetItems( ([
   ({ "booth" }) : (: GetLong :),
   ({ "grass","ground","area" }) :
      "The ground around the table has been walked over so many "
      "times that the grass has worn away.",
   ({ "canopy" }) :
      "It is made of a thin, soft canvas.",
   ({ "ware","wares" }) :
      "Wares line the table on all sides, ranging from "
      "stale fish to steins of ale.",
   ({ "fish","fishes","fishs" }) :
      "Stale fish line the table on the east side.",
   ({ "steins","stein","steins of ale" }) :
      "Steins of ale line the west side of the table.",
   ({ "table" }) : 
      "A small oak table with a glossy top holds the wares of the bazaar.",
   ({ "canvas" }) : "The canvas is soft and flowing.",
   ({ "post","posts" }) : "Wooden posts support the canvas.",
  ]) );
    SetItemAdjectives( ([
     "booth" : ({ "small" }),
     "grass" : ({ "scarce" }),
     "canopy" : ({ "canvas" }),
     "canvas" : ({ "thin","soft" }),
     "stein" : ({ "ale" }),
     "fish" : ({ "smelly" }),
     "post" : ({ "wood" }),
  ]) );
  SetInventory( ([ BAZAAR_NPC + "fish_vendor" : 1,
                   BAZAAR_NPC + "ale_vendor" : 1,
                   BAZAAR_NPC + "shopper" : 1,
                   BAZAAR_NPC + "farmer" : 1, ]) );
  SetSmell( ([
     "default" : "The smell of fish fills the air.",
  ]) );
  SetListen( ([
   "default" : "You hear the canvas flapping in the breeze.",
  ]) );
}
