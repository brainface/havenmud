#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;
inherit LIB_TOUCH;

static void create() {
  room::create();
  SetShort("the Smithy of Parva");
  SetExits( ([
    "out" : PARVA_ROOM "path2",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    PARVA_NPC "smith" : 1,
    PARVA_NPC "mule"  : 1,
    PARVA_NPC "smith_trainer" : 1,
    ]) );
  SetLong(
    "Heated by the forge in the back and darkly covered by unscourged "
    "soot from eons of smithing, the Parvan smithy is a tireless building "
    "full of the tools of the smithing trade from the blackened iron anvil "
    "to the enormous millwheel bellows turned by a gentled mule. The front "
    "of the building serves as a shop, showcasing the wares made here."
    );
  SetItems( ([
    "forge" : "The forge is a massive affair and is covered in soot.",
    "soot"  : "The soot is ash and other material built of from years of forging.",
    ({ "tool", "tools" }) : "The tools of smithing include the anvil and the bellows.",
    "anvil" : "This anvil is a large block of shaped metal used for pounding and shaping.",
    "bellows" : "The bellows is the air-pressure device used to superheat the forge.",
    ]) );
  SetItemAdjectives( ([
    "soot" : ({ "unscourged", }),
    "anvil": ({ "blackened", "iron", }),
    "bellows" :  ({ "enormous", "millwheel" }),
    ]) );
  SetSmell("The smithy smells of smoke and soot.");
  SetTouch("The heat in here is intense.");
  SetListen("The crackle of the forge fires is a dull roar.");
}