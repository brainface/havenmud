#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("torch");
  SetCraftedObject(STD_LIGHT "torch");
  SetCraftingMessage( ({"wrap", "$agent_name $agent_verb an oil-soaked "
    "rag around a scrap of wood."}) );
  SetMaterials( ([
    "scrap wood" : 1,
    "cloth rag"  : 1
    ]) );
  SetSkills( ([
    "textile working" : 5,
    "wood working" : 5,
  ]) );
}


