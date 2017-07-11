// Ogre invasion of Soleil
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../ois.h"
inherit LIB_INVADER;


static void create() {
  invader::create();
  SetKeyName("shaman");
  SetShort("a Kuthar shaman");
  SetId( ({ "shaman", "ogre_inv" }) );
  SetAdjectives( ({ "urgesh", "large", "fat", "imposing" }) );
  SetStat("intelligence",30,4); 
  SetLong(
    "Many strange holy symbols adorn the shaman of Kuthar. "
    "He is dumb looking, but apparently had high enough "
    "intelligence to master the Kuthar way of life and "
    "become a shaman. He is large and fat, and looks "
    "rather imposing."
  );
  SetRace("ogre");
  RemoveLanguage("Shangtai");
  SetLanguage("Uruk", 100, 1);
  SetGender("male");
  SetClass("shaman");
  SetLevel(38);
  SetMorality(-300);
  SetReligion("Kuthar","Kuthar");
  SetInventory( ([
    OIS_OBJ + "club_leader" : "wield club in right hand",
    OIS_OBJ + "tunic_leader" : "wear tunic",
    OIS_OBJ + "pants_leader" : "wear pants",
  ]) );
  SetCurrency("skins",125+random(25));
  SetAction(6, ({ 
    "!attack first citizen",
    "!attack first muezzin",
    "!say Kill fuzzies!",
    "!say Shaman say kill fuzzies. Kill fuzzies!",
    "!growl",
    "!burp",
    "!snarl",
    "!cast sphere", 
  }));
  SetCombatAction(40, ({ 
    "!cast bolt",
    "!cast crush",
    "!cast sphere",
    "!cast mangle",
    "!cast hurt",
    "!cast smash",
    "!cast shockwave",
    "!growl",
    "!emote spits on the ground.",
    "!shout Help ogre shaman!",
    "!thump",
  }) );
  SetSpellBook( ([
    "bolt"        : 100,
    "crush"       : 100,
    "sphere"      : 100,
    "hurt"        : 100,
    "mangle"      : 100,
    "smash"       : 100,
    "shockwave"   : 100,
  ]) );
  SetFriends( ({ "ogre_inv" }) );
  SetWanderSpeed(15);
  SetWanderPath("go up");
}
