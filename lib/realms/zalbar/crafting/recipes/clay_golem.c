#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
  ::create();
  SetRecipe("clay golem");
  SetCraftedObject("/realms/zalbar/crafting/metal/clay_golem");
  SetMaterials( ([
    "clay block" : 1,
	"emerald"    : 2,
	"tar"        : 1,
    ]) );
  SetSkills( ([
    "natural working" : 25,
    ]) );
}
