/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../trog.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in a tunnel under Mount Trog");
  SetClimate("underground");
  SetAmbientLight(15);
  SetExits( ([
//    "east" : TROG_ROOM "spider01",
    "west" : TROG_ROOM "tunnel05",
    ]) );
  SetLong(
    "Directly to the east the shaft opens into a mess of web. The tunnel is hard to "
    "navigate due to the excessive amount of spider webs which line the tunnel walls. "
    
    );
  SetSmell("The cave is damp and musty.");
  SetListen("A strange clacking and chirping noise comes from the east.");
}