#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
#include "../gurthlad.h"

static void create()  {
  room::create();
  SetShort("a dead plain");
  SetLong("A endless, dead, dry plain. There is not much of interest "
          "here. Nothing can be seen  but the dead land rolling away "
          "over the horizon. A road can be seen close to the north.");
  SetExits( ([
          "north" : GUROV_VIRTUAL + "gurovrd/-1,0",
          "south" : G_ROOMS + "/room2"]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of shriveled dead grass.",
          "dirt" : "Dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "The dead land stretches away in every "
          "direction. Nothing can be seen but dead grass and dirt as far "
          "as the eye can see.",
          "road" : "A dusty road running from east to west can be seen "
          "far to the north."]) );
  SetSmell( ([
          "default" :  "A light wind brings a faint smell of death."]) );
  SetInventory( ([
          G_OBJ + "/sign" : 1 ]) );
  }
