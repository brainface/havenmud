#include <lib.h>
#include "prasanna.h"

inherit LIB_DOOR;


static void create()
{
  door::create();
  
  SetSide("north", ([ "id" : "gate",
                      "short" : "a bronze gate",
                      "long" : "A large bronze gate, sealed indefinately to "
                                 "prevent passage deeper into the city.",
                      "lockable" : 0 ]) );
  SetSide("south", ([ "id" : "gate",
                      "short" : "a bronze gate",
                      "long" : "An impenetrable bronze gate, sealing the "
                                 "south side of the city off.",
                      "lockable" : 0 ]) );
  SetClosed(1);
  SetLocked(1);
}
