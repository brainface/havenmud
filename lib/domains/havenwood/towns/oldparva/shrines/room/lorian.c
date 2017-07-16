#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetTown("Parva");
   SetDomain("Havenwood");
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("a Lorian shrine");
   SetLong("The entire building is made of firm pine wood, with decorative murals "
           "formed in the walls using a combination of carving and painting.  "
           "Flowers and pine boughs line the edges of the building, and in the "
           "center of the room is a sparkling marble fountain.  There is an exit "
           "going out in the south wall.");
   SetItems( ([
                ({ "lorian shrine","shrine","building" }) : (: GetLong :),
                ({ "walls","murals","wall","mural","wood" }) :
                   "The walls are covered with engraved paintings that depict "
                   "Lorian life.  One mural displays a fortified village near "
                   "the WestWood, filled with similar buildings.  The people "
                   "are mostly muezzins, gelflings, and halflings, with a "
                   "few random other creatures involved.  Another wall displays "
                   "the Lorians on a crusade against the evil creatures of the "
                   "world, striking them down with lightning and ripping limbs "
                   "from their bodies.  Another wall shows the Lorians making "
                   "a peaceful agreement with Parva while in search for a haven "
                   "away from the Eclats in the WestWood.  The final wall "
                   "shows the Lorians ruling the world, and all other races involved "
                   "in their religion.",
                ({ "pine boughs and flowers","flowers","flower","bough","boughs" }) :
                   "Beneath the murals, around the edges of the building alone, " 
                   "are fresh pine boughs and flowers.  Nothing is wilted or "
                   "even dying.  Bright colors seem to radiate from the collection.",
                ({ "south wall","wall","exit" }) :
                   "The mural on the south wall shows the peaceful agreement between "
                   "Parva and the Lorians.  The mural works around the exit.",
           ]) );
   SetItemAdjectives( ([
                         "shrine" : ({ "lorian" }),
                         "walls" : ({ "decorative","firm","pine" }),
                         "boughs" : ({ "pine" }),
                    ]) );
   SetExits( ([
                "out" : P_ROOM + "/path",
           ]) );
   SetInventory( ([
                    PS_NPC + "/lorianpriest" : 1,
                    PS_OBJ + "/lorianfountain" : 1,
               ]) );
}
