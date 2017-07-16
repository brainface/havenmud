// torak 10/27/12
#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
	::create();
	SetRecipe("bamboo spike");
	SetValue(100);
}
