#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("flesh golem");
  //SetCraftedObject(STD_CRAFTING "metal/iron_golem");
  SetCraftedObject("/realms/zalbar/crafting/flesh_golem");
  SetMaterials( ([
    "corpse"        : 6,
	"bloodstone"    : 2,
	"coarse thread" : 1,
    ]) );
  SetSkills( ([
    "natural working" : 10,
	"textile working" : 10,
    ]) );
}
