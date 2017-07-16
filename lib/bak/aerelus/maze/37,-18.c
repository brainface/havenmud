#include <lib.h>
inherit LIB_ROOM;
#include "maze.h"
int BeenDug;

static void create() {
  room::create();
  SetShort("in a narrow hedge maze");
  SetLong(
    "This long, narrow maze is made up of extremely dense hedges, so thick that "
    "the only possible means of escape is either death, or reaching the exit. The "
    "maze seems to end here, where the soil looks loosened somewhat."
  );
  BeenDug = 0;
  SetSmell( ([
    "default" : "The scent of decaying wood hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "The quiet on the air is disturbing.",
    ]) );  
  SetExits( ([    
    "north" : MAZE "37,-17",
    ]) );  
}

varargs mixed eventDig(object who, string what) {
  object scroll = new(MAZE_OBJ "fakescroll");
  if (!scroll) return "Digging doesn't reveal anything.";
  if (BeenDug) return "The earth looks freshly turned like "
    "someone has already dug here.";
  send_messages( ({ "dig", "bend" }),
    "$agent_name $agent_verb into the ground and then "
    "$agent_verb over to pick something up.",
    who, 0, environment(who) );
  scroll->eventMove(who);
  message("action", "You uncover a scroll buried in the ground.",
      this_player() );
  BeenDug = 1;
  return 1;
}