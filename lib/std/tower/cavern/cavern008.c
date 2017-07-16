#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/draco",2);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_cold(1);
  set_short("a cave");
  set_long("\
From here, you can see light off to the southwest and southeast.\n\
This portion of the cave is getting more and more to look like \n\
a habitation rather than a cave. You can see when you look around \n\
that there are small black marks on the floor where fires have been \n\
built in the past, and that wooden benches are arrayed near to the \n\
walls.\n");
  add_look(({"mark","marks"}), "\
These marks are the simple remains of a firepit.\n");
  add_look(({"bench","benches"}),"\
The benches are simple wooden seats for use around the fires.\n");
  add_exit("west",CAVERN+"/cavern007");
  add_exit("east",CAVERN+"/cavern015");
  add_exit("north",CAVERN+"/cavern006");
  add_exit("southeast",CAVERN+"/cavern010");
  add_exit("southwest",CAVERN+"/cavern009");
}
