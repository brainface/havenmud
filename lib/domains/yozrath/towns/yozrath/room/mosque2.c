#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Room of the Faithful");
  SetNewsgroups( ({ "religion.kylin" }) );
  SetExits( ([
    "south" : YOZRATH_ROOM "mosque1",
    ]) );
  SetProperty("no attack", 1);
  SetProperty("no conjuring", 1);
  SetProperty("no teleport", 1);
  SetLong(
    "The Room of the Faithful is a quiet, protected niche within the "
    "Mosque of Yozrath that serves as a gathering place for the Faithful. "
    "To the south lies the entrance to the Mosque. Arranged around the room "
    "are several mats for quiet prayer."
    );
  SetSmell("Incense from the entrance gives the room a pleasant odor.");
  SetListen("The Room of the Faithful is quiet and peaceful.");
  SetItems( ([
    ({ "mat", "mats" }) : "Prayer mats lie neatly arranged in the room.",
    ]) );
}
