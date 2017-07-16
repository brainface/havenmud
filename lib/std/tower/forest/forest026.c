#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS+ "/skel", 2 + random(3));
  if (arg) return;
  set_cold(1);
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
The trees here are thinner, allowing you to see to the \n\
south and west.  Looking around, you realize that you \n\
have travelled deep into the heart of Rath-Khan's forest.\n\
You have faith that you can escape.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest022");
  add_exit("south", FOREST + "/forest016");
}

