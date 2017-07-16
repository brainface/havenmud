// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>

inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide("tavern", ([
      "id" : "door",
      "adjective" : "wooden",
      "short" : "a wooden door",
      "long" : "This door is made out of planks of pine wood. "
               "It looks sturdy, but lacks precise craftsmanship "
               "and is riddled with gaps and seams that allow "
               "air and light to bleed through. ",
      "lockable" : 0,
  ]) );
  SetSide("out", ([
      "id" : "door",
      "adjective" : "wooden",
      "short" : "a wooden door",
      "long" : "This door is made out of planks of pine wood. "
               "It looks sturdy, but lacks precise craftsmanship "
               "and is riddled with gaps and seams that allow "
               "air and light to bleed through. ",
      "lockable" : 0,
  ]) );
  SetClosed(1);
}
