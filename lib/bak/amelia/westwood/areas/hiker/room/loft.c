#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(20);
   SetShort("in the loft");
   SetLong("The floor is bare with sandy dirt scattered across it in "
           "little lines.  It seems as if few people ever journey to "
           "this peculiar room.  It is not large, and its size "
           "is even more greatly diminished by the slanting ceiling.  "
           "A ladder heads down from here.");
   SetItems( ([
                ({ "peculiar room","room","loft" }) :
                   (: GetLong :),
                ({ "bare floor","floor" }) :
                   "The only thing on the floor is the dirt that "
                   "somehow adds a sense of desolate charector to it.  "
                   "It's like the room is stranded, in the middle of a "
                   "desert, where nothing occurs.",
                ({ "sandy dirt","dirt","sand","little lines","line",
                   "little line","lines","miniature dunes","dunes",
                   "miniature dune","dune" }) :
                   "The dirt is not evenly spread across the floor, but "
                   "has gathered into miniature dunes on the bare floor.",
                ({ "slanting ceiling","ceiling" }) :
                   "The ceiling slants towards a central point in the "
                   "middle.  It is plain and bare.",
                ({ "wooden ladder","ladder" }) :
                   "The ladder is old and wooden, with signs of greying "
                   "age in it.  It heads down.",
           ]) );
   SetListen( ([
                 "default" : "All is quiet.",
            ]) );
   SetExits( ([
                "down" : H_ROOM + "cabin",
           ]) );
   SetProperty("no magic",1);
   SetProperty("no teleport",1);
   SetProperty("no attack",1);
   SetProperty("no bump",1);
   SetProperty("no steal",1);
}
