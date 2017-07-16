#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("iron ingot");
        SetCraftedObject(STD_CRAFTING "metal/iron_ingot");
        SetMaterials( ([
          "iron nugget" : 2,
          ]) );
        SetSkills( ([
           "metal working" : 50,
        ]) );
}

