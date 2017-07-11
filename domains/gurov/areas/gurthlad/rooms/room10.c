
#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  
  room::create();
  SetShort("a shadowed plain");
  SetLong("A dusty, dead plain. There is nothing much of interest here. "
         "Nothing can be seen but the brown land stretching away "
         "into the distance. In the semi-darkness a small hill can be "
         "seen to the west.");
  SetObviousExits("south, east, northwest");
  SetExits( ([
          "south" : G_ROOMS+"/room9.c",
          "northwest" : G_ROOMS+"/room4.c",
          "east" : G_ROOMS+"/room11.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetListen( ([
          "default" : "A faint squealing sound can be heard in the "
          "distance."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon. ",
          "hill" : "A small hill, barely more than a hump in the "
          "flatness."]) );
  }
