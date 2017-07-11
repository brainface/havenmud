/* This is a swing for people to ride on. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a swing");
  SetLong("A large wooden swing is the prominent ediface here. There "
     "are support beams on either side, and two thick ropes hanging "
     "from the top are connected to a smooth wooden seat at the "
     "bottom. There are a few dandelions sprinkled among the "
     "sparse grass. Booths are visible to the east and west, "
     "while a fence of some sort is to the north.");
  SetItems( ([
   ({ "swing" }) : (: GetLong :),
   ({ "ediface" }) : (: GetLong :),
   ({ "beam", "beams" }) : "The thick beams are very tall, and appear to be quite strong.",
   ({ "rope", "ropes" }) : "They hang from the top cross beam and are tied to the wooden seat at the bottom.",
   ({ "seat" }) : "It has been sanded down to avoid splinters and could easily accommodate several people.",
   ({ "dandelion", "dandelions" }) : "There are a few little dandelions around the edges of the beams.",
   ({ "grass" }) : "Although not dead, the grass here is sparse.",
   ({ "fence" }) : "In the center of the tall fence is a gate.",
  ]) );
  SetItemAdjectives( ([
   "swing" : ({ "large", "wooden" }),
   "beam" : ({ "support", "tall", "strong" }),
   "rope" : ({ "two", "thick" }),
   "seat" : ({ "smooth", "wooden" }),
   "dandelion" : ({ "few" }),
  ]) );
  SetSmell( ([
     "default" : "The smell of food drifts in from the east.",
  ]) );
  SetListen( ([
     "default" : "Sounds of laughter fill the air.",
  ]) );
  SetExits( ([
     "south" : BAZAAR_ROOM "mud",
     "north" : BAZAAR_ROOM "pen",
     "east" : BAZAAR_ROOM "food",
     "west" : BAZAAR_ROOM "bet.c",
  ]) );
  SetInventory( ([ BAZAAR_NPC+ "brak" : 1, ]) );
}
