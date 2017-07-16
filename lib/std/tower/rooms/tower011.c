#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_light(1);
  set_terrain(TER_INSIDE);
  set_short("a hall");
  set_long("\
Chairs and tables litter this room in an almost chaotic way.\n\
Looking about you, you see that this room must have been \n\
the common room for the soldiers of Rath-Khan's army back \n\
in his height of power. The room is filled with racks and \n\
rusted weapons, all aged tremendously by their stay in \n\
the tower.\n");
  add_look(({"chairs","tables"}),"\
This is just normal, albeit old, furniture.\n");
  add_look("weapons","These are old rusted weapons.  They are worthless.\n");
  add_look(({"rack","racks"}),"\
The racks have been aged and are nearly corrupted to junk.\n");
  add_exit("south",TOWER+"/tower022");
  add_exit("west",TOWER+"/tower012");
  replace_program(ROOM);
}
