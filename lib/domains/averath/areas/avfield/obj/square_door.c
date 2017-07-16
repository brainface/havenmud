#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north", ([
    "keyname" : ("door"),
    "short"   : "a steel door",
    "long"    : "The door is made of steel. It doesn't have any signs "
                "of wear on it at all. There is a small etching in the "
                "center of it of a humanoid figure. Carved around the "
                "etching is a square. ",
    "id"      : "door",
    "adjectives" : ({"steel"}),
    "lockable" : 1,
    "keys"     : "square_key",
    ]) );
  SetSide("south", ([
    "keyname"    : ("door"),
    "short"      : "a steel door",
    "long"       : "The door is made of steel. It doesn't have any signs "
                   "of wear on it at all. There is a small etching in the "
                   "center of it of a humanoid figure. Carved around the "
                   "etching is a square.",
    "id"         : "door",
    "adjectives" : ({"steel"}),
    "lockable"   : 1,
    "keys"       : "square_key",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(100);
}
