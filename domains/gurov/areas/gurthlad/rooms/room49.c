#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest here. "
          "Nothing can be seen  but the dead land rolling away over the "
          "horizon.");
  SetObviousExits("north, east, southwest");
  SetExits( ([
           "north" : G_ROOMS + "/room51",
           "east" : G_ROOMS + "/room50",
           "southwest" : G_ROOMS + "/room47"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
           ({ "plain", "land" }) : "The dead land stretches away in every "
           "direction. Nothing can be seen but dead grass and dirt as far as "
           "the eye can see."]) );
  SetSmell( ([
           "default" :  "A light wind brings a faint smell of death."]) );
  }
