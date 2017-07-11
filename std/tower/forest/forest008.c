#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  make_unique_object("skeleton", CRITS + "/skel");
  if (arg) return;
  set_terrain(TER_FOREST);
  set_cold(1);
  set_short("a forest");
  set_long("\
The forest draws up close to the river here.  You can see \n\
a small portion of the river passing by to the northeast, and\n\
can just barely make out the sounds of rushing water.  Looking\n\
around you, you can see that the evergreens along this path are\n\
aged and seem to be among the oldest parts of the forest so far.\n\
Off to the west, a dark shape looms out of the forest like a \n\
needle of death rising to challenge the heavens.\n");
  add_trigger("listen","You here the sound of water to the northeast,\n\
and can here the sounds of forest life elsewhere.  Strangely,\n\
you cannot here anything from the west.\n");
  add_look("river","\
The water rushing through the forest is of the palest blue.\n");
  set_light(1);
  add_look("shape","A huge tower rises from the forest to the west.\n");
  add_look(({"evergreen","evergreens"}),"\
Old, gnarly pines are growing in tight packs.\n");
  add_exit("west", FOREST + "/forest013");
  add_exit("east", FOREST + "/forest003");
  add_exit("north", FOREST + "/forest009");
  add_exit("south", FOREST + "/forest007");
}

