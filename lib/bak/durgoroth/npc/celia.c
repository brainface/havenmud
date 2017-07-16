// Title: Durgoroth Town
// File: celia.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Celia, healer of Durgoroth town
//
// Revision History: 
//

#include <lib.h>
inherit LIB_HEALER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	healer::create();
	SetKeyName("celia");
	SetId( ({ "celia","durgoroth healer","healer" }) );
	SetShort("Celia, the Healer of Durgoroth");
	SetLong("Celia is an elegant young woman in glowing "
		"white robes. While young, she is a very acomplished "
		"healer, and not many wounds are beyond her skill to "
		"tend.");
	SetRace("human");
	SetClass("priest");
	SetReligion("Saahagoth","Saahagoth");
  SetTown("Durgoroth");
  SetLevel(90);
  SetStat("wisdom", 10000, 1);
	SetGender("female");
	SetMorality(-20);
	SetProperty("durgorothNPC",1);
	SetCurrency("crystals", 50 + random(51));
	SetSpellBook( ([
  		"pious obstructions" : 100,
      "purify" 						 : 100,
      "touch of death" 		 : 100,
      "hellfire" 					 : 100,
      "cause bleeding"		 : 100,
      "unholy power"			 : 100,
      ]) );
  SetCombatAction(50, ({
     	"!cast hellfire",
     	"!cast pious obstructions",
     	"!cast purify",
     	"!cast touch of death",
     	"!cast cause bleeding",
  		(: summonGuard, this_object() :),
  		}) );
	SetLocalCurrency("crystals");
  SetFees( ([
    "resurrect" : 100,
    "magic" 		: 10,
    "stamina" 	: 5,
    "health" 		: 3,
    "restore" 	: 50,
    ]) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	}
