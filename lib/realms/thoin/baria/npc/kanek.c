//
// Summary: a sub-class leader to hold half of Creb's spells
// Created by: Rhakz@Haven - Angel Cazares
// For: Baria
// Date: 12/07/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Kanek");
  SetShort("Kanek the Adept Shaman");
  SetId( ({"kanek","kanek the adept shaman","shaman","adept shaman",
           "adept"}) );
  SetLong("Kanek is a young shaman who helps Creb with the teaching "
          "of spells to other shamans. He was proved powerful enough "
          "by Creb to aid him in that task. He looks strong, and must "
          "be powerful thanks to his knowledge in magic and his faith "
          "in Rhakz."
         );
  SetAdjectives( ({"young","strong","powerful"}) );
  SetMorality(-10);
  SetRace("human");
  SetGender("male");
  SetClass("shaman");
  SetLevel(30);
  SetReligion("Kuthar", "Kuthar");
  SetTown("Baria");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100 , 1);
  SetFriends( ({"kanek","barian kid","native"}) );
  SetCombatAction (60, ({
                         "!cast dragon claw",
                         "!cast holy shield"
                  }) );
  SetSpellBook( ([
                  "harmony hand" : 100,
                  "harmony wind" : 100,
                  "divine magic" : 100,
                  "divine magic fully" : 100,
                  "sanctify" : 100,
                  "dispel poison" :100,
                  "dragon's blood" :100,
                  "awakening" : 100,
                  "divine religion" : 100,
                  "cure blindness" : 100,
                  "holy shield" : 100,
                  "mend heavy" : 100,
                  "create detox potion" : 100,
                  "remove paralysis" : 100,
                  "regenerate limb" : 100,
                  "dragon claw" : 100
              ]) );
  SetNoJoin(1);
}
