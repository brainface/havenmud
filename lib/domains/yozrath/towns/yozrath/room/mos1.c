#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Mosque Road east of the Northern Gate");
  SetClimate("arid");
  SetExits( ([
    "east" : YOZRATH_ROOM "mos2",
    "west" : YOZRATH_ROOM "gate1",
    ]) );
  SetLong(
    "To the west, the Northern Gate opens to the desert. To the east "
    "lie both the Hall of Janissaries and the Mosque of Yozrath, both "
    "centers for training in the desert. The road is lined with buildings, "
    "but none appear to be accessable from here. The Mosque to the east "
    "seems to be a vitally important building to the Sheikdom."
    );
  SetItems( ([
    "hall" : "The Hall of Janissaries lies to the east and is the home "
             "of the warrior corps of the desert.",
    "mosque" : "The Mosque of Yozrath is the largest spiritual center in "
               "the desert and is home to the Imams, the faithful of Kylin.",
    ({ "building", "buildings" }) : "None of the lesser buildings appear accessable.",
    ]) );
  SetSmell("A faint tinge of incense wafts in the air.");
  SetListen("The sounds of city life abound.");               
}
