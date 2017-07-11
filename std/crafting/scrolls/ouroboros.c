#include <lib.h>
inherit LIB_RECIPE_SCROLL;

static void create() {
        ::create();
        SetId("design");
        SetKeyName("ouroboros design");
        SetAdjectives(({ "ouroboros", "strange"}));
        SetShort("a strange ouroboros design");
        SetRecipe("ouroboros ring");
        SetLong(
          "This dusty and somewhat unsettling scroll is cracked and parched "
          "with age, doodled upon with snakes, and for some reason has a "
          "crude turkey leg with a giant no symbol drawn around it featured "
          "prominently. It appears to be for some sort of magical ring, or "
          "perhaps some sort of turkey sandwich. Perhaps you should more "
          "closely 'read' it?");
        SetValue(50000);
}

