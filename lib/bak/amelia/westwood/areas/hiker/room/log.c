#include <lib.h>
inherit LIB_FISHING;
#include "../hiker.h"

static void create() {
   fishing::create();
   SetShort("on a log");
   SetDomain("WestWood");
   SetLong("The fallen log is slightly rotten and bends a little "
           "under the weight of the years, but doesn't break or "
           "slide unter the water.  Instead, it stays nicely "
           "propped up against a wooden bridge that one could "
           "probably climb down onto.  Below is a fast moving "
           "stream.");
   SetItems( ([
                ({ "west wood","wood","woods","forest" }) :
                   (: GetLong :),
                ({ "fast moving stream","moving stream","fast stream",
                   "stream","water","moving water" }) :
                   "The stream rushing along merrily, twinkling in the "
                   "light and making the gushing water noises that " 
                   "all moving water makes, whether in a fountain in the "
                   "middle of a town or running into a pool out in the "
                   "forest.",
                ({ "wooden bridge","bridge","solid wood","wood" }) :
                   "The bridge is made of solid wood, and by climbing "
                   "down the log a little, one could get on it.",
           ]) );
   SetListen( ([
                 "default" : "The stream rushes along.",
                 "stream" : "Most streams rush along and make noises, "
                    "and this one is not an exception.  It trickles "
                    "off rocks and drips down into the main body, where "
                    "it gets carried off with the great giggles of "
                    "water.",
            ]) );
   SetSmell( ([
                "default" : "There is a quality a stream gives to the "
                   "overall fragrance of an area; it dampens it and "
                   "makes it somehow more clean and more pure.",
                "stream" : "The stream dampens the smell of the area, "
                   "cleaning it up with its own clean essence.",
           ]) );
   SetExits( ([
                "down" : H_ROOM + "stream",
           ]) );
   SetInventory( ([
                    H_ROOM + "log_u" : 1,
                    H_NPC + "swimboy" : 2+random(3),
               ]) );
   SetSpeed(4);
   SetFish( ([
               H_OBJ + "fisha" : 10,
               H_OBJ + "fishb" : 10,
          ]) );
   SetChance(10);
   SetMaxFishing(3);
}
