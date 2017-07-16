/* This is a place to buy food and drinks. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a food booth");
  SetLong("Here is a little wooden shack that was apparently "
     "quite hastily built. A few of the boards are nailed "
     "together crooked, and the roof would undoubtedly leak "
     "if it were to rain. There is very little grass growing in the "
     "dirt around the booth, and several food scraps are "
     "laying on the ground. There are some tables visible to "
     "the north and south, and the branches of a huge oak "
     "tree stretch in from the east.");
  SetSmell( ([
     "default" : "The smell of meats cooking fills the air.",
  ]) );
  SetListen( ([
     "default" : "Hearty laughter drifts in from all around.",
  ]) );
  SetItems( ([
   ({ "shack" }) : "There are several gaps in the boards where they were nailed together crooked."
     " It looks as if food is sold here.",
   ({ "board", "boards" }) : "The boards are weather-worn and nailed together crooked.",
   ({ "roof" }) : "The poorly thatched roof is full of holes.",
   ({ "dirt", "ground" }) : "There isn't much grass here, and there are food scraps dropped on the ground.",
   ({ "scraps" }) : "Pieces of meat and some napkins are littered on the ground.",
  ]) );
  SetItemAdjectives( ([
   "shack" : ({ "little", "wooden" }),
   "scraps" : ({ "food", "several" }),
   ]) );
  SetExits( ([
     "north" : BAZAAR_ROOM "table1",
     "west" : BAZAAR_ROOM "swing",
     "south" : BAZAAR_ROOM "table2",
     "east" : BAZAAR_ROOM "tree",
  ]) );
   SetInventory( ([ BAZAAR_NPC + "robby" : 1, ]) );
}
