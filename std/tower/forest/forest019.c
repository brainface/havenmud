#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/skel",4);
  if (arg) return;
  set_cold(1);
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
The snow crumples beneath your feet as you move through\n\
the trees.  You can hear winter rabbits playing in the \n\
trees but can't quite see any.  The snow here is rather \n\
thin, allowing you to see patches of ground underneath\n\
the snow.\n");
  add_look(({"tree","trees"}),"The evergreens are densely packed here.\n");
  add_look("snow","The snow is crisp and white.\n");
  add_look("ground","The ground shows the wear of a land in perpetual winter.\n");
  add_trigger("listen","\
You hear the scampering feet if winter rabbits.\n");
  set_light(1);
  add_exit("east", FOREST + "/forest014");
  add_exit("north", FOREST + "/forest020");
  add_exit("south", FOREST +"/forest018");
}

