#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(1);
  set_short("private room");
  set_long("\
This is the private sitting room of Rath-Khan.\n\
Looking around, you see plush chairs and sofas\n\
that speak of wealth and class.  About the room\n\
there are paintings and tapestries depicting\n\
the height of Rath-Khan's power.\n");

  add_look(({"painting","paintings","tapestry","tapestries"}),"\
These, like the other artworks in the tower, show \n\
scenes of violence and gore from centuries past.\n");

  add_look(({"chair","chairs"}),"\
The chairs appear very comfortable.\n");

  add_look(({"sofa","sofas"}),"\
The sofas appear large enough to lie on.\n");

  add_exit("east",TOWER+"/tower025");
  replace_program(ROOM);
}
