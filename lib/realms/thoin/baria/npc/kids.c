//
// Summary: kids of Baria
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 10/21/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  switch (random(2)) {
    case 0:
      SetKeyName("barian kid");
      SetCurrency("chits", 2);
      SetShort("a barian kid");
      SetId( ({ "kid","baria_wander","barian kid","barian" }) );
      SetRace("human");
      SetClass("fighter");
      SetLevel(random(3));
      SetLong("This kid looks happy and spends his time playing "
              "around with the other kids. He looks strong for "
              "a young boy."
             );
      SetGender("male");
      SetMorality(300);
      RemoveLanguage("Enlan");
      SetLanguage("Barian", 100, 1);
      SetAction(5, ({
                     "!say Would you play with me?",
                     "!say Yahoo!",
                     "The kid runs around screaming, \"Whee!\"",
                     "!say I like to go to play in the jungle.",
               }) );
      SetWander(10);
      break;
    case 1:
      SetKeyName("barian kid");
      SetCurrency("chits", 3);
      SetShort("a barian kid");
      SetId( ({ "kid","baria_wander","barian kid","barian" }) );
      SetRace("human");
      SetClass("fighter");
      SetLevel(random(3));
      SetLong("This little girl is playing around with the other "
              "kids in the village. She looks very happy."
             );
      SetGender("female");
      SetMorality(300);
      RemoveLanguage("Enlan");
      SetLanguage("Barian", 100, 1);
      SetAction(6, ({
                     "!say Play with me!",
                     "!say House chores are boring.",                     
                     "!say Mommy says I shouldn't go into the jungle."
               }) );
      SetWander(10);
      break;
  }
}


