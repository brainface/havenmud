#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("a large room");
   SetLong("Walls surround in all directions save east, "
           "where the room continues on.  An arch opens to the "
           "south, and doors are in the north and west walls.  The "
           "north door is fairly grand, while the western one seems "
           "rather plain.");
   SetItems( ([
                ({ "large room","room","castle","hall" }) :
                   (: GetLong :),
                ({ "large archway","large arch","arch","archway",
                   "great arch","great archway","grand hall","hall" }) :
                   "The archway creates an exit heading "
                   "into the grand hall just south of here.  Its curving "
                   "design pushes the rocks employed in building it "
                   "against each other, causing the structure to be "
                   "more secure than a simple square doorway.",
                ({ "stone walls","stone wall","wall","walls",
                   "north wall","west wall","south wall","gray stones",
                   "gray stone","grey stones","grey stone","stone",
                   "stones","wooden beams","wood beams","beams",
                   "wooden beam","wood beam","beam","wood",
                   "heavy rocks","heavy rock","rock","rocks" }) :
                   "Gray stones make up the walls, and all the rest of "
                   "this castle, save the wooden beams that "
                   "add extra support to the heavy rocks.  In the north "
                   "wall there is a rather opulent door, while in the "
                   "west wall a plain door is found.  The south wall "
                   "contains a great arch.  The east wall is "
                   "non-existent, as the room continues on.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/dining",
                "south" : VC_ROOM + "/grhall1",
                "east"  : VC_ROOM + "/ent",
                "west"  : VC_ROOM + "/hall2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/servant" : 2,
                    VC_NPC + "/slave_f" : random(2),
               ]) );
}
