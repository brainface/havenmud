#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("recipe");
        SetKeyName("recipe");
        SetAdjectives( ({ "boot", "broth"}) );
        SetShort("a boot broth recipe");
        SetRecipe("boot broth");
        SetLong("A desperate recipe for starving sailors. It seems to involve "
          "cooking boots.");
        SetValue(500);
}

