#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north", ([
    "keyname" : ("door"),
    "short"   : "a heavy oak door",
    "long"    : "This large heavy door is set deeply into the north wall. "
                "It is made of thick oak with a large key hole.",
    "id"      : "door",
    "adjectives" : ({"large", "oak", "thick" }),
    "lockable" : 1,
    "keys"     : "key1",
    ]) );
  SetSide("south", ([
    "keyname"    : ("door"),
    "short"      : "an iron door",
    "long"       : "The door is reinforced with thick iron straps screwed into "
                   "the heavy oak in a lattace pattern.",
    "id"         : "door",
    "adjectives" : ({"large", "oak", "thick", "reinforced"}),
    "lockable"   : 1,
    "keys"       : "key1",
    ]) );
  SetClosed(1);
  SetLocked(1);
  SetLockStrength(175);
}

mixed eventUnlock(object who, object key) {
  mixed res = ::eventUnlock(who, key);
  if (res == 1) { key->eventDestruct(); }
  return res;
}
