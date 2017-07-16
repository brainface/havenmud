// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide(
    "north",
    ([ "id" : ({
      "north door","northern door", "door"
    }),
    "short" : "a stained-glass door",
    "long" : "This stained-glass door is made up of colorful plates of "
      "glass. When light shines through the plates, a beautiful pattern of "
      "colors is projected on nearby surfaces. It has shiny gold doorknobs "
      "that look recently polished.",
    "lockable" : 0,
  ]) );

  SetSide(
    "south",
    ([ "id" : ({
      "south door","southern door", "door"
    }),
    "short" : "a stained-glass door",
    "long" : "This stained-glass door is made up of colorful plates of "
      "glass. When light shines through the plates, a beautiful pattern of "
      "colors is projected on nearby surfaces. It has shiny gold doorknobs "
      "that look recently polished.",
    "lockable" : 0,
  ]) );

  SetClosed(1);
}

/** Approved by Laoise at Sun May 21 17:03:23 2006. **/