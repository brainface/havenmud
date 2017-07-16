#include <lib.h>
inherit LIB_FISHING;
#include "../westwood.h"
 
static void create() 
{
  fishing::create();
  SetDomain("WestWood");
  SetClimate("temperate");
  SetShort("a crystal clear lake");
  SetLong("This is a clean, clear lake.  From the surface at any part "
    "of the lake the bottom can be seen.  The water looks pure and clean "
    "enough to drink.  Small reeds grow along the bottom and fish can "
    "be seen darting about their business.  Fenfir trees press in on "
    "all sides of the lake, leaving small shorelines and further "
    "making this an ideal location for idle time.  In the middle of "
    "lake sits a castle atop a small island.");
  SetItems( ([
    ({ "lake","water","surface","bottom" }) : (: GetLong :),
    ({ "trees","tree" }) : "The beautiful fenfir trees flourish in the "
      "fertile atmosphere of the WestWood, growing close to the shores "
      "of the lake.",
    ({ "plant","plants","reed","reeds" }) : "The plants in the "
      "bottom of the lake are nothing more than smalls reeds "
      "that grow well in wet enviroment of the lake.  They "
      "stand very tall and are a very light, almost "
      "translucent, shade of green.",
    ({ "fish" }) : "Small fish common only to the WestWood swim about "
      "amongst the reeds.  Their only task seems to be the amusement "
      "of those who watch them swim.",
    ({ "castle","island" }) : "In the middle of the lake sits a small "
      "island with a grand castle on it.  The sand of the island is "
      "a pure white that matches the color of the castle walls.  The "
      "consists of a single ground level with four guard towers on the "
      "corners of the castle.",
  ]) );
  SetItemAdjectives( ([
    "reed" : "small",
    "tree" : "fenfir",
    "lake" : ({ "clean","clear" }),
    "bottom" : "lake",
    "island" : "small",
  ]) );
  SetInventory( ([
    "lake" : 1,
  ]) );
  SetListen( ([
    "default" : "The lake is silent except for the occasional fish "
      "jumping and insect buzzing by.",
  ]) );
  SetSmell( ([
    "default" : "The light airy smell of the fenfir trees drifts through "
      "air.",
  ]) );
  SetSpeed(3);
  SetFish( ([ 
    "fish_a" : 25,
    "fish_b" : 5,
  ]) );
  SetChance(45);
  SetMaxFishing(25);
}
