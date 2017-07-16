#include <mudlib.h>
#include <perms.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS+"/guard",2);
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(1);
  set_short("guest lounge");
  set_long("\
The room gives off a laid back atmosphere as you enter.\n\
The couches and chairs spread out in the room let you \n\
know that wealth resides here.  This seems to have been\n\
a lounge of some kind that must have housed grand balls\n\
in the days of Rath-Khan's Empire.\n");
  add_look("couch","\
The couch seems to be fluffy still after all the ages.\n");
  add_look("couches","\
The couches seem fluffy after all the years.\n");
  add_look(({"chair","chairs"}),"\
The chairs appear comfortable and relaxing.\n");
  add_exit("south",TOWER+"/tower024");
  add_exit("west",TOWER+"/tower015");
}

status west_hook() {
  if(IS_APPLICANT(this_player())) return 0;
  if (present("guard")) {
    write("The guard's eyes glow and his head shakes 'No' at you.\n");
    say("The guard stopped " + TP->NAME+ " from going west.\n");
    return 1;
  }
  return 0;
}
