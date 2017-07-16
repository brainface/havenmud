
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
    "keys"       : "assassin_key_001",
    ]) );
  SetSide("cabin", ([
    "keyname"    : ("door"),
    "short"      : "a sturdy door",
    "long"       : "The door is built from local wood. It appears to be very durable.",
    "id"         : "door",
    "adjectives" : ({"sturdy","oak","durable"}),
    "lockable"   : 1,
    "keys"       : "assassin_key_001",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(100);
}
