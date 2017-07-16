#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("guide", "torchmaking");
        SetKeyName("guide");
        SetAdjectives( ({ "guide","on"}) );
        SetShort("a guide on torchmaking");
        SetRecipe("torch");
        SetLong("A simple pamphlet explaining how to make torches and not set "
          "yourself on fire.");
        SetValue(100);
}

