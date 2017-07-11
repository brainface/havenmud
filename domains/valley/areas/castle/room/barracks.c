#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

int StopExit();

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(28);
   SetShort("in the barracks");
   SetLong(
     "The damp light inside the barracks is soft and yet somehow "
     "seems particularly harsh and demanding. A large trap door "
     "is in the floor, probably leading to the bunks that the "
     "Lord's army may sleep in and gain some precious rest. "
     "a couple torches speckle the north and south walls, but "
     "to the east and west, there are no lights. There are doors to "
     "the north and west."
   );
   SetItems( ([
                ({ "stone walls","stone wall","north wall","south wall",
                   "wall","walls","west wall","east wall","torches",
                   "torch" }) :
                   "The torches flicker darkly from the north and south "
                   "walls, casting not much light upon these stone walls. "
                   "Doors are in the west and north walls, and torches on "
                   "the north and south ones.",
                ({ "large trap door","large door","trap door","door",
                   "floor" }) :
                   "The door is set into the floor solidly, protecting "
                   "the privacy of the army.",
                ({ "barracks" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/gen_10",
                "west"  : VC_ROOM + "/tower_3a",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 8,
               ]) );
}

int StopExit() {
   message("system","The trap door blocks your way, and refuses to open.",
           this_player());
   return 0;
}
