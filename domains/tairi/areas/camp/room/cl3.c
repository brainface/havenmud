#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNightLight(10);
  SetShort("a campsite");
  SetDayLong(
    "The blue sky hangs over this campsite revealing this "
    "to be a busy area of travel.  There is a tent "
    "here which seems to be occupied by some of the ronin. "
    "There is a large firepit here which could cook for dozens of people."
    );
  SetNightLong(
    "The stars are blotted out by the roar of a campfire, "
    "easily capable of cooking for dozens of people. There is a large "
    "tent here which is likely to house several ronin. The fire burns in "
    "a large firepit." 
    "To the northeast there seems to be a path out of the campsite."
    );
  SetExits( ([
    "northeast" : CAMP_ROOM + "cl2",
    ]) );
  SetSmell( ([
    "default" : "The smell of burnt wood hangs in the air.",
    ]) );
  SetItems( ([
      "firepit" : "This pit could house a large campfire.",
      "campfire" : "This large fire could cook for dozens.",
      ({ "tent" }) : "The brown tent appears to be both large and occupied.",
      ]) );
  SetItemAdjectives( ([
    "tent" : ({ "large", "brown", "occupied" }),
    "firepit" : ({ "large", }),
    ]) );
  SetEnters( ([
      "tent" : CAMP_TENT + "brown",
      ]) );
  SetInventory( ([
     CAMP_NPC + "bandit" : 1,
     CAMP_NPC + "labandit" : 1,
     CAMP_NPC + "dog" : 1,
     ]) );
}
