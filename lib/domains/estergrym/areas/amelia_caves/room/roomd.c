// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("the mice burrow");
   SetLong("The ground here is fairly dark and rough, and there "
           "isn't much space to manuver in as the ceiling is low.  "
           "The cave tapers off to a small crack to the west.");
   SetItems( ([
                ({ "dark ground","rough ground","ground" }) :
                   "The ground is rough and unfinished.",
                ({ "low ceiling","ceiling" }) :
                   "Dark gray rock makes up the low ceiling.",
                ({ "dark gray rock","dark rock","gray rock","rock" }) :
                   "The dark gray rock makes up the entire room.",
                ({ "small crack","crack" }) :
                   "This cave ends as a small crack, too small to look "
                   "through.",
           ]) );
   SetExits( ([
                "southwest" : C_ROOM + "roomb"
           ]) );
   SetInventory( ([
                    C_NPC + "mouse" : 5
               ]) );
}
