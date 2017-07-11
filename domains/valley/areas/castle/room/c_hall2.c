#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(15);
   SetShort("dark hallway");
   SetLong("Low torches are mounted on either side of the hall, far "
           "apart from either of the openings.  To the east is a door "
           "and to the west is another basic opening, but both "
           "lead to the beds of the dead.  The hallway stretches to "
           "the north and south, growing very dark to the north, as "
           "there are no torches in that direction.");
   SetItems( ([
                ({ "hall openings","openings","opening" }) :
                   "The openings in the walls lead to the east and west, "
                   "but the east opening is filled by a door.  Both have "
                   "similar arch shapes to them and the same dark "
                   "presence.",
                ({ "low torches","torches","torch","low torch" }) :
                   "The torches struggle to cast light on this area, "
                   "but flame so low that they seem to be overcome by "
                   "darkness.",
                ({ "dark hallway","hallway","hall" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/c_hall3",
                "east"  : VC_ROOM + "/c_side4",
                "west"  : VC_ROOM + "/c_side3",
                "south" : VC_ROOM + "/c_hall1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/c_ghoul" : 1,
               ]) );
}
