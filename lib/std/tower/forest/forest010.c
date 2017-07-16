#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS+"/skel",5);
  if (arg) return;
  set_terrain(TER_FOREST);
  set_cold(1);
  set_short("a forest");
  set_long("\
This part of the forest is secluded from the rest.  \n\
To the west through the trees, you can hear the babbling\n\
of the river as it meanders from the north.  You can also\n\
make out the calls of wild birds as they take refuge from\n\
Rath-Khan's evil in the brush.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  add_look("brush","These are just normal evergreen trees.\n");
  set_light(1);
  add_exit("east", FOREST + "/forest005");
}

