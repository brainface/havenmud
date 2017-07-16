#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
 
static void create() {
 
    room::create();
    SetShort("an open field");
    SetLong("At this point, it is clear that this clearing is something more "
          "than a pleasant field.  There is an ominous feeling about it, "
          "and the grass and dirt are torn up in several places.  A path "
          "leads downhill to the west, and the field continues to the south, "
          "with the road to the north.");
    SetItems( ([
          ({ "grass and dirt", "grass", "dirt" }) :
          "The grass and dirt of the field have been torn up by a large group "
          "of people walking through.",
          ({ "muddy ditch","ditch" }) :
          "The ditch is about five feet lower than the field, and it is "
          "muddy and wet.",
          ({ "distant road","road" }) :
          "The road can barely be seen in the distance to the north.",
          ({ "dirt path","path" }) :
          "This dirt path leads west into a ditch.",
          ({ "pleasant field", "open field", "field", "clearing" }) :
          "The clearing is quite calm and relaxing at this point.",
       ]) );
    SetExits( ([
          "north" : BEORN_ROOM + "road.c",
          "south" : BEORN_ROOM + "field2.c",
          "west" : BEORN_ROOM + "field4.c",
          ]) );
    SetInventory( ([
          BEORN_NPC + "osoldier.c" : 1,
          ]) );
    SetListen( ([
          "default" : "The occasional scream can be heard.",
          ]) );
}
