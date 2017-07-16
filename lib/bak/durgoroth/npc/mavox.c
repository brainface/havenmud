// Title: Durgoroth Town
// File: mavox.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: Mavox, General store shop keeper
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
inherit LIB_VENDOR;
#include "../durgoroth.h"
#include "rescueme.h"

static void create() {
	vendor::create();
	SetKeyName("mavox");
	SetShort("Mavox the shopkeep");
	SetId( ({ "mavox the shopkeep","shopkeep","shopkeeper" }) );
	SetLong("Mavox is a respectable citizen. And while "
					"he is not know for his love of other races "
					"he has never turned away any person with "
					"money in their pockets. He is dressed in "
					"a simple nosferatu garb, and is wearing "
					"a apron.");
	SetRace("nosferatu");
  SetTown("Durgoroth");
  SetReligion("Saahagoth");
	SetClass("rogue");
	SetLevel(20);
	SetGender("male");
	SetMorality(-350);
	SetProperty("durgorothNPC", 1);
	SetVendorType(VT_ALL);
	SetLocalCurrency("crystals");
	SetCurrency("crystals", 10 + random(200));
	SetStorageRoom( D_ROOM +"/sr_general");
	SetCombatAction( 30, (: summonGuard, this_player() :) );
	SetDie( (: IDie :) );
 }
