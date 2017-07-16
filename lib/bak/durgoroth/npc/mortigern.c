// Title: Durgoroth Town
// File: mortigern.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Mortigern, Evoker Leader of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_LEADER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	leader::create();
	SetKeyName("mortigern");
	SetShort("Mortigern, Grand Magus of Durgoroth");
	SetId( ({ "mortigern, grand magus of durgoroth","mortigern",
		"grand magus","mage","evoker" }) );
	SetRace("human"); 
	SetClass("evoker");
	SetTown("Durgoroth"); 
	SetGender("male");
	SetLevel(60);
	SetProperty("durgorothNPC",1);
	SetMorality(-400);
	SetLong("Mortigern is a tall, frail human in long brown "
					"robes. But contrary to his appearance, he is known to be "
					"a very knowledgable and powerful evoker.");
	SetCurrency("crystals", 100 + random(400));
	SetPlayerTitles( ([
		"newbie" : "the studying Magus of Durgoroth",
		"mortal" : "the Magus of Durgoroth",
		"hm"     : "the High Magus of Durgoroth",
		"legend" : "the Lord Magus of Durgoroth",
		"avatar" : "the Embodyment of Magic",
		]) );
	SetSpellBook( ([
		"chain lightning" : 100,
	  "energy wall" : 100,
  	"disintegrate" : 100,
    "fireball" : 100,
 		]) );
	SetCombatAction(70, ({
		"!cast energy wall",
		"!cast chain lightning",
		"!cast disintegrate",
		"!cast fireball",
		}) );
	SetFriends( ({"uruial","sandis"}) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	SetFreeEquip( ([
		"/std/weapon/pole/staff":1
		]) );
  SetTaughtSpheres( ({ 
  	"conjuring", 
  	"conjuring evokation", 
  	"conjuring enchantment" 
  	}) );
	}
