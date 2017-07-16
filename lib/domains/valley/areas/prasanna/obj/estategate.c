#include <lib.h>
#include "prasanna.h"

inherit LIB_DOOR;

static void create() {

  door::create();
  SetSide("north", ([ 
    "id" : "gate",
    "short" : "a bronze gate",
    "long" : "This is a large bronze gate, which "
             "bars entry to the estate of Maeralin.",
    "lockable" : 0 ]) );
  SetSide("south", ([ 
    "id" : "gate",
    "short" : "a bronze gate",
    "long" : "This is a large bronze gate, which "
             "bars entry to the estate of Maeralin.",
    "lockable" : 0 ]) );
  SetClosed(1);
  SetLocked(1);
  }
