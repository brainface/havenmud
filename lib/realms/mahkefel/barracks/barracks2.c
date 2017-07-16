// barracks level 2: archery bugaloo
#include "../wood.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  ::create();

  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("an Archery Range in the Tree");
  SetLong(
    "Along the spiderwebbing branches of the tree a multitude of wooden "
    "targets hang from ropes or nailed to the tough bark of the tree. "
    );
  SetSmell("A ");
  SetListen("The clanging of weapons permeates the air.");
  SetItems( ([
   /* ({ "weapon", "weapons", "gear", "armour", "armours" }) :
       "Miscellanious weapons and armours lie waiting for use by the "
       "defenders of the forest.",
    ({ "room", "barracks" }) : (:GetLong:),
    ({ "floor", "ground" }) :
       "The floor is covered with various weapons and gear.",
    ]) );
    */
  SetItemAdjectives( ([
    //      "weapons" : ({ "various", "scattered" }),
    ]) );
  SetInventory( ([
    HWD_NPC "/fellia"  : 1,
    ]) );
  SetExits( ([
    //"up" : HWD_ROOM "/barracks3",
    //"down" : HWD_ROOM "/barracks1",
    ]) );
}

