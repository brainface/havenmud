#include <lib.h>
#include "../vest.h"
#define GROVE 1
inherit VIA_DIR "vest";

static void create(int x, int y) {
  ::create(5, 0);
  if (GROVE) 
    AddExit("north", "/domains/peninsula/areas/grove/room/entrance");
}
