// mahkefel@haven
#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
    SetRecipe("crude spade");
  SetCraftedObject(STD_CRAFTING "survival/crude_spade");
  SetCraftingMessage( ({ ({"force", "affix" }),
    "$agent_name $agent_verb some scrap metal into a spade-like shape, "
    "the $agent_verb it to a short piece of wood with some leather straps."}) );
  SetMaterials( ([
    "leather strip"   : 1,
    "scrap metal" : 1,
    "scrap wood"  : 1,    
    ]) );
  SetSkills( ([
     "leather working" : 15,
     "metal working"   : 15,
     "wood working"    : 15,
  ]) );
}

