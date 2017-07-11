/* Lamrani Temple, East Hallway, Room 3 */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("lower plane", 1);
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "west" : TEMPLE_ROOM "e2",
    "south" : TEMPLE_ROOM "e4",
    ]) );
  SetShort("along the east hallway");
  SetLong("The cold marble floor continues further into the "
          "temple to the south and leads out to the west. "
          "Along the walls are scenes of compassion and caring "
          "enough to make the greatest of warriors cry. The "
          "passage to the south appears to be a large archway.");
  SetItems( ([
    ({ "arch", "archway" }) : "The archway is a large, almost wooden "
                              "opening to the south.",
    ({ "wall", "walls" }) : "The walls are lined with scenes of compassion.",
    ({ "scene", "scenes" }) : "The scenes show caring in a way that mere "
                              "love cannot describe.",
    ({ "floor" }) : "The floor is shined to a high gloss.",
    ]) );
  SetItemAdjectives( ([
    "arch" : ({ "large", "wooden" }),
    "floor" : ({ "cold", "marble" }),
    ]) );
  SetSmell( ([
      "default" : "The air is clear and crisp here.",
      ]) );
  SetListen( ([
      "default" : "The hallway if blissfully quiet.",
      ]) );
 }
