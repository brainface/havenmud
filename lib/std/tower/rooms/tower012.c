#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  object ob;
  ::reset(arg);
  add_clone(CRITS+"/capt");
  make_unique_object("avenger",WPNS+"/unholy");
  ob = present("avenger");
  if (ob) move_object(ob,find_living("captain"));
  command("wield sword",find_living("captain"));
  add_clone(CRITS+"/eskel",random(3));
  add_clone(CRITS+"/skel",random(4));
  if (arg) return;
  set_no_clean_up();
  set_terrain(TER_INSIDE);
  set_light(1);
  set_short("Barracks");
  set_long("\
This seems to have been the barracks for the soldiers\n\
of Rath-Khan.  Beds are stacked on top of each other in\n\
an odd fashion here, and you suspect that this room \n\
only houses a small number of officers and pages.\n\
The room is ornamented with the things that one would \n\
naturally place in a bedroom, with knicknacks and\n\
other finery.\n");
  add_look("beds","\
These seem to be normal beds.\n");
  add_look("knicknacks","\
These are normal items of the finest make.  \n\
In short, you see a lot of junk.\n");
  add_exit("east",TOWER+"/tower011");
}
