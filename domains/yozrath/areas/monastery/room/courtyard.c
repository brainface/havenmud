// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("arid");
  SetShort("the monastery courtyard");
  SetLong(
    "The courtyard is well protected by the monastery walls, which keep "
    "out the harsh desert winds. The ground is covered in sand with "
    "footprints leading in every direction. To the north, the main worship "
    "hall stands tall and appears to be of a higher quality than the others. "
    "To the east is a towering belfry. A larger building to the west looks "
    "militaristic, with a carving of a curved sword in the stone above the "
    "entrance. To the south there is a huge wooden gate which looks like it "
    "leads out to the desert."
  );
  SetItems( ([
  ({ "courtyard" }) :
    "The courtyard is surrounded by buildings.",
  ({ "walls", "monastery" }) :
    "The huge wall surrounds the monastery. It's bricks are beginning "
    "to crumble a little, but it still looks more than capable of "
    "keeping out unwanted guests.",
  ({ "sand", "ground" }) :
    "The desert sand covers the ground here.",
  ({ "footprints" }) :
    "The footprints in the sand lead in all directions.",
  ({ "hall" }) :
    "This pleasant-looking building seems to be the place where "
    "monks go to worship their god.",
  ({ "belfry" }) :
    "The belfry is the tallest building in the monastery. ",
  ({ "building", "entrance" }) :
    "The building looks like a place where monks go to train "
    "their combat skills. It has a carving of a curved sword above the "
    "entrance.",
  ({ "sword", "carving", "stone" }) :
    "The carving of a curved sword above the entrance of "
    "the training building suggests that the monks go here to practice "
    "with swords.",
  ({ "Gate" }) :
    "The gate is open, welcoming all visitors to the monastery.",
  ]) );
  SetItemAdjectives( ([
    "hall" : ({ "main", "worship", "tall" }),
    "gate" : ({ "huge", "wooden" }),
    "building" : ({ "militaristic", "larger" }),
    "sword" : ({ "curved" }),
    "belfry" : ({ "towering" }),
    "walls" : ({ "monastery" }),
  ]) );
  SetInventory( ([
    AREA_NPC "guard" : 1,
    AREA_NPC "peasant" : 2,
  ]) );
  SetListen( ([
    "default" : "The sounds of deep chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The smell of wine and incense is carried on the air from "
    "the north.",
  ]) );
  SetExits( ([
    "south" : AREA_ROOM "gates",
  ]) );
  SetEnters( ([
    "building" : AREA_ROOM "training_building",
    "hall" : AREA_ROOM "main_hall",
    "belfry" : AREA_ROOM "belfry",
  ]) );
}
