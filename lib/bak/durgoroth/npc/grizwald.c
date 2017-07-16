// Title : Durgoroth Town
// File: grizwald.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	Grizwald, the mayor of Durgoroth town
//
// Revision History: 
//

#include <lib.h>
inherit LIB_MAYOR;
#include "../durgoroth.h"
#include "rescueme.h"

void DoAction();
void Splat( object who, object target );

static void create() {
	mayor::create();
	SetKeyName("grizwald");
	SetId( ({ "grizwald, lord of the gorithim","lord grizwald",
		"lord of the gorithim","gorithim lord","lord","grizwald",
		"mayor" }) );
	SetShort("Grizwald, Lord of the Gorithim");
	SetLong("Lord Grizwald is a massive and strikingly handsome "
		"man. He is a skilled warrior, and is famous for his "
		"many exploits. The greatest of which was uniting the "
		"scattered clans of humans in the region into the nation "
		"of the Gorithim. His greatest ambition is the conquest "
		"of all of Kailie, and with his new alliance with the "
		"Nosferatu crusade, it is a possibility.");
	SetRace("human");
	SetClass("fighter");
	SetClass("rogue");
	SetLevel(50);
	SetGender("male");
	SetMorality(-1000);
	SetProperty("durgorothNPC", 1);
	SetTown("Durgoroth");
	SetInventory( ([
		D_OBJ + "/lord_sword" : "wield sword",
		D_OBJ + "/lord_plate" : "wear armour",
		D_OBJ + "/fur_cloak" : "wear cloak",
		]) );
	SetCurrency("crystals", 300 + random(250) );
	SetAction( 10, "!speak If yea wish to join the mighty city "
		"of Durgoroth, I be the one to speak to." );
	SetCombatAction( 35, (: DoAction :) );
	SetDie( (: IDie :) );
	RemoveLanguage("Enlan");
	SetLanguage("Blaodric", 100, 1);
	}

void DoAction() {
	if(!random(3))
		leaderToMe();
	else if(random(2))
		Splat(this_object(), this_object()->GetCurrentEnemy());
	else
		this_object()->eventForce("hack");
	}

void Splat( object who, object target ) {
	message("splat", "Grizwald screams with "
		"%^BOLD%^RED%^BLOODLUST%^RESET%^ as he wades through "
		"your attacks to deliver a killing blow.",
		environment(who));
	who->GetWielded()[0]->eventStrike(target) + (5 + random(6));
	}
