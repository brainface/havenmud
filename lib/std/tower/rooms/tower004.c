#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("Crypt Gates");
  set_long("\
This room is a shrine to death in all its forms.\n\
From the bas relief on the walls to the tables\n\
on the floor, this room embodies death.\n");

  add_look("relief","\
The display is a horrific one showing skeletons\n\
in various conditions doing things that would \n\
turn the stomach of the most hardened cleric \n\
of Mitra.\n");

  add_look("table","A large table made entirely of bone.\n");

  add_look(({"table","tables"}),"\
The tables seem normal, excepting that the legs\n\
are carved in the image of skeletons engaged \n\
in various grotesque positions.\n");

  add_exit("north", TOWER + "/tower001");
  add_exit("up", TOWER + "/tower014");

  add_trigger("sit","You can't feel at ease here!\n");
  replace_program(ROOM);
}
