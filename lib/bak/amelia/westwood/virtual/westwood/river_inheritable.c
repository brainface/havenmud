#include <lib.h>
inherit LIB_FISHING;

void eventNoise();
int chance1 = (50 + random(75));
 
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
