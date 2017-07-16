#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("sketch");
        SetKeyName("gilded birdcage sketch");
        SetAdjectives(({ "gilded","birdcage"}));
        SetShort("a sketch of a gilded birdcage");
        SetRecipe("gilded birdcage");
        SetLong("This sheet of paper has a finely drawn sketch of a "
          "fancy birdcage drawn upon it. It looks detailed enough "
          "that you could reproduce the design yourself, if you "
          "'read' it closely enough?");
        SetValue(1000);
}

