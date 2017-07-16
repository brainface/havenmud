// Coded by Zeratul
// 3-17-2000
// Ninja Leader - NIIIINNNNJJJJJJAAAA!

#include <lib.h>
#include <std.h>
#include "../ninja.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("ninja master");
  SetRace("human");
  SetShort("the ninja master");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetClass("ninja");
  SetLevel(45);
  SetGender("male");
  SetTown("Tairi");
  SetFriends( ({
     "guard","ninja","old man"
  }) );
  SetId( ({ "ninja", "master" }) );
  SetAdjectives( ({ "ninja", "master" }) );
  SetLong(
     "This ninja warrior is from the valley lands of Tai-Ri. He is the "
     "master of the ninjas, watching over the place with a keen sense of "
     "responsibility. "
  );
  SetMorality(100);
  SetInventory( ([
     N_OBJ + "shozoku" : "wear armour",
     N_OBJ + "ninjato" : "wield sword",
  ]) );
  SetFreeEquip( ([
    N_OBJ + "newbie_ninjato" : 1,
    N_OBJ "shozoku" : 1,
  ]) );
  SetAction(5, ({
     "!speak The way of the warrior is long and difficult.",
     "!speak I will train those who wish to become ninjas.",
     "A look of peace appears on the ninja master's face.",
  }) );
  SetCombatAction(5, ({
     "!yell Ayukan!",
     "!cast vine wall",
  }) );
  SetPlayerTitles( ([
      "newbie" : "the Initiate of Shadows",
      "mortal" : "the Shinobi",
      "hm"     : "the Emissary of Secrets",
      "legend" : "the Night Stalker",
      "avatar" : "the Blade in the Darkness",
  ]) );
  SetCombatStyleLevel("ninjitsu", 100);
  SetCombatStyle("ninjitsu");
  }
