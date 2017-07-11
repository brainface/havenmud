#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("guide");
        SetKeyName("guide");
        SetAdjectives( ({ "guide", "to"}) );
        SetShort("a guide to shim making");
        SetRecipe("shim");
        SetLong("A short guide explaining how make a homemade prybar for "
          "bypassing simple locks.");
        SetValue(500);
}

