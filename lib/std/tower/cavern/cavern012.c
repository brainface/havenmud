#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_cold(3);
  set_short("a cave");
  set_long("\
The cave here is getting deeper and deeper into the ground, \n\
and as it does so, it is getting colder.  Off to the east, \n\
you can sense a tremendous presence that scares you slightly. \n");
  add_exit("southwest",CAVERN+"/cavern011");
  add_exit("southeast",CAVERN+"/cavern014");
  replace_program(ARCTIC); 
}
