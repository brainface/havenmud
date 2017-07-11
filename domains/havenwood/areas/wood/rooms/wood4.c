//Updated 12/2015 by Aless
//Directions were wrong, Added items, adjectives, etc.

#include <lib.h>
#include "../wood.h"
#define ROAD "/domains/havenwood/virtual/havenwoodroad/155,155"
#define ARIKA_ROOM  "/domains/havenwood/areas/glen/rooms/path1"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetDomain("HavenWood");
  
  SetShort("on the fringes of the HavenWood");
  SetDayLong("This large forest is full of tall, colorful trees that seem to "
     "welcome travellers. A well-worn path continues to the east and the main "
     "Havenwood road is just to the west. The large, leafy boughs of the trees "
     "form a shady canopy from the sunlight and act as an archway of sorts leading "
     "to another path northeast.");
  SetNightLong("This large forest is full of tall, colorful trees that seem to "
     "welcome travellers. A well-worn path continues to the east and the main "
     "Havenwood road is just to the west. The large, leafy boughs of the trees "
     "form a shadowy canopy that filters the moonlight and act as an archway of "
     "sorts leading to another path northeast.");
  SetItems( ([
     ({ "forest", "havenwood" }) : (:GetLong:),
     ({ "tree", "trees", "trunk", "trunks" }) :
        "Though the trees come in all shapes and sizes, there is no doubt that "
        "this is an old forest. Thick trunks reach high up into the sky and their "
        "leafy boughs provide quite a bit of cover." ,
     ({ "bough", "boughs", "branch", "branches", "canopy", "arch", "archway" }) :
        "Large, leafy branches from each tree stretch out as if in greeting to one " 
        "another, forming a sort of canopy overhead that acts much as an archway "
        "to the northeastern path.",
     ({ "leaf" }) : 
        "There are so many and each is so similar to the last.",
     ({ "leaves" }) :
        "Much like the trees themselves, the leaves come in all shapes and sizes, "
        "each one very similar but uniquely its own. They leave the landscape awash "
        "in vibrant color.",
     ({ "path", "paths" }) :
        "A few paths diverge here, a well-worn path leads east while another leads "
        "northeast through an arch of boughs.",
     ({ "ground", "floor" }) :
        "The forest floor is littered with colorful leaves.",
     ({ "road" }) :
        "The main Havenwood road is visable just to the west.",
     ]) );
  SetItemAdjectives( ([
     "forest" : ({ "" }),  
     "tree" : ({ "large", "tall", "colorful" }),
     "bough" : ({ "leafy", "large", "shadowy", "shady" }),
     "leaves" : ({ "colorful", "small", "big", "large", "tiny", "vibrant" }),
     "path" : ({ "well-worn", "worn", "northeastern" }),
     "ground" : ({ "littered", "forest" }),
     "road" : ({ "west", "havenwood" }),
     ]) );
  SetExits( ([
     "west" : ROAD,
     "northeast" : HWD_ROOM + "/wood3",
     "east": ARIKA_ROOM,
     ]) );

}
