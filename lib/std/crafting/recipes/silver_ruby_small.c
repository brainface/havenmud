#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("silver ruby necklace");
        SetCraftedObject(STD_CRAFTING "metal/silver_ruby_small");
        SetMaterials( ([
          "silver nugget" : 2,
          "ruby" : 1,
          ]) );
        SetSkills( ([
          "metal working" : 50,
          "natural working" : 50,
          ]) );
}


