#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  add_money(1000 + random(2500));
  if (arg) return;
  set_short("a treasure room");
  set_long("\
This seems to be some form of treasure chamber.\n\
Looking about, the loot seems to to taken from \n\
unwilling victims through the years.\n");
  add_look("loot","Every item seems wet for some reason.\n");
  set_light(1);
  set_no_clean_up(1);
  add_exit("south",TOWER+"/tower023");
  add_trigger("sit","You can't rest here!\n");
}
