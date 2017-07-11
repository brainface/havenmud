#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("instructions");
        SetKeyName("bronze smelting instructions");
        SetAdjectives(({ "bronze", "smelting"}));
        SetShort("a list of instructions for smelting bronze");
        SetRecipe("bronze ingot");
        SetLong("This appears to be a simple list of instructions for "
          "basic bronze forging. A sketch of a smelter and various "
          "notes on temperature and so on are included. "
          "Perhaps you should more closely 'read' it?");
        SetValue(5000);
}

