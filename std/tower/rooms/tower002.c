#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("East wing");
  set_long("\
This room seems to be more of a room to relax and rest prior\n\
to some sort of church service.  The door to the south is\n\
a large oaken one inlaid with silver runes.  The whole area\n\
gives off a feeling of evil.\n");

  add_look("runes","\
The runes seem to be in an archaic tongue.\n");

  add_look("door","\
The door is a huge oaken masterpiece engraved with runes.\n");

  add_trigger("sit","You can't be at ease here!\n");

  add_exit("south", TOWER + "/tower020");
  add_exit("west", TOWER + "/tower001");
  replace_program(ROOM);
}
