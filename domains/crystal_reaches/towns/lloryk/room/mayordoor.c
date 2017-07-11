#include <lib.h>
#include "../path.h"

inherit LIB_DOOR;


static void create()
{
  door::create();
  
  SetSide("west", ([ "id" : "door",
                      "short" : "a faded red door",
                      "long" : "The small round red door looks very sturdy.",
                      "lockable" : 1,
                      "keys" : "zzmayor key"]) );
  SetSide("east", ([ "id" : "door",
                      "short" : "a faded red door",
                      "long" : "The small round red door looks very sturdy.",
                      "lockable" : 1,
                      "keys" : "zzmayor key"]) );

  SetClosed(1);
  SetLocked(1);
}
