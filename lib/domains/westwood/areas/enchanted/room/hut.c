// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../balz.h"
 
static void create() {
   room::create();
   
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("a gloomy hut");
   SetLong("Deep shadows hide the corners of the hut, while dirt "
           "covers every flat surface, and dust every tilted one.  "
           "An old book sits on the top of a desk to one side of "
           "window-less hut, and twigs, leaves, and branches litter "
           "its floor.  Magical paraphernalia sits next to a half-"
           "formed tree.");
   SetItems( ([
                ({ "deep shadows","shadows","shadow","corners",
                   "corner" }) :
                   "Dark and gloomy shadows fill the corners of "
                   "this hut.",
                ({ "flat surface","dirt" }) :
                   "Dirt has found it's way on to every flat surface "
                   "inside this entire hut, except for the magical "
                   "paraphernalia.",
                ({ "tilted surface","dust" }) :
                   "Dust covers all the tilted surfaces of the "
                   "hut, except for the magical paraphernalia, "
                   "which seems strangely clean.",
                ({ "wizard book","old book","book","old leatherbound book",
                   "leathbound book" }) :
                   "The book is full of "
                   "notes on how golems are created, and exactly "
                   "how the old wizard that lives here in this hut "
                   "created and gave life to the enchanted trees who "
                   "make up the surrounding forest.  Towards the end "
                   "of the book, a quick scanning reveals that the "
                   "wizard is trying to perfect his methods, to make "
                   "strong and imperishable golems, but that right "
                   "now the only way he has found to make them more "
                   "strong is to mix silver and gold into the wood.",
                ({ "wizard's desk","desk" }) :
                   "An old, leatherbound book sits on the desk, "
                   "and looks as if it is used for taking notes "
                   "on the golem wizard's trees.",
                ({ "twigs leaves and branches","twigs","branches",
                   "leaves" }) :
                   "Leaves and branches and twigs hide the floor "
                   "from sight, brought in while the wizard was "
                   "working on his trees.",
                ({ "magical paraphernalia","paraphernalia" }) :
                   "Dust and dirt free magical paraphernalia sit "
                   "idly next to the half-formed tree, probably "
                   "used to bring the trees to life.",
                ({ "half-formed tree","tree" }) :
                   "A few branches stick out of one side of the tree, "
                   "but the other sides are bereft of the stout "
                   "objects.  There seems to be some strange things "
                   "mixed into the wood.",
           ]) );
   SetSmell( ([
                "default" : "Musty chemical smells fill the air.",
           ]) );
   SetExits( ([
                "out" : B_ROOM + "/etd",
           ]) );
   SetObviousExits("out");
   SetInventory( ([
                    B_NPC + "/wiz" : 1,
               ]) );
}
