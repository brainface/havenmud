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
           "of a 4 foot gnome.  In one corner lies its bed, and in "
           "another a little desk made for someone of small "
           "stature.  The walls seem to be of a slightly lighter, "
           "more soft rock.");
   SetItems( ([
                ({ "small room","room" }) :
                   "The room is fairly small, meant for a "
                   "gnome about 4 feet tall.",
                ({ "gnome home","home" }) :
                   "Yes, this is the gnome's home.",
                ({ "gnome bed","bed" }) :
                   "The bed is nicely made.  Some people could "
                   "probably learn from this gnome's example.",
                ({ "little desk","desk" }) :
                   "The desk is neatly arranged.",
                ({ "light walls","wall","walls","light wall" }) :
                   "The walls are made of a lighter rock than "
                   "the surrounding caves.",
                ({ "soft rock","light rock","rock" }) :
                   "The rock is paler than that of the "
                   "surrounding caves.",
           ]) );
   SetSmell( ([
                "default" :
                   "The room smells musty and old.",
           ]) );
   SetExits( ([
                "out" : C_ROOM + "roomn",
           ]) );
   SetInventory( ([
                    C_NPC + "gnome1" : 1,
               ]) );
}
