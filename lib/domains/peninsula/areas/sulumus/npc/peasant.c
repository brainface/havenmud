// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include <std.h>
#include "../sulumus.h"

inherit LIB_SENTIENT;

int type = random(2);

static void create() {
  sentient::create();
  SetMorality(25);
  SetClass("merchant");

  if (type == 0) {
  SetKeyName("peasant man");
  SetId( ({ "man" }) );
  SetAdjectives( ({ "a", "peasant" }) );
  SetShort("a peasant man");
  SetLong(
     "By his unkept hair, scruffy beard, and dirty shirt, it is obvious "
     "that this man is a poor commoner. His face looks of a man who has "
     "a tough spirit, enduring physical labor and tough jobs to sacrifice for "
     "his children to grow up comfortably. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("male");
  SetSkill("slash combat", 1, 2);
  SetSkill("fishing", 1, 1);
  SetLevel(8);
  SetInventory( ([
     STD_WEAPON + "dented_sword" : "wield sword",
     STD_CLOTHING + "shirt" : "wear shirt",
     STD_CLOTHING + "pants" : "wear pants",
     STD_CLOTHING + "shoes" : "wear shoes",
  ]) );
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetAction(1, ({
     "!nod",
     "!say Sometimes jobs can be tough, but I accept it. ",
     "!say We're just barely getting by, but we're doing it!",
     "!say Brodi sometimes sends me and a few other men from the trading "
     "post to attend training on using swords. He even gave us our swords, "
     "although they look a bit old and worn. ",
     "!say Hello there.",
     "!nod",
     "!smile",
     "!say I love my children.",
  }) );
  SetCombatAction(3, ({
     "!say I sure hope my combat training pays off!",
     "!say die!",
     "!say run away!",
     "!say take this!",
     "!laugh loud",
     "!say Fear me!",
  }) );
}

  if (type == 1) {
  SetKeyName("peasant woman");
  SetId( ({ "woman" }) );
  SetAdjectives( ({ "a", "peasant" }) );
  SetShort("a peasant woman");
  SetLong(
     "By her unkept appearance, it is obvious that this woman is a poor "
     "commoner. Her clothes are ragged and her skin is soft, suggesting her "
     "line of duties aren't that of tough physical tasks, though however "
     "tedious they may be. She looks to be a pleasant soul, trying to just "
     "get by and be happy as best as possible. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("female");
  SetSkill("melee combat", 1, 2);
  SetLevel(6);
  SetInventory( ([
     STD_CLOTHING + "pants" : "wear pants",
     STD_CLOTHING + "shirt" : "wear shirt",
     STD_CLOTHING + "shoes" : "wear shoes",
  ]) );
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetAction(1, ({
     "!nod",
     "!say Hello.",
     "!nod",
     "!smile",
     "!say I love my children.",
     "!say Never miss a moment, do you?",
  }) );
  SetCombatAction(3, ({
     "!say Get away from me you fiend!",
     "!say Get your hands off of me!",
     "!say Don't touch me! Stop!",
  }) );
}

}
