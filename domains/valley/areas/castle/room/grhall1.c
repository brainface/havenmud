#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("Great Hall");
   SetLong("The stonework of the walls was simple, with fairly uniform "
           "blocks stacked high and pasted together with a grayish "
           "mortar.  Beams of wood help support the structure, so that "
           "rocks alone might not be responsible for the safety of those "
           "under this roof.  Animal skins from various conquests of the "
           "castle's Lord have been spread out on the wall, and paintings "
           "of his relatives, and likely himself, have also been posted "
           "on the stones.  To the west, the room continues in all its "
           "grandness, while a large archway exists to the north, leading "
           "into the hall.  A small door is in the eastern wall.  Torches "
           "light the room from positions on the walls.");
   SetItems( ([
                ({ "large archway","large arch","arch","archway" }) :
                   "The archway creates an exit heading out "
                   "into the hall just north of here.  Its curving "
                   "design pushes the rocks employed in building it "
                   "against each other, causing the structure to be "
                   "more secure than a simple square doorway.",
                ({ "great hall","hall","castle","structure" }) : 
                   (: GetLong :),
                ({ "stone walls","stonework","stone","stones",
                   "stone wall","wall","walls","uniform blocks",
                   "fairly uniform blocks","grayish mortar",
                   "beams of wood","roof","animal skins","paintings",
                   "fairly uniform block","uniform block","block",
                   "blocks","rock","rocks","wooden beams","beams",
                   "wood","beam","wooden beam","beam of wood",
                   "animal skin","skin","skins","painting","mortar",
                   "torches","torch" }) :
                   "The walls are made of stones, fit together with a "
                   "mortar of grayish color, with wooden beams aiding in "
                   "the support of the roof.  Animal skins and paintings "
                   "cover the walls decoratively.  Torches are placed "
                   "at similar intervals along the wall, lighting the "
                   "Great Hall.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/hall1",
                "west" : VC_ROOM + "/grhall2",
                "east" : VC_ROOM + "/stair1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/guest" : random(6)+5,
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
