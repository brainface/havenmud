#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dusty, dead plain. There is not much of interest here. "
         "Nothing can be seen but the brown land stretching away "
         "into the distance. In the semi-darkness a road can be seen "
         "fairly far to the north and a small hill can be seen to "
         "the south.");
  SetObviousExits("north, south, west");
  SetExits( ([
          "south" : G_ROOMS+"/room4.c",
          "west" : G_ROOMS+"/room5.c",
          "north" : G_ROOMS+"/room2.c"]) );
  SetListen( ([
          "default" : "A squealing sound can be heard close by."]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered brown dead grass.",
          "dirt" : "Dusty, gray, lifeless dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt and a small hill.",
          "road" : "A road a good distance to the north.",
          "hill" : "A small hill, barely more than a hump in the "
          "flatness."]) );
  }
