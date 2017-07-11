


#include <lib.h>
#include "../bathhouse.h"

inherit LIB_ROOM;

static void create() {
 room::create();
 SetTown("Parva");
 SetClimate("indoors");
 SetAmbientLight(30);
 SetShort("the steam filled bathing room");
 SetLong(
    "A huge cloud of steam is hovering over the bath like some abyssmal miasma "
    "making it hard to see. Off to the left there is a small steam covered "
    "porthole style window. The ceiling houses a few vents, which obviously "
    "are malfunctioning. In the center of the room is one large communal bath "
    "surrounded by a wooden walkway. Along the southern wall, towels hang from "  
    "pegs similar to those in the changing room. The doorway leading south to "
    "the changing rooms looks rather inviting."
  );
 SetItems( ([
    ({ "water","baths", "bath" }) :
    "The water looks less than fresh, having a slightly brown hue, but the "
    "sporadically spaced soap bubbles give the impression that this would be "
    "a suitable place to wash away the dirt and grim from a long day of "
    "travelling.",
    ({ "ceiling", "vent", "vents" }) :
    "Nestled nicely into the woodworking of the ceiling are two metallic vents. "
    "Considering the large amount of steam in the room, the vents apparently are "
    "out of order.",
    ({ "window", "porthole" }) :
    "If only the window was not so foggy, perhaps you could see a tree through it.",
    ({ "door", "doorway" }) :
    "The doorway is made of wood, just like the rest of the building, and leads "
    "south to the changing rooms.",
    ({ "pegs", "towels", "peg", "southern wall" }) :
    "The southern wall has been adorned with wooden pegs so that the customers can "
    "hang their towels while they bathe.",
    ({ "cloud", "steam", "miasma" }) :
    "Foggy white steam has filled the room, giving everything an off-white color.",
    ({ "walkway", "way" }) :
    "The wooden walkway surrounds the baths. The path is a bit slippery, but "
    "careful navigation and foot work will make walking around the baths a "
    "pleasant experience.",
  ]) );

 SetItemAdjectives( ([
    "pegs" : ({ "wooden", "wood" }),
    "peg" : ({ "wooden", "wood" }),
    "vent" : ({ "metallic" }),
    "door" : ({ "south", "southern" }),
    "walkway" : ({ "wooden", "wood" }),
    "window" : ({ "foggy", "steamy", "porthole" }),
    "vents" : ({ "metallic" }),
    "water" : ({ "steamy", "bubbling", "hot" }),    
  ]) );
 SetSmell( ([
    "default" : "A pungent odor of lilacs and other herbs effectively mask "
    "the scent of the city here.",
    "water" : "The water smells of liliac and other herbs.",
  ]) );
 SetListen( ([
    "default" : "The bubbling water provides a relaxing ambient sound.",
    "water" : "The water bubbles rhythmically.",
  ]) );
 SetExits( ([
    "south" : BH_ROOM + "changingroom",
  ]) );
 SetInventory( ([
    BH_NPC + "boy" :1,
  ]) );
}
