// Title: Durgoroth Town
// File: fountain.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: The Durgoroth fountain
//
// Revision History: 
//

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
	meal::create();
	SetKeyName("fountain");
	SetShort("the Durgoroth fountain");
	SetId( ({ "durgoroth fountain" }) );
	SetMealType(MEAL_DRINK);
	SetLong("This is the fountain of Durgoroth. It is an "
					"ancient stone basin with ornate carvings of "
					"various beasts cavorting in the water.");
	SetPreventGet("You cannot take the fountain.");
  SetPortions(-1);
	SetStrength(15);
  SetMealMessages("You drink from the slightly metallic-tasting fountain.",
                  "$N drinks from the Durgoroth fountain.");
 }
