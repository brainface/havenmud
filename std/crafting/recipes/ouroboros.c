#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("ouroboros ring");
        SetCraftedObject(STD_CRAFTING "mithril/ouroboros");
        SetMaterials( ([
          "mithril ingot" : 1,
          "bloodstone" : 2,
          "sandworm spice" : 1,
          ]) );
        SetSkills( ([
        "mithril working" : 100,
        "natural working" : 100,
        "enchantment" : 200,
        ]) );
}

