// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a small tunnel");
   SetLong("The tunnel seems much more dry and dusty here, with small "
           "cobwebs hanging in the corners and large bumps in the "
           "floor.");
   SetItems( ([
                ({ "dry and dusty tunnel","small tunnel","tunnel",
                   "dry tunnel","dusty tunnel" }) :
                   "The tunnel here is made of a dark, dry rock that seems "
                   "to be fairly solid.",
                ({ "dark dry rock","dry rock","dark rock","rock" }) :
                   "The dark rock composes the tunnel here.",
                ({ "tunnel dust", "dust" }) :
                   "A fine, powder-like dust can be seen speckled across "
                   "the floor.",
                ({ "small cobwebs","small cobweb","cobwebs","cobweb" }) :
                    "The cobwebs have faired fairly well in this section "
                    "of the tunnel, but some seem to have fallen apart.",
                ({ "cobweb corner","corner" }) :
                   "The cobwebs are fairing rather well in this corner, "
                   "but some remain slightly tattered and worn through.",
                ({ "large bumps","large bump","bumps","bump" }) :
                   "Irregularities in the ground have made the floor "
                   "rather bumpy around here.",
                ({ "bumpy floor","floor","ground" }) :
                   "The large bumps make the floor rough and irregular.",
           ]) );
   SetExits( ([
                "west" : C_ROOM + "roomb",
                "south" : C_ROOM + "roomi",
           ]) );
   SetInventory( ([
                    C_NPC + "rat" : 2,
                    C_NPC + "spider" : 2,
               ]) );
}
