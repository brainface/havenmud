#include <lib.h>
#include "../path.h"

inherit LIB_DOOR;


static void create()
{
  door::create();
  
  SetSide("cabin", ([ "id" : "door",
                      "short" : "a sturdy door",
                      "long" : "A sturdy, well built, wooden door.",
                      "lockable" : 1,
                      "keys" : "cabin key"]) );
  SetSide("out", ([ "id" : "door",
                      "short" : "a sturdy door",
                      "long" : "A sturdy, well built, wooden door.",
                      "lockable" : 1,
                      "keys" : "cabin key"]) );

  SetClosed(1);
  SetLocked(1);
}
