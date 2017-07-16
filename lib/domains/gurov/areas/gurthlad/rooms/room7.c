#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "There is not mush of interest here. Nothing can be seen but "
         "the brown land stretching into the "
         "distance. In the semi-darkness a hill can be seen to the "
         "east.");
  SetObviousExits("south, northeast");
  SetExits( ([
          "northeast" : G_ROOMS+"/room4.c",
          "south" : G_ROOMS+"/room8.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          "hill" : "A small hill to the east, it is barely more than "
          "a lump in the flatness."]) );
  }
