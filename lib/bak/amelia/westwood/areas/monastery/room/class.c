#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("inside a classroom");
   SetDomain("WestWood");
   SetLong("A couple benches lead up to the podium at the front "
           "of the room, each bench sitting under a different picture "
           "that is painted on to the wall.  The floor is slightly "
           "dirty; some of the debris of the forest has been tracked "
           "in and not swept up.  An open area in the eastern wall "
           "leads outside.");
   SetItems( ([
                ({ "eclat classroom","classroom","room","class",
                   "wood" }) :
                   (: GetLong :),
                ({ "wooden benches","wooden bench","benches","bench",
                   "wood" }) :
                   "The benches are plain and unadorned, being simply "
                   "one long piece of wood stacked on two stumps.  "
                   "There are about three of them total, lined up "
                   "in front of the podium.",
                ({ "bench stumps","bench stump","stumps","stump",
                   "wood" }) :
                   "The stumps are small, but hold the benches up "
                   "off the ground efficiently.  There is one on each "
                   "end of each bench.",
                ({ "long pieces of wood","long piece of wood","pieces of "
                   "wood","piece of wood","long pieces","long piece",
                   "pieces","piece","wood" }) :
                   "The long pieces of wood are balanced on two "
                   "stumps each, making up the sitting area for the "
                   "benches.",
                ({ "wooden podium","podium","wood","raised area",
                   "area" }) :
                   "The podium is a raised area in the front of the room, "
                   "probably for the teacher to stand on so the students "
                   "can see what is going on.",
                ({ "wall murals","mural","wall mural","murals",
                   "walls","wall","painting","paintings","pictures",
                   "picture","writing" }) :
                   "Above each end of the benches is another section of "
                   "some lesson painted on the walls.  Some writing done "
                   "in oiseau covers the pictures.",
                ({ "dirty floor","floor","dirt","forest debris",
                   "debris","dust","small twigs","small twig",
                   "twigs","twig","dried up leaves","dried up leaf",
                   "dried leaves","dried leaf","leaves","leaf" }) :
                   "Dirt and dust and a few small twigs and dried up "
                   "leaves decorate the dirty floor.",
           ]) );
   SetListen( ([
                 "default" : "Jovial laughter can be heard from outside.",
            ]) );
   SetSmell( ([
                "default" : "The smells of stirred up dust drift "
                   "through the room.",
           ]) );
   SetExits( ([
                "out" : M_ROOM + "plat_d",
           ]) );
   SetInventory( ([
                    M_NPC + "teach_g" : 1,
                    M_NPC + "teach_k" : 1,
                    M_NPC + "student" : 3+random(4),
               ]) );
}
