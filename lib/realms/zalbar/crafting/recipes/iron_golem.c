#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("iron golem");
  //SetCraftedObject(STD_CRAFTING "metal/iron_golem");
  SetCraftedObject("/realms/zalbar/crafting/iron_golem");
  SetMaterials( ([
    "iron_ingot"     : 20,
	"diamond"        : 2,
	"metal hardener" : 1,
    ]) );
  SetSkills( ([
    "metal working" : 100,
    ]) );
}