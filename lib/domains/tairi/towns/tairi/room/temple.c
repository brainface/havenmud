// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../tairi.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetShort("The Taisoka Temple entrance");
  SetExits( ([
    "out" : "path8",
    "up" : "lvl2",
          ]) );
  SetClimate("indoors");
  SetAmbientLight(30);
  SetLong("The entrance to the temple is lined with hanging flowers, "
          "and opens into a large spacious garden. Everywhere you "
          "look there is life and energy.  Small paths weave in and "
          "out of the gardens making a catacombs.  Oddly, there is "
          "warmth here which does not seem to have any noticible source.  "
          "A wooden staircase leads up into the temple from the center "
          "of the garden.");
  SetItems( ([
    ({ "entrance", "temple" }) :
    	 (: GetLong :),
    ({ "flowers" }) : 
    	 "The flowers are soft and delicate.  They are the colour of light pastels.",
    ({ "wall", "walls", "plants", "ceiling" }) : 
    	 "The walls are lined with large leafy plants that run up the walls and "
    	 "to the ceiling",
    ({ "garden", "area" }) : 
    	 "This is a large garden containing every plant imaginable.",
    ({ "path", "paths" }) : 
    	 "The paths are made up of hard cobble stone sand.",
    ({ "staircase" }) :
    	 "A wooden staircase leads up from the center of the garden.",
    ]) );
  SetItemAdjectives( ([
    "flowers" : ({ "hanging" }),
    "garden"  : ({ "large", "spacious" }),
    "path"    : ({ "small" }),
    "plants"  : ({ "large", "leafy" }),
    ]) );
  SetReligion("Taisoka");
  SetInventory( ([
        TAI_RI_NPC "cleric" : 1,
    ]) );
  SetSmell( ([
    "default" : "The scent of strong incense hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "Repeating chants cling to the temple's atmosphere.",
    ]) );
}
