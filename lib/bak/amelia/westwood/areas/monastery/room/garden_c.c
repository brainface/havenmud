#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("in a garden");
   SetDomain("WestWood");
   SetLong("Rose bushes line the walls to the north and west, blooming "
           "with brillant roses in various colors.  Around their bases "
           "is rich dirt, moist and dark, blocked off from the grassy "
           "ground by some plain rocks arranged in rows.  The garden "
           "is open to the east and south, allowing passage.");
   SetItems( ([
                ({ "eclat garden","eclatish garden","garden" }) :
                   (: GetLong :),
                ({ "rose bushes","rose bush","bush","bushes","roses",
                   "brillant roses","brillant rose","rose",
                   "yellow roses","red roses","white roses",
                   "black roses","yellow rose","red rose","white rose",
                   "black rose" }) :
                   "Yellow roses and red roses and white roses and "
                   "even a few black roses grace the rose bushes that "
                   "line the walls.",
                ({ "stone walls","stone wall","walls","wall",
                   "stone" }) :
                   "The stone walls are to the north and west, "
                   "lined with rose bushes.  They extend to the south "
                   "and east.",
                ({ "rich dirt","dirt","growing space","space" }) :
                   "The dirt is loose and rich, providing wonderful "
                   "growing space for the rose bushes.",
                ({ "grassy ground","ground","grass","soft grass" }) :
                   "Grass grows on the ground outside the "
                   "rock barriers, leading the way on its soft "
                   "path to the east and south.",
                ({ "plain rocks","plain rock","rock","rocks",
                   "rock barriers","rock barrier","barriers",
                   "barrier" }) :
                   "The rocks line up between the rich dirt and the "
                   "soft grass, preventing the grass from taking over "
                   "the space reserved for rose bushes.",
           ]) );
   SetListen( ([
                 "default" : "It's almost as if one could hear the grass "
                    "grow in the peaceful silence here.",
            ]) );
   SetSmell( ([
                "default" : "The roses fill the air with their "
                   "smells.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "garden_d",
                "south" : M_ROOM + "garden_a",
           ]) );
   SetInventory( ([
                    M_NPC + "gardener" : 1,
                    M_NPC + "monk_h" : random(4)+1,
                    M_NPC + "monk_j" : 2,
                    M_NPC + "trav_wor" : 2+random(2),
               ]) );
}
