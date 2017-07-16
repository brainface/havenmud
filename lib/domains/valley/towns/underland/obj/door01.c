// Torak November 2013

#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("east", ([
    "id" : ({ 
      "small wooden door", "wooden door", "smal door", "door", "circular door", 
      "small circular door", "circular wooden door", "small circular wooden door", 
      "small wooden circular door",
    }),
    "short" : "asmall wooden door",
    "long" : "The road from the valley ends at a little wooden door secured tightly "
      "to the side of the mountain. The door has been painted a delightful green "
      "in contrast to the grey rocky surface of the mountain. A knob in the center "
      "appears to <open> it. The door is circular and leads into the mountain.",
    "lockable" : 0,
  ]) );
  SetSide("west", ([
    "id" : ({ 
      "small wooden door", "wooden door", "smal door", "door", "circular door", 
      "small circular door", "circular wooden door", "small circular wooden door", 
      "small wooden circular door",
    }),
    "short" : "a small wooden door",
    "long" : "The road from town ends at a little wooden door secured tightly "
      "to the side of the mountain. The door has been painted a delightful green "
      "in contrast to the grey rocky surface of the mountain. A knob in the center "
      "appears to <open> it. The door is circular and leads out of the mountain.",
    "lockable" : 0,
  ]) );
  SetClosed(1);
}
