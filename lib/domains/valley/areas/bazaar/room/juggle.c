/* This is a simple room where a juggling jester is performing. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a clearing");
  SetLong("This is a grassy clearing surrounded by booths. "
     "Most of the grass has been trampled by the "
     "traffic and entertainers. A large tree is visible to "
     "the west, while the ticket booth is back to the east.");
  SetSmell( ([
     "default" : "The smell of food mixes with the fresh air.",
  ]) );
  SetListen( ([
     "default" : "You hear loud laughter and distant shouting.",
  ]) );
  SetItems( ([
   ({ "grass" }) : "The grass covering the ground has been trampled.",
   ({ "tree" }) : "A very large tree is west of here.",
   ({ "clearing" }) : (: GetLong :),
   ({ "booth", "booths" }) : "There are various places to shop in several directions.",
  ]) );
  SetItemAdjectives( ([
   "grass" : ({ "trampled" }),
   "clearing" : ({ "grassy" }),
   "tree" : ({ "large" }),
  ]) );
  SetExits( ([
     "north" : BAZAAR_ROOM "empty",
     "west" : BAZAAR_ROOM "tree",
     "east" : BAZAAR_ROOM "booth",
     "south" : BAZAAR_ROOM "trinket",
  ]) );
  SetInventory( ([ BAZAAR_NPC "juggler.c" : 1, ]) );

}
