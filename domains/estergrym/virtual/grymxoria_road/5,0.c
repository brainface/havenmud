#include <lib.h>
#include <domains.h>
inherit ESTERGRYM_VIRTUAL "grymxoria_road";

static void create(int x, int y) {
  ::create(5, 0);
  AddLong(" A small path leads towards a small cave to the north");
  AddExit("north", ESTERGRYM_AREAS "skaven/room/r0");
}