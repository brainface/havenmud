#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/draco", random(3) + 1);
  if (arg) return;
  set_cold(1);
  set_short("a cave");
  set_terrain(TER_UNDERGROUND);
  set_long("\
From the north, you can see a partial glitter of light\n\
from the cavern's mouth.  However, further in to the east\n\
you feel a warmth of some great evil.\n");
  add_exit("north",CAVERN+"/cavern001");
  add_exit("northeast",CAVERN+"/cavern003");
  add_exit("southeast",CAVERN+"/cavern004");
  replace_program(ARCTIC);
}
