#include <lib.h>
#include "../caves.h"
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("spring");
    SetShort("a spring coming from a wall");
    SetLong("This is a small, slow flowing spring coming from a "
            "hole in the wall.  It flows down the wall, then disappears "
            "into a small hole in the floor.  The water is clear, "
            "tasteless and very, very cold.");
    SetMealType(MEAL_DRINK);
    SetPreventGet("You can't get a spring");
   SetEmptyItem(CAVES_OBJ + "spring");
    SetStrength(45);
    SetMealMessages( ({
                       "$N drink from a stream.",
                       "$N drinks from a stream.",
                   }) );
}
