// NOTE: This NPC is not currently intended to be put in the game

#include <lib.h>
inherit LIB_NPC;
#include "../durgoroth.h"
#include "target.h"

void Hunted();
void CheckInvis();
void GearUp();

static void create() {
	npc::create();
	SetKeyName("assassin");
	SetId( ({ "fanatic","Saa'HaGoth assassin","fanatical assassin" }) );
	SetShort("a fanatical Saa'HaGoth assassin");
	SetLong("A frenzied nosferatu bent on the destruction of all "
					"heretics.");
	SetRace("nosferatu");
	SetClass("rogue");
	SetClass("fighter");
	SetSkill("conjuring", 50);
	SetSkill("evokation", 50);
	SetLevel(85);
	SetGender("male");
	SetMorality(-1500);
	SetInventory( ([
		 D_OBJ + "/nosf_dagger" : "wield dagger in left hand",
		 D_OBJ + "/blood_sword" : "wield sword",
		 D_OBJ + "/nosf_armour" : "wear armour",
		]) );
	SetSpellBook( ([
		"invisibility" : 100,
		"energy wall"  : 100,
		"disintegrate" : 100,
		]) );
	SetAction( 20, (: CheckInvis :) );
	SetCombatAction( 40, ({ 
		"!disorient",
   	"!cast disintegrate",
		"!cast energy wall", }) );
	SetEncounter( (: Hunted :));
	}

void CheckInvis() {
	if (!( this_object()->GetInvis()))
		this_object()->eventForce("cast invisibility");
	}

void Hunted() {
	if ( this_player()->GetKeyName() == target ) {
		this_object()->eventForce("say Die Heretic!");
		this_object()->eventForce("backstab "+target);
		this_object()->eventForce("follow "+target);
		call_out( (: GearUp :), 5 );
		}
	}

void GearUp() {
	call_out(this_object()->eventForce("cast aura"), 10);
	}
