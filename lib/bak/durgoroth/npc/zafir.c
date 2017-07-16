// Title: Durgoroth Town
// File: zafir.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract: Zafir, Ranger leader of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_LEADER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	leader::create();
	SetKeyName("zafir");
	SetRace("human");
	SetClass("ranger");
	SetLevel(40);
	SetGender("male");
	SetProperty("durgorothNPC",1);
	SetTown("Durgoroth");
	SetMorality(-500);
	SetShort("Zafir, Master of the Rangers of the Northlands");
	SetId( ({ "zafir, master of the rangers","master zafir","ranger",
		"master"}) );
	SetLong("Zafir is a tall and lean human with piercing eyes. "
					"He is dressed in a simple gray cloak that completely "
					"covers his body, and carries a simple bow. He is always "
					"ready to admit new members to the rangers of the northlands "
					"if they show themselves to be worthy.");
	SetInventory( ([
		D_OBJ + "/longbow" : "wield bow",
		]) );
	SetCurrency("crystals", 50 + random(51));
  SetNoJoin(1);
	SetCombatAction( 25, (: summonGuard, this_object() :) );
	SetPlayerTitles(  ([
		"newbie" : "the initiate Ranger of the Northlands",
		"mortal" : "the Ranger of the Northlands",
		"hm" 	   : "the Warden of the Northlands",
		"legend" : "the Master of the Northern Wastes",
		"avatar" : "the Legendary Ranger of the Northlands",
		"nomad"  : "the Wanderer of the Northlands",
		]) );
   
  SetTaughtSpheres( ({ 
  	"natural magic", 
  	"natural evokation",  
  	}) );
  SetCombatAction(35, ({
  	"!cast terra",
  	"!cast condense air",
  	"!cast vine wall",
  	"!cast tangle",
  	}) );
  SetSpellBook( ([
		"barkskin" : 100,
		"terra" : 100,
		"invigorate" : 100,
		"lunar charge" : 100,
		"scatter protections" : 100,
		"summon animal" : 100,
		"tangle" : 100,
		"tend wounds" : 100,
		"condense air" : 100,
		"regrowth" : 100,
    "vine wall" : 100,
   	]) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	SetFreeEquip( ([
		"/std/weapon/projectile/long_bow":1
		]));
	}
