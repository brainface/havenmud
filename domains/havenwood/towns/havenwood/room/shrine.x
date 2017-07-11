/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../wood.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetExits( ([
    "out" : HWD_ROOM "/gelf7",
    ]) );
  SetInventory( ([
    HWD_NPC "/gittia" : 1,
    ]) );
  SetProperty("no bump", 1);
  SetShort("inside the Shrine");
  SetLong(
    "The Shrine to Harmony is a quiet place "
    "filled with the accoutrements of the worship of the "
    "Lady of Mercy."
    );
  SetSmell("A faint scent of incense sits in the air.");
  SetReligion( ({ "Kylin" }) );
  SetClimate("indoors");
  SetAmbientLight(20);
}

