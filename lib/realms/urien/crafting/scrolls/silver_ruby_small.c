#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("design");
        SetKeyName("necklace design");
        SetAdjectives(({ "silver","ruby","necklace"}));
        SetShort("a silver ruby necklace design");
        SetRecipe("silver ruby necklace");
        SetValue(5000);
}


