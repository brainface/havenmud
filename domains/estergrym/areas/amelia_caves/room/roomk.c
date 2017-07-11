// amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a dusty cavern's southern end");
   SetLong("This cavern is the melding of three tunnels, which come from "
           "the west, northeast, and south.  It is fairly dry here, and "
           "rather dusty, too.  Some cobwebs hang in the corners.");
   SetItems( ([
                ({ "dusty cavern","cavern" }) :
                   "The small, dust-powdered cavern is made from the "
                   "connection of three tunnels.",
                ({ "cavern dust","dust" }) :
                   "The fine and powdery dust "
                   "coats this cavern.",
                ({ "west tunnel","tunnel" }) :
                   "The west tunnel joins with the cavern to "
                   "the north.",
                ({ "northeast tunnel","tunnel" }) :
                   "The northeast tunnel joins with the cavern to the "
                   "north.",
                ({ "south tunnel","tunnel" }) :
                   "The south tunnel leads off into a more "
                   "chilled place.",
                ({ "corner cobwebs","corner cobweb","cobweb","cobwebs" }) :
                   "Dry and dusty, the shabby spider webs haven't held "
                   "up very well in this cavern.",
                ({ "cobweb corner","corner" }) :
                   "Dusty old cobwebs fill the corners.",
                ({ "three tunnels","tunnels" }) :
                   "Three tunnels meld into a cavern here.",
           ]) );
   SetExits( ([
                "south" : C_ROOM + "rooml",
                "north" : C_ROOM + "roomj",
           ]) );
   SetInventory( ([
                    C_NPC + "spider" : 2,
                    C_NPC + "lilbat" : 1,
               ]) );
}
 
