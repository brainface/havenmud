#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("a pirate galleon");
  SetClimate("temperate");
  SetExits( ([
       "north" : ACOVE_ROOMS + "cove3",
       "east" : ACOVE_ROOMS + "cove5",
       "west" : ACOVE_ROOMS + "cove7",
      "up" : ACOVE_ROOMS + "cove16",
        ]) );
  SetLong("Upon boarding this old shipwreck, it is impossible "
          "to imagine what lies ahead.  On the surface, "
        "the wreck seems to be in remarkably good condition "
            "but a strong sense of evil is palpable. The "
        "deck lists slightly to one side. The crow's nest "
        "is above and the deck of the ship runs to the east "
        "and to the west. The beach is to the north.");
  SetItems( ([
      ({ "ship","galleon"}) : (: GetLong :),
      ({ "shipwreck","wreck" }) : "This wreck appears to be deserted.",
      ({"deck","decks","surface"}) : "The decks are in good "
      "condition - almost as if maintained by phantom hands.",
     ({"crows nest","nest"}) : "It is high above the main "
        "deck, providing a good vantage point for the ship's "
        "lookout.",
      ]) );
  SetInventory( ([
       ACOVE_NPC + "bosunsmate" : 1,
      ]) );
}
