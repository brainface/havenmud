#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest here. "
           "Nothing can be seen  but the dead land rolling away over the "
           "horizon.");
  SetObviousExits("northwest, south, west");
  SetExits( ([
           "south" : G_ROOMS + "/room48",
           "west" : G_ROOMS + "/room49",
           "northwest" : G_ROOMS + "/room51"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
           ({ "plain", "land" }) : "The dead land stretches away in every "
           "direction. Nothing can be seen but dead grass and dirt as far as "
           "the eye can see."]) );
  SetSmell( ([
           "default" :  "A light wind brings a faint smell of death."]) );
  SetInventory( ([
           G_NPC + "/orc_scout" : 2 ]) );  
  }
