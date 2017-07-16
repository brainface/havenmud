#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_cold(1);
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
The forest is getting thicker here, and the snow reflects\n\
that in the way it lies on the ground.  Off to the east, \n\
you can hear the rush of the river as it passes through.\n\
The forest to the west seems almost impassable, but you\n\
think you can see through it at certain places.\n");
  add_look(({"forest","trees","tree"}),"\
The trees come together into a wall of wood to the west.\n");
  add_look("wall","\
While the wall of wood is formidable, you may be able to \n\
squirm through it.\n");
  add_look("snow","The snow has fallen in a haphazard way,\n\
showing the way the trees hang above.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("east", FOREST + "/forest015");
  add_exit("south", FOREST + "/forest019");
}

void init() {
  ::init();
  add_action("squirm","squirm");
}

int squirm(string str) {
  if (!str) {
    write("You squirm around.\n");
    say(TP->NAME+" squirms around.\n");
    return 1;
  }
  if (str != "west" && str != "w") {
    write("You don't seem to get very far!\n");
    say(TP->NAME+" squirms off to the " + str + " but doesn't get far.\n");
    return 1;
  }
  write("You squirm through the wall of wood.\n");
  say(TP->NAME+" squirms through the west wall.\n");
  move_object(TP, FOREST + "/forest025");
  command("look",TP);
  return 1;
}
