#include <lib.h>
#include <domains.h>
inherit "/domains/yozrath/virtual/desert";
int DomainCheck();

static void create(int x, int y) {
  ::create(33, 47);
  SetShort("At the base of a spiraling ramp");
  AddLong(" A ramp begins to spiral upward here to the southeast.");
  AddItem("ramp","It's formed from some white, translucent material. "
    "At this spot the gradient is barely noticable.");
  AddExit("southeast", YOZRATH_AREAS "minaret/room/path0t1" );
  SetRoom(33,47);
}
