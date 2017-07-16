#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_cold(3);
  set_terrain(TER_UNDERGROUND);
  set_short("a cave");
  set_long("\
The cave here is deep and cold.  To the east you can sense \n\
a presence of evil.  You are daunted by the images that run \n\
through your mind.  The rocks laying around the cave are smooth \n\
from countless centuries of laying in place.  You notice that \n\
many of the niches in the wall seem to have some pattern to \n\
them, almost part of a symbolic language.\n");
  add_look(({"niche","niches"}),"\
The scratches in the wall seem to be warnings of danger.\n");
  add_look(({"rock","rocks"}),"\
These rocks are smooth and almost shine in the light.\n");
  add_exit("northwest",CAVERN+"/cavern011");
  add_exit("southwest",CAVERN+"/cavern015");
  add_exit("northeast",CAVERN+"/cavern014");
  replace_program(ARCTIC);
}
