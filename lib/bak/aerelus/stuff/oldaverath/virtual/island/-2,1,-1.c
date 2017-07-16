#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-2,1,-1);
  RemoveExit("east");
}
