#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
 ::reset(arg);
 add_clone(CRITS+"/woodsman");
 if (arg) return;
  set_terrain(TER_INSIDE);
  set_light(1);
  set_short("a cottage in the woods");
  set_long("\
The cottage seems to be a quaint yet musty building,\n\
with concern given more towards practicality than \n\
toward beauty.  The cupboards seem to have been hewn \n\
directly into the wood of the walls, and you wonder\n\
why this would be built so.  The fireplace seems to \n\
have been recently used, but is not currently lit.\n\
On the floor, a bearskin rug adds to the decor.\n");
  add_look(({"cupboards","cupboard"}),"\
The cupboards seem to be nearly empty except for some\n\
moldering scraps from days past.\n");
  add_look("fireplace","\
The ashes in the fireplace seem to be recent.\n\
The chimney rises from the ground to ceiling.\n\
You feel a draft as you look up.\n");
  add_look(({"bearskin","rug"}),"\
The rug is a simple through skin taken from an \n\
unfortunate forest creature.\n");
  add_look("chimney","\
The chimney is a stone structure rising up.\n\
Something seems odd about the chimney.\n");
  add_exit("out",  FOREST + "/forest024");
}

void init() {
  ::init();
  add_action("search","search");
  add_action("up","up");
}

int search(string str) {
  if (!str) {
    ::search(str);
    return 1;
  }
  if (str == "chimney") {
    say(TP->NAME+" searches the chimney.\n");
    write("\
You search the chimney and see a small ladder going up.\n");
    return 1;
  }
  if (str == "fireplace") {
    say(TP->NAME+" searches in the fireplace.\n");
    write("\
You look into the fireplace.  Looking up, you see a ladder.\n");
    return 1;
  }
  if (str) {
    write("Search what?\n");
    say(TP->NAME+" searchs "+str+".\n");
    return 1;
  }
}

int up() {
  move_object(TP,FOREST + "/house2");
  command("look",TP);
  return 1;
}
