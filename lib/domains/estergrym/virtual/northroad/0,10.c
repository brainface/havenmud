// exit west to urien's tower
#include <lib.h>
#include <domains.h>
inherit "/domains/estergrym/virtual/northroad";
#include "/domains/estergrym/areas/tower/defs.h"

static void create(int x, int y) {
  ::create(0, 10);
  AddExit("west", TOWER_ROOMS "cave01");  
  Setup(0, 10);
}
