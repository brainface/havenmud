#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/dragon");
  if (arg) return;
  set_cold(3);
  set_terrain(TER_UNDERGROUND);
  add_terrain(TER_CITY);
  set_light(1);
  set_short("an underground city");
  set_long("\
As you step into the wide opening, you realize that this is\n\
the den of a large black dragon.  Claw marks line the walls\n\
and bones lie strewn about.\n");
  add_look(({"claw","marks"}),"\
Hard lines cut through the rock with razor sharp talons.\n");
  add_look("bones","\
Remains of those who have preceeded you.\n");
  add_exit("northwest",CAVERN+"/cavern012");
  add_exit("southwest",CAVERN+"/cavern013");
}
