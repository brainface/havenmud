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
Looking about you, you see that the trees have grown into \n\
a solid wall to the south.  Off to the north you see some \n\
sort of clearing in the trees.  However, here there is no \n\
respite from the trees and snow.  You can only hope that  \n\
the evil that is Rath-Khan will not find you here.\n");
  add_look(({"tree","trees"}),"\
The trees are typical winter evergreens.\n");
  add_look("snow","|WKBThis is snow!\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest021");
  add_exit("north", FOREST + "/forest026");
  replace_program(ROOM);
}

