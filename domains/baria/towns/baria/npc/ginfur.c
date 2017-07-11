//
//  a barkeep
//  Created by Kyla
//  Modified by Rhakz - Angel Cazares
//  Date: 10/13/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Ginfur");
  SetId( ({ "ginfur", "chef" }) );
  SetAdjectives( ({ "large", "burly" }) );
  SetShort("ginfur the large and burly chef");
  SetLong(
     "Ginfur is the person whom prepares the meals for the town of Baria. "
     "His large and burly stature is complimented by the fact that he is "
     "tanned heavily all over his body. He seems to be an honest and "
     "direct person, never giving into deceiving his customers or attempting "
     "to swindle them out of their money. His talent in the kitchen has made "
     "him have a name for himself; He is known throughout all of the Jungle. "
  );
  SetGender("male");
  SetRace("human");
  SetMorality(30);
  SetTown("Baria");
  SetClass("merchant");
  SetLocalCurrency("chits");
  SetSkill("melee combat", 1, 2);
  SetLevel(17);
  AddCurrency("chits", 35 + random(25));
  SetAction(4, ({
     "!yell Come and taste my wonderful meals!",
     "!yell Sit down and have some of my delicious monkey meat "
     "platter!",
     "!yell Treat yourself to a wonderful coconut meat special!",
     "!yell Enjoy some of my refreshing Barian Cocktails!",
     "!say This job is what I live for.",
     "!say It has taken me many years to perfect my cooking methods.",
     "!yawn",
  }) );
  SetMenuItems( ([
                  "barian cocktail" : BARIA_OBJ + "barian_cocktail",
                  "monkey meat" : BARIA_OBJ + "monkey_meat",
                  "coconut meat" : BARIA_OBJ + "coconut_meat"
              ]) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
}

