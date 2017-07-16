//
// Summary: door for the tunnel and lair
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 03/02/99
//
#include <lib.h>
inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide("north", ([ 
          "id" : ({"black door","door","massive door","massive "
                   "black door"}),
          "short" : "a massive black door",
          "long" : "This is a huge black door that separates the "
                   "tunnel from another chamber.\n"
                   "There does not seem to be a lock on it.",
          "lockable" : 0,
          "keys" : 0,
      ]) );
  SetSide("south", ([ 
          "id" : ({"black door","door","massive door","massive black "
                   "door"}),
          "short" : "a massive black door",
          "long" : "This is a huge black door that separates the "
                   "lair from the tunnel.\n"
                   "There does not seem to be a lock on it.",
          "lockable" : 0,
          "keys" : 0,
      ]) );
  SetClosed(1);
  SetLocked(0);
}
