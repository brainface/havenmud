#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("instructions");
        SetKeyName("mithril purifying instructions");
        SetAdjectives(({ "mithril", "purifying"}));
        SetShort("a list of instructions for purifying mithril");
        SetRecipe("mithril ingot");
        SetLong("This appears to be a complex flowchart of instructions for "
          "the simplest of mithril working. A sketch of a hex-free smelter "
          "and various notes on moon phase and so on are included. "
          "Perhaps you should more closely 'read' it?");
        SetValue(5000);
}


