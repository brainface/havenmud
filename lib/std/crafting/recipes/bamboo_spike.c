// torak 10/27/12
#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("bamboo spike");
  SetUnique(1); // quest recipe, will not be autotaught--mahk
  SetCraftedObject(STD_CRAFTING "wood/bamboo_spike");
  SetMaterials( ([
    "bamboo shaft" : 1,
    ]) );
  SetSkills( ([
    "wood working" : 1,
    ]) );
  }

