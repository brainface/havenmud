/* the unicorn room
   Kyla 10-19-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a hidden glen");
  SetObviousExits("west");
  SetExits( ([
            "west" : MEADOW_ROOMS + "meadow5",
           ]) );
  SetSmell( ([
           "default" : "This area smells of morning dew, and dry grass."
           ]) );
  SetListen( ([
             "default" : "A mystical humm can be heard." 
             ]) );
  SetLong("The long grass of the meadow becomes much shorter here as "
          "the meadow turns into a hidden glen. The area feels very "
           "magical and seems to radiate a sense of innocence. The glen "
          "abruptly stops here and it seems to be a self-enclosed "
          "area.");
  SetItems( ([
           "grass" : "The grass here is shorter than in the meadow.",
            ]) );
  SetInventory( ([
             MEADOW_NPC + "unicorn" : 1,
               ]) );
  }
