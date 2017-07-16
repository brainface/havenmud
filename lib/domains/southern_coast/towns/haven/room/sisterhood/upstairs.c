#include <lib.h>
#include "../../haven.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetAmbientLight(35);
  SetProperty("no magic", 1);
  SetProperty("no attack", 1);
  SetNewsgroups( ({ "guild.sisterhood" }) );
  SetShort("the Inner Sanctum of the Order of the Sword and Dragon");
  SetLong(
    "The second level of the building is much more friendly and comfortable. "
    "Arranged around the wide open area are various cushions for the members of "
    "the Order to relax and rest for a while. Hanging on a plain stone wall "
    "is a large royal blue tapestry with the symbol of Kylin threaded upon it in "
    "silver."
    );
  SetItems( ([
    ({ "cushion", "cushions" }) : "These cushions look very comfortable.",
    ({ "tapestry", "symbol"  }) : "The Kylin Holy Symbol is a balance (a set "
                                  "of equal scales) with a dragon intertwined.",
    ]) );
  SetExits( ([
    "down" : H_ROOM "sisterhood/entrance",
    ]) );
}
