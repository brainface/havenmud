#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";
 
static void create() 
{
  ::create(25, 18);
  SetDomain("WestWood");
  SetShort("a shoreline to a river");
  SetLong("A river passes though this part of the forest.  All "
    "around the forest presses in tight to the shoreline creating a "
    "screen that almost hides the river.  The light glistens off the "
    "river creating an effect of light dancing about the trees.  A "
    "small house sits here along the shore.");
  SetItems( ([
    ({ "river","forest","shore","shoreline" }) : (: GetLong :),
    ({ "trees","tree" }) :
      "The beautiful fenfir trees flourish in the fertile "
      "atmosphere of the WestWood, growing close to the "
      "river.",
    ({ "light" }) : "The reflections of light off the river creates "
      "an interesting effect on the trees, highlighting them in places"
      " and deepening shadows in others.",
    ({ "water" }) : "The water is clear and ripples slightly from fish"
      " jumping about the water.",
    ({ "fish"}) : "Fish do not like living in crowded areas.",
    ({ "house" }) : "This small house appears to be a nice place to "
      "live.  It is nestled along the shore of the river.",
  ]) );
  SetItemAdjectives( ([
    "fish" : "small",
    "house" : "small",
  ]) );
  SetListen( ([
    "default" : "The river blurbles noisily though here.",
  ]) );
  SetSmell( ([
    "default" : "The air smells lightly of fish.",
  ]) );
  SetObviousExits("north, northwest, west, southwest");
  SetExits( ([
    "north" : V_ROOM + "25,19",
    "northwest" : V_ROOM + "24,19",
    "west" : V_ROOM + "24,18",
    "southwest" : V_ROOM + "24,17",
  ]) );
  SetEnters( ([
    "house" : V_ROOM + "p_house_3",
  ]) );
}
