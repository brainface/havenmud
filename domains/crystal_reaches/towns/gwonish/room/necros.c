/* Necro Hall */
#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;
inherit LIB_TOUCH;

static void create() {
  ::create();
  SetShort("inside a dark and evil hall");
  SetAmbientLight(5);
  SetClimate("indoors");
  SetExits( ([
    "out" : GWONISH_ROOM "gw06",
    ]) );
  SetLong(
    "The stone building has little in the way of light, being a perfectly "
    "dark, enclosed structure that seems to resemble a tomb. Stains on the "
    "floor look very much like blood, and a small pile in the corner appears "
    "to be bones. A wide altar sits in the center of the tomb, stained a ruddy "
    "copper color and appearing to be used for evil rites."
    );
  SetSmell( ([
    "default" : "A foul coppery smell mixes with the rot.",
    ]) );
  SetTouch( ([
    "default" : "The chamber gives off an uneasy feeling.",
    ]) );
  SetItems( ([
    "floor" : "The floor has many stains on it.",
    ({ "stain", "stains" }) : "The stains appear to be from bloody rites.",
    ({ "pile" }) : "The pile seems to contail small halfling bones.",
    ({ "bone", "bones" }) : "The bones are small, like halflings.",
    "altar" : "The altar is short and circular, appearing to be used "
              "in rites.  The altar is covered with coppery stains.",
    ]) );
  SetItemAdjectives( ([
    "stain" : ({ "coppery", "copper", }),
    "pile"  : ({ "small", }),
    "bone"  : ({ "small", "halfling", }),
    "altar" : ({ "wide", "stained", }),
    ]) );
  SetInventory( ([
    GWONISH_NPC "necro" : 1,
    ]) );
}