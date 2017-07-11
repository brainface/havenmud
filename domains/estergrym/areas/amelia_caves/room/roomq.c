// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a gnome's hole");
   SetLong("This small room, which is not very cozy, is the home "
           "of a 4 foot gnome.  A picture is pasted up on the "
           "western-most wall, and a pile of blankets lies in a "
           "corner.  Cobwebs hang from the ceiling."
           "  The walls seem to be of a slightly lighter, "
           "more soft rock.");
   SetItems( ([
                ({ "small room","room" }) :
                   "The room is fairly small, meant for a "
                   "gnome about 4 feet tall.",
                ({ "gnome home","home" }) :
                   "Yes, this is the gnome's home.",
                ({ "pile of blankets","blankets","blanket" }) :
                   "The blankets are old, worn, and dirty.",
                ({ "picture on the wall","picture" }) :
                   "The picture is so badly faded, it is impossible to "
                   "make out what it is of.",
                ({ "cobweb on ceiling","cobwebs on ceiling","cobwebs","cobweb" }) :
                   "The cobwebs are rather pretty in a creepy way.",
                ({ "light walls","light wall","wall","walls" }) :
                   "The walls are made of a lighter rock than "
                   "the surrounding caves.",
                ({ "cave rock","rock" }) :
                   "The rock is paler than that of the surrounding caves.",
           ]) );
   SetSmell( ([
                "default" :
                   "The room smells musty and old.",
           ]) );
   SetExits( ([
                "out" : C_ROOM + "rooml",
           ]) );
   SetInventory( ([
                    C_NPC + "gnome2" : 1,
               ]) );
}
