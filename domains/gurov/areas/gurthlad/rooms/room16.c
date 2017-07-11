#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "There is not much of interest here. Nothing can be seen but "
         "the brown land stretching into the "
         "distance.");
  SetObviousExits("northeast, east, west");
  SetExits( ([
          "northeast" : G_ROOMS+"/room8.c",
          "east" : G_ROOMS+"/room17.c",
          "west" : G_ROOMS + "/room15.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon."]) );
  SetInventory( ([ G_NPC + "/human_explr.c" : 1 ]) );
  }
