#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dead, dry plain. "
         "Nothing can be seen but the brown land stretching into the "
         "distance. In the semi-darkness a hill can be seen to the "
         "west.");
  SetObviousExits("north, northwest, southwest");
  SetExits( ([
          "southwest" : G_ROOMS+"/room18.c",
          "north" : G_ROOMS+"/room10.c",
          "northwest" : G_ROOMS+ "/room6.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          "hill" : "A small hill to the west, it is barely more than "
          "a lump in the flatness."]) );
  }
