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
Looking around you, you realize that there seem to be \n\
many paths leading into this place.  The snow is only\n\
mildly drifted, as this is a wide expanse.  Off to the\n\
south, the trees have formed a shelter against the wind.\n\
To the east, though, the tower rises like a spire in\n\
the heart of the sky.\n");
  add_look("trees","\
These seem to be normal evergreens.\n");
  add_look("shelter","\
The trees have enclosed an area that seems safe.\n");
  add_look("tower","\
The tower rises into the sky like a dark claw,\n\
daring the clouds to reach down and touch it.\n");
  add_look("snow","\
This is powdery white snow.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest023");
  add_exit("east", FOREST + "/forest013");
  add_exit("north", FOREST + "/forest019");
  add_exit("south", FOREST +"/forest017");
  replace_program(ROOM);
}

