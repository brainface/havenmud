
#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("north",
    ([
      "id" : "frozen door",
      "short": "a frozen door",
       "long": "It appears to be solid wood which has been frozen "
               "completely over. It is secured to the doorway which "
               "remarkably allows access despite the weather.",
      "lockable" : 0,
    ])
  );
  SetSide("south",
    ([
     "id" : "frozen door",
     "short": "a frozen door",
     "long" : "It appears to be solid wood which has been frozen "
              "completely over. It is secured to the doorway which "
              "remarkably allows access despite the weather.",
     "lockable" : 0,
    ])
  );
  SetClosed(1);
}

