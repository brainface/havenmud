#include <lib.h>
inherit LIB_ROOM;
#include "maze.h"

static void create() {
  room::create();
  SetShort("in a narrow hedge maze");
  SetLong(
    "This long, narrow maze is made up of extremely dense hedges, so thick that "
    "the only possible means of escape is either death, or reaching the exit. A "
    "sparse green mist drifts over the ground here. The hedges seem to move ever "
    "so slightly, despite the lack of wind."
  );
  SetSmell( ([
    "default" : "The scent of decaying wood hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "The quiet on the air is disturbing.",
    ]) );  
  SetExits( ([
    "southeast" : MAZE "7,-1",
    "north" : "/domains/planes/virtual/forest/20,20",
    ]) );
  SetInventory( ([ MAZE_NPC + "dryad" : 1, ]) );
}
