// Torak November 2012

#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("fort", ([
    "id" : ({ 
      "large wooden gate", "wooden gate", "large gate", "gate"
    }),
    "short" : "a large wooden gate",
    "long" : "The wooden gate leads into the fort.",
    "lockable" : 0,
  ]) );
  SetSide("out", ([
    "id" : ({ 
      "large wooden gate", "wooden gate", "large gate", "gate"
    }),
    "short" : "a large wooden gate",
    "long" : "The wooden gate leads out to the base of the mountain.",
    "lockable" : 0,
  ]) );
  SetClosed(1);
}
