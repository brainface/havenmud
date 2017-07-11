#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "There is not much of interest here. Nothing can be seen but "
         "the brown land stretching into the "
         "distance. In the semi-darkness a large dead tree can be seen to the "
         "south.");
  SetObviousExits("north, south");
  SetExits( ([
          "south" : G_ROOMS+"/room34.c",
          "north" : G_ROOMS+"/room18.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          "tree" : "A large, withered, dead tree can be seen to the south. "
          "Its blackened limbs stretch up against sky as if it is begging "
          "for mercy."]) );
  }
