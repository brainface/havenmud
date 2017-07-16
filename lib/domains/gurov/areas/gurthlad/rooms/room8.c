#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "There is not much of interest here. Nothing can be seen but "
         "the brown land stretching into the "
         "distance. In the semi-darkness a hill can be seen to the "
         "east.");
  SetObviousExits("north, northeast, southeast, southwest");
  SetExits( ([
          "southeast" : G_ROOMS+"/room17.c",
          "north" : G_ROOMS+"/room7.c",
          "northeast" : G_ROOMS+"/room6.c",
          "southwest" : G_ROOMS + "/room16.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          "hill" : "A small hill to the east, it is barely more than "
          "a lump in the flatness."]) );
  SetInventory( ([ G_NPC + "/orc_scout.c" : 1 ]) );
  }
