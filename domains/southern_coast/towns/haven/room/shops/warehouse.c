//
// The Warehouse
// Filename: warehouse.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetClimate("indoors");
   SetShort("a massive building for crafting ships");
   SetAmbientLight(35);
   SetExits( ([
      "out" : "../merchants_way/mw1",
   ]) );
   SetLong(
     "The center of the Elven Navy is a sight to behold. Ships in various stage of building "
     "are held from various stages of the ceiling and naval recruits run to and fro working "
     "with the Master Crafters to build the fleet and maintain it. A small desk is arranged "
     "on the main floor as a makeshift office, but it is apparent the Crafters spend little "
     "time with paperwork and mostly work on the fleet."
     );
   SetSmell( ([
      "default" : "Sawdust mixes with various oils to give the berth a seaworthy smell."
     ]) );
   SetItems( ([
     "desk" : "The desk is small and has little of note upon it.",
     ({ "ship", "ships" }) : "The ships are only partially assembled here before "
                             "being magically transferred to the wharf.",
     ]) );
   SetItemAdjectives( ([
      ]) );
   SetInventory( ([
     H_NPC "shipseller" : 1,
     H_NPC "shiptrainer" : 1,
     H_NPC "sailor_leader" : 1,
     ]) );
}
