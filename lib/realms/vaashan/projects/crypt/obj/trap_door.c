
#include <lib.h>
 inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide("up", ([
    "keyname" : ("door"),
    "short" : "a trap door",
    "long" : "The door is built of sturdy oak, cross-braced with iron. It "
       "appears to be very durable.",
    "id" : "door",
    "adjectives" : ({"trap","oak","durable"}),
    "lockable" : 1,
    "keys" : "TRAPKEY",
    ]) );
  SetSide("down", ([
    "keyname" : ("door"),
    "short" : "a trap door",
    "long" : "The door is built of sturdy oak, cross-braced with iron. It "
       "appears to be very durable.",
    "id" : "door",
    "adjectives" : ({"trap","oak","durable"}),
    "lockable" : 0,
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(75);
}