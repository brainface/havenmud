#include <lib.h>
#include "../averath.h"
inherit LIB_SENTIENT; 

static void create() {
  sentient::create();
  SetKeyName("caleb");
  SetId( ({ "caleb", "dean", "farmer" }) );
  SetAdjectives( ({ "caleb" }) );
  SetGender("male");
  SetLong("Caleb is tall and lean with shoulder length black "
          "ruffed hair. His eyes are brown and cheery. "
          "His back has a slight hump to it and his hands "
          "are rough and dirt covered. His face is deep "
          "red with sunburn.");
  SetShort("Caleb Dean the Farmer");
  SetRace("human");
  SetBaseLanguage("Avera");
  SetClass("merchant");
  SetLevel(13);
  SetMorality(100);
  SetAction(2, ({
      "!emote looks over the table.",
      "!sigh",
      "!speak how much for the ale?",
      "!emote looks guilty.",
    }) );
  SetCombatAction(2, ({
      "!emote spins and connects with an uppercut.",
         }) );
 
} 
