#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;
int searchvar;

void reset(int arg) {
  ::reset(arg);
  searchvar=0;
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(1);
  set_short("a hidden alcove");
  set_long("\
The attic crawlspace seems to be the hiding place\n\
of the house's valuables.  Looking around, you\n\
see chests of various sorts.\n");
  add_look(({"chest","chests"}),"\
These seem to be normal chests.\n");
  add_exit("down",FOREST + "/house");
}

void init() {
  ::init();
  add_action("open","open");
}

int open(string str) {
  if (!str) {
    write("You should be more specific.\n");
    return 1;
  }
  if (str == "chest") {
    if (random(10)==0 && searchvar==0) {
      move_object(clone_object(TRSR+"/gem"),TP);
      write("What Luck!  You find a gem!\n");
      say(TP->NAME+" opens a chest.\n");
      searchvar++;
      return 1;
    }
    write("Sorry, you find nothing.\n");
    say(TP->NAME+" opens a chest.\n");
    return 1;
  }
}
