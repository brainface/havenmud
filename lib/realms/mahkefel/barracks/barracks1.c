// barracks level 2: archery bugaloo
#include "../wood.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  ::create();

  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a Barracks in the Lower Tree");
  SetLong(
    "This appears to be the sleeping quarters of the barracks, such as it is. "
    "Hammocks hang cocoon-like from the long, low branches, and the "
    "thick curtain of leaves and furry vines seems to muffle sound "
    "from above and below. A particularly thick branch hangs off to the west."
    );
  SetSmell("It smells a lot like a bunch of sweaty people went to sleep without taking a bath.");
  SetListen("Faint muffles noises of weapons clashing and revellers shouting barely penetrates the foliage.");
/*  SetItems( ([
    ({ "weapon", "weapons", "gear", "armour", "armours" }) :
       "Miscellanious weapons and armours lie waiting for use by the "
       "defenders of the forest.",
    ({ "room", "barracks" }) : (:GetLong:),
    ({ "floor", "ground" }) :
       "The floor is covered with various weapons and gear.",
    ]) );
  SetItemAdjectives( ([
          "weapons" : ({ "various", "scattered" }),
    ]) );*/
  SetInventory( ([
    //HWD_NPC "/fellia"  : 1,
    // sleeping wildelves
    ]) );
  SetExits( ([
    //"up" : HWD_ROOM "/barracks3",
    //"down" : HWD_ROOM "/barracks1",
    ]) );
}

