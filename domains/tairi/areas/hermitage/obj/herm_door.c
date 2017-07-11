#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("south", ([
    "keyname" : ("door"),
    "short"   : "an iron door",
    "long"    : "This door is of a very simple yet sturdy construction.",
    "id"      : "door",
    "adjectives" : ({"simple", "sturdy", "iron" }),
    "lockable" : 1,
    "keys" : "herm_key",
    ]) );
  SetSide("north", ([
    "keyname"    : ("door"),
    "short"      : "an iron door",
    "long"       : "This door is of a very simple yet sturdy construction",
    "id"         : "door",
    "adjectives" : ({"simple", "sturdy", "iron"}),
    "lockable"   : 1,
    "keys" : "herm_key",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(50000);
}
 

mixed eventUnlock(object who, object key) {
  mixed res = ::eventUnlock(who, key);
  if (res == 1) { key->eventDestruct(); }
  return res;
}

