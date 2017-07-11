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
The forest breaks off to the south as you come upon a river.\n\
The river moves swiftly from the northwest to the southeast and\n\
has a pale blue-white color to it.  It is the cleanest water you\n\
have ever seen.  You wish you had more time to simply sit and\n\
stare at the fabulous marvel.  The snow is light in the area \n\
and you are able to be almost comfortable here.\n");
  add_trigger("listen","You here the bubbling sound of water crashing on rocks.\n");
  set_light(1);
  add_look("snow","|WKBThe snow is drifted nicely.\n");
  add_look("river","The water is a pale blue, and you can see the riverbed clearly.\n");
  add_look("riverbed","Small rocks litter the river bottom.\n");
  add_look(({"rock","rocks"}),"\
These seem to be small pebbles, normal for a swift river.\n");
  add_exit("west", FOREST + "/forest008");
  add_exit("south", FOREST + "/forest002");
  replace_program(ROOM);
}

