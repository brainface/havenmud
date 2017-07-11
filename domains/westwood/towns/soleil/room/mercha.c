#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("a comfortable home");
   SetLong("A warm rug lays across the wood "
           "floor, kept carefully clean by the "
           "owners of this home.  Two large "
           "chairs face each other in front of a "
           "beautiful window with stain-glass "
           "edges.  One doorway leads to the "
           "north; the other leads out.");
   SetItems( ([
                ({ "comfortable home","home","house" }) :
                   (: GetLong :),
                ({ "warm rug","rug" }) :
                   "The warm rug strewn across the "
                   "floor appears to have been knitted.  "
                   "It is patterned using forest "
                   "browns and greens with a touch of "
                   "grey-white.",
                ({ "wood floor","floor" }) :
                   "The floor is predominately "
                   "covered by the rug.  Two chairs "
                   "rest upon it as well, facing "
                   "each other and a window.  "
                   "The floor is plain and made of "
                   "wood.",
                ({ "beautiful window","window" }) :
                   "The window is circular in shape, "
                   "with rose-patterned stain glass "
                   "on the edges.",
                ({ "stain-glass","glass" }) :
                   "The glass is colored and put "
                   "together to form a pattern of "
                   "red and blue roses with green "
                   "stems and leaves.  Small brown "
                   "thorns cling to some of the "
                   "stems.",
                ({ "two doorways","doorway","doorway" }) :
                   "The two doorways lead out and "
                   "to the north.",
           ]) );
   SetItemAdjectives( ([
                         "rug" : ({ "warm" }),
                         "floor" : ({ "wood","wooden" }),
                         "home" : ({ "comfortable" }),
                         "chairs" : ({ "two","large" }),
                         "window" : ({ "beautiful" }),
                         "glass" : ({ "stain","stained","glass" }),
                         "doorway" : ({ "two" }),
                    ]) );
   SetSmell( ([
                "default" : "The smells of fresh-baked "
                   "sweets fill the air.",
           ]) );
   SetListen( ([
                 "default" : "Someone hums nearby.",
            ]) );
   SetExits( ([
                "out" : S_ROOM + "tree_a",
                "north" : S_ROOM + "merchb",
           ]) );
   SetInventory( ([
                    S_NPC + "merchant_nobu" : 1,
                    S_NPC + "trainer_diviner" : 1,
               ]) );
}
