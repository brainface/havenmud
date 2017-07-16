#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  object ob;
  ::reset(arg);
  ob = present("wolf");
  if (!ob) make_object("wolf", CRITS + "/wolf",random(4));
  if (arg) return;
  set_terrain(TER_FOREST);
  set_cold(1);
  set_short("a forest");
  set_long("\
The woods have formed a small enclosure here.  Looking\n\
around, you get the feeling that this may have been \n\
the lair of some creature.  There are bones lying\n\
scattered about the room in a haphazard way, and in \n\
many cases, vital organs lay attached to these bones.\n\
Whatever it is that lives here, you hope it doesn't find \n\
out that you have disturbed it's realm.\n");
  add_look("bones","\
The bones of humanoid creatures litter the ground.\n\
Most of the bones appear gnarled and gnawed by a \n\
fierce woodland creature.  Oddly, some of the bones\n\
do not seem to have been fed upon, mearly brought \n\
here by the creature.  You have no idea why.\n");
  add_trigger("listen","You hear the sounds of the forest.\n");
  set_light(1);
  add_exit("south", FOREST + "/forest011");
}

