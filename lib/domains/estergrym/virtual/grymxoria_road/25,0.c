#include <lib.h>
#include <domains.h>
inherit ESTERGRYM_VIRTUAL "grymxoria_road";

static void create(int x, int y) {
  ::create(25, 0);
  AddLong(" A small path leads north");
  AddExit("north", ESTERGRYM_AREAS "troll_valley/room/crack");
}