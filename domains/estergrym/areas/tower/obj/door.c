// dammit dave

#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("tower",
    ([
      "id" : "door",
      "short": "a sturdy door",
    "long" : "The door is built of sturdy maple, cross-braced with iron. It "
             "appears to be very durable.",
      "lockable" : 0,
    ])
  );
  SetSide("out",
    ([
     "id" : "door",
     "short": "a sturdy door",
    "long" : "The door is built of sturdy maple, cross-braced with iron. It "
             "appears to be very durable.",
     "lockable" : 0,
    ])
  );
  SetClosed(1);
}

