#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetDayLight(-10);
   SetNightLight(-10);
   SetShort("at the gate");
   SetLong("To the south, a portcullis fills the space of this tunnel "
           "though the grand walls of the castle here.  Dark "
           "gray stones form the walls surrounding the area, pushing "
           "down on the very air that fills the tunnel.  The light "
           "brightens and the world opens up to the west.");
   SetItems( ([
                ({ "tunnel","castle","world" }) :
                   (: GetLong :),
                ({ "grand walls","dark gray stones","grand wall",
                   "wall","walls","dark stones","gray stones",
                   "dark stone","dark gray stone","gray stone",
                   "stones","stone","dark grey stones","dark grey stone",
                   "grey stone","grey stones" }) :
                   "The stones are fit together securely, all of a "
                   "fairly uniform shape but almost looking as if they "
                   "were part of a puzzle whose pieces didn't have "
                   "interlocking bits, but just wavy line edges.",
           ]) );
   SetExits( ([
                "west"  : VC_ROOM + "/gen_07",
                "south" : VC_ROOM + "/realent",
           ]) );
   SetInventory( ([
                    VC_NPC + "/guard_c" : 2,
               ]) );
}
