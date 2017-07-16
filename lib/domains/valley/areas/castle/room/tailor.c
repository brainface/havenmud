#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("store of a tailor");
   SetLong("Piles of finished clothing are stacked around the room, "
           "which is swept mostly clean of things like dust and dirt.  "
           "The walls are all wooden, except the back one, since someone "
           "was apparently too lazy to build it, and instead just made "
           "the walls and ceiling press up against the castle walls.  "
           "A door leads out to the south.");
   SetItems( ([
                ({ "store walls","store wall","wall","walls","wooden walls",
                   "wooden wall","back wall","castle walls",
                   "castle wall","walls of castle","wall of castle",
                   "walls of the castle","wall of the castle" }) :
                   "The wooden walls have been put together well, but at "
                   "the end the carpenter must have gotten lazy, since "
                   "the back wall is remarkably similar to the walls "
                   "of the castle visable outside.",
                ({ "store of a tailor","tailor store","store of tailor",
                   "store","room" }) :
                   (: GetLong :),
                ({ "piles of finished clothing","pile of finished clothing",
                   "pile","piles","finished clothing","clothing",
                   "piles of clothing","pile of clothing","items","item",
                   "basic elementary clothing","basic clothing",
                   "elementary clothing","leather belts","leather belt",
                   "belts","belt","brown cloaks","brown cloak","cloak",
                   "cloaks","white gloves","white glove","gloves",
                   "glove","work gloves","work glove","brown pants",
                   "pants","white shirt","white shirts","shirt","shirts",
                   "wool socks","wool sock","socks","sock","black vests",
                   "black vest","vest","vests" }) :
                   "Various items of basic, elementary clothing can be "
                   "found in the piles.  Leather belts, brown cloaks, "
                   "white gloves, work gloves, brown pants, white "
                   "shirts, wool socks, and black vests fill the piles.",
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/gen_03",
           ]) );
   SetInventory( ([
                    VC_NPC + "/tailor" : 1,
               ]) );
}
