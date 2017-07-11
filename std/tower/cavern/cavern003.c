#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/dr_shaman");
  if (arg) return;
  set_cold(1);
  set_terrain(TER_UNDERGROUND);
  set_short("a cave");
  set_long("\
Off to the east, you see that the cave is on a slight \n\
decline, descending into the darkness and cold of the \n\
cavern.  The area you stand in seems to have been set \n\
aside for some kind of ritual, as along the floor are \n\
strewn bones around a firepit.\n");
  add_look(({"bone","bones"}),"\
The bones have a vaguely humanoid shape.\n");
  add_look("firepit","\
The pit seems to have been used for the cooking of \n\
a fatty animal.  You can tell this from the grease \n\
smudges along the ground.\n");
  add_look(({"smudge","smudges"}),"\
The smudges are an oily substance that smears easily at \n\
the touch.\n");
  add_exit("south",CAVERN+"/cavern004");
  add_exit("northwest",CAVERN+"/cavern001");
  add_exit("southwest",CAVERN+"/cavern002");
}
