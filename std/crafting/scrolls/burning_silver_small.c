#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("rune");
        SetKeyName("necklace rune");
        SetAdjectives(({ "silver","burning","necklace"}));
        SetShort("a burning silver necklace rune");
        SetRecipe("burning silver necklace");
        SetValue(5000);
}

