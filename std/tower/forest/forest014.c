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
The trees are thinner here as you approach the river.\n\
You find it almost ominous that wherever the shadow of \n\
the tower reaches, no trees grow.  To the northeast, the\n\
river continues on its path through this icy realm.\n\
By far, however, the sight that grabs your eyes is the\n\
tower itself to the south.\n");
  add_look("tower","It's a huge and terrifying creation.\n");
  add_look("shadow","The shadow seems to be a wall of darkness.\n");
  add_look("river","The river is a clear and cold stream.\n");
  add_look("trees","These seem to be normal evergreens.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest019");
  add_exit("east", FOREST + "/forest009");
  add_exit("north", FOREST + "/forest015");
  add_exit("south", FOREST + "/forest013");
  replace_program(ROOM);
}

