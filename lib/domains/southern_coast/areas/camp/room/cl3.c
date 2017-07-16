#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNightLight(10);
  SetShort("a campside");
  SetDayLong(
    "The blue sky hangs over this campsite revealing this "
    "to be a busy area of travel.  There are three tents "
    "here (a blue tent, a black tent, and a brown tent), "
    "all of which seem to be occupied by some person "
    "or another.  There is a large firepit here which could "
    "cook for dozens of people."
    );
  SetNightLong(
    "The stars are blotted out by the roar of a campfire, "
    "easily capable of cooking for dozens of people.  There "
    "are three tents here each of which could hold a small "
    "family. The tents are blue, black, and brown. " 
    "To the north there seems to be a path out of the campsite."
    );
  SetExits( ([
    "northeast" : CAMP_ROOM + "/cl2",
    ]) );
  SetSmell( ([
    "default" : "The smell of burnt wood hangs in the air.",
    ]) );
  SetItems( ([
          "firepit" : "This pit could house a large campfire.",
          "campfire" : "This large fire could cook for dozens.",
      ({ "blue tent" , "tent" }) : "The blue tent looks the largest.",
      ({ "black tent", "tent" }) : "The black tent seems fairly small.",
      ({ "brown tent", "tent" }) : "The brown tent seems to be used quite a bit.",
      ]) );
  SetEnters( ([
      "blue tent" : CAMP_TENT + "/blue",
      "black tent" : CAMP_TENT + "/black",
      "brown tent" : CAMP_TENT + "/brown",
      ]) );
  SetInventory( ([
     CAMP_NPC + "/bandit" : 1,
     CAMP_NPC + "/labandit" : 1,
     CAMP_NPC + "/dog" : 3,
     ]) );
}
