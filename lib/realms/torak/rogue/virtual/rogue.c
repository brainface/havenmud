#include <lib.h>
#include <domains.h>
#include "../rogue.h"
inherit LIB_ROOM;

static void create(int x, int y) {
  ::create();
  SetShort("in a cavern");
  SetClimate("underground");
  SetAmbientLight(15);
  SetLong(
    "Wow.  What a large cavern.  ECHO, Echo, echo."
    );
  if (x < 7) AddExit("east", "/realms/torak/rogue/virtual/rogue/" + (x + 1) + "," + (y) );
  if (x > 1) AddExit("west", "/realms/torak/rogue/virtual/rogue/" + (x - 1) + "," + (y) );
  if (y < 3) AddExit("north", "/realms/torak/rogue/virtual/rogue/" + (x) + "," + (y + 1) );
  if (y > 1) AddExit("south", "/realms/torak/rogue/virtual/rogue/" + (x) + "," + (y - 1) );
  }
