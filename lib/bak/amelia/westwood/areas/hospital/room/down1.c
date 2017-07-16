#include <lib.h>
inherit LIB_ROOM;
#include "../hospital.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(5);
   SetShort("on the lower floor of a hospital");
   SetLong("The lights have been dimmed here using special balls that "
           "set themselves to making whatever room they are created in "
           "dark for those who can't see well in the light.  The walls "
           "are still white and so is everything else, and a gentle "
           "ramp goes up into brighter areas for other patients.");
   SetItems( ([
                ({ "eclat hospital","hospital","room" }) :
                   (: GetLong :),
                ({ "special balls","balls","ball" }) :
                   "The balls here absorb light to make it dark for the "
                   "patients who cannot see in the light.  They could "
                   "be set to create light also, but for a place like "
                   "this, they just remove light from the air.  They "
                   "are set up near the ceiling, hanging on the wall.",
                ({ "white walls","walls","wall","ceiling","floor" }) :
                   "The white walls shine cleanly, will dark balls "
                   "hanging from them near the ceiling to make the "
                   "hospital dark here.",
                ({ "gentle ramp","ramp" }) :
                   "The ramp slopes at a gentle angle, leading up into "
                   "a bright world above.  It probably isn't hard to "
                   "help patients up and down it.",
                ({ "bright world","world","areas","area" }) :
                   "Up the ramp is an area where there is a lot more "
                   "light.  It is mostly for those who can see well "
                   "at such frequencies.",
           ]) );
   SetItemAdjectives( ([
                         "balls" : ({ "special","dark","darkness" }),
                         "walls" : ({ "white","clean" }),
                         "areas" : ({ "bright","brighter" }),
                    ]) );
   SetInventory( ([
                    H_NPC + "patientd" : 3,
                    H_NPC + "doc_c" : 1,
               ]) );
   SetExits( ([
                "up" : H_ROOM + "r5",
           ]) );
}
