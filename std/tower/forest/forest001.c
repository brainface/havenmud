#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;

  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
Patches of snow cover the ground as you pass through\n\
the trees.  You hear the soft melody of winter birds\n\
that do not fear the snow, and you see the glistening\n\
shapes of icicles hanging from those few branches that\n\
that stick out far enough to attract ice.  A large hole \n\
is in the ground here, leading into the depths of the earth.\n");
  add_look("hole","\
This is a dark hole leading into the earth.\n");
  add_look("icicles","You see both large and small icicles.\n");
  add_look("birds","Some lovely white birds are singing in the branches.\n");
  add_look("snow","The crisp, white floofy snow looks good and smells good.\n");
  add_look("branches","The trees boughs hang out at some points, attracting water.\n");
  add_look("trees","These seem to be normal pines and other evergreens.\n");
    set_cold(1);
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("down", CAVERN +"/cavern001");
  add_exit("west", FOREST + "/forest006");
  add_exit("north", FOREST + "/forest002");
  replace_program(ROOM);
}


