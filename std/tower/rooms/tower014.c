#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  make_unique_object("skeletan", CRITS + "/eskel");
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_short("hallway");
  set_long("\
This hall extends about ten paces in an east-west direction.\n\
Looking about you, you see painting on the deeply ebony\n\
colored walls.  The floor seems smooth and almost unbroken,\n\
though it has surely stood for thousands of years.  You see\n\
tables and small pots along the walls.\n");
  add_look(({"paintings","painting"}),"\
These pictures depict scenes from the mortal days of \n\
Rath-Khan.  You see hordes of warriors marching under a \n\
crimson and golden banner.  In many of the scenes, the \n\
warriors are slaying Elves.  However, in one case, you see\n\
that the troops are slaying Orcs.\n");
  add_look("banner","|YRBThe banner depicts a crown on a blood-red field.\n");
  add_look(({"pot","pots"}),"These seem to have once held plant matter.\n");
  add_look(({"table","tables"}),"The tables seem to be simple furniture.\n");
  add_look("elves","The mass slaughter of the Elves is horrible.\n");
  add_look("orcs","The Orcish Boyz seem to give a good accounting of themselves.\n");
  add_look("floor","You see a small curved arrow pointing east.\n");
  add_look("walls","The smooth walls seem to be in perfect condition.\n");
  add_exit("east", TOWER + "/tower022");
  add_exit("up",  TOWER+"/tower017");
  add_exit("west", TOWER + "/tower021");
  add_exit("down", TOWER + "/tower004");
}
