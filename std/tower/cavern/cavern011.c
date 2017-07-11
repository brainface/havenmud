#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_cold(2);
  set_short("a cave");
  set_terrain(TER_UNDERGROUND);
  set_long("\
The cave slopes down into the earth in this direction, leading \n\
you to believe that further east the cave will slope further and \n\
further into the ground.  Something seems odd about this direction \n\
and cave, but you can't quite put your finger on it.\n");
  add_exit("southwest",CAVERN+"/cavern006");
  add_exit("southeast",CAVERN+"/cavern013");
  add_exit("northeast",CAVERN+"/cavern012");
  replace_program(ARCTIC);
}
