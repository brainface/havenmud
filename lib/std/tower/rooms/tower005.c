#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_short("Hall of Rites");
  set_long("\
This hall was used for the celebrations of death and dying\n\
in the peak of the Lich-King's power.  The draperies are old \n\
and moldy, as are the furnishings.  In this room you get a \n\
sense of loss rather than a sense of evil.\n");

  add_look("draperies","\
The draperies are richly embroidered with golden thread.\n\
You can feel that this place was almost holy compared\n\
to the evil of the tower.\n");

  add_look("furnishings","The rich velvet seems inviting to your weary bones.\n");

  add_trigger("relax","You relax comforatbly.\n");
  add_trigger("sit","The horrors of the tower do not allow you respite.\n");

  add_exit("up", TOWER + "/tower001");
  add_exit("north", TOWER+ "/tower007");
  add_exit("south", TOWER + "/tower009");
  replace_program(ROOM); 
}
