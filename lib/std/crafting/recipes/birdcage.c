#include <lib.h>
#include <std.h>
inherit LIB_RECIPE;

static void create() {
        ::create();
        SetRecipe("gilded birdcage");
        SetCraftedObject("/std/mission_obj/birdcage");
        SetMaterials( ([
          "bronze ingot" : 2,
          "gold ingot" : 1,
          ]) );
        SetSkills( ([
          "metal working" : 25,
          ]) );
}

