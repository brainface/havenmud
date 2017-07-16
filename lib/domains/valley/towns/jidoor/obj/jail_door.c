#include <lib.h>
 inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide("out", ([
    "keyname" : ("door"),
    "short" : "a sturdy door",
    "long" : "The door is built of sturdy oak, cross-braced with iron. It "
       "appears to be very durable.",
    "id" : "door",
    "adjectives" : ({"sturdy","oak","durable"}),
    "lockable" : 1,
    "key" : "jidoor_jail_key"
    ]) );
  SetSide("building", ([
    "keyname" : ("door"),
    "short" : "a sturdy door",
    "long" : "The door is built of sturdy oak, cross-braced with iron. It "
       "appears to be very durable.",
    "id" : "door",
    "adjectives" : ({"sturdy","oak","durable"}),
    "lockable" : 1,
    "key" : "jidoor_jail_key"
    ]) );
  SetClosed(1);
  SetLocked(1);
}
