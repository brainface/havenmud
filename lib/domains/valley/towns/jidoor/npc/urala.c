//
// Urala the innkeeper
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_BARKEEP;

static void create() {
   barkeep::create();
   SetKeyName("urala");
   SetId( ({ "urala", "barkeep","jidoor_npc" }) );
   SetShort("Urala the Barkeep");
   SetLong("This little lady is serves the patrons of the War Hall."
           "She seems friendly and willing to help anyone interested "
           "in her services.  She doesn't appear to be much of a "
           "warrior though.");
   SetClass("merchant");
   SetLevel(5);
   SetRace("sprite");
   SetClass("merchant");
   SetSkill("conjuring");
   SetSkill("evokation");
   SetGender("female");
   SetMorality(20);
   SetLocalCurrency("rupies");
   SetMenuItems( ([
      "steak" : "/std/meal/food/steak",
      ]) );
   SetSpellBook( ([
   		"aura"     : 100,
   		"missile"  : 100,
   		"ice ball" : 100,
   	  ]) );
   SetCombatAction(40, ({
   	  "!cast aura",
   	  "!cast missile",
   	  "!cast ice ball",
   		}) );
}
