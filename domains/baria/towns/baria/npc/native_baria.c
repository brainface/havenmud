//
// Summary: a citizen of Baria
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 10/21/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("native");
  SetId( ({ "native", "baria_wander" }) );
  SetAdjectives( ({ "baria" }) );
  SetShort("a barian native");
  SetLong("This is a citizen of the village of Baria. He looks "
          "relaxed and happy as he walks around breathing fresh "
          "air."
         );
  SetRace("human");
  SetClass("fighter");
  SetLevel(random(5)+3);
  SetCurrency("chits", random(25));
  SetGender("male");
  SetLimit(4);
  SetMorality(random(100));
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetInventory( ([
     BARIA_OBJ + "loincloth" : "wear loincloth",
  ]) );
  SetAction(2, ({
                 "!say Chief Mianin is one the best mayors Baria "
                   "has had.",
                 "!say The bank teller is Mianin's twin brother.",
                 "!say Praise be to our Ancestors.",
                 "!say Kysanth's lair is hidden deep in the jungle.",
                 "!say There is an ancient pyramid among the Barian "
                   "Jungle.",
                 "!say I saw some dark-elves in the jungle the other "
                   "day."
      }) );
  SetWander(10);
  SetFriends( ({ "guard","kid" }) );
  /*
  SetTalkResponses( ([
                      ({ "mianin","chief mianin","mayor" }) :
                           "Mianin has been the mayor "
                           "of this village for several "
                           "years.",
                      ({ "bank teller","teller" }) :
                           "Pakal is Mianin's brother "
                           "and teller of the humble "
                           "bank of Baria.",
                      ({ "artanis","lord","god" }) :
                           "The Great Artanis has been our new Lord "
                           "since Kyla abandoned us. He is taking "
                           "good care of his followers.",
                      ({ "kysanth","lair","kysanth's lair" }) :
                           "Kysanth is a huge black dragon that "
                           "watches over Baria. The location of her "
                           "lair is only known by a few barians.",
                     ({ "pyramid" }) : "There is an old pyramid just "
                                       "a few pachekis from here.",
                     ({"dark-elves","dark-elf"}) :
                           "I saw some strange elves wandering in "
                           "the jungle the other day, near some "
                           "ruins."
  ]) );
  */
}


