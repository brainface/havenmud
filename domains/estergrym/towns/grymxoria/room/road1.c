#include <lib.h>
#include "../grymxoria.h"
#define WORLD "/domains/estergrym/virtual/grymxoria_road/40,0"
inherit LIB_ROOM;

int PreExit(string);

static void create() {
  room::create();
  SetTown("Grymxoria");
  SetClimate("sub-arctic");
  SetShort("grymxoria City Gate");
  SetLong(
    "The road opens up into a huge city. The road passes "
    "under an elaborately carved black stone arch set in a "
    "high wall made of roughly hewn stone blocks. "
    "Hung in the arch is a set of huge gates made of red metal. "
    "The Blood River passes through these gates, while "
    "pedestrians must go through one of the smaller doors "
    "on each side of the main gate. The river follows "
    "the road named after it into the city to south. Along "
    "the road the Grymxoria city barracks can be seen."
  );
  SetItems( ([
    "arch" : "This huge arch is carved partially out of the living "
             "stone of the cavern. There are three doorways set in the "
             "arch, a large central one through which the Blood river "
             "passes and two smaller gates, one to each side of the "
             "river, through which pedestrians may pass.",
    "wall" : "The city wall of Grymxoria is made out of large "
             "roughly hewn stone blocks, stacked and mortared. "
             "It looks strong enough to turn back any assault.",
   ({ "gates", "gate" }) : "This set of huge gates is made "
             "of a red metal. The Blood river passes through the "
             "opening between them.",
   ({ "doors", }) : "The two small gates, one to "
          "each side of the river, are hung with metal doors "
          "similar to the ones in the main gate.",
   ({ "river", }) : "The blood river flows down the center of the "
          "divided two lane road. It gets its name from the reddish "
          "color of the water from the large amounts of iron and "
          "copper in it.",
   ]) );
  SetItemAdjectives( ([
    "arch" : ({ "huge", "black", "stone", "carved", "elaborately", }),
    "wall" : ({ "high", "stone", }),
    "gates" : ({ "huge", "red", "metal", }),
    "doors" : ({ "smaller", }),
    "river" : ({ "blood", }),
  ]) );
  SetListen( ([
    "default" : "The river swishes and gurgles eerily.",
  ]) );
  SetInventory( ([
    G_NPC "guard" : 2,
  ]) );
  SetExits( ([
    "south" : G_ROOM + "road2",
  ]) );
  AddExit("north", WORLD, (: PreExit :) );
}

int PreExit(string dir) {
 if (this_player()->id("grym_npc")) return 0;
  return 1;
}

