#include <lib.h>
inherit LIB_FISHING;
 
static void create() 
{
  fishing::create();
  SetDomain("WestWood");
  SetShort("a shoreline to a river");
  SetLong("A river passes though this part of the forest.  Small "
    "fish jump about the river, creating ripples in the water.  All "
    "around the forest presses in tight to the shoreline creating a "
    "screen that almost hides the river.  The light glistens off the "
    "river creating an effect of light dancing about the trees.");
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
    ({ "fish"}) : "Small fish jump about the river, occasionally "
      "stirring up the bigger fish who eats them quickly and quietly."
  ]) );
  SetItemAdjectives( ([
    "fish" : "small",
  ]) );
  SetListen( ([
    "default" : "The river blurbles noisily though here.",
  ]) );
  SetSmell( ([
    "default" : "The air smells lightly of fish.",
  ]) );
  SetSpeed(3);
  SetFish( ([ 
    "fish_a" : 25,
    "fish_b" : 10,
  ]) );
  SetChance(45);
  SetMaxFishing(25);
}
