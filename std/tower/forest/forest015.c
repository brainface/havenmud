#include <mudlib.h>
#include <types.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_cold(1);
  set_terrain(TER_FOREST);
  set_short("a forest");
  set_long("\
The river runs through the forest here in a gentle rush\n\
of water.  Looking about you, the trees seem to grow very\n\
nearly to the waters edge.  You wonder in an offhanded way\n\
why these trees are so close to the water.  Some animals\n\
are playing in the trees here, oblivious to your presence.\n");
  add_look("animals","You see that they are playing in the trees,\n\
but you also note that they do not approach the river.\n");
  add_look("trees","The evergrees have grown nearly into the water.\n");
  add_look("river","\
The river runs in a north-west to south-east way.\n\
The water seems cool and refreshing, you almost\n\
want to bathe in it.  However, you also see a \n\
small animal skeleton near the river.\n");
  add_look("skeleton","\
This creature seems to have died here near the river.\n\
With that sobering thought, you recall stories from \n\
your youth about people drowning.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest020");
  add_exit("south", FOREST + "/forest014");
}

void init() {
  ::init();
  add_action("bathe","bathe");
}

int bathe(string str) {
  if (random(6) < 3) {
    write("|BKBThe waters refresh you greatly!\n");
    say(TP->NAME + " bathes in the river.\n");
    TP->restore_spell_points(200);
    return 1;
  }
  write("|BKBYou are overtaken by the water!\n");
  say(TP->query_cap_name()+" seems to be drowning!\n");
  move_object(TP, TOWER + "/tower016");
  TP->hit_player(random(500),DAM_POISON);
  command("unequip",TP);
  command("drop all",TP);
  command("drop money",TP);
  command("quit",TP);
  return 1;
}

