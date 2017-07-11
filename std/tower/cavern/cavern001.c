#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_short("a cave");
  set_light(1);
  set_long("\
You are in a cave.  The cave seems to be fairly spacious\n\
and somehow this doesn't encourage you.  Looking around \n\
you see signs of life, footprints here and there, bones \n\
lying gnarled on the ground.  The snow doesn't seem to \n\
penetrate into the cave, and oddly this also doesn't \n\
seem to reassure you.  The room is still chilly.\n");
  add_look(({"footprint","footprints"}),"\
The foots prints seem to be almost human except for \n\
a vague claw-type shape on it.\n");
  add_look(({"bone","bones"}),"\
The gnarled bones seem to have been the remains of small \n\
animal life.\n");
  add_look("claw","\
These seem to be Draconian claws.\n");
set_cold(1);
  add_exit("out", FOREST+"/forest001");
  add_exit("south", CAVERN+"/cavern002");
  add_exit("southeast", CAVERN+"/cavern003");
  set_light(0);
  replace_program(ARCTIC);
}
