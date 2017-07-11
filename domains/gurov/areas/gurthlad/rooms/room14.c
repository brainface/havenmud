#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest "
          "here but a large dead tree to the southeast. Nothing can be seen "
          "in the distance but the dead land rolling away over the horizon.");
  SetObviousExits("northeast, south");
  SetExits( ([
          "northeast" : G_ROOMS + "/room47",
          "south" : G_ROOMS + "/room22"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "The dead land stretches away in every "
          "direction. Nothing can be seen but dead grass and dirt as far "
          "as the eye can see.",
          ({ "tree", "dead tree", "large tree", "large dead tree" }) : "A large "
          "dead tree, its withered and blackened limbs stretch up against the "
          "sky as if begging for mercy."]) );
  SetSmell( ([
                 "default" :  "A light wind brings a faint smell of death."]) );
  SetInventory( ([
                 G_NPC + "/orc_scout" : 1]) );
  }
