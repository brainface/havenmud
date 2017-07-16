/* with linguist and palace
 */
#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("before the palace");
  SetExits( ([
    "north" : "path11",
    "south" : "path9",
    ]) );
  SetLong("The Way of the Warrior ends here in front of one "
          "large and one small building.  Off to the south is "
          "the center of Tairi.  The large building to the east "
          "is obviously the Grand Palace of the Daimyo of Tairi, while "
          "the small building to the west has few distinct markings.  "
          "A small path leads north to the beach.");
  SetItems( ([
    ({ "way", "road" }) : 
    	    "The Way of the Warrior dirt beaten road ends here by the Grand "
    	    "Palace of the Daimyo and a small undistinguished building.",
    ({ "home", "building" }) : 
    	    "This is the home of the local linguist.",
    ({ "palace", "building" }) : 
    	    "This is the Grand Palace of the Daimyo, home to the master of "
    	    "Tairi.",
    ({ "center", "town", "tairi" }) :
    	    "The center of Tairi is south along the Way of the Warrior.",
    ({ "path", "beach" }) :
    	    "The small dirt path runs north to the beach.",
    ]) );
  SetItemAdjectives( ([
    "home"   : ({ "small", "undistinguished" }),
    "palace" : ({ "large", "grand", "daimyo" }),
    "way"    : ({ "dirt", "beaten" }),
    "path"   : ({ "small", "dirt" }),
    "center" : ({ "town", "tairi" }),
    ]) );
  SetEnters( ([
    "home" : TAI_RI_ROOM + "linguist",
    "palace" : TAI_RI_ROOM + "p4",
    ]) );
  SetSmell( ([
    "default" : "There is a faint smell of flowers here.",
    ]) );
  SetListen( ([
    "default" : "Sounds of life emanate from the palace.",
    ]) );
  SetInventory( ([
//     TAI_RI_NPC "citizen" : 1,
    ]) );
}
    
