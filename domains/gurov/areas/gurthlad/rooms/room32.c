#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("top of a hill in a dead plain");
  SetLong("Looking out a endless, dead, dry plain can be seen. There "
          "is not much of interest here. Nothing can be seen  but the dead "
          "land rolling away over the horizon. In the semi darkness something "
          "can be seen rising into the sky to the west and a large tree can be "
          "seen off to the east.");
  SetObviousExits("north, south, east");
  SetExits( ([
          "north" : G_ROOMS + "/room25",
          "south" : G_ROOMS + "/room41",
          "east" : G_ROOMS + "/room33"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "The dead land stretches away in every "
          "direction. Nothing can be seen but dead grass and dirt as far as the "
          "eye can see.",
          "tree" : "A dead tree, its dead and blackened limbs stretch up "
          "towards the sky as if begging for mercy.",
          ({ "something", "sky" }) : "In the semi darkness what looks like "
          "a small column of smoke can be seen rising into the sky in the "
          "west."]) );
  SetSmell( ([
          "default" :  "A light wind brings a faint smell of death."]) );
  SetInventory( ([
          G_NPC + "/orc_scout" : 3 ]) );
  }
