#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/dwarf",3);
  add_clone(CRITS + "/draco",3);
  add_clone(CRITS + "/dr_lord",1);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_light(1);
  set_short("a cave");
  set_long("\
This seems to be the audience chamber and living quarters of \n\
the king of the draconians.  Scattered around the room are \n\
firepits which give off heat and light enough to keep the room \n\
almost cozy.  The walls are hewn from the stone here in an almost \n\
perfect manner, and they appear smooth.\n");
  add_look("stone","\
This is normal stone that forms the cavern walls.\n");
  add_look(({"firepit","firepits"}),"\
These seem to be normal fires.\n");
  add_look(({"wall","walls"}),"\
The walls are smoothly cut to seem less like a cave.\n");
  add_exit("west",CAVERN+"/cavern009");
  add_exit("northwest",CAVERN+"/cavern008");
}
