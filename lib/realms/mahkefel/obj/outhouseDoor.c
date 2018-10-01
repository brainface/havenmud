#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north",
    ([ "id" : "door", 
     "short": "a wooden door",
     "long" : "a wooden door with a crescent shaped window.",
     "lockable" : 1])
  );
  SetSide("south",
    ([ "id" : "door", 
     "short": "a wooden door",
     "long" : "a wooden door with a crescent shaped window.",
     "lockable" : 0]) 
  );
  SetClosed(1);

}
