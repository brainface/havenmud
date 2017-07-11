// music hall readded by torak@haven on nov 23rd '12

#include <lib.h>
#include "../haven.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Imperial Road");
  SetObviousExits("east, west");
  SetExits( ([
    "west" : H_ROOM + "imperial_road/ir4",
    "east" : H_ROOM + "imperial_road/ir6" ]) );
  SetDayLong(
    "The road is a hive of activity. To the east, the road "
    "leads on deeper into the city's heart, passing by the "
    "town post office further to the east. Off to the west "
    "is the town's bank and a small inn. The music hall of "
    "Haven Town sits along the northern edge of the road."
    );
  SetNightLong(
    "The road is a calm pace of evening activity, with "
    "people passing by at a smooth, relaxed pace. To the "
    "east is the town post office, while off to the west "
    "is the city's financial heart. The music hall of Haven "
    "Town sits along the northern edge of the road."
  );
  SetItems( ([
    ({"hall","music hall"}) : "The music hall is a gathering place for the \n"
      "bards of Haven Town.",
  ]) );
  SetEnters( ([
    "hall" : H_ROOM + "misc_buildings/music_hall",
  ]) );
}
