/* 5/03 Libitina / newbie area / water from the creek */
// Fixed, 5 years later.. (Kairehn 01/06/2008)
#include <lib.h>
#include <std.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("creek");
    SetShort("creek water");
    SetId( ({"water","creek"}) );
    SetAdjectives( ({ "creek" , "cold" }) );
    SetLong("The cold creek water looks so clean and refreshing. It gurgles "
      "along, so tempting that someone might want to drink from it.");
    SetPreventGet("And just where would you put that much water?!");
    SetMass(500);
    SetInvis(1);   
    SetStrength(15);
    SetMealType(MEAL_DRINK);
    SetMealMessages("$N scoop up some water in your hand and drink it.",
      "$N scoops up some creek water and drinks it.");
}
