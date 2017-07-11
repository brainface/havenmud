#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/draco",2);
  add_clone(CRITS + "/dwarf",4);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_cold(1);
  set_light(1);
  set_short("a cave");
  set_long("\
Scattered about this room are several firepits, many of \n\
which are burning, making this room warm and well lit. \n\
You notice that this room seems to have been set up almost \n\
as an antechamber of some sorts.\n");
  add_look("firepit","This is a normal fire.\n");
  add_exit("east",CAVERN+"/cavern010");
  add_exit("northeast",CAVERN+"/cavern008");
}
