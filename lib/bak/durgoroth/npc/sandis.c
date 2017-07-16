// Title: Durgoroth Town
// File: sandis.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Sandis, assistant evoker of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_LEADER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	leader::create();
	SetKeyName("sandis");
	SetShort("Sandis, Apprentice Evoker");
	SetId( ({ "Sandis, Apprentice Evoker","sandis",
		"apprentice evoker","evoker" }) );
	SetRace("human"); 
	SetClass("evoker");
	SetTown("Durgoroth"); 
	SetGender("male");
    SetSkill("enchantment", 0, 1);
	SetLevel(20);
	SetProperty("durgorothNPC",1);
	SetMorality(-100);
	SetLong("Sandis is a small, robust Gorithim. He is "
        "Mortigern's apprentice, and helps to teach younger "
        "evokers spells so that Mortigern can concentrate on "
        "more imprortant matters.");
	SetCurrency("crystals", 100 + random(201));
	SetPlayerTitles( ([
		"newbie" : "the studying Magus of Durgoroth",
		"mortal" : "the Magus of Durgoroth",
		"hm" : "the High Magus of Durgoroth",
		"legend" : "the Lord Magus of Durgoroth",
		"avatar" : "the Embodyment of Magic",
		]) );
  SetTaughtSpheres( ({ "magical necromancy", 
    "magical evokation", "magical enchantment" }) );
	SetSpellBook( ([
  		"aura" : 100,
		"bolt" : 100,
		"buffer" : 100,
		"channeling" : 100,
        "dispel invisibility" : 100,
        "energy field" : 100,
        "fireball" : 100,
        "invisibility" : 100,
        "missile" : 100,
        "shock" : 100,
        "sphere" : 100,
        "terra" : 100,
        "blindness" : 100,
        "anti-magic field" : 100,
        "create dark globe" : 100,
        "curse" : 100,
        "paralysis" : 100,
		"shield area" : 100,
		]) );
	SetCombatAction( 45, ({
		"!cast elemental protection",
		"!cast chain lightning",
		}) );
	SetFriends( ({"uruial","mortigern"}) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	SetFreeEquip((["/std/weapon/pole/staff":1]));
	}
