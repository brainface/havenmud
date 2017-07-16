#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("Grand Ball room");
  set_long("\
This was once the Grand Ball room of the King Rath-Khan.\n\
What once must have been beautiful tapestries line the \n\
walls.  Six huge golden fountains are spread across the\n\
room in a style that amazes you.  You are fascinated by the\n\
display of wealth.\n");
  add_look(({"fountain","fountains"}),"\
These fountains poured water into basins made of gold ages ago.\n");
  add_look("tapestries","\
The marvel of the woven beauties astounds you.\n");
  add_exit("north", TOWER + "/tower003");
  replace_program(ROOM);
}
