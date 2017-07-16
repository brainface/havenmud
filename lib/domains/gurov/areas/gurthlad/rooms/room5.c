#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dusty, dead plain. Nothing can be seen but the brown land "
         "stretching away into the distance. Unlike much of the plain, "
         "there are some small tuber like plants here.");
  SetObviousExits("east");
  SetExits( ([
          "east" : G_ROOMS+"/room3.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "plain", "land" }) : "A dusty brown plain. You can't see anything "
          "in the distance.",
          ({ "plants", "plant", "tubers", "tuber" }) : "There are tops of "
          "small brown tuber plants sticking out of the ground. These "
          "are what the Squealers eat."]) );
  SetInventory( ([ G_NPC + "/squealer" : 2 ]) );
  }
