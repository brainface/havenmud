#include <lib.h>
#include "../averath.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetClimate("indoors");
   SetShort("a massive building for crafting ships");
   SetAmbientLight(35);
   SetExits( ([
      "out" : AVERATH_ROOM "wharf",
   ]) );
   SetLong(
     "The center of the Averath shipping industry is a sight to behold. Ships "
     "in various stage of building are held from various stages of the "
     "ceiling and naval recruits run to and fro working with shipwrights to "
     "build fleets and maintain them. A small desk is arranged on the main "
     "floor as a makeshift office, but it is apparent the shipping magnates "
     "spend little time with paperwork and mostly work on their fleets."
     );
   SetSmell( ([
      "default" : "Sawdust mixes with various oils to give the berth a "
        "seaworthy smell."
     ]) );
   SetItems( ([
     "desk" : "The desk is small and has little of note upon it.",
     ({ "ship", "ships" }) : "The ships are assembled here before being "
       "launched into the sea.",
     ]) );
   SetItemAdjectives( ([
      ]) );
   SetInventory( ([
     AVERATH_NPC "shipseller" : 1,
     ]) );
}
