
#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("south",
    ([
      "id" : "black door",
      "short": "a black door",
       "long": "It appears to be solid wood which has been frozen "
               "completely over. It is secured to the doorway which "
               "remarkably allows access despite the weather.",
      "lockable" : 0,
    ])
  );
  SetSide("north",
    ([
     "id" : "black door",
     "short": "a black door",
     "long" : "It appears to be solid wood which has been frozen "
              "completely over. It is secured to the doorway which "
              "remarkably allows access despite the weather.",
     "lockable" : 0,
    ])
  );
  SetClosed(1);
}

