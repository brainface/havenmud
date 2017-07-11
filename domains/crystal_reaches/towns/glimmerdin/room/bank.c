#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("a richly decorated segment of the cavern");
  SetLong(
    "Enchanting stone work is all about the room, none more so than "
    "the elaborate counter where transactions take place at this "
    "ancient institution of wealth.  Somehow managing not to contrast "
    "with the luxury of the rest of the room, a fortified vault is set "
    "into the south wall. A mithril gate guards the egress to the "
    "west." 
    );
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
    ({ "stone", "work" }) :
        "Engraved into the dark stone are symbols of wealth.",
    ({ "symbol", "symbols" }) :
        "Even though it is in hard stone the engraving is so delicately "
        "crafted it must have taken master craftsmen years to do.",
    ({ "counter" }) :
      "The teller's counter is a masters piece work and provides a place to "
      "do business.",
    ({ "vault" }) :
      "Blocked by a huge door of mithril, the vault is an imposing sight.",
    ({ "door" }) :
      "Bands of Mithril steel cover the already thick door of mithril, "
      "making the door nearly impervious to assault.",
   ]));
 SetItemAdjectives( ([
   "stone"   : ({ "stone", "enchanting", }),
   "counter" : ({ "elaborate", }),
   "vault"   : ({ "fortified", }),
   "door"    : ({ "mithril", "huge", "vault", }), 
   ]) );
 SetExits( ([
   "out" : G_ROOM "gh_south",
   ]) );
 SetSmell( ([
   "default" : "The room smells of expensive imported flowers.",
   ]) );
 SetListen( ([
   "default": "The bank is quiet and stately.",
   ]) );
 SetInventory( ([
   G_NPC "banker" : 1,
   ]) );
}
