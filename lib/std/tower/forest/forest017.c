#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/skel",2);
  if (arg) return;
  set_cold(1);
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
This is a small shelter from the cold and snow. \n\
You can see that this area has been frequented  \n\
by the local animals, as there are droppings    \n\
in piles large and small.  Overall, this is a   \n\
good place to rest, you think.\n");
  add_look("droppings","\
These are piles of used food left by animals, silly!\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("north", FOREST +"/forest018");
  replace_program(ROOM);
}

