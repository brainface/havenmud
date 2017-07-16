
#include <lib.h>
inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide("out", ([
    "keyname"    : "door",
    "short"      : "a sturdy door",
    "long"       : "The door is built from local wood. It appears to be very durable.",
    "id"         : "door",
    "adjectives" : ({"sturdy","oak","durable"}),
    "lockable"   : 1,
    "keys"       : "jidoor_key_001",
    ]) );
  SetSide("house", ([
    "keyname"    : ("door"),
    "short"      : "a sturdy door",
    "long"       : "The door is built from local wood. It appears to be very durable.",
    "id"         : "door",
    "adjectives" : ({"sturdy","oak","durable"}),
    "lockable"   : 1,
    "keys"       : "jidoor_key_001",
    ]) );
  SetClosed(0);
  SetLocked(0);
  SetLockStrength(100);
}
