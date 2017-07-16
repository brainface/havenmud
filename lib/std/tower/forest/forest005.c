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
The snow covers the forest floor here like a gentle\n\
blanket, leaving almost no trace of the ground beneath\n\
it.  Looking at the trees around you, you wonder how\n\
a place so peaceful and serene could house such evil\n\
as Rath-Khan.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  add_look("trees","These seem to be normal evergreens.\n");
  add_look("snow","The snow is a cold white blanket on the ground.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest010");
  add_exit("south", FOREST + "/forest004");
  replace_program(ROOM);
}

