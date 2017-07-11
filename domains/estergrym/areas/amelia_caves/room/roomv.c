// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a gnome's home");
   SetLong("This small room, which is not very cozy, is the home "
           "of a 4 foot gnome.  Up against one wall is a rickety "
           "bookshelf.  The walls seem to be of a slightly lighter, "
           "softer rock.");
   SetItems( ([
                ({ "small room","room" }) :
                   "The room is fairly small, meant for a "
                   "gnome about 4 feet tall.",
                ({ "gnome home","home" }) :
                   "Yes, this is the gnome's home.",
                ({ "rickety bookshelf","bookshelf" }) :
                   "The rickety bookshelf is, strangely enough, "
                   "bookless.",
                ({ "light walls","light wall","wall","walls" }) :
                   "The walls are made of a lighter rock than "
                   "the surrounding caves.",
                ({ "cave rock","rock" }) :
                   "The rock is paler than that "
                   "of the surrounding caves.",
           ]) );
   SetSmell( ([
                "default" : "The room smells musty and old.",
           ]) );
   SetExits( ([
                "north" : C_ROOM + "roomu",
           ]) );
   SetInventory( ([
                    C_NPC + "gnome3" : 1,
               ]) );
}
