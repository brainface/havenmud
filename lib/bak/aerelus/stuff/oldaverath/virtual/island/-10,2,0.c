#include <lib.h>
#include <domains.h>
inherit LIB_ISLAND;
static void create(int x, int y, int z) {
  ::create(-10,2,0);
  SetInventory( ([
    AVERATH_NPC "bandit" : 2,
    ]) );
}
