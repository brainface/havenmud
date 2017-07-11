#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("instructions");
        SetKeyName("silver smelting instructions");
        SetAdjectives(({ "silver", "smelting"}));
        SetShort("a list of instructions for purifying silver");
        SetRecipe("silver ingot");
        SetLong("This appears to be a simple list of instructions for "
          "basic silver smithing. A sketch of a smelter and various "
          "notes on temperature and so on are included. "
          "Perhaps you should more closely 'read' it?");
        SetValue(5000);
}

