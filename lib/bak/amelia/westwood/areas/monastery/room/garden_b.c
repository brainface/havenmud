#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("in a garden");
   SetDomain("WestWood");
   SetLong("A lot of shorter flowers grow in front of blooming bushes "
           "which are pressed up against the stone walls to the east and "
           "south.  The land is open to the north and west, where the "
           "garden continues with soft grass as a carpet.  Some rocks, "
           "lain so that they cut into the earth, block the grass from "
           "invading into the area for flowers and bushes.");
   SetItems( ([
                ({ "eclat garden","eclatish garden","garden" }) :
                   (: GetLong :),
                ({ "shorter flowers","shorter flower","flower","flowers",
                   "short flowers","short flower","blooming bushes",
                   "blooming bush","bushes","bush" }) :
                   "The flowers bloom in front the bushes, which also "
                   "flower abundantly.  There is a lot of variety "
                   "present with the bushes and flowers.",
                ({ "stone walls","stone walls","walls","wall",
                   "stone" }) :
                   "The walls extend to the north and west, standing "
                   "as the barriers between this world and the one "
                   "beyond to the east and south.  Some bushes are "
                   "pressed quite close to the wall.",
                ({ "soft grass","grass","carpet","land","earth",
                   "thick grass","healthy grass" }) :
                   "Grass grows in excessive and strong quantities to the "
                   "west and north, flourishing here in the area "
                   "set aside from the flowers and bushes.  The "
                   "rocks seem to be working, as no grass grows inside "
                   "the boundary line they have created.",
                ({ "plain rocks","plain rock","rock","rocks" }) :
                   "The rocks stick out of the ground, clearly present "
                   "to protect the flowers and bushes from the ravashing "
                   "attacks of thick and healthy grass.  They have "

                   "been lain very neatly and carefully.",
           ]) );
   SetListen( ([
                 "default" : "The wind whistles above, but not more than "
                  "a breeze moves through the garden.",
            ]) );
   SetSmell( ([
                "default" : "The flowers and bushes smell sweet.",
           ]) );
   SetExits( ([
                "north" : M_ROOM + "garden_d",
                "west"  : M_ROOM + "garden_a",
           ]) );
   SetInventory( ([
                    M_NPC + "gardener" : random(3)+1,
                    M_NPC + "monk_c" : 2+random(3),
                    M_NPC + "monk_j" : 1,
                    M_NPC + "trav_wor" : 3,
]) );
}
