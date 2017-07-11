#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("darkfire torch");
  SetCraftedObject(STD_LIGHT "torch_dark");
  SetCraftingMessage( ({ "coat" , "$agent_name $agent_verb one end of a scrap "
    "of wood with nasty looking gristle."}) );
  SetMaterials( ([
    "scrap wood" : 1,
    "gristle"    : 1
    ]) );
  SetSkills( ([
    "natural working" : 5,
    "wood working" : 5,
  ]) );
}


