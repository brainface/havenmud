// Inn Place
// Updated by Ranquest 29th Jan 1999

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Twitchy Nymph");
  SetInventory( ([
    SOUTHERN_COAST_AREAS "coffeehouse/npc/pjack" : 1,
    SOUTHERN_COAST_AREAS "coffeehouse/npc/wtpatron" : random(3)+1 ]) );
  SetSmell( ([
    "default" : "The coffeehouse smells of roasting beans and baking pastries.",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "out" : SOUTHERN_COAST_VIRTUAL + "havenroad/-20,0",
     ]) );
  SetLong(
    "This moderate size building is home to The Twitching "
    "Nymph coffeehouse.  Its walls are adorned with colorful paintings of "
    "various nymphs drinking coffee. Several large comfy looking chairs populate "
    "the shop as well as a few small tables. Torches and candles provide the "
    "light for the room giving it a homey appearance."
    );
  SetItems( ([
    ]) );
  SetItemAdjectives( ([
    ]) );
}
/* Approved by Balishae on Wed Jul  2 15:58:14 1997. */
