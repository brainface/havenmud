#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("silver ingot");
        SetCraftedObject(STD_CRAFTING "metal/silver_ingot");
        SetMaterials( ([
          "silver nugget" : 2,
          ]) );
        SetSkills( ([
          "metal working" : 20,
        ]) );
}

