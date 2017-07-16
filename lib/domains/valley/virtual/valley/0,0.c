
#include <lib.h>
#include <domains.h>

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetShort("The Valley Crossroads");
  SetLong(
    "This appears to be a nexus of traffic through the Valley, as the road is "
    "well maintained and uncluttered by deadfall. However, there's oddly not "
    "a lot of footprints and not a single wagon rut. The leaves of the "
    "surrounding trees, however, are bent this way and that as if a great "
    "wind had moved through, heading north."
  );
  SetExits( ([
    "east" : VALLEY_VIRTUAL "valley/1,0",
    "west" : VALLEY_VIRTUAL "valley/-1,0",
    "north" : VALLEY_VIRTUAL "valley/0,1",
    "northeast" : VALLEY_VIRTUAL "valley/1,1",     
  ]) );
  SetInventory( ([
    VALLEY_VIRTUAL "sign/valley00" : 1,
  ]) );

}


