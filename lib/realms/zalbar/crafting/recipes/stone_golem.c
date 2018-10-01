#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("stone golem");
  SetCraftedObject("/realms/zalbar/crafting/stone_golem");
  SetMaterials( ([
    "stone block" : 1,
	"onyx"        : 2,
	"chisel"      : 1,
	"hammer"      : 1,
	"amber oil"   : 1,
    ]) );
  SetSkills( ([
    "natural working" : 50,
    ]) );
}
