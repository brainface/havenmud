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
You stand along the banks of the mighty river.  Looking\n\
to the north, you see that the forest continues on.  To the \n\
east, you see a path leading through the snow into a lightly\n\
wooded area.  Southwest, looming like a huuuuuge blackened claw\n\
stands the tower of Rath-Khan.  The bridge that crosses the river\n\
seems ageless, with a sturdy quality about it.  You would believe \n\
that it has stood for thousands of years.\n");
  add_look("river","The river flows from the northwest to the southeast.\n");
  add_look("bridge","The bridge is a large, wooden creation that has stood \n\
over this river for countless centuries.\n");
  add_look("snow","The snow is light here, with much of it blowing away while\n\
you watch.  The drifts that are present are fairly small.\n");
  add_look("tower","\
The tower is a fearfully imposing site standing against the sky.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest014");
  add_exit("south", FOREST + "/forest008");
  add_exit("east", FOREST + "/forest004");
  replace_program(ROOM);
}

