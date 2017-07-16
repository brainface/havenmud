#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
  ::create();
  SetId("instructions");
  SetKeyName("iron golem instructions");
  SetAdjectives(({ "iron", "golem"}));
  SetShort("a list of instructions for creating a body for an iron golem");
  SetRecipe("iron golem");
  SetLong("This appears to be a simple list of instructions for "
          "creating a body for a golem. A sketch of a large humanoid body and "
		  "a smelter with various notes on temperature and so on are included. "
          "Perhaps you should more closely 'read' it?");
  SetValue(5000);
}