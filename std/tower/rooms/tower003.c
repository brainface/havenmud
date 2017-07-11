#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("inside the tower");
  set_long("\
This appears to have been a large reception area.\n\
Tables litter the room and chairs are overturned in\n\
numerous places. You get an uneasy feeling.\n");

  add_look(({"tables","chairs"}),"\
The tables and chairs seem to have an ageless wood \n\
quality about them.\n");

  add_trigger("sit","You could never be at ease here!\n");

  add_exit("east", TOWER + "/tower001");
  add_exit("south", TOWER + "/tower019");
  replace_program(ROOM);
}
