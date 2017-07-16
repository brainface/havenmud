/* This is a small picnic area for carnival-goers to sit and eat or talk. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a picnic area");
  SetLong("This is a small area that has been set aside "
     "for people to sit down and eat, or just to chat. "
     "There are three wooden picnic tables with benches, "
     "a birdbath, and a flowerbed. There seems to be a "
     "big mud pit to the west, and there are several shops "
     "to the east. The food booth is back to the north.");
  SetSmell( ([
     "default" : "It smells strongly of cooked meats here."
  ]) );
  SetListen( ([
     "default" : "You can hear laughter and some odd squishy sounds coming from the west."
  ]) );
  SetItems( ([
   ({ "table", "tables" }) : "The tables are hand-made and unpolised. Some people have scratched their names into the wood.",
   ({ "flower", "flowers", "forget-me-not", "forget-me-nots" }) : "They are small and purple.",
   ({ "bench", "benches" }) : "They are hand-made wooden benches.",
   ({ "birdbath" }) : "It is made of stone. A little birdie is splashing in the water.",
   ({ "flowerbed" }) : "It is full of pretty forget-me-nots.",
   ({ "drawings", "names" }) : "It says CYRANO WAS HERE in a bold print.",
   ({ "birdie" }) : "The birdie is hopping around the edge of the birdbath.",
  ]) );
  SetItemAdjectives( ([
   "table" : ({ "three", "wooden", "picnic" }),
   "forget-me-nots" : ({ "pretty" }),
  ]) );
  SetExits( ([
     "north" : BAZAAR_ROOM "food",
     "east" : BAZAAR_ROOM "carpet",
     "west" : BAZAAR_ROOM "mud",
     "northeast" : BAZAAR_ROOM "tree",
  ]) );
}
