#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("instructions");
        SetKeyName("gold purifying instructions");
        SetAdjectives(({ "gold", "purifying"}));
        SetShort("a list of instructions for purifying gold");
        SetRecipe("gold ingot");
        SetLong("This appears to be a simple list of instructions for "
          "basic gold smelting. A sketch of a smelter and various "
          "notes on temperature and so on are included. "
          "Perhaps you should more closely 'read' it?");
        SetValue(5000);
}

