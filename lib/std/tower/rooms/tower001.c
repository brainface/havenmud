#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("Tower Entrance");
  set_long("\
This is the entrance hall to the tower of Rath-Khan,\n\
the Lich-King.  You are surrounded by a shroud of evil\n\
as you look at the various tapestries and paintings \n\
around you.\n");

  add_look("tapestries","\
These tapestries are covered with dust.  Brushing away the \n\
dust reveals that they are intricatly woven masterpieces.\n");

  add_look("paintings","\
The paintings represent people who lived in the hayday\n\
of evil and were the most feared men in the world.\n");

  add_trigger("sit","You cannot rest here!\n");
  add_trigger("listen","Everything is quiet.\n");
  add_exit("out", FOREST + "/forest013");
  add_exit("down", TOWER + "/tower005");
  add_exit("east", TOWER + "/tower002");
  add_exit("west", TOWER + "/tower003");
  add_exit("south", TOWER + "/tower004");
  replace_program(ROOM);
}

status out_hook() {
  if (TP->id("skeleton")) { 
    say("The skeleton stays far away from the door.\n");
    write("Rath Khan will not allow you to leave.\n");
    return 1;
  }
  return 0;
}
