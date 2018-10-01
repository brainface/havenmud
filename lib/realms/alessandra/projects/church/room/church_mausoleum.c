//  Portia 12-11-98 Graveyard v2.0
//  Updated by Alessandra 2010

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("underground");
  SetShort("a chilly mausoleum");
  SetLong(
     "This is now a mausloeum. Indoors, benches, altar, tall ceiling. "
     "Flickering candles, cold, black roses in holders on walls. "
     );
  SetSmell( ([
     "default" : "This is smells.",
     ]) );
  SetListen( ([
     "default" : "This is noises.",
     ]) );
  SetItems( ([
     ]) );
  SetItemAdjectives( ([
     ]) );
  SetInventory( ([
     MAL_NPC + "necro_lead" : 1,
//   "/quests/alchemist/npc/whey_spider" : 5,
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "west" : MAL_ROOMS + "church_garden3",
//   "out" : MAL_ROOMS + "church_garden3",
     ]) );
}
