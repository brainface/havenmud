#include <mudlib.h>
#include <perms.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (!present("man")) make_object("keeper", CRITS + "/keeper");
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_short("Crypt Entrance");
  set_long("\
This is the entrance to the Crypt that houses the remains\n\
of the greatest and most powerful evil beings ever. The \n\
ceiling is low over your head, and it seems from here that\n\
you are being stifled in the crampted quarters.  Statues\n\
litter the room, all in gold relief.  You are again\n\
overwhelmed by the wealth and beauty of this place.\n");
  add_look("ceiling","The low ceiling has murals on it.\n");
  add_look("murals","\
Like the other art in the tower, the murals focus on \n\
the dead.  However, the scenes do not seem evil,\n\
merely undead.\n");
  add_look("statues","\
The statues are all covered in gold.  They depict\n\
scenes and ideas from ages past, when the knights\n\
of the Emperor where finally driven back to the \n\
wastelands of the far north.\n");
  set_light(0);
  add_trigger("sit","You are still shaken by the horrors of the tower.\n");
  add_trigger("lick","Your tongue refuses to come out of it's mouth.\n");
  add_look("statue","The statues represent Rath-Khan's hirelings.\n");
  add_exit("south",TOWER+"/tower010");
  add_exit("north", TOWER + "/tower005");
}

status south_hook() {
  if (IS_APPLICANT(TP)) return 0;
  if (present("keeper")) {
    write("The Crypt keeper will not allow it.\n");
    say("The Crypt keeper blocks " + TP->NAME + ".\n");
    return 1;
  }
  return 0;
}
