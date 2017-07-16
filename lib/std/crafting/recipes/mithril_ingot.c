#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("mithril ingot");
        SetCraftedObject(STD_CRAFTING "mithril/mithril_ingot");
        SetMaterials( ([
          "mithril nugget" : 2,
          ]) );
        SetSkills( ([
        "mithril working" : 25,
        ]) );
}

