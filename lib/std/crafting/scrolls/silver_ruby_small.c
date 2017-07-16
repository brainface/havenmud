#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("design");
        SetKeyName("necklace design");
        SetAdjectives(({ "silver","ruby","necklace"}));
        SetShort("a silver ruby necklace design");
        SetRecipe("silver ruby necklace");
        SetLong("Several profiles of a piece of jewerly are etched with "
          "painstaking penmanship in intricate detail along this parchment. "
          "It looks to be a very beautiful design, if somewhat small. "
          "Perhaps you should more closely 'read' it?");
        SetValue(5000);
}

