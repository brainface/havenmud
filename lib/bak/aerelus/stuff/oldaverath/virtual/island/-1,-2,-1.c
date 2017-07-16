#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-1,-2,-1);
  RemoveExit("north");
}
