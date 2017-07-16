#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a pirate galleon");
  SetClimate("temperate");
  SetExits( ([
      "east" : ACOVE_ROOMS + "cove6",
      "west" : ACOVE_ROOMS + "cove4",
       ]) );
  SetLong("This section of the galleon's deck slopes "
         "slightly.  Four ancient brandy casks seem "
         "to be intact where they rest at the side "
         "rail. The planks are in good condition as "
         "if maintained by unseen hands.");
  SetItems( ([
       ({ "ship","galleon"}) : (: GetLong :),
       ({ "section", "deck" }): "The oak planks look old "
                               "and worn.",
       ({"plank","planks"}) : "The oaken planks of the ship's "
                           "deck are smooth and worn.",
      ({ "cask", "casks" }) : "These casks are old but seem "
                             "to be intact and full.",
      "rail" : "The heavy oak seems to be sturdy.",
      ]) );
  SetItemAdjectives( ([
    "casks" : ({"ancient","intact","brandy"}),
    ]) );
  SetInventory( ([
      ACOVE_NPC + "crew1" : 1,
      ]) );
}
