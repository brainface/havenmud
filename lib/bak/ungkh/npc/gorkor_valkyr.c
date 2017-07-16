//-- Torak@Haven --//

#include <lib.h>
#include "../ungkh.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("gorkor");
  SetRace("goblin");
  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);
  SetClass("valkyr");
  SetLevel(50);
  SetGender("male");
  SetTown("Ungkh");
  SetReligion("Kuthar");
  SetMorality(0);
  SetId( ({
    "goblin","gorkor"
    }) );
  SetAdjectives( ({
    "fierce",
    }) );
  SetShort("gorkor the fierce");
  SetLong("Gorkor is a short mean little goblin with "
          "legendary control of his own body in the "
          "city of Ungkh.  He has a mean temper and "
          "though he is a goblin, he is able to back "
          "up his foul mouth with power.");
  SetAction(1, ({
    "!exclaim foul creature, leave me alone!",
    "!stretch",
    "!say no one is as good as me",
    "!scratch",
    }) );
  SetCombatAction(1, ({
    }) );
  SetCurrency("skins",150+random(50)+random(50));
  SetPlayerTitles( ([
    "newbie" : "the Knavish Dogface",
    "mortal" : "the Mean Skirmisher",
    "hm"     : "the Infamous Guerrilla",
    "legend" : "the Scurrilous Warmonger",
    "avatar" : "the Commando",
    ]) );
}
