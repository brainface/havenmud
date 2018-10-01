#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("south",
    ([
      "id" : "gate",
      "short": "a thick wooden gate",
      "long" : "Slabs of wood a handspan thick encircled by iron "
         "bands form the gate here. The steel hinges nailed into "
         "the gate disappear somewhere in the ice of the wall. This "
         "looks for all the world like the cargo hatch of a warship "
         "repurposed into a divider for the paranoid to hide behind.",
      "lockable" : 0,
    ])
  );
  SetSide("north",
    ([
      "id" : "gate",
      "short": "a thick wooden gate",
      "long" : "Slabs of wood a handspan thick encircled by iron "
         "bands form the gate here. The steel hinges nailed into "
         "the gate disappear somewhere in the ice of the wall. This "
         "looks for all the world like the cargo hatch of a warship "
         "repurposed into a divider for the paranoid to hide behind.",
      "lockable" : 0,
    ])
  );
  SetClosed(1);
}

