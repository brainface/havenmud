// Coded by Zeratul 11-27-99
#include <lib.h>
#include "../lake.h"
inherit LIB_DOOR;

static void create() {
  door::create();

  SetSide("cabin", ([ "id" : "door",
     "short" : "a wood door",
     "long" : "A wooden cabin door.",
     "lockable" : 1,
     "keys" : "cabin_key"]) );
  SetSide("out", ([ "id" : "door",
     "short" : "a wood door",
     "long" : "A wooden cabin door.",
     "lockable" : 1,
     "keys" : "cabin_key"]) );
  SetClosed(1);
  SetLocked(0);
}
