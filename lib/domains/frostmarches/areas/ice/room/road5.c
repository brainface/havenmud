#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an offshoot of cold road");
  SetClimate("sub-arctic");
  SetLong("This offshoot does not look as well-traveled as the "
    "normal road.  Exits lead north and southeast.  The "
    "weather feels colder to the north.");
  SetObviousExits("north, southeast");
  SetItems( ([ ({ "cold weather", "weather"}):
    "The weather is getting colder to the north.",
    ({ "area", "road", "offshoot"}): (: GetLong :)]) );
  SetExits( ([ "north" : ICE_ROOM + "/room1.c",
      "southeast": ICE_ROOM + "/road4.c"]) );
}
