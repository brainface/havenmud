#include <lib.h>
#include <domains.h>
#include "../namatar.h"
inherit LIB_ROOM;

void SetRoom(int, int);

/*
  if (x == -350 && y < 50 && y > -50) {
    w = NAMATAR_VIRTUAL "namatar/" + -351 + "," + y;
  }
  if (x == -450 && y < 50 && y > -50) {
    e = NAMATAR_VIRTUAL "namatar/" + -449 + "," + y;
  }
  if (y == 50 && x < -350 && x > -450) {
    s = NAMATAR_VIRTUAL "namatar/" + x + "," + 49;
  }
  if (y == -50 && x < -350 && x > -450) {
    n = NAMATAR_VIRTUAL "namatar/" + x + "," + -49;
  }
*/

static void create(int x, int y) {
  ::create();
  SetShort("on the Isle of Namatar");
  SetClimate("temperate");
  SetLong(
    "The plains of Namatar spread out over a great distance. Rolling grassland would make excellent farmland "
    "if cultivated. Occasional trees are spread out here, but none growing in any semblence of pattern or thickness."
    );
  SetRoom(x, y);
}

void SetRoom(int x, int y) {
  string n, s, e, w;
  n = NAMATAR_VIRTUAL + "namatar/" + (x) + "," + (y + 1);
  s = NAMATAR_VIRTUAL + "namatar/" + (x) + "," + (y - 1);
  e = NAMATAR_VIRTUAL + "namatar/" + (x + 1) + "," + (y);
  w = NAMATAR_VIRTUAL + "namatar/" + (x - 1) + "," + (y);
  if (x == -351) e = INNERSEA_VIRTUAL + "ocean/" + -350 + "," + y;
  if (x == -449) w = INNERSEA_VIRTUAL + "ocean/" + -450 + "," + y;
  if (y ==  49)  n = INNERSEA_VIRTUAL + "ocean/" + x + "," + 50;
  if (y == -49)  s = INNERSEA_VIRTUAL + "ocean/" + x + "," + -50;
  AddExit("north", n); 
  AddExit("south", s);
  AddExit("east", e);
  AddExit("west", w);
  if (x >= -375 && x != -351) AddLong(" The ocean is nearby to the east.");
  if (x <= -425 && x != -449) AddLong(" The ocean is nearby to the west.");
  if (y > 40 && y != 49)    AddLong(" The ocean is nearby to the north.");
  if (y < -40 && y != -49)   AddLong(" The ocean is nearby to the south.");

  // handle shoreline
  if (x == -351 || x == -449 || y == 49 || y == -49) {
    SetShort("On the shores of Namatar");
    SetLong(
      "A thin line of scrub-covered dunes is all that stands here "
      "between the shore and a vast stretch "
      "of plains. The violent waves of the sea to the "
    );
    SetProperty("coastal",1);
    if (x == -351 && y == 49) {
      AddLong("north and east");
    } else if (x == -351 && y == -49) {
      AddLong("south and east");
    } else if (x == -449 && y == 49) {
      AddLong("north and west");
    } else if (x == -449 && y == -49) {
      AddLong("south and west");
    } else if (x == -351) {
      AddLong("east");
    } else if (x == -449) {
      AddLong("west");
    } else if (y == 49) {
      AddLong("north");
    } else if (y == -49) {
      AddLong("south");
    }
    AddLong(" make swimming far from land a dangerous prospect.");
  }

  // handle badlands (higher level virtual)
  if (x >= -408 && x <= -368 && y <= 20 && y >= -20) {
    SetShort("the Badlands");
    SetLong(
      "The idealic plains of Namatar give way here to a sun scorched and barren land. "
      "Clumps of stunted grasses lay scattered about and only a few scraggly trees "
      "struggle to survive. It's unclear whether the devastation is natural or "
      "catastrophic." 
    );
    // TODO: add dudes.
  }

  if (!random(20)) AddInventory(NAMATAR_NPC "nomad", 1);
  if (!random(10)) AddInventory(NAMATAR_NPC "horse", 1);
}


