#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("a warm room");
   SetLong("A shining tapestry covers the north wall, depicting some "
           "imaginary battle between a man and a dragon.  A similarily "
           "beautiful rug garnishes the floor, covering many of the pale "
           "gray stones and keeping the room cheerily warm.  A grand door"
           "is in the south wall, and another door, aslo quite opulent, "
           "is in the western one.  An open doorway leads to the east.");
   SetItems( ([
                ({ "shining tapestry","tapestry","north wall","wall",
                   "imaginary battle","battle","man","dragon",
                   "picture" }) :
                   "The colors of the tapestry are unusually clear, "
                   "and the work quite detailed.  It appears as if the "
                   "man and the dragon are fighting violantly; the "
                   "picture almost comes alive.",
                ({ "beautiful rug","rug","floor","pale gray stones",
                   "pale gray stone","pale stones","pale stone",
                   "gray stones","gray stone","stone","stones" }) :
                   "The rug is a gorgeous color, thick and warm in the "
                   "cold atmosphere of the stones and castle.",
                ({ "open doorway","doorway","open door","door" }) :
                   "The door leads into a room to the east, where some "
                   "orange light seems to be flickering, "
                   "probably from some sort of fire.",
                ({ "warm room","room","castle" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "east"  : VC_ROOM + "/llroom3",
                "south" : VC_ROOM + "/hall4",
                "west"  : VC_ROOM + "/llroom1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/lady" : 1,
               ]) );
}
