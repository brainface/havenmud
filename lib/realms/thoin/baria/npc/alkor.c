//
//  Summary: ranger for baria.
//  Created by Rhakz@Haven -- Angel Cazares
//  For: Baria
//  Date: 10/04/99
//
#include <lib.h>
#include <std.h>
#include "../jungle.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Alkor");
  SetShort("Alkor the Protector of the Barian Jungle");
  SetId( ({ "alkor" }) );
  SetAdjectives( ({ "protector", "barian", "jungle" }) );
  SetLong("This agile-looking man is the ranger in charge of taking "
          "care of the beautiful Dark Jungle. The look in his light-"
          "brown eyes denotes shyness, as well as courage. "
         );
  SetRace("human");
  SetMorality(150);
  SetGender("male");
  SetClass("ranger");
/*
  SetUniqueSkills( ([
     "projectile attack" : 1,
     "projectile defense" : 2,
     "stealth" : 1,
     "evokation" : 1,
     "enchantment" : 2,
     "multi-handed" : 2,
     "multi-weapon" : 2,
     "farming" : 0,
     "armour smithing" : 0,
     "leather working" : 0,
     "melee defense" : 3,
     "slash attack" : 3,
     "slash defense" : 3,
     "fishing" : 3,
     "healing" : 0,
  ]) );
*/
  SetAction(3, ({
     "!cast enhanced natural veil",
  }) );
  SetCombatAction(25, ({ 
                        "!cast enhanced natural veil"
  }) );
  SetLevel(100);
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetTown("Baria");
  SetCurrency( ([
     "chits" : 3500 + random(5000),
  ]) );
  SetReligion("Kuthar");
  SetFreeEquip( ([
     STD_WEAPON + "projectile/bola" : 2,
  ]) );
  SetSpellBook( ([
     "enhanced natural veil" : 100,
  ]) );
  SetInventory( ([
     BARIA_OBJ + "junglewind" : "wield bow",
     BARIA_OBJ + "loincloth" : "wear loincloth",
     BARIA_OBJ + "scale_armour" : "wear armour",
  ]) );
  SetTaughtSpheres( ({
                      "natural",
                      "natural evokation",
                      "natural enchantment"
  }) );
  SetPlayerTitles( ([
                     "newbie" : "the Young Watcher of the Jungle",
                     "mortal" : "the Keeper of the Barian Jungle",
                     "high mortal" : "the Beloved Ranger of Baria and the Jungle",
                     "legend" : "the Corageous Barian Overseer of Nature",
                     "avatar" : "the Guardian of the Dark Virgin Jungle",
                     "barbarian" : "the Basher of the Ruiners of Nature"
  ]) );
}
