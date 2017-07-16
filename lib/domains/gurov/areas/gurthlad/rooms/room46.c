#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "There is not much of interest here. Nothing can be seen but "
         "the brown land stretching into the "
         "distance. There are brown tuber plants, of the type sqealers "
         "like, sticking out of the ground all around.");
  SetObviousExits("north, west");
  SetExits( ([
          "north" : G_ROOMS+"/room42.c",
          "west" : G_ROOMS+"/room45.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          ({ "tuber", "tubers", "plant", "plants" }) : "These brown, red "
          "leafed, tubers are all around. These plants are the squealers "
          "primary food."]) );
  SetInventory( ([ G_NPC + "/squealer.c" : 2 ]) );
  }
