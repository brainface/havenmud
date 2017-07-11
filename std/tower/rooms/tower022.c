#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(1);
  set_short("South east tower");
  set_long("\
The hallway continues to move along to the east in a path\n\
that seems less detailed than the tower has thus been.\n\
It seems from this point to have been given a practical use\n\
rather than the more finely crafted rooms you have seen below.\n\
The chairs and tables here seem to be purposeful, and the walls\n\
are less adorned.\n");
  add_look("walls","\
The walls are not decorated in any way.\n");
  add_look(({"chairs","tables"}),"\
These seem to have been suffled about in a practical,\n\
almost utilitarian manner subtable for general use.\n");
  add_exit("west",TOWER+"/tower014");
  add_exit("north",TOWER+"/tower011");
  replace_program(ROOM);
}
