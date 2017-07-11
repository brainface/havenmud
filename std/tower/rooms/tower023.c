#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS+"/eskel",2);
  if (arg) return;
  set_light(1);
  set_terrain(TER_INSIDE);
  set_short("Guard Post");
  set_long("\
This room does not seem to be as posh as the reception\n\
hall you just left.  In fact, you think it looks alot \n\
like this room is a miniature fortification.  A guard \n\
post sits behind a small wall facing you.  The room is \n\
devoid of furniture that could be used to favor an attack.\n\
You believe that the designer was a master of warfare and \n\
strategy.\n");
  add_look("post","\
The guard post seems to be a desk and chair behind a wall.\n");
  add_look("wall","\
A short four foot wall to stall an advance.\n");
  add_look("chair","\
A normal chair.\n");
  add_look("desk","\
A normal desk.\n");
  add_exit("north",TOWER+"/tower016");
  add_exit("east", TOWER+"/tower017");
}

status north_hook() {
  if (present("guard")) {
    write("You don't think the guard will let you go that way.\n");
    say("The guard stares "+TP->NAME+" down when "+TP->PRON+" tries to leave.\n");
    return 1;
  }
  return 0;
}
