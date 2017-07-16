#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_cold(1);
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
You stand amongst rows of trees, all dusted lightly by\n\
snow.  Looking around, you almost feel that the world \n\
is at peace.  However, you know in your heart the terror\n\
that Rath-Khan causes, and that sobering thought hardens\n\
your resolve.\n");
  add_look("snow","|WKBThis is snow!\n");
  add_look(({"trees","tree"}),"\
These are evergreens, lightly dusted by snow.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("east", FOREST +"/forest026");
  add_exit("south",FOREST + "/forest021");
  add_exit("north", FOREST + "/forest023");
  replace_program(ROOM);
}

