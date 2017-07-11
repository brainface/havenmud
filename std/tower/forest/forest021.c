#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  add_look("snow","This is snow!\n");
  add_look(({"trees","tree"}),"\
These are nice evergreens.\n");
  set_cold(1);
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
You stand in the southwest corner of the forest.  To the\n\
east, you can see the trees lightening up some.  The snow\n\
is light and powdered here.  You feel almost at ease.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("east", FOREST +"/forest016");
  add_exit("north", FOREST + "/forest022");
  replace_program(ROOM);
}

