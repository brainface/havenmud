#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north", ([
    "keyname" : ("door"),
    "short"   : "a cast iron door",
    "long"    : "The door is a small cast iron door. It resembles "
                "that of a gate. It is, however, very sturdy. There is "
                "large triangle in the middle of the door. ",
    "id"      : "door",
    "adjectives" : ({"cast iron"}),
    "lockable" : 1,
    "keys"     : "triangle_key",
    ]) );
  SetSide("south", ([
    "keyname"    : ("door"),
    "short"      : "a cast iron door",
    "long"       : "The door is a small cast iron door. It resembles "
                "that of a gate. It is, however, very sturdy. There is "
                "large triangle in the middle of the door.",
    "id"         : "door",
    "adjectives" : ({"cast iron"}),
    "lockable"   : 1,
    "keys"       : "triangle_key",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(350);
}
