#include <lib.h>
#include <domains.h>
inherit ESTERGRYM_VIRTUAL "grymxoria_road";

static void create(int x, int y) {
  ::create(15, 0);
  AddLong(" A small path leads north");
  AddExit("north", ESTERGRYM_AREAS "underdark/room/room1a");
}