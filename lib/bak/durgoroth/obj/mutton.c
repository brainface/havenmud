// Title : Durgoroth Town
// File: mutton.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract:	A leg of mutton, sold by the Durgoroth Inn
//
// Revision History: 
//

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
	meal::create();
	SetKeyName("mutton");
	SetId( ({"leg of mutton","leg"}) );
	SetShort("a leg of mutton");
	SetLong("A large roasted leg of mutton.");
	SetMass(50);
	SetMealType(MEAL_FOOD);
	SetStrength(40);
	SetMealMessages("You wolf down your mutton like a barbarian.",
									"$N wolfs down "+possessive(this_player())+" leg of mutton "
									"like a barbarian.");
	}
