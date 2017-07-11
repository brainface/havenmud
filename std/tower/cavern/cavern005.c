#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/draco",2);
  add_clone(CRITS + "/dwarf",4);
  if (arg) return;
  set_terrain(TER_UNDERGROUND);
  set_cold(1);
  set_short("a cave");
  set_long("\
The cavern passage bends here from northwest to south, \n\
giving you a feeling that perhaps not all of this cave \n\
is a natural wonder.  It almost appears that this cave \n\
was carved as a passage deliberately.\n");
  add_exit("south", CAVERN+"/cavern006");
  add_exit("southwest",CAVERN+"/cavern004");
}
