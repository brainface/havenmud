//
// filename: door1
// Thoin@Haven 01-16-06
//

#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north", ([
    "keyname"    : ("door"),
    "short"      : "a large iron door",
    "long"       : "The door is composed of a large slab of iron engraved "
                   "with a vivid image of a large elemental slaughtering a "
                   "small town.",
    "id"         : "door",
    "adjectives" : ({"iron", "large" }),
    "lockable"   : 1,
    "keys"       : "doorkey1",
    ]) );
  SetSide("south", ([
    "keyname"    : ("door"),
    "short"      : "a large iron door",
    "long"       : "The door is composed of a large slab of iron engraved "
                   "with a vivid image of a large elemental slaughtering a "
                   "small town.",
    "id"         : "door",
    "adjectives" : ({"iron", "large" }),
    "lockable"   : 1,
    "keys"       : "doorkey1",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(500);
}
