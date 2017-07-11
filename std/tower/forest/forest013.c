#include <mudlib.h>
#include <perms.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/skel",3);
  if (arg) return;
  set_terrain(TER_FOREST);
  set_cold(1);
  set_short("A forest");
  set_long("\
A small clearing gives way here to the most terrifing sight\n\
you have ever beheld.  Rising from the ground is a Tower so\n\
large that you can barely see it's summit from where you stand.\n\
The base of the tower is covered in snow, and the door seems\n\
to almost beckon you to come in out of the cold.  However, \n\
you get a dread feeling that the Tower is not for the weak\n\
at heart.  The trees themselves seem different in their respect\n\
for the power the Tower contains.  You can only hope that the\n\
legends about the Tower of the Lich-King, Rath-Khan, are false.\n");
  add_look("snow","The snow drifts lazily up next to the tower.\n");
  add_look("tower","The Tower of Rath-Khan is huuuge and terrifying.\n");
  add_look("base","\
The base of the tower is dug firmly into the ground.\n\
It must have taken many slaves to make a tower this\n\
large.\n");
  add_look("summit","\
The pinnale of the tower rises at least 5 stories above you.\n");
  add_trigger("listen","You don't hear anything at all.\n");
  add_trigger("sit","You could never be at ease here!\n");
  set_light(1);
  add_exit("west", FOREST + "/forest018");
  add_exit("east", FOREST + "/forest008");
  add_exit("north", FOREST + "/forest014");
  add_exit("enter", TOWER+"/tower001");
  add_look("trees","The trees are staying back by about 10 paces.\n");
  add_look("door","The door is a huge monolith of stone and iron.\n");
}

status enter_hook() {

  if(IS_APPLICANT(this_player())) return 0;

  if (present("skeleton")) {
    write("The skeleton blocks your path.\n");
    say(TP->NAME + " was blocked from reaching the door.\n");
    return 1;
  }
  return 0;
}
