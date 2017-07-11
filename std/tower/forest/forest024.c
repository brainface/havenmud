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
Sitting in the middle of this patch of woods is a\n\
small cottage.  The cottage sits still and quiet in\n\
the woods.  Piles of wood stand at ease next to the\n\
house.  A small stream of smoke rises up from the \n\
chimney.\n");
  add_look("wood","Piles of firewood are relaxed against the house.\n");
  add_look("woods","The evergreens completely enclose this patch.\n");
  add_look("smoke","A thin wisp of black smoke rises up.\n");
  add_look("chimney","A stone structure attached to the house.\n");
  add_look(({"cottage","house"}),"\
This wooden building stands in the midst of the patch.\n\
It seems to be an older building, as the logs seem aged.\n");
  add_look(({"log","logs"}),"\
These old logs seem to have been carved hundreds of years ago.\n\
They seem to have been hewed by a rough hand not trained\n\
in woodsmans skills.\n");
  add_trigger("listen","\
You can hear birds chirping and can just barely hear the\n\
gentle rush of the river.\n");
  set_light(1);
  add_exit("north", FOREST + "/forest025");
  add_exit("enter", FOREST + "/house");
  replace_program(ROOM);
}

