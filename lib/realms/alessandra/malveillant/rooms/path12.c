/*   Portia  12-8-98
     The path to the inn.
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a muddy path");
 SetClimate("underground");
 SetExits( ([
   "northwest" : MAL_ROOMS + "center2",
   "north" : MAL_ROOMS + "path11",
   "west" : MAL_ROOMS + "path13",
   ]) );
 SetListen( ([
   "default" : "Much noise comes from the building.",
   ]) );
 SetSmell( ([
   "default" : "The odor of food is strong here.",
   ]) );
 SetInventory( ([
   MAL_NPC + "guard1" : 1,
   ]) );
 SetLong("This path appears to be used quite a bit and "
   "is therefore quite muddy. It is full of footprints and "
   "other signs of life. A large building lies to south. "
   "Next to the door there is a large carving in the obsidian "
   "wall. This building seems to be larger than any others on "
   "this level with the exception of the church.");
 SetItems( ([
   ({"path"}) : (:GetLong:),
   ({"footprints", "footprint", "signs", "signs of life"}) :
       "These footprints were not made by something very large.",
   ({"building", "inn"}) : "The large building appears to be an inn.",
   ({"door"}) : "The door to the inn appears to be open.",
   ({"carving"}) : "The large carving is the image of a rose.",
   ({"image", "rose"}) : "The rose is the symbol of the Soirin faith.",
   ({"wall"}) : "The large wall is made of obsidian.",
   ({"level"}) :"This is the lower level of Malveillant.",
   ({"church"}) : "The church is the largest building in Malveillant.",
   ]) );
 SetItemAdjectives( ([
   "path" : ({"muddy", "often used"}),
   "building" : ({"large"}),
   "door" : ({"large", "open"}),
   "carving" : ({"large"}),
   "wall" : ({"large", "obsidian"}),
   "level" : ({"lower"}),
   "church" : ({"large"}),
   ]) );
 SetEnters( ([
   "inn" : MAL_ROOMS + "inn.c",
   ]) );
 }
