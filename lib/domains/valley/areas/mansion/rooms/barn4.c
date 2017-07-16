/* a small stall
   kyla 3-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small stall");
SetDomain("Valley");
  SetClimate("indoors");
  SetExits( ([
      "north" : MANSION_ROOMS + "barn2",
     "west" : MANSION_ROOMS + "barn3",
      ]) );
  SetInventory( ([
      PASTURE_NPC + "goat" : 2,
          ]) );
  SetSmell( ([
     "default" : "The smell of manure is strong here.",
         ]) );
  SetListen( ([
      "default" : "The stomping of animal hoofs can be heard.",
           ]) );
  SetLong("The small stall is covered in straw and manure. This area "
          "could use a good cleaning. To the north is the entranceway "
          "into the barn and to the west lies another small stall. The "
          "air is full of dust and the occansional fly.");
  SetItems( ([
      ({"stall", "barn"}) : (:GetLong:),
        "straw" : "The dry straw is scattered around the stall.",
         "manure" : "The manure is quite abundant.",
        "area" : (:GetLong:),
      ({"door", "entranceway"}) : "The large door is to the north.",
         "dust" : "The dust sparkles in the sunlight.",
        "sunlight" : "The sunlight reflects off of the dust.",
        ({"fly", "flies"}) : "The flies are a minor annoyance.",
     ]) );
  }
