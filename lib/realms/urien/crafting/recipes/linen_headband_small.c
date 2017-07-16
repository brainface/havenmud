#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
	::create();
	SetRecipe("white linen headband");
	SetCraftedObject(STD_CRAFTING "textile/headband_small");
	SetMaterials( ([
	  "linen scrap" : 3,
	  ]) );
	SetSkills( ([
	  "textile working" : 1,
	  ]) );
}