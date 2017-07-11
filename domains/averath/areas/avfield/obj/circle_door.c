#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("southeast", ([
    "keyname" : ("door"),
    "short"   : "a mithril door",
    "long"    : "The door is made of solid mithril. It is secured "
                "to a metal frame that was cemented into the sandy "
                "walls of the burrow. There is a circle cut into "
                "the center of it. ",
    "id"      : "door",
    "adjectives" : ({"mithril"}),
    "lockable" : 1,
    "keys"     : "circle_key",
    ]) );
  SetSide("northwest", ([
    "keyname"    : ("door"),
    "short"      : "a mithril door",
    "long"       : "The door is made of solid mithril. It is secured "
                "to a metal frame that was cemented into the sandy "
                "walls of the burrow. There is a circle cut into "
                "the center of it.",
    "id"         : "door",
    "adjectives" : ({"mithril"}),
    "lockable"   : 1,
    "keys"       : "circle_key",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(600);
}
