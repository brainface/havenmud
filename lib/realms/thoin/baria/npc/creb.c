//
//  Creb the spiritual leader
//  Kyla 11-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/13/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_LEADER;


static void create() {
  leader::create();
  SetKeyName("Creb");
  SetShort("Creb the Spiritual Kuthar Advisor");
  SetId( ({"creb", "man", "advisor","spiritual advisor","creb the "
           "spiritual advisor"}) );
  SetAdjectives( ({ "old", "wise", }) );
  SetLong("This old man is the Spiritual Advisor of the village of "
          "Baria. He is very wise and very powerful because of his "
          "magical abilities and his great faith in his God."
         );
  SetRace("human");
  SetLevel(50);
  SetMorality(600 - random(800));
  SetGender("male");
  SetClass("shaman");
  SetCombatAction(70, ({ 
                        "!cast ancestrial protection",
                        "!cast mangle",
                        "!cast thrash",
                        "!cast chain lightning",
                        "!cast chain lightning"
                  }) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetTown("Baria");
  SetReligion("Kuthar");
  SetFriends( ({"kanek","barian kid","native"}) );
  SetFreeEquip( ([
                  BARIA_OBJ + "club" : 1,
                  BARIA_OBJ + "vest" : 1
              ]) );
  SetSpellBook( ([
                  "ancestrial protection" : 100,
                  "chain lightning" : 100,
                  "mangle" : 100,
                  "thrash" : 100
                ]) );
  SetTaughtSpheres( ({ "magic", "magical necromancy",
                      "magical evokation",
                      "clerical", "clerical necromancy",
                      "clerical evokation",
                  }) );
  SetPlayerTitles( ([
     "newbie" : "the Apprentice Shaman of Kuthar",
     "mortal" : "the Wise Shaman of Kuthar",
     "high mortal" : "the High Mi'Dach of Kuthar",
     "legend" : "the Zealous Mi'Dach of Kuthar",
     "avatar" : "the Sensational Protector of the Ancients",
  ]) );
}
