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
The forest becomes very thick at this point.  To the\n\
west is a wall of wood that towers above you.  To the\n\
east and north the paths appear transversable.  The snow\n\
is less thick here also, and this seems like a good place\n\
to be.  The air is crisp as it blows across you.  You can\n\
smell the pine scent on the wind, and you know that life\n\
does not get much better than this.\n");
  add_look("snow","The snow has small patches of yellow here.\n");
  add_look("wall","The path has grown impassable to the west.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("east", FOREST+"/forest006");
  add_exit("north",FOREST+"/forest012");
  replace_program(ROOM);
}
