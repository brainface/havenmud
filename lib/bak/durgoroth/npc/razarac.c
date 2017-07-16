// Title : Durgoroth Town
// File: razarac.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	Razarac Taurang, cavalier leader of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_LEADER;
#include "../durgoroth.h"
#include "guardian.h"
#include "rescueme.h"

void DoAction();

static void create() {
	leader::create();
	SetKeyName("razarac");
	SetId( ({ "razarac taurang","master of the blades",
						"master of Saahagoth","taurang" }) );
  SetShort("Razarac Taurang, Master of the Blades");
	SetLong("Razarac is the Master of the knights of the Nosferatu "
          "crusade, also known as the Blades of Chaos. He "
					"is an experienced warrior and commander. And he could "
					"easilly dispatch all but the hardiest opponents.");
	SetRace("nosferatu");
	SetClass("cavalier");
  SetNoJoin(1);
	SetLevel(45);
	SetGender("male");
	SetMorality(-750);
	SetProperty("durgorothNPC", 1);
	SetInventory( ([
		 D_OBJ + "/katana" : "wield katana",
		 D_OBJ + "/blood_sword" : "wield blood sword",
		 D_OBJ + "/nosf_armour" : "wear armour",
		 D_OBJ + "/crusade_shield" : "wear shield on left arm",
		 D_OBJ + "/crusade_cloak" : "wear cloak",
		]) );
	SetCurrency("crystals", 200 + random(250));
	SetCombatAction(35, (: DoAction :) );
	SetTown("Durgoroth");
	SetReligion("Saahagoth");
	SetPlayerTitles( ([
		"newbie" : "the Apprentice Dark Knight",
    "mortal" : "the Dark Knight",
    "hm" 		 : "the Feared Dark Knight",
    "legend" : "the Legendary Dark Knight",
		"avatar" : "the One From Whom All Light Flees",
		"necromancer" : "the Dark Knight of the Undead Realm",
		"cleric" : "the Unholy Knight of Evil",
		]) );
	SetFriends( friends );
	SetFreeEquip( ([
		"/std/weapon/pierce/fencing_sword":1
		]) );
	}

void DoAction() {
	if(random(2))
		leaderToMe();
	else {
		object target = this_object()->GetCurrentEnemy();
		this_object()->eventForce("slice "+target->GetKeyName()+
			" with katana");
		}
	}
