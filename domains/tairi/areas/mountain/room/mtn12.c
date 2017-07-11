//Selket@Haven
//2006

#include <lib.h>
#include "../mtn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("on a steep path up the side of Shatadru Mountain");
  SetLong(
    "Here the path climbs steeply up a precipice onto a higher "
    "level of the mountain. Niches and chinks in the rock show "
    "where others have practically clawed their way up. The "
    "way down is to the southwest, but one can almost make out "
    "the summit of Shatadru through the cloudbank far overhead. "
  );
  SetItems( ([
    ({ "precipice", "path" }) : 
    "The path leads almost straight up and southwest along the "
    "edges of the mountain",
    ({ "niche", "chink", "niches", "chinks" }) : 
    "Bits of rock have been scratched out of the mountain to "
    "form handholds, footholds, and wingholds for those who "
    "seek to reach the top.",
    ({ "summit", "cloudbank" }) : 
    "The summit is far above, obscured by silvery clouds. ",
  ]) );
  SetExits( ([
    "southwest" : MTN_ROOM "/mtn11",
    "up" : MTN_ROOM "/mtn13",
  ]) );
  SetInventory( ([
    MTN_NPC "/goat2" : 2,
  ]) );
  SetListen("Distant bleatings can be heard.");
  SetSmell("The chilling air smells somewhat of goats.");
}
