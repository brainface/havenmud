#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_FOREST);
  set_cold(1);
  set_short("a forest");
  set_long("\
You are stumbling through the forest.  You hear the crunching\n\
of the snow beneath your feet, but the trees seem to be thicker\n\
here than ever before.  It is very quiet in here.  You think that\n\
your voice would never carry out of this forest!  You are beginning\n\
to feel despair close in over you, but you see escape is near.\n");
  add_trigger("listen","You hear nothing.\n");
  add_trigger("shout","The shout dies in your throat.\n");
  set_light(1);
  add_look("snow","The snow is thick here, coming almost to your knees.\n");
  add_look("trees","The trees have grown into a wall of wood here.\n");
  add_exit("north", FOREST + "/forest008");
  add_exit("east", FOREST + "/forest002");
  add_exit("south", FOREST + "/forest006");
  replace_program(ROOM);
}

