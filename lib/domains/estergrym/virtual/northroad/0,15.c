// Kairehn - exit to ogre lair area
#include <lib.h>
#include <domains.h>
inherit "/domains/estergrym/virtual/northroad";
#include "/domains/estergrym/areas/ogrelair/ogrelair.h"

static void create(int x, int y) {
  ::create(0, 15);
  AddExit("west", LAIR_ROOMS "path1");  
  Setup(0, 15);
}
