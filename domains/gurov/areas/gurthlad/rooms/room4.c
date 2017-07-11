#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dusty, dead plain. There is not much of interest here. "
         "Nothing can be seen but the brown land stretching away "
         "into the distance. In the semi-darkness you can see a small "
         "hill to the south.");
  SetObviousExits("north, south, southeast, southwest");
  SetExits( ([
          "south" : G_ROOMS+"/room6.c",
          "southeast" : G_ROOMS+"/room10.c",
          "southwest" : G_ROOMS+"/room7.c",
          "north" : G_ROOMS+"/room3.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered brown dead grass.",
          "dirt" : "Dusty, gray, lifeless dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt and a small hill nearby.",
          "hill" : "A small hill, barely more than a hump in the "
          "flatness."]) );
  }
