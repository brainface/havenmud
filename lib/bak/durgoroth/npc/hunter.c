// Title: Destroyed Grymxoria Town
// File: hunter.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Marlshak, the Hunter leader of Grymxoria
// Now a part of Durgoroth, and edited to be a Durg npc
//
// Revision History: 
//

#include <lib.h>
#include <damage_types.h>
inherit LIB_LEADER;
#include "../durgoroth.h"

static void create() {
	leader::create();
	SetKeyName("Marlshak");
	SetRace("daemon");
  SetClass("ranger");
	SetLevel(40);
	SetGender("male");
	SetProperty("durgorothNPC",1);
	SetTown("Durgoroth");
	SetMorality(-500);
	SetShort("Marlshak, the Master Hunter of Durgoroth");
	SetId( ({ "marlshak","master hunter","master","hunter" }) );
	SetLong("Marlshak is a medium sized Daemon, making him only "
        	"about six and a half feet tall. He looks very swift "
        	"and cunning, for a Daemon, but also very strong. He "
        	"is the leader of the Hunters in Durgoroth, and is not "
        	"one to take fighting against lightly.");
	SetCurrency("crystals", 50 + random(350));
	SetPlayerTitles(  ([
		"newbie" : "the Lowly Maggot, Initiate Hunter",
		"mortal" : "the Hoarder of Skulls",
		"hm" 		 : "the Flesh Eater",
		"legend" : "the Bloodthirsty Predator",
		"avatar" : "the Inescapable Devourer",
		]) );
    SetFriends(({"daemon","daemon guard","daemoness"}));
    SetMeleeAttackString("claws");
    SetMeleeDamageType(SLASH);
    SetFreeEquip( ([
    	"/std/weapon/projectile/long_bow":1
    	]) );
    }
