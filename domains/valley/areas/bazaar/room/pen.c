/* Here is a petting zoo for small children. */
#include <lib.h>
#include <std.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a petting zoo");
   SetLong("This small pen looks as if it might be able to hold several "
     "animals. The ground is a little muddy, and there are quite a "
     "few different footprints on the ground. There is a hill to "
     "the north, and a large swing of some kind to the south.");
  SetItems( ([
   ({ "pen" }) : (: GetLong :),
   ({ "ground" }) : "It is muddy and covered in footprints.",
   ({ "footprint", "footprints" }) : "There are footprints of several kinds of animals.",
   ({ "hill" }) : "A grassy hill is visible to the north",
   ({ "swing" }) : "A massive wooden structure stands to the south.",
  ]) );
  SetItemAdjectives( ([
   "pen" : ({ "small" }),
   "footprint" : ({ "different" }),
   "swing" : ({ "large" }),
  ]) );
  SetSmell( ([
     "default" : "It smells like farm animals here.",
  ]) );
  SetListen( ([
     "default" : "You hear laughter drifting in from all around and an occasional animal noise.",
  ]) );
  SetInventory( ([
    STD_NPC "cow" : random(3),
    STD_NPC "donkey" : random(3),
    STD_NPC "pig" : random(3),
    STD_NPC "goat" : random(2)+2,
  ]) );
  SetExits( ([
     "north" : BAZAAR_ROOM "hill",
     "south" : BAZAAR_ROOM "swing",
  ]) );
}

