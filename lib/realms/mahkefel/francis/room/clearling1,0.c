/* Field0,1
 * An empty field in front of
 * all this wagonage
 *
 */

#include <lib.h>
#include "../francis.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-tropical");
  SetDomain("Havenwood");
  SetShort("A grassy clearing");
  SetLong("Clearly, it contains grass.");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "A bird chitters angrily above in something that sounds annoyingly like gnomish.",
  ]) );

  SetSmell( ([
    "default" : "Mud and pollen mix together in some sort of ill-advised stew."
  ]) );
  SetExits( ([
      "north" : FRANCIS_ROOM "barn1,1",
      "east"  : FRANCIS_ROOM "clear2,0"
  ]) );

}
