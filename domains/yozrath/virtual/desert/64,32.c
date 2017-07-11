#include <lib.h>
#include <domains.h>
inherit "/domains/yozrath/virtual/desert";

static void create(int x, int y) {
  ::create(64,32);
  AddLong(" A dingy black tent sits here oblivious to the inhospitality of the area.");
  AddItem("tent", "This tent has seen better days.");
  SetRoom(64,32);
  AddEnter("tent", YOZRATH_TOWNS "yozrath/room/necro");
}
