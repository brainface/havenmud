/*  Portia  10-21-98
    A cleric leader for Malveillant.
    - Titles updated because Parva and what???
    - Aless 2014
*/

#include <lib.h>
#include <domains.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Luciano");
  SetShort("Luciano the Parvan Priest of Soirin");
  SetId( ({ "luciano", "priest", }) );
  SetAdjectives( ({"parvan", "soirin"}) );
  SetLong(
    "Luciano's dark, shifting eyes stare out of a quietly handsome face. "
    "He is known through Parva not only as the one who meticulously tends "
    "this shrine but also for his innumerable sneaky, evil dealings."
    );
  SetRace("human");
  SetGender("male");
  SetReligion("Soirin","Soirin");
  SetClass("priest");
  SetSkill("poison magic",1,1);
  SetSkill("pierce combat",1,1);
  SetTown("Parva");
  SetMorality(-1500);
  SetLevel(40);
  SetCurrency("oros",random(300) + 5);
  SetInventory( ([
      HAVENWOOD_TOWNS + "malveillant/obj/clothing/cler_medallion" : "wear medallion",
      HAVENWOOD_TOWNS + "malveillant/obj/weapons/elf_rapier" : "wield rapier",
         ]) );
  SetUniqueSkills( ([
    "blunt combat" : 0,
    "knife combat" : 1,
    "stealth" : 2,
    ]) );
  
  SetSpellBook( ([
      "harm body" : 100,
      "poison arrow" : 100,
      "shield of faith" : 100,
      "pain touch" : 100,
      ]) );
  SetCombatAction(45, ({
       "!cast harm body",
       "!cast poison arrow",
       "!cast shield of faith",
       "!cast pain touch",
       }) );
  
  SetPlayerTitles( ([
      "newbie" : "the Initiate of the Dark Altar",
      "mortal" : "the Nightshade",
      "hm"     : "the Shadowed Hand of Soirin",
      "legend" : "the Preacher of Darkness",
      "avatar" : "the Elusive Dagger of Soirin",
      "fighter" : "the Cunning Blade of Melchezidek",
      "rogue"   : "the Midnight Trickster",
      "bard"    : "the Twilight Nightingale"
       ]) );
  SetFreeEquip( ([
    HAVENWOOD_TOWNS + "malveillant/obj/weapons/cleric_knife" : 1,
    ]) );  
}
