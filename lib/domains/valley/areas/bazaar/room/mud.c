/* This is a mud pit for people to play around in. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a mud pit");
  SetLong("Here is a watery mud pit that looks like it might "
     "have been made especially for wrestling in. The thick "
     "mud oozes all over the ground, making a general mess. "
     "There is also a large tub of water off to one side for "
     "rinsing off with. You can see the food booth over to the "
     "northeast.");
  SetItems( ([
   ({ "pit" }) : "It is several yards in length and width and is at least three feet deep.",
   ({ "mud" }) : "The mud is thick and smooth. There are very few pebbles mixed in with it.",
   ({ "ground" }) : "The ground is covered in thick, dark mud.",
   ({ "tub" }) : "It is about 5 feet in diameter and it is full of crystal clear water.",
   ({ "water" }) : "It mysteriously stays clean no matter how much mud is washed off in the tub.",
  ]) );
  SetItemAdjectives( ([
   "pit" : ({ "mud", "water" }),
   "mud" : ({ "thick" }),
   "tub" : ({ "large" }),
   "water" : ({ "crystal", "clear" }),
  ]) );
  SetSmell( ([
     "default" : "It smells like a mixture of dirt and food here."
  ]) );
  SetListen( ([
     "default" : "You can hear people laughing and yelling."
  ]) );
  SetExits( ([
     "north" : BAZAAR_ROOM "swing",
     "east" : BAZAAR_ROOM "table2",
     "northwest" : BAZAAR_ROOM "bet",
  ]) );
}
