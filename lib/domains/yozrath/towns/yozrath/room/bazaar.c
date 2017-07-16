#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : YOZRATH_ROOM "baz2",
    ]) );
  SetLong(
    "The Yozrath Bazaar is a bustling area at all hours. Vendors are usually "
    "present attempting to hawk their wares and various services are advertised "
    "as being present. Booths, carts, and stalls line every available inch of "
    "space, leaving only a moderate path to allow customers to pass through while "
    "shopping."
    " There is a small post office here."
    );
  SetSmell("Odd scents come from several of the booths.");
  SetListen("The roar of the Bazaar is deafening.");
  SetItems( ([
    ({ "booth", "booths", "cart", "carts", "stall", "stalls" }) : "The booths, carts, "
              "and stalls that line the bazaar are varied and different, but the same "
              "in their purpose.",
   "office" : "This is a post office.",
    ]) );
  SetItemAdjectives( ([
    "office" : ({ "post", "small" }),
    ]) );
  SetEnters( ([
    "office" : YOZRATH_ROOM "post",
    ]) );
  SetInventory( ([
    YOZRATH_NPC "ishmael" : 1,
    YOZRATH_NPC "teller"  : 1,
    YOZRATH_NPC "instruments" : 1,
    YOZRATH_NPC "merchant" : 1,
    YOZRATH_NPC "guard"    : 2,
    ]) );
  SetShort("the Yozrath Bazaar");
}

void heart_beat() {
  string yell;
  ::heart_beat();
  if (!random(10)) {
    switch(random(10)) {
      case 0:
        yell = "A vendor yells out, \"Fresh fish.  We catch 'em, you buy 'em!\"";
      break;
      case 1:
        yell = "A pretty necklace for a pretty lady!";
     default:
    }
   }
  }
