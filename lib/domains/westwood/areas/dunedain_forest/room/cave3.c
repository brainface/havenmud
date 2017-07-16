#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
  room::create();
SetClimate("indoors");
  SetShort("a cave filled with loot");
  SetLong("The floor of the cave is littered with loot of all kinds.  To one "
          "side lie the heads of dead creatures kept as trophies of war.  To "
          "another side lie the remains of previous meals.  A rug tattered "
          "after many years of use sits in the center of the room.  A path "
          "can be seen leading out to a river in the east.");
  SetListen( ([ "default" : "The scurrying of rats can be heard."]) );
  SetSmell( ([ "default" : "An awful stench assaults your nostrils."]) );
  SetItems( ([
    ({ "cave filled with loot","cave","loot" }) :
       (: GetLong() :),
    ({ "small path","path","river in the east","river" }) :
       "A small path leads out of the cave towards a river in the east.",
    ({ "heads of dead creatures","heads","head of dead creature","head"
       "trophies of war","trophies","trophy of war","trophy"}) :
       "The heads of elves, halflings, and other creatures sit at the side "
       "of the cave.",
    ({ "remains of previous meals","remains","previous meals","meals",
       "previous meal","meal","bones","bone" }) :
       "Bones and other remains from previous meals lie on one side of the "
       "cave.",
    ({ "tattered old rug","old tattered rug","old rug","tattered rug",
       "once magnificent rug","rug" }) :
       "What at one time may have been a magnificent rug now lies at the "
       "center of the cave in deplorable condition."
  ]) );

  SetExits( ([
    "out" : F_ROOM "forest10"
  ]) );
  SetInventory( ([
    F_NPC "chief" : 1
  ]) );
}