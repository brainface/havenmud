#include "../bhi.h"
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
    "keys"     : "moes_key",
    ]) );
  SetSide("south", ([
    "keyname"    : ("door"),
    "short"      : "an iron door",
    "long"       : "The door is reinforced with thick iron straps screwed into "
                   "the heavy oak in a lattace pattern.",
    "id"         : "door",
    "adjectives" : ({"large", "oak", "thick", "reinforced"}),
    "lockable"   : 1,
    "keys"       : "moes_key",
    ]) );
  SetClosed(1);
  SetLocked(0);
  SetLockStrength(175);
}
