#include <lib.h>
#include "../defs.h"
#include "/domains/baria/towns/baria/jungle.h"
#include <domains.h>

inherit LIB_ROOM;


static void create() {
  room::create();
  SetClimate("indoors");
  SetObviousExits("out");
  SetShort("the Barian smoke hut");
  SetLong(
          "This round straw hut could use some organizing. "
          "A sturdy wooden beam rests in the hut supporting "
          "the center of the ceiling. Numerous spices and "
          "herbs rest in several crates on the east side next "
          "to a single large stone slab. The ground is "
          "fairly tidy, but appears that it has not been swept "
          "in quite some time.");

  SetExits( ([
            "out"  : BARIA_ROOM "path9",
           ]) );
  SetRadiantLight(60);
  SetSmell( ([
            "default" : "The smell of spices lingers about.",
           ]) );
  SetListen( ([
            "default" : "The sounds of the jungle outside creep in.",
           ]) );
  SetInventory(([ 
                  SHOP_NPC "ragar" : 1,
              ]));
  SetItems( ([
     "spices"  : "Spices rest in a wooden crate near the east wall. "
                 "They appear to have been just dumped there.",
     "herbs"   : "Herbs rest in a wooden crate near the stone slab. "
                 "They are organized in no particular fashion.",
     "ceiling" : "The ceiling is made of straw and supported by the "
                 "beam.",
     "doorway" : "The doorway rests to the south, leading back into the town.",
     "straw"   : "This is a thick hay straw with a slight yellow color.",
    ({ "hut", "straw hut" })        : (: GetLong() :),
    ({ "ground", "floor" })         : "The ground is littered with bits "
                                       "of dirt which has found its "
                                       "way into the hut from the outside.",
    ({ "wall", "straw wall", "walls", "straw walls" })      : 
                                       "It is made of straw and is free "
                                       "of any decoration. A doorway "
                                       "has been made to the south, leading "
                                       "back into town.",
    ({ "crates", "wooden crates", "crate", "wooden crate" }) : 
                                       "The wooden crates have been well-"
                                       "crafted, and appear to have been "
                                       "made to last for some time. There "
                                       "are two of them, one which holds "
                                       "some spices and the other herbs.",
    ({ "slab", "stone slab"})       : "It almost appears to be some sort "
                                       "of desk. It is just a rectangular "
                                       "stone resting next to the crates.",
    ({ "beam", "wooden beam" })     : "It stands in the center of the hut, "
                                       "supporting the ceiling from caving "
                                       "in during rough weather.",

              ]) );
  
  }
