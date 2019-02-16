// mahk 2019
// stables entrances
#include <lib.h>
#include <domains.h>
#include "../vimp.h"
inherit VIMP_DIR "vimp";
int DomainCheck();

static void create(int x, int y) {
  ::create(0, 0);
  Setup();
  AddLong(" A cobblestone path leads east to a stables.");
  AddExit("east", PENINSULA_AREAS "stables/room/stables");
}

