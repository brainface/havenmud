
#include <mudlib.h>
#include <perms.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS+"/eskel",2);
  if (arg) return;
  set_light(0);
  set_terrain(TER_INSIDE);
  set_short("Guard room");
  set_long("\
You are in a waiting chamber.  The plush chairs and fabulous\n\
decor tell you that guests of the highest station have passed\n\
through this room.  The floor looks to have been carefully \n\
cleaned, and the stairwell leading up seems to have been\n\
polished to perfection.\n");
  add_look(({"stairs","stairwell"}),"\
Where do these stairs go?  They go up!\n");
  add_look("chairs","\
The chairs are made of the finest velvet.\n");
  add_look("decor","\
The decor of the room is surprisingly tasteful.\n");
  add_exit("down",TOWER+"/tower014");
  add_exit("west",TOWER+"/tower023");
  add_exit("east",TOWER+"/tower024");
  add_exit("up",TOWER+"/tower025");
}

status up_hook() {
  if(!present("guard")) { return 0; }
  if(IS_APPLICANT(TP) || TP->query_alignment() < 0) {
    say("The guard salutes "+TP->NAME+" and let's "+TP->OBJ+" pass.\n");
    write("The guard salutes you and allows you to pass.\n");
    return 0;
  }
  say("The guard refuses to allow "+TP->NAME+" to pass.\n");
  write("The guard refuses to allow you to pass.\n");
  return 1;
}
