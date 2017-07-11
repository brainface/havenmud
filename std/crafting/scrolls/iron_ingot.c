#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("instructions");
        SetKeyName("iron smelting instructions");
        SetAdjectives(({ "iron", "smelting"}));
        SetShort("a list of instructions for purifying iron");
        SetRecipe("iron ingot");
        SetLong("This appears to be a simple list of instructions for "
          "basic iron smelting. A sketch of a smelter and various "
          "notes on temperature and so on are included. "
          "Perhaps you should more closely 'read' it?");
        SetValue(5000);
}

