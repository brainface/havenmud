#include <lib.h>
#include "../gurthlad.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetShort("a shadowed plain");
  SetLong("A dusty, dead plain. Nothing can be seen but the brown "
         "land stretching away into the distance. In the semi-darkness "
         "a road can be seen off to the north. In the ground all about "
         "are some tubers growing.");
  SetObviousExits("south");
  SetExits( ([
          "south" : G_ROOMS+"/room12.c"]) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          " road " : "There is a road a ways to the south, it streaches off "
          "out of sight.",
          ({ "tuber", "tubers", "plant", "plants", "ground" }) : 
          "There are small brown tuber plants growing out of the ground "
          "all around. These are the plants that Squealers like to eat."]) );
  SetInventory( ([ G_NPC + "/squealer" : 2 ]) );
  }
