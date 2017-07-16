#include <lib.h>
inherit LIB_SAGE;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	sage::create();
	SetKeyName("shavoy");
	SetRace("nosferatu");
	SetShort("Shavoy the Historian");
	SetId( ({ "shavoy the historian","historian" }) );
	SetLong("Shavoy is the most learned Nosferatu historian. "
					"He knows almost everything there is to know about "
					"the nosferatu.");
	SetGender("male");
	SetClass("evoker");
	SetReligion("Saahagoth");
	SetMorality(-350);
	SetProperty("durgorothNPC", 1);
	SetSpellBook( ([
		"missile"    : 100,
		"fireball"   : 100,
		"lava storm" : 100,
		"sphere"     : 100,
		]) );
  SetTaughtLanguages( ({"Blaodric","Enlan","Eltherian","Gryshnak","Uruk"}));
	SetLocalCurrency("crystals");
	SetCharge(300);
	SetLevel(35);
	SetCurrency("crystals", 25 + random(200));
	SetCombatAction(35,({ 
		"!cast missile",
		"!cast fireball",
		"!cast lava storm",
		"!cast sphere",
		(: summonGuard, this_player() :),
		}) );
	SetDie( (: IDie :) );
 }


