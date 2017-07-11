/* Red Bull's Den
   Ela 8/3/98
*/


#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Matus' den");
  SetClimate("underground");
  SetObviousExits("out");
  SetExits( ([
          "out" : WOOD_ROOMS + "wood10",
          ]) );
  SetLong("This dark cave is claimed by Matus, the legendary "
          "beast of faeland. Bones litter the floor, crunching "
          "beneath careless feet. Rust-colored blood stains "
         "the ground. Heavy shadows linger forbiddingly, "
         "deepening into dense black voids in the deeper "
         "recesses of the cave. This is not a pleasant place.");
  SetItems( ([
          ({"dark den","den","cave"}) : "The cave is tomblike " 
                 "and chilling.",
          ({"bone","bones","collection"}) : "Old bleached "
                 "bones mingle with fresher bloody ones in a "
                 "macabre collection.",
          ({"floor","ground"}) : "The leftovers of numerous "
                 "feasts are obvious at a single glance of "
                 "the den's floor.",
         ({"blood","stain","stains","puddles","puddle"}) : 
                 "Deep stains and standing puddles of blood "
                 "are evidence of many feedings.",
         ({"shadow","shadows"}) : "Dark shadows line the den.",
         ]) );
  SetSmell( ([
         "default" : "The metallic scent of blood saturates "
                     "the cave.",
         ]) );
  SetListen( ([
        "default" : "It is quiet as a tomb here.",
        ]) );
  SetInventory( ([
         WOOD_NPC + "matus" : 1,
         ]) );

}
