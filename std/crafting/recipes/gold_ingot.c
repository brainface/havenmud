#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("gold ingot");
        SetCraftedObject(STD_CRAFTING "metal/gold_ingot");
        SetMaterials( ([
          "gold nugget" : 2,
          ]) );
        SetSkills( ([
        "metal working" : 75,
        ]) );
}

