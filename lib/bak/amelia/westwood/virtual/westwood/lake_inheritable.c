#include <lib.h>
inherit LIB_FISHING;
#include "../westwood.h"
 
void eventNoise();
int chance1 = (50 + random(75));

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
    "making this an ideal location for idle time.");
  SetItems( ([
    ({ "lake","water","surface","bottom" }) : (: GetLong :),
    ({ "trees","tree" }) : "The beautiful aspen trees flourish in the "
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
  ]) );
  SetItemAdjectives( ([
    "reed" : "small",
    "tree" : "fenfir",
    "lake" : ({ "clean","clear" }),
    "bottom" : "lake",
  ]) );
  SetInventory( ([
/*
    V_ROOM + "lake" : 1,
*/
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
    V_ROOM + "fish_a" : 25,
    V_ROOM + "fish_b" : 5,
  ]) );
  SetChance(45);
  SetMaxFishing(25);
  call_out( (: eventNoise :), chance1 );
}

void eventNoise() {
  int chance2 = (50 + random(75));
  int rand = random(3);

  if (rand == 0)
  {
    message("other_action","A cricket chirps off in the distance."
      "",this_object());
    call_out( (: eventNoise :), chance2);
    return;
  }
  else if (rand == 1)
  {
    message("other_action","A fish jumps into the air, landing "
      "back in the river with a splash.",this_object());
    call_out( (: eventNoise :), chance2);
    return;
  }
  else
  {
    message("other_action","A bird sings off in the trees."
      "",this_object());
    call_out( (: eventNoise :), chance2);
    return;
  }    
}
