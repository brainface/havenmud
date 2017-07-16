#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS+"/eskel",2);
  if (arg) return;
  set_short("west basement");
  set_long("\
This room seems to have been a store room.\n");
  set_terrain(TER_INSIDE);
  add_exit("east",TOWER+"/tower005");
}
