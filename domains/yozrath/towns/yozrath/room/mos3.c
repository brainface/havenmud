#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Mosque Road directly in front of the Mosque");
  SetClimate("arid");
  SetExits( ([
    "west" : YOZRATH_ROOM "mos2",
    ]) );
  SetLong(
    "The Mosque Road ends here at the base of the Mosque of Yozrath. This smooth "
    "brown building has a tall spiral minaret built on to it, a place from which "
    "the Imam of Yozrath can call the faithful to prayer. To the west, the road "
    "leads back into the town, but here nothing stands more important than the "
    "Mosque for which the road is named."
    );
  SetItems( ([
    "mosque" : "This large structure is the Mosque of Yozrath, an imposing stone "
               "building that houses the Faithful of the Sheikdom. A large minaret "
               "rises from the southern edge of the Mosque into the sky.",
    "minaret" : "A minaret is a thin tower that spikes into the sky.",
    ]) );
  SetEnters( ([
    "mosque" : YOZRATH_ROOM "mosque1",
    ]) );
  SetSmell("Incense burns within the Mosque.");
  SetListen("Chants and prayers echo off the walls of the Mosque.");
}
