// Title: Durgoroth Town
// File: narya.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: Narya, Durgoroth bank teller
// Revision History: 
//

#include <lib.h>
inherit LIB_TELLER;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	teller::create();
	SetBankName("Durgoroth Bank");
	SetLocalCurrency("crystals");
	SetCurrencies( ({ "imperials", "bloodgems", "chits",
		"orcteef", "nuggets"}) );
	SetLocalFee(0);
	SetNonLocalFee(2);
	SetExchangeFee(0.01);
	SetKeyName("narya");
	SetShort("Narya, mistress of the bank");
	SetId( ({ "narya","mistress", "teller" }) );
	SetLong("Narya is the mistress of the Durgoroth bank. "
					"She is very polite and professional about her "
					"job, but is known to be one who gets very angry "
					"when given any trouble.");
	SetRace("nosferatu");
	SetGender("female");
	SetClass("rogue");
	SetTown("Durgoroth");
	SetReligion("Saahagoth");
	SetLevel(30);
	SetMorality(-450);
	SetProperty("durgorothNPC", 1);
	SetCurrency("crystals",random(50));
	SetCombatAction( 30, ({
		(: summonGuard, this_player() :),
		"!disorient",
		}) );
	SetDie( (: IDie :) );
	}
