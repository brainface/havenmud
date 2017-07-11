// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a moldy tunnel");
   SetLong("In this section of the tunnel, a peculiar moss has grown up "
           "the walls and across the floor, probably flourishing in the "
           "strangely warm air here, or maybe some of the strange bugs "
           "that are flying around.  It has created a soft carpet "
           "for one to walk upon, but fades off in all the obvious exits: "
           " north, east, and down through a small hole.");
   SetItems( ([
                ({ "tunnel section","section of tunnel","tunnel" }) :
                   "Warm, dry air has made a strange moss flourish in "
                   "this section of the cave.",
                ({ "peculiar moss","moss" }) :
                   "The moss is a peculiar green-blue color.",
                ({ "small hole","hole","down","exit" }) :
                   "The moss seems to fade out farther down the tunnel.",
                ({ "moss carpet","carpet","soft carpet" }) :
                   "A soft, springy mold makes the carpet.",
                ({ "moss covered wall","moss covered walls","wall","walls" }) :
                   "Moss has made it part way up all the walls of this "
                   "tunnel",
                ({ "moss covered floor","floor" }) :
                   "A strange green-blue moss has completely covered the "
                   "floor, not a bit reveals itself from underneath.",
                ({ "strange bugs","strange bug","bug","bugs" }) :
                   "The fruit-fly like bugs seem to be everywhere, as "
                   "they fly around in large numbers, as well as seem "
                   "to be of a greater-than-average size.",
           ]) );
   SetSmell( ([
                "default" : "A strange smell fills the air.",
                ({ "moss carpet","moss","peculiar moss" }) :
                   "The strange moss smells dry and musty.",
           ]) );
   SetExits( ([
                "north" : C_ROOM + "roomf",
                "east" : C_ROOM + "roomj",
                "down" : C_ROOM + "roomo",
           ]) );
   SetInventory( ([
                    C_NPC + "fly.c" : 3,
               ]) );
}
