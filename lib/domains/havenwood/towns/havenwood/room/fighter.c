#include "../wood.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  ::create();

  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("within the Barracks");
  SetLong(
    "This barracks serves as the center for the two main arms of the "
    "defense of the Havenwood: fighters and rangers. Scattered around "
    "the room are various weapons and the gear used to train the young "
    "defenders of the forest."
    );
  SetSmell("A faint smell of sweat taints the air.");
  SetListen("The clanging of weapons permeates the air.");
  SetItems( ([
    ({ "weapon", "weapons", "gear", "armour", "armours" }) :
       "Miscellanious weapons and armours lie waiting for use by the "
       "defenders of the forest.",
    ({ "room", "barracks" }) : (:GetLong:),
    ({ "floor", "ground" }) :
       "The floor is covered with various weapons and gear.",
    ]) );
  SetItemAdjectives( ([
          "weapons" : ({ "various", "scattered" }),  
    ]) );
  SetInventory( ([
    HWD_NPC "/fighter" : 1,
    HWD_NPC "/fellia"  : 1,
    ]) );
  SetProperty("no bump", 1);
  SetExits( ([
    "out" : HWD_ROOM "/gelf6",
    ]) );
}
