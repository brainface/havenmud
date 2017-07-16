#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_short("a cave");
  set_cold(1);
  set_long("\
The cavern is steeply declined toward the south, with \n\
several cavern niches opened up into the space you stand\n\
in.  The dust on the floor is several inches deep, and \n\
footsteps are in the dust leading south.\n");
  add_look(({"step","footstep","footsteps"}),"\
The footsteps are vaguely human, except for the\n\
claw attached to them\n");
  add_look("claw","\
The claw marks the prints as Draconian.\n");
  add_look("dust","\
This is normal, though deep, dirt.\n");
  add_look("niches","\
These seem to be the obvious exits.\n");
  add_exit("north",CAVERN+"/cavern003");
  add_exit("northwest",CAVERN+"/cavern002");
  add_exit("east",CAVERN+"/cavern006");
  add_exit("south",CAVERN+"/cavern007");
  add_exit("northeast",CAVERN+"/cavern005");
  replace_program(ARCTIC);
}
