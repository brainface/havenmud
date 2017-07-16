#include <lib.h>
#include <domains.h>
inherit LIB_ISLAND;

static void create(int x, int y, int z) {
  ::create(10,3,0);
  SetLong(GetLong() + " There is a small hut here.");
  AddItem("hut", "The hut is a small wooden fisher's hut, possibly owned by a merchant. "
    "At present it is closed and appears abandoned.");
}
