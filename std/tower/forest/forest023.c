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
This is the path leading into the forest of Rath-Khan!\n\
Looking about you, you see that the snow is settled in \n\
a way that shows you how still and calm the forest is. \n\
Somehow, you don't find this reassuring.\n");
  add_look("snow","|WKBThis is light, floofy snow.\n");
  add_look(({"trees","tree"}),"\
You see various types of evergreens, from pines\n\
to other conifers.  Occasionally, you even see \n\
decidious trees like oaks.\n");
  add_exit("northwest","/domains/hyperborea/valley/valley10");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("east", FOREST + "/forest018");
  add_exit("south", FOREST +  "/forest022");
  replace_program(ROOM);
}

