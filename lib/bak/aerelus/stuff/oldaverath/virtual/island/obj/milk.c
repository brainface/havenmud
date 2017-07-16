#include <lib.h>
#include <meal_types.h>
#include <domains.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("milk");
    SetId( ({ "glass", "milk", "glass of milk" }) );
    SetShort("a tall glass of milk");
    SetLong("A tall glass of milk. Yum, eh?");
    SetMass(5);
    SetMealType(MEAL_DRINK);
    SetStrength(10);
    SetMealMessages("You slam back the tall glass of milk.",
                    "$N slams back the tall glass of milk like a pro.");
    SetEmptyName("bottle");
    SetEmptyShort("an empty glass");
    SetEmptyLong("The empty glass still retains some milky residue.");
}
