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
This small patch of woodlands is suprisingly\n\
devoid of snow cover.  Looking around, you see\n\
a path to the east and a small house off to the\n\
south.\n");
  add_look("house","This seems to be a small cottage in the woods.\n");
  add_look("snow","The snow here is only sparse, as the woods block\
 the wind.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("east", FOREST + "/forest020");
  add_exit("south", FOREST + "/forest024");
  replace_program(ROOM);
}

