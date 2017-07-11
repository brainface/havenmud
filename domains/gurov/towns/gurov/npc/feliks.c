#include <lib.h>
#include "../gurov.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("feliks");
  SetShort("Feliks Felikovich, local barkeep");
  SetId( ({"feliks", "felikovich", "barkeep"}) );
  SetAdjectives( ({"local"}) );
  SetGender("male");
  SetRace("human"); 
  SetTown("Gurov");
  SetMorality(-200);
  SetReligion("Aberach");
  SetClass("fighter");
  SetLevel(30);
  SetLong(
    "Felik has worked in the Winey Wench all his life, like "
    "his father before him. Although perhaps not the best "
    "salesman, he does the work since it is all he has ever "
    "known. He has grown quite hardy and rather jaded "
    "from dealing with drunken louts.");
  SetLocalCurrency("rubles");
  SetCurrency("rubles",random(100) + 20);
  SetCombatAction(5 , ({
                "!yell Get out of my bar!",
                "!yell I think you've had enough!",
                }) );
  SetAction(5, ({
         "!emote wipes out the inside of an old glass.",
         "!emote grumbles and looks surly.",
   }) );
  SetMenuItems( ([
      "steak"  : "/std/meal/food/steak",
        "cheese" : "/std/meal/food/cheese",
        "bread"  : "/std/meal/food/bread",
                "milk"   : "/std/meal/drink/milk",
      ]) );
  }
