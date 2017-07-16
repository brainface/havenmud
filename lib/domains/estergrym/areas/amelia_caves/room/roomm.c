// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("on the stream banks");
   SetLong("The stream turns more gentle here, after its descent from "
           "above.  It continues in a southward direction, gaining "
           "more speed the farther it heads.  The banks seem to "
           "widen, also.");
   SetItems( ([
                ({ "gentle stream","stream" }) :
                   "The stream's gentle waters continue their "
                   "everlasting movement.",
                ({ "stream water","water","stream waters","waters" }) :
                   "The water is dark and murky.",
                ({ "stream banks","stream bank","bank","banks" }) :
                   "The stream has ground away at the stone, "
                   "creating a rather sizely tunnel.  However, now "
                   "less water flows through, making the river smaller"
                   " than the tunnel.",
                ({ "ground stone","stone" }) :
                   "The stone of this tunnel has been gently fashioned "
                   "by the stream years ago when more water flowed "
                   "through here.",
                ({ "sizely tunnel","stream tunnel","tunnel" }) :
                   "The tunnel was created long ago by the waters of "
                   "stream.",
            ]) );
   SetListen( ([
                 "default" : "The water splashes around you.",
            ]) );
   SetInventory( ([
                    C_NPC + "dogfish" : 3,
                    C_NPC + "trout" : 1,
                    C_NPC + "catfish" : 1,
               ]) );
   SetExits( ([
                "up" : C_ROOM + "roomh",
                "south" : C_ROOM + "roomo",
           ]) );
}
