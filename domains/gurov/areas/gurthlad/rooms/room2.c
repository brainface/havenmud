#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dusty, dead plain. There is not much of interest here. "
         "The dusty brown land streches away into the distance. "
         "In the semi-darkness a road can be seen off "
         "to the north.");
  SetObviousExits("north, south");
  SetExits( ([
          "north" : G_ROOMS+"/room1.c",
          "south" : G_ROOMS+"/room3.c"]) );
  SetListen( ([
          "default" : "A faint squealing sound can be heard in "
          "the distance."]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but the dead land stretching away.",
          "road" : "A road a short distance to the north."]) );
  }
