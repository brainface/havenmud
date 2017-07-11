#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_cold(2);
  set_short("a cave");
  set_long("\
This opening seems to be a junction between the upper cavern \n\
and the deeper cavern.  It is cold here, and you can tell that \n\
this area is less inhabited than the western caverns.  Somehow, \n\
you do not find this comforting.\n");
  add_exit("west",CAVERN+"/cavern008");
  add_exit("northwest",CAVERN+"/cavern006");
  add_exit("northeast",CAVERN+"/cavern013");
  replace_program(ARCTIC);
}
