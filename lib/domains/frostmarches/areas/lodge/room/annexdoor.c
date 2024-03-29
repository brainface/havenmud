#include "../lodge.h"
#include <lib.h>
inherit LIB_DOOR;
static void create() {
  door::create();
  SetSide("annex", ([ "id" : "door",
  "short" : "a complicated door",
  "long" : "This door is small in size but could fit mostly anyone.  The lock on the "
  "door needs a special shaped key to open.",
  "lockable" : 1,
  "keys" : "ice_key"]) );
  SetSide("staircase", ([ "id" : "door",
  "short" : "a complicated door",
  "long" : "This door is small in size but could fit mostly anyone.  The lock on the "
  "door needs a special shaped key to open.",
  "lockable" : 1,
  "keys" : "ice_key"]) );
  SetClosed(1);
  SetLocked(1);
}
