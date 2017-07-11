#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "south" : PARVA_ROOM "wharf1",
    ]) );
  SetShort("along the wharf in Parva");
  SetLong(
    "The Parvan road dead ends here before a modest wooden cottage. "
    "Pansies bloom in whitewashed windowboxes on the side of the cottage "
    "that faces the street, making it look more inviting than the other "
    "ramshackle buildings around it. The road follows the shoreline south."
  );
  SetItems( ([
    ({ "road", "street" }) : "The sandy road runs along the wharf.",
    "cottage" : "The cottage houses the local language teacher.",
    "pansies" : "The delicate flowers have happy, rich purple faces.",
    "windowboxes" : "The windowboxes are made of old, whitewashed wood, but they are full of beautiful flowers.",
    "buildings" : "The decrepit buildings of Parva seem to be all but falling apart. ",
    ]) );
  SetItemAdjectives( ([
    "road" : ({ "parvan" }),
    "cottage" : ({ "modest", "wooden" }),
    "windowboxes" : ({ "whitewashed" }),
    "buildings" : ({ "ramshackle", }),
    ]) );
  SetEnters( ([
    "cottage" : PARVA_ROOM "sage",
    ]) );
  SetSmell("Something smells positively awful in this town.");
  SetListen("At all hours, Parva is alive with raucous noise.");
  SetInventory( ([
    ]) );
}