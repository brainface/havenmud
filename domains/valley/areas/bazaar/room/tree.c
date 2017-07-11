/* This is the center of the bazaar. A large tree gives shade to patrons while people gather to talk. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a large tree");
  SetLong("This is the center of the bazaar. A huge oak tree "
     "is here to provide shade for the weary. There is a "
      "small flowerbed encircling the base of the tree "
     "that is full of pretty red tulips. From here you can see "
     "booths, picnic areas, and little clearings where people "
     "are milling about.");
  SetItems( ([
     ({ "tree" }) : "This massive oak tree is an excellent source of shade. Its branches extend out several feet.",
   ({ "branch", "branches" }) : "Leafy foliage covers the branches of the tree.",
   ({ "flowerbed" }) : "The bed of tulips extends all the way around the base of the tree.",
   ({ "tulip", "tulips" }) : "The tulips are healthy and well-cared for. They are a vibrant red color.",
  ]) );
  SetItemAdjectives( ([
   "tree" : ({ "huge", "oak" }),
   "flowerbed" : ({ "small" }),
   "tulip" : ({ "pretty", "red" }),
  ]) );
  SetSmell( ([
     "default" : "The smell of meat being cooked mixes with the fresh air.",
  ]) );
  SetListen( ([
     "default" : "Sounds of laughter fill the air.",
  ]) );
  SetExits( ([
     "east" : BAZAAR_ROOM "juggle",
     "south" : BAZAAR_ROOM "carpet",
     "west" : BAZAAR_ROOM "food",
     "north" : BAZAAR_ROOM "stilt",
     "northeast" : BAZAAR_ROOM "empty",
     "southeast" : BAZAAR_ROOM "trinket",
     "southwest" : BAZAAR_ROOM "table2",
     "northwest" : BAZAAR_ROOM "table1",
  ]) );
}
