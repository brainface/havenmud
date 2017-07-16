#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;
int searchvar;

void reset(int arg) {
  ::reset(arg);
  searchvar=0;
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(0);
  set_short("Crypt");
  set_long("\
This is the Crypt of Rath Khan's followers. Looking around,\n\
you see that the room is in pristine shape.  There are ten \n\
caskets spaced thoughout the room.\n");
  add_look("caskets","You see several marble tombs, all with gold and jewelry fixed on them.\n");
  add_exit("north", TOWER + "/tower009");
}

int search(string arg) {
  if (arg != "caskets" && arg != "casket") {
     ::search(arg);
     return 1;
  }

  if (random(4)) {
    write("You search the caskets and find nothing.\n");
    say(TP->NAME + " searches a casket.\n");
    return 1;
  }
  else if (searchvar==0) {
    write("You find something!\n");
    say(TP->NAME + " searches a casket.\n");
    move_object(clone_object(TRSR+"/gem"),TP);
    if (random(4)) add_clone(CRITS+"/wraith", random(10));
  }
  searchvar++;
  return 1;
}

status north_hook() {
  if (TP->query_ghost()) return 0;
  if (present("wraith")) {
    write("|RKBThe wraith hisses 'Not yet, vermin...'\n");
    say("The wraith blocks " + TP->NAME + " from leaving.\n");
    return 1;
  }
  return 0;
}
