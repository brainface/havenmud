#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (!present("skeleton")) {make_object("skeleton",CRITS+"/skel");}
  if (arg) return;
  set_terrain(TER_FOREST);
  set_cold(1);
  set_short("a forest");
  set_long("\
The woods are thick in this area.  Through the pines and\n\
brush, you can see a river in the distance to the south.\n\
Though the trees appear to be no differant than others, you\n\
sense that this small patch of ground is differant.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  add_look("pines","You see that the trees appear darker here.\n");
  add_look("brush","The bushes are just your normal everyday bushes.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest009");
  add_exit("north", FOREST + "/forest005");
}

