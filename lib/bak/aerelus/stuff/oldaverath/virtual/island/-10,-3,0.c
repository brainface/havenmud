#include <lib.h>
#include <domains.h>
#include "../undead.h"
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(-10,-3);
  SetShort("on the plains of Averath");
  SetLong(
     "The sea lies to the south and west. To the east, a mountain rises into "
     "the sky. The mountain looks fierce and lonely from this side. To the "
     "north and east, the plains continue. There is a large hole in the ground "
     "here which forms a crude opening into the island's interior."); 
  SetItems( ([
    ({ "hole", "opening" }) : "This opening seems to form a tunnel down.",
    ]) );
  SetItemAdjectives( ([
    "hole" : ({ "crude", "large" }),
    ]) );
  SetEnters( ([
     "opening" : AVERATH_ISLAND + "-10,-3,-1",
    ]) );
  SetListen( ([
     "default" : "Birds chirp happily around you.",
    ]) );
  SetSmell( ([
     "default" : "The fresh air is a wonderfully clean smell. ",
    ]) );
  SetInventory( ([
    ]) );
}
