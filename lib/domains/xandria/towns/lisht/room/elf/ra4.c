#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "north" : LISHT_ROOM "elf/ra3",
    "south" : XANDRIA_AREAS "newbie/room/1b",
    ]) );
  SetShort("River Alley by the Wall of Lisht");
  SetDayLight(-10);
  SetLong(
    "The Wall of Lisht lines the alley to the west, preventing "
    "travel. Sitting against the Wall is a small building that "
    "seems more run down than other buildings around the area. "
    "To the south lies an exit into a small oasis."
    );
  SetSmell("A breeze wafts in from the south.");
  SetItems( ([
    "building" : "This building is very run down.",
    "wall"     : "The wall of Lisht is an imposing barrier.",
    "exit"     : "The exit leads to an oasis.",
    ]) );
  SetEnters( ([
    "building" : LISHT_ROOM "elf/rogue",
    ]) );
}
