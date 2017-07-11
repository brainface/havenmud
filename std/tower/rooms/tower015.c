#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/vip", 4+random(2));
  if (arg) return;
  set_light(1);
  set_terrain(TER_INSIDE);
  set_short("suites");
  set_long("\
This room was a suite for the highest ranking visitors\n\
to the court of Rath-Khan.  The beds that are spread\n\
around represent the culture of Rath-Khan's decadence.\n\
No difference is paid to quartering for males or females,\n\
nor does it seem that it mattered.  The room itself\n\
is large enough to hold several people, yet still feel \n\
comfortable.  You are once again in awe at the design of\n\
the tower.\n");
  add_look(({"bed","beds"}),"\
The beds are lined up in a fashion that gives each guest\n\
space without compromising the room's purpose of holding\n\
as many people as possible.\n");
  add_exit("east",TOWER+"/tower018");
}
