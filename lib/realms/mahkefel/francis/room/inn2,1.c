/* A small inn 
 *
 *
 */

#include <lib.h>
#include "../francis.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  //SetClimate("sub-tropical");
  SetDomain("Havenwood");
  SetShort("A stone inn");
  SetLong("It's hard to tell if this building is made of stone or if a pile of gravel just sort of fell that way.");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "A bird chitters angrily above in something that sounds annoyingly like gnomish.",
  ]) );

  SetSmell( ([
    "default" : "The scent of fresh bread mixes with something greasy and harder to define."
  ]) );
  SetExits( ([
      "north" : FRANCIS_ROOM "fence2,2",
      "west"  : FRANCIS_ROOM "barn1,1",
      "south" : FRANCIS_ROOM "clear2,0"
  ]) );

}
