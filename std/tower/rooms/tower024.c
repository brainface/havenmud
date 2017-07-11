#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int iArg) {
  ::reset(iArg);
  if(iArg) return;

  set_terrain(TER_INSIDE);
  set_light(1);
  set_short("Guest wing");
  set_long("\
You seem to be in the entrance chamber to the visitors' \n\
quarters. Looking at your surroundings, you can see that\n\
the paintings on the walls are more palatable to the eye\n\
than those on other floors. Also, the furnishings seem \n\
more spacially friendly. The walls are smooth and \n\
glistening in the luxury suites of the third floor.\n");

  add_look(({"painting","paintings"}),"\
These seem to be lovely paintings of fruit and trees.\n");

  add_look("furnishings","\
The chairs and tables here seem made for relaxation than\n\
practical purposes.\n");

  add_look(({"chairs","tables","chair","table"}),"\
These are normal, if luxurious, items.\n");

  add_look(({"wall","walls"}),"\
The walls here are polished to a shine.\n");

  add_exit("west",TOWER+"/tower017");
  add_exit("north",TOWER+"/tower018");
  replace_program(ROOM);
}
