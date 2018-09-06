#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("guide", "darkfire");
        SetKeyName("guide");
        SetAdjectives( ({ "guide","on"}) );
        SetShort("a guide on darkfire");
        SetRecipe("darkfire torch");
        SetLong("A simple pamphlet explaining how to make darkfire torches "
          "and not blind yourself.");
        SetValue(100);
}

