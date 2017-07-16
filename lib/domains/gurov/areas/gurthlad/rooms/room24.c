#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "There is not much of interest here. Nothing can be seen but "
         "the brown land stretching into the "
         "distance. In the semi-darkness a withered dead tree can be seen "
         "close to the west. What looks like a column of smoke can be seen "
         "rising into the sky in the southwest.");
  SetObviousExits("north, south, west");
  SetExits( ([
          "north" : G_ROOMS+"/room15",
          "south" : G_ROOMS+"/room31",
          "west" : G_ROOMS + "/room23"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          "tree" : "A large, withered, dead tree can be seen to the south. "
          "Its blackened limbs stretch up against sky as if it is begging "
          "for mercy.",
  "smoke" : "A column of black wood smoke rising into the sky in the southwest."]) );
  }
