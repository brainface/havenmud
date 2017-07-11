#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
This is a small clearing in the woods.  Due to it being open\n\
it seems that the snow is not as drifted here.  As you wander\n\
through the clearing, you see that squirrels and even rabbits\n\
are frolicking about.  The pines surrounding the clearing \n\
have grown into a wall, and only the paths leading back\n\
through forest seem passable at all.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  add_look("rabbits","You see cute little white floofy rabbits.\n");
  add_look("pines","The trees seem to be normal, albeit old and healthy, pines.\n");
  add_look("squirrels","The small animals are playing in the winter wonder.\n");
  add_look("rabbits","The animals are playing in the winter wonder.\n");
  add_look("snow","The small crests of snow are beautiful in the light.\n");
  set_cold(1);
  set_light(1);
  add_exit("west", FOREST + "/forest007");
  add_exit("north", FOREST + "/forest003");
  add_exit("south", FOREST + "/forest001");
  replace_program(ROOM);
}

