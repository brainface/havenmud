#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/dwarf",4);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_cold(1);
  set_short("a cave");
  set_long("\
The cave here seems less forboding than in other places. \n\
As a matter of fact, you would say that it is almost hospitable. \n\
The draconians must have taken pains to clean this area for something.\n");
  add_exit("north",CAVERN+"/cavern004");
  add_exit("east",CAVERN+"/cavern008");
}
