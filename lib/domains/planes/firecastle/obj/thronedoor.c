//
// filename: thronedoor
// Thoin@Haven 01-16-06
//

#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north", ([
    "keyname"    : ("door"),
    "short"      : "a large silver door",
    "long"       : "The door is composed of mostly silver and is engraved "
                   "with a vivid image of a man consumed by flames.",
    "id"         : "door",
    "adjectives" : ({"silver", "large" }),
    "lockable"   : 1,
    "keys"       : "thronekey1",
    ]) );
  SetSide("south", ([
    "keyname"    : ("door"),
    "short"      : "a large silver door",
    "long"       : "The door is composed of mostly silver and is engraved "
                   "with a vivid image of a man consumed by flames.",
    "id"         : "door",
    "adjectives" : ({"silver", "large" }),
    "lockable"   : 1,
    "keys"       : "thronekey1",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(500);
}

