#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("kennel",
    ([
      "id" : "gate",
      "short": "a wooden gate",
      "long" : "A few planks of wood crisscrossed into a servicable, "
        "dog-proof door.",
      "lockable" : 0,
    ])
  );
  SetSide("out",
    ([
      "id" : "gate",
      "short": "a wooden gate",
      "long" : "A few planks of wood crisscrossed into a servicable, "
      "dog-proof door.",
     "lockable" : 0,
    ])
  );
  SetClosed(1);
}

