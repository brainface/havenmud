#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create(int x, int y) {
  ::create();
  SetShort("in a swiftly moving underground river");
  SetProperty("shallows", 1);
  SetClimate("underground");
  SetAmbientLight(20);
  SetLong(
    "The swiftly moving underground river is a tributary off the River Bjorn. "
    "The water is deep and nearly fills the entire passage, but a thin air "
    "pocket exists at the very top of the cave allowing the occasional breath. "
    );
  if (x < 40)              AddExit("northeast", YOZRATH_VIRTUAL "river/" + (x + 1) + "," + (y + 1) );
  if (y <= 40 && x <= 40)  AddExit("southwest", YOZRATH_VIRTUAL "river/" + (x - 1) + "," + (y - 1) );
  if (x == 40 && y < 100)  AddExit("north",     YOZRATH_VIRTUAL "river/" + x + "," + (y + 1) );
  if (x == 40 && y > 40)   AddExit("south",     YOZRATH_VIRTUAL "river/" + x + "," + (y - 1) );
  if (x == 40 && y == 100) AddExit("up",        YOZRATH_VIRTUAL "desert/40,100");
  if (x == 0  && y == 0)   AddExit("up",        YOZRATH_TOWNS   "yozrath/room/oasis3");
  if (x == 0) RemoveExit("southwest");
}
