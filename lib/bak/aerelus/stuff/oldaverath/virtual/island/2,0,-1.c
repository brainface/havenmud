#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(2,0,-1);
  RemoveExit("west");
}
