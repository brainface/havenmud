#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_cold(1);
  set_short("a cave");
  set_long("\
This portion of the cave seems to be a junction for many of \n\
the cavern's twisting passages.  From the south, you can hear \n\
the gutteral sounds of draconian speech, while to the east, \n\
all is very quiet.\n");
  add_exit("north", CAVERN+"/cavern005");
  add_exit("west",CAVERN+"/cavern004");
  add_exit("south",CAVERN+"/cavern008");
  add_exit("northeast",CAVERN+"/cavern011");
  add_exit("southeast",CAVERN+"/cavern015");
  replace_program(ARCTIC);
}
