#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest here. "
          "Nothing can be seen  but the dead land rolling away over the "
          "horizon, a small hill to the west, and a dead tree to the east.");
  SetObviousExits("east, west");
  SetExits( ([
          "east" : G_ROOMS + "/room34",
          "west" : G_ROOMS + "/room32"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "The dead land stretches away in every "
          "direction. Nothing can be seen but dead grass and dirt as far as the "
          "eye can see.",
          "hill" : "A small hill, barely more than a small hump in the flatness "
          "rises up to the west.",
          "tree" : "A dead tree, its dead and blackened limbs stretch up "
          "towards the sky as if begging for mercy."]) );
  SetSmell( ([
          "default" :  "A light wind brings a faint smell of death."]) );
  SetInventory( ([
          G_NPC + "/orc_scout" : 2 ]) );
  }
