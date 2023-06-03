#include <lib.h>
#include <domains.h>
inherit WESTWOOD_VIRTUAL "westwood";

static void create(int x, int y) {
  x = y = 30;
  ::create(30,30);
  AddLong("To the east a path leads to the Ruins of the Ivory Castle "
         "along Lake Pokenay."
         );
  AddExit("east", WESTWOOD_AREAS "ruins/room/drawbridge");
}
