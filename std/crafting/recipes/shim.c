// mahkefel@haven
#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("shim");
  SetCraftedObject(STD_CRAFTING "survival/shim");
  SetCraftingMessage( ({"bang", "$agent_name $agent_verb some scrap metal "
    "into a shim."}) );
  SetMaterials( ([
    "scrap metal" : 1,
    ]) );
  SetSkills( ([
     "lockpicking"   : 25,
     "metal working" : 25,
  ]) );
}

