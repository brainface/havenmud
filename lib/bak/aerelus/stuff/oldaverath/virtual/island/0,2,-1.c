#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(0,2,-1);
  RemoveExit("south");
}
