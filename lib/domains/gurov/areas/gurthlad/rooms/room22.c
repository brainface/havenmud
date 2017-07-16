#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest "
          "here but a large dead tree to the east. Nothing can be seen in "
          "the distance but the dead land rolling away over the horizon. A "
          "column of smoke can be seen rising into the sky in the south.");
  SetObviousExits("north, east");
  SetExits( ([
          "east" : G_ROOMS + "/room23",
          "north" : G_ROOMS + "/room14"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "The dead land stretches away in every "
          "direction. Nothing can be seen but dead grass and dirt as far "
          "as the eye can see.",
          ({ "tree", "dead tree", "large tree", "large dead tree" }) : "A "
          "large dead tree. its withered and blackened limbs stretch up "
          "against the sky as if begging for mercy.",
          ({ "smoke", "column of smoke", "sky" }) : "A small column of "
          "grey smoke can be seen rising into the sky in the south."]) );
  SetSmell( ([
          "default" :  "A light wind brings a faint smell of death."]) );
  SetInventory( ([
          G_NPC + "/human_explr" : 1]) );
  }
