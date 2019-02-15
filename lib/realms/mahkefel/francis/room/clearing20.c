/* more grass how exciting
 * why did i make 3 grass rooms
 *
 */

#include <lib.h>
#include "../francis.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  //SetClimate("sub-tropical");
  SetDomain("Havenwood");
  SetShort("An overgrown field");
  SetLong("Some uh... weedy cornfields?");

  SetItems( ([ ]) );

  SetListen( ([
    "default" : "A bird chitters angrily above in something that sounds annoyingly like gnomish.",
  ]) );

  SetSmell( ([
    "default" : "The scent of fresh bread mixes with something greasy and harder to define."
  ]) );
  SetExits( ([
      "north" : FRANCIS_ROOM "inn21",
      "west"  : FRANCIS_ROOM "clearing10",
  ]) );

}
