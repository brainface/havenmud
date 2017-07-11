#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a hill in shadowed plain");
  SetLong("Looking out from the hill the dusty, dead plain can be seen. "
         "Nothing can be seen but the brown land stretching into the "
         "distance. In the semi-darkness something can be seen rising "
         "into the sky in the southwest.");
  SetObviousExits("north, southeast, southwest");
  SetExits( ([
          "southeast" : G_ROOMS+"/room9.c",
          "southwest" : G_ROOMS+"/room8.c",
          "north" : G_ROOMS+"/room4.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of shriveled dead grass.",
          "dirt" : "Dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          ({"something", "sky"}) : "You can faintly see a column of smoke "
          "rising into the sky in the southwest."]) );
  SetInventory( ([ G_NPC + "/orc_scout" : 2 ]) );
}
