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
         "north.");
  SetObviousExits("south, northeast, west");
  SetExits( ([
          "northeast" : G_ROOMS+"/room9.c",
          "south" : G_ROOMS+"/room26.c",
          "west" : G_ROOMS + "/room17.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          "hill" : "A small hill to the north, it is barely more than "
          "a lump in the flatness."]) );
  SetInventory( ([ G_NPC + "/orc_scout.c" : 2 ]) );
  }
