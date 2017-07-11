#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("A small chapel");
  set_long("\
The Chapel seems to be full of people!  Sitting in the\n\
pews are more than forty people.  All of them seem intent on\n\
the ceremony at the front of the room.\n");
  add_look("people","The people all have something in common.  They are all dead.\n");
  add_look("pews","The pews are made of fine oak.\n");
set_domain("hyperborea");
  add_look("ceremony","A cleric is preaching at the front of the room.\n");
  add_look("cleric","A large corpse, still fresh by your guess.\n");
  add_exit("north", TOWER + "/tower002");
  add_trigger("sit","You can't be at ease here!\n");
  add_trigger("smell","The stench of Death is in this place.\n");
  replace_program(ROOM);
}
