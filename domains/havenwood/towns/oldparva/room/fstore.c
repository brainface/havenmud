#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetShort("fish shop");
   SetLong("Bins full of fish and creatures of the sea "
           "fill the fish shop.  The building itself is "
           "one of the finer ones in Parva; it is "
           "not so ready to fall apart as all the others.  "
           "The only exit is out.");
   SetItems( ([
                ({ "fish shop","store","building","shop" }) :
                   (: GetLong :),
                ({ "fish bins","bins","bin" }) :
                   "A number of bins filled with fish are "
                   "scattered about the shop.  A few "
                   "bins are filled with other varieties of "
                   "sea creatures, like oysters and clams.",
                ({ "various fish","fish" }) :
                   "The fish are mostly dead.  They are being "
                   "kept as cold as possible until someone "
                   "buys them.  There is quite a variety.",
                ({ "sea creatures","creatures","creature" }) :
                   "A large variety of sea creatures other "
                   "than fish fill bins.  Clams, oysters, and "
                   "squids are three of them.",
                ({ "clams in bins","clam","clams" }) :
                   "The clams in the bins are still raw and "
                   "wait for cooking--or being swallowed just "
                   "as they are.",
                ({ "oysters in bins","oysters","oyster" }) :
                   "The oysters are ugly little shellfish "
                   "with rippling shells and a strong sea "
                   "smell.",
                ({ "squid in bins","squid" }) :
                   "The squid aren't too large.  They are all "
                   "black and about a foot long each.",
           ]) );
   SetItemAdjectives( ([
                         "store" : ({ "fish" }),
                         "bins" : ({ "fish","seafood" }),
                         "creature" : ({ "sea" }),
                    ]) );
   SetListen( ([
                 "default" : "Water runs through the bins to "
                    "keep the seafood fresh.",
            ]) );
   SetSmell( ([
          "default" : "The building reeks of seafood.",
           ]) );
   SetExits( ([
                "out" : P_ROOM + "/path2",
           ]) );
   SetInventory( ([
                    P_NPC + "/fishguy" : 1,
               ]) );
}
