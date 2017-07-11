#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("bronze ingot");
        SetCraftedObject(STD_CRAFTING "metal/bronze_ingot");
        SetMaterials( ([
          "copper nugget" : 1,
          "tin nugget" : 1,
          ]) );
        SetSkills( ([
          "metal working" : 5,
        ]) );
}

