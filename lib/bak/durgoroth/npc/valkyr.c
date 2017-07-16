// Title: Destroyed Grymxoria Town
// File: valkyr.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Garbrud, the Valkyr leader of Grymxoria
//
// Revision History: 
//

#include <lib.h>
#include <damage_types.h>
inherit LIB_LEADER;
#include "../durgoroth.h"

static void create() {
	leader::create();
	SetKeyName("Garbrud");
	SetRace("daemon");
	SetClass("rogue");
	SetLevel(40);
  SetNoJoin(1);
	SetGender("male");
	SetProperty("durgorothNPC",1);
	SetTown("Durgoroth");
	SetReligion("Saahagoth");
	SetMorality(-500);
	SetShort("Garbrud, the Master Valkyr of Durgoroth");
	SetId( ({ "garbrud","master valkyr","master","valkyr" }) );
	SetLong("Garbrud is a huge and menacing form. Massive "
     		  "muscles bulging under his dark skin. He is the master "
        	"of the Valkyr of Durgoroth, and is renowned for his "
        	"ruthlessness in combat. His scarred body gives mute "
        	"testiment to his decades of battle.");
	SetCurrency("crystals", 50 + random(400));
	SetPlayerTitles(  ([
		"newbie" : "the Lowly Maggot, Initiate Valkyr",
		"mortal" : "the Daemonic Valkyr",
		"hm" 		 : "the Shadowy Slayer",
		"legend" : "the Stalker of the Planes",
		]) );
  SetFriends(({"daemon","daemon guard","daemoness"}));
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
  SetFreeEquip((["/domains/frostmarches/towns/durgoroth/obj/leather.c":1]));
	}
