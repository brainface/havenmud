#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("guide");
        SetKeyName("guide");
        SetAdjectives( ({ "guide", "to"}) );
        SetShort("a guide to spade making");
        SetRecipe("crude spade");
        SetLong("A short guide explaining how make a makeshift spade.");
        SetValue(300);
}

