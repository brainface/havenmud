#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("Treasure Hall");
  set_long("\
This is the treasure hall for Rath-Khan's empire.  Strewn\n\
across the room are piles of gems and jewelery.  In the back\n\
corner of the room, you see several barrels.\n");
  add_trigger("sit","You can't rest in a place like this!\n");
  add_exit("south", TOWER + "/tower005");
  add_look(({"barrels","barrel"}),"Some large wooden barrels.\n");
  add_look(({"gems","gem","jewelery","jewels","piles","pile"}),"\
These valuables seem almost translucent.\n");
  add_trigger("get","The item you reach for seems to disappear at your touch!\n");
  replace_program(ROOM);
}
