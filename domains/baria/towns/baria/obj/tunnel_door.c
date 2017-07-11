//
// Summary: door for the tunnel and lair
// Created by: Rhakz@Haven -- Angel Cazares
// For Baria
// Date: 31/01/99
//
#include <lib.h>
inherit LIB_DOOR;

static void create() {
  door::create();
  SetSide("north", ([ 
          "id" : ({"wooden door","door","massive door","massive "
                   "wooden door"}),
          "short" : "a massive wooden door",
          "long" : "This is a huge wooden door that separates the "
                   "lair from another chamber.\n"
                   "There does not seem to be a lock on it.",
          "lockable" : 0,
          "keys" : 0,
      ]) );
  SetSide("south", ([
          "id" : ({"wooden door","door","massive door","massive wooden "
                   "door"}),
          "short" : "a massive wooden door",
          "long" : "This is a huge wooden door that separates the "
                   "tunnel from the lair.\n"
                   "There does not seem to be a lock on it.",
          "lockable" : 0,
          "keys" : 0,
      ]) );
  SetClosed(1);
  SetLocked(0);
}
