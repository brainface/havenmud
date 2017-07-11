#include <lib.h>
#include "../inn.h"
inherit LIB_BARKEEP;

static void create()
{
  barkeep::create();
  SetKeyName("jord");
  SetShort("Jord the innkeeper");
  SetId( ({ "jord the innkeeper", "innkeeper", "jord" }) );
  SetLong("This is Jord, keeper of the Morning Star Inn.  Curiously, he "
          "seems to have lost his right arm, probably in some battle long "
          "ago.  A certain fire in his eyes suggests that perhaps he longs "
          "for that battle once again.  Until then, he waits patiently for "
          "someone to buy some bread or ale.");
  SetRace("human");
  RemoveLimb("right arm", 0);
  SetGender("male");
  SetClass("fighter");
  SetLevel(30);
  SetMorality(400);
  SetInventory( ([
                 I_OBJ + "/pants" : "wear pants",
                 I_OBJ + "/club" : "wield club"
                 ]) );
  SetMenuItems( ([
                 "ale" : I_OBJ + "/ale",
                 "bread" : I_OBJ + "/bread"
                 ]) );
/*
  RemoveLanguage("Enlan");
  SetLanguage("Drakem", 100, 1);
*/
  SetAction(10,
    ({
     "!speak I think I've had a pretty good year.",
     "!speak With a little luck I should be able to expand the inn soon.",
     "!whistle tunelessly"
     }) );
  SetLocalCurrency("senones");
  SetCurrency("senones", random(100)+250 );
}
