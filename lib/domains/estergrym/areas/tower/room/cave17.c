
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("southwest, southeast, north");
  SetShort("a fork in the cave");
  SetLong(
          "The tunnels to the south combine into a single "
          "tunnel that leads to the north toward a faint "
          "light. Large rocks line the eastern and western "
          "walls resting next to eachother. The black "
          "clay floor bends in three directions with the "
          "tunnels.");
  SetInventory( ([ 
                 TOWER_NPC "wcorpse" : 2, 
				  ]) );
  SetExits( ([
            "southwest"     : TOWER_ROOMS "cave15",
            "southeast"     : TOWER_ROOMS "cave16",
            "north"         : TOWER_ROOMS "cave18",
           ]) );
  SetSmell( ([
            "default" : "A hint of blood can be smelt.",
           ]) );
  SetListen( ([
            "default" : "A slight breeze whistles from the north."
           ]) );
  
  SetItems( ([
     "ceiling" : "The ceiling has been rounded and smoothened slightly "
                 "bending off into the tunnels.",
     "walls"   : "The walls have been smoothened and flattened somewhat "
                 "providing space for travel. Large rocks line the east "
                 "and west walls.",
     "tunnels" : "They bend off in three directions, north, southwest and "
                 "southeast.", 
    ({ "ground", "floor" }) : "It is made of a dark packed clay and "
                               "lines the cavern ground.",
    ({ "rocks" }) : "Large rocks line the east and western "
                    "walls and lead north. They are of equal "
                    "to a teenage human child in size.",
    ({ "light" }) : "A faint triangular light shines quite "
                    "a distance to the north.",
	"rock" : "The large rock is black in color and rests next to "
	         "a similar rock. It border the walls.",
	"clay" : "It is black with darker specks of rock in it.",
              ]) );
  SetItemAdjectives( ([
    "rocks" : ({ "large","black" }),
    "light" : ({ "faint" }),
    "rock" : ({ "large","black","" }),
    "clay" : ({ "dark","specks","rock" }),
  ]) ); 
 }
