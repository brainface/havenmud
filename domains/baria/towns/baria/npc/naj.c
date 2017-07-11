//
//  Naj the necromancer
//  Created by Rhakz@Haven -- Angel Cazares
//  For Baria
//  Date: 05/04/99
//
#include <lib.h>
#include "../jungle.h"
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
  SetCombatAction(85, ({ 
         "!cast veil from beyond",
         "!cast hunger",
         "!cast wither",
         "!cast disintegrate"
         }) );
  SetLevel(65);
  SetLanguage("Barian", 100, 1);
  SetTown("Baria");
  SetReligion("Kuthar");
  SetFriends( ({"barian kid","native","guard"}) );
  SetFreeEquip( ([
                  BARIA_OBJ + "staff" : 1
              ]) );
  SetSpellBook( ([
                  "hunger" 					 : 100,
                  "veil from beyond" : 100,
                  "wither"           : 100,
                  "disintegrate"     : 100,
              ]) );
  SetPlayerTitles( ([
                     "newbie" : "the Dark Magic Novice",
                     "mortal" : "the Dark Magician of Baria",
                     "hm"     : "the Black Mage of the Jungle",
                     "legend" : "the Obscure Conjurer of Death",
                     "avatar" : "the Black Magic Harnesser of the Barian Jungle"
                 ]) );
  SetTaughtSpheres( ({ 
  	"magical", 
  	"magical necromancy",
    "magical evokation",
    }) );
}
