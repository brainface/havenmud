// Title : Durgoroth Town
// File: porridge.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract:	A bowl of porridge, sold by the Dark Sun Inn
//
// Revision History: 
//

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
	meal::create();
	SetKeyName("porridge");
	SetId( ({"bowl of porridge","bowl"}) );
	SetShort("a bowl of porridge");
	SetLong("A large bowl of ambiguous mush, called porridge.");
	SetMass(50);
	SetMealType(MEAL_FOOD);
	SetStrength(20);
	SetMealMessages("Oh, this porridge is much too cold.",
									"$N eats his porridge.");
	}
