#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("burning silver necklace");
        SetCraftedObject(STD_CRAFTING "metal/burning_silver_small");
        SetMaterials( ([
          "silver ruby necklace" : 1,
          ]) );
        SetSkills( ([
          "enchantment" : 50,
          ]) );
}

