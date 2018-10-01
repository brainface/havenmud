//
//  Naj the necromancer
//  Created by Rhakz@Haven -- Angel Cazares
//  For Baria
//  Date: 05/04/99
//
#include <lib.h>
#include "../sarde.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Naj");
  SetShort("Naj the Black Magician");
  SetId( ({"naj", "draconian", "magician","black magician"}) );
  SetAdjectives( ({ "burly", "powerful", }) );
  SetLong("This burly draconian has been studying the black arts "
          "of necromancy for quite some time and now he has "
          "mastered them. He has an odd look in his eyes, as if "
          "he was foreseeing death. He is very powerful and adept "
          "at dark magic."
         );
  SetRace("draconian");
  SetMorality(-600);
  SetGender("male");
  SetClass("necromancer");
  SetCombatAction(70, ({ 
                        "!cast reckoning",
                        "!cast hunger",
                        "!cast chaos bolt",
                        "!cast plane warp"
                  }) );
  SetLevel(65);
  SetLanguage("Barian", 100, 1);
  SetTown("Sarde");
  SetReligion("Kuthar");
  SetFriends( ({"barian kid","native","guard"}) );
  SetFreeEquip( ([
                  SARDE_OBJ + "staff" : 1
              ]) );
  SetSpellBook( ([
                  "wards of protection" : 100,
                  "chill touch" : 100,
                  "splash" : 100,
                  "wound" : 100,
                  "hellfire" : 100,
                  "reckoning" : 100,
                  "hunger" : 100,
                  "transfusion" : 100,
                  "chaos bolt" : 100,
                  "ethereal touch" :100,
                  "earth touch" : 100,
                  "plane warp" : 100
              ]) );
  SetPlayerTitles( ([
                     "newbie" : "the Dark Magic Novice",
                     "mortal" : "the Dark Magician of Sarde",
                     "hm" : "the Black Mage of the Jungle",
                     "legend" : "the Obscure Conjurer of Death",
                     "avatar" : "the Black Magic Harnesser of the Barian Jungle"
                 ]) );
  SetTaughtSpheres( ({ "magical", "magical necromancy",
    "magical enchantment",
    }) );
}
