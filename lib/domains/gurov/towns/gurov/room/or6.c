#include <lib.h>
#include <domains.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "south" : GUROV_ROOM "or5",
    ]) );
  SetShort("the Outer Road by the Barracks and Hospital");
  SetLong(
    "The Outer Road comes to an end here in front of two of the Principality's "
    "more important buildings. Lying along the western side of the road is the "
    "barracks, home to the Prince's Own, the main armed force of the land. "
    "Those who are seeking a career in combat often find their way into the "
    "barracks for training. The other building is the Hospital, which is a "
    "famous center for the healing arts, second only to the famed Eclat Hospital "
    "in the WestWood."
    );
  SetSmell("The smells of incense waft from the hospital.");
  SetListen("The occasional clash of combat training comes from the barracks.");
  SetItems( ([
    "barracks" : "The barracks has barred iron windows and a flat roof "
                 "that archers could fire from if needed.",
    "hospital" : "The Gurov Hospital is a building for the wounded and "
                 "those in need.",
    ]) );
  SetEnters( ([
    "barracks" : GUROV_ROOM "barracks",
    "hospital" : GUROV_AREAS "hospital/room/entrance",
    ]) );
}