//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in a scroll storeroom");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetLong(
    "This room of the papermaking workshop is used to dry and "
    "roll the long sheets of papyrus paper once it is plaited "
    "together. Long stone biers stretch and flatten the paper, "
    "while slotted cabinets in the walls hold finished scrolls. "
    "An doorway leads south, into the rest of the workshop."
  );
  SetItems( ([
    ({ "papyrus", "paper", "sheets" }) :
    "The papyrus processing ends here, where the paper dries "
    "on biers and then is rolled up into blank scrolls.",
    ({ "bier", "biers" }) :
    "The biers are made of warm stones that seem to soak up "
    "the moisture from the paper as it dries.",
    ({ "cabinet", "cabinets", "wall", "walls" }) : 
    "Each cabinet is stuffed with any number of scrolls.",
    ({ "doorway" }) : 
    "The open doorway faces south.",
  ]) );
  SetItemAdjectives( ([
  "bier" : ({ "long", "stone" }),
  "cabinet" : ({ "slotted" }),
  ]) );
  SetInventory( ([
    LAKE_NPC "gatherer" : 1,
    LAKE_NPC "papyrusmaker" : 1,
  ]) );
  SetListen("The paper crackles as it dries.");
  SetSmell("It smells like paper here.");
  SetExits( ([
    "south"  : LAKE_ROOM "/6a",
  ]) );
}
