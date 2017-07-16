#include <lib.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest here. "
           "Nothing can be seen  but the dead land rolling away over the "
           "horizon. A road can be seen to the north.");
  SetObviousExits("north, south, southeast");
  SetExits( ([
           "south" : G_ROOMS + "/room49",
           "north" : G_ROOMS + "/room53",
           "southeast" : G_ROOMS + "/room50"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
           ({ "plain", "land" }) : "The dead land stretches away in every "
           "direction. Nothing can be seen but dead grass and dirt as far as "
           "the eye can see.",
           "road" : "A dusty road running from east to west can be seen to "
           "the north."]) );
  SetSmell( ([
           "default" :  "A light wind brings a faint smell of death."]) );
  SetInventory( ([
           G_NPC + "/orc_scout" : 1 ]) );  
  }
