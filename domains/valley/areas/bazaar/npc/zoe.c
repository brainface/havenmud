//
// Zoe, ticket seller for the bazaar
// Created by Athalie
// NOTE: This file needs to be manipulated in order to not read "I currently serve, etc" when a player asks her to browse. ~
//
#include <lib.h>
#include "../bazaar.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
   SetKeyName("zoe");
   SetId( ({ "zoe", "seller", "zoe the ticket seller" }) );
   SetAdjectives( ({ "ticket" }) );
   SetShort("Zoe the ticket seller");
   SetLong("This cheerful sprite girl couldn't be more than fifteen years "
     "old. She spends most of her time in the booth waving to customers "
     "and playing with her hair. Her clothes are threadbare and seem to "
     "be several sizes too small. However, Zoe has a little gleam in "
     "her eyes that seems to show that her spirit hasn't been broken down "
     "by her living conditions.");
   
   SetRace("sprite");
   SetClass("mystic");
   SetLevel(12);
   SetSpellBook( ([
   		"aura"         : 100,
   		"ice ball"     : 100,
   		"vermin horde" :100,
   		"condense air" :100,
   	  ]) );
   SetGender("female");
   SetMorality(50);
   SetAction(5, ({
      "!speak These tickets are good for admission into all of the events here!",
      "!emote twirls a strand of hair around her slender fingers.",
   		}) );
   SetLocalCurrency("rupies");
   SetMenuItems( ([
      "ticket" : BAZAAR_OBJ "ticket",
      ]) );
   SetCombatAction(75, ({
   		"!cast aura",
   		"!cast ice ball",
   		"!cast vermin horde",
   		"!cast condense air",
   		}) );
}
