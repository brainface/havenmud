#include <lib.h>
inherit LIB_ROOM;
#include "maze/maze.h"

void init() 
{
  if (random(10))
  {
  object hedge;  
  if (!hedge = present("hedge", this_object()))
  {
  	hedge = new(MAZE_NPC "hedge");   
  }
  room::init();  
  if (hedge && !(this_player()->GetUndead()))
  {
     hedge->eventMove(this_object());
     message("system", "One of the hedges springs to life and begins to "
       "attack you!", this_player() );
     hedge->SetAttack(this_player());
    }
  }
}

void heart_beat() 
{
  object hedge = present("hedge", this_object());
  room::heart_beat();  
   
  hedge->eventMove(this_object());
  hedge->SetAttack(filter(all_inventory(this_object()), (: playerp :) ) );  
}
