
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("northwest, east");
  SetShort("at a turn in a cave");
  SetLong(
          "The tunnel bends to the northwest from here proudly "
          "displaying the same usual sights. Packed blackened clay "
          "composes the ground with the ceiling high above it. "
          "The walls are not secure, but loose "
          "with chunks of soft soil which are still supporting "
          "the cave ceiling.");
  SetInventory( ([ 
                    TOWER_NPC "wcorpse" : 1
                     ]) );
  SetExits( ([
            "northwest" : TOWER_ROOMS "cave04",
            "east"      : TOWER_ROOMS "cave02",   
           ]) );
  SetSmell( ([
            "default" : "It smells strong of raw, wet soil.",
           ]) );
  SetListen( ([
            "default" : "Soft noises are heard deeper into the cave."
           ]) );
  SetItems( ([
     "ceiling" : "The ceiling rises in this portion of the tunnel "
                 "upward, almost like a large foyer. It almost "
                 "appears flat.",
     "puddles" : "The puddles litter the floor by the walls. They "
                 "get their water from the slow leak from the soil "
                 "walls.",
     "walls"   : "The walls are made of a dark soil, they are very wet "
                 "and appear to collapse from holding too much water.",
     "clay"    : "It is moist and almost solid grounding, it looks "
                 "almost plush.",
    ({ "ground", "floor" }) : "Packed blackened clay composes the floor "
                               "in the tunnel, looking worse deeper into "
                               "the cave.",
     "soil"  : "The soil looks soft and beaten, as "
               "if something is draining its very being.",
              ]) );
  SetItemAdjectives( ([
    "ceiling" : ({ "flat" }),
    "puddles" : ({ "soil" }),
    "walls" : ({ "dark","soil","wet" }),
    "ground" : ({ "clay" }),
    "soil" : ({ "soft" }),
  ]) ); 
 }
