#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north", ([
    "keyname" : ("door"),
    "short"   : "an iron door",
    "long"    : "The door is a huge iron beast which looks like it could "
                "hold back the demons of the Lower Planes.",
    "id"      : "door",
    "adjectives" : ({"iron", "huge" }),
    "lockable" : 1,
    "keys"     : "key33",
    ]) );
  SetSide("south", ([
    "keyname"    : ("door"),
    "short"      : "an iron door",
    "long"       : "The door is a huge iron monster of a creation.",
    "id"         : "door",
    "adjectives" : ({"huge", "iron"}),
    "lockable"   : 1,
    "keys"       : "key33",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(500);
}

mixed eventUnlock(object who, object key) {
  mixed res = ::eventUnlock(who, key);
  if (res == 1) { key->eventDestruct(); }
  return res;
}


