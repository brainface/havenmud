#include <lib.h>
#include "../vimp.h"
inherit VIMP_DIR "vimp";

static void create(int x, int y) {
  ::create(14, 20);
  AddExit("northwest", "/domains/peninsula/areas/sulumus/room/path");
}
