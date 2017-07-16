// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

static void create() {
   room::create();
   SetTown("Soleil");
   SetShort("Soleil Cemetery");
   SetDomain("WestWood");
   SetLong("The cemetery is quiet and peaceful.  Light sifts down from "
           "above, not of all it just natural light.  Small white stones "
           "carve a path through the graves so people do not step on "
           "then, but some footprints show that not everyone obeys these "
           "unspoken rules.  The graves themselves do not have plaques "
           "on them, but around the cemetery are some raised plaques "
           "right beside the path that seem to have writing on them.  A "
           "path to the south heads back towards town.");
   SetItems( ([
                ({ "soleil cemetery","cemetary" }) : (: GetLong :),
                ({ "small white stones","small stones","white stones",
                   "stones","small white stone","small stone","white stone",
                   "stone","path" }) :
                   "The stones line the edge of the path that winds "
                   "through the cemetery.  They are very clear against "
                   "against the general browns and greens of this area.",
                ({ "soleil's graves","graves","grave","new graves",
                   "new grave" }) :
                   "The graves are hard to see, but slight indentions "
                   "in the ground and breaks in the vegetation that has "
                   "been almost encourages to grow here show where "
                   "the graves exist.  Only the newest graves, however, "
                   "seem to be free of the plants.",
                ({ "cemetery vegetation","vegetation","plants","plant" }) :
                   "Plants and other green things grow around here, "
                   "except on the path and new graves.  The green things "
                   "seem to thrive in the soil.",
                ({ "grave footprints","footprint","footprint" }) :
                   "Small footprints, like that of a child, can be "
                   "seen beyond the boundaries of the white stones.  They "
                   "seem to have done little harm, however.",
                ({ "raised plaques","plaques","plaque","raised plaque" }) :
                   "The plaques stand right beside the path for all to "
                   "read, but are only written in Oiseau, the muezzin "
                   "language.  It appears to be names and sometimes "
                   "histories of who these graves belong to, and what "
                   "they have done.",
                ({ "south path","path" }) :
                   "The path to the south heads back to the town, "
                   "away from the graves and cemetery markers.",
           ]) );
   SetListen( ([
                 "default" : "A light breeze rustles through the cemetery.",
            ]) );
   SetExits( ([
                "south" : S_ROOM + "pool",
           ]) );
   SetInventory( ([
                    S_NPC + "cemetary_worker" : random(2)+1,
                    S_NPC + "dog_shaggy" : random(2),
               ]) );
}
