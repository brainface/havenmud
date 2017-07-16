#include <lib.h>
#include "../gurov.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetExits( ([
    "south" : GUROV_ROOM "cathedral3",
    ]) );
  SetShort("the Shrine of Magildan in Gurov");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "Thick grey stone makes up the walls of the shrine of Magildan. Sitting "
    "between the shrines of the forces of True Evil and Pure Goodness on Kailie "
    "is the simple shrine of the Lord of Magic. "
    );
  SetReligion( ({ "Magildan" }) );
  SetInventory( ([
    GUROV_NPC "mag_mystic" : 1,
  ]) );
}
