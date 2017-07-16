#include <lib.h>
#include <domains.h>
#include "../argoth.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a short road");
  SetLong(
    "This short path runs between Karak Varn and its large suburb, Argoth. "
    "To the north lies the grand fortress city of Karak Varn, while to the "
    "south lies the city of Argoth. The paved cobblestones of the road lie "
    "in martial order lining a very orderly direction between the cities."
    );
  SetItems( ([
    ]) );
  SetExits( ([
    "north" : CRYSTAL_REACHES_TOWNS "karak/room/rd4",
    "south" : ARGOTH_ROOM + "rd1",
  ]) );
  SetSmell( ([
    "default" : "There is a slight smell of freshly cut grass.",
  ]) );
  SetListen( ([
    "default" : "The sounds of construction can be heard."
  ]) );
}
