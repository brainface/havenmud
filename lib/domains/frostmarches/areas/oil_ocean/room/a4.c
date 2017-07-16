//Illura@haven
//a4
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("an abandoned shipwreck");
  SetLong(
    "Here where the oil ocean meets the real one, the ground is "
    "nearly fluid. This must have caused a great deal of mystery "
    "to the sailors on this abandoned ship, which has come aground "
    "here so long ago that the wind has all but obliterated the "
    "paint from its hull. The holed sails hang slack and limp, gray with "
    "age, but the absence of holes or having sunk very deep into "
    "the ooze suggests the ship is still boardable, if not seaworthy."
  );
  SetExits( ([
    "north" : OIL_ROOM "/a3",
    "south" : OIL_ROOM "/a5",
    "east"  : OIL_ROOM "/b4"
  ]) );
  SetItems( ([
    ({"oil", "ocean","ooze"}) : 
      "Here the oil ocean laps up against the sea, "
      "but the black ooze under your feet is nearly "
      "indistinguishable from the other parts of this area.",
    ({"ship", "tub","shipwreck"}) : 
      "The ship is old and all but destroyed. Even the "
      "barnacles on the hull look ancient.",
    ({"barnacle","barnacles"}) :
	  "The barnacles on the hull look ancient.",
    ({"paint", "hull", "sails"}) : 
	  "The peeling paint and holed sails suggest this old "
	  "tub has seen better days.",
  ]) );
  SetEnters( ([
    "ship" : OIL_ROOM "ship1",
    ]) );
  SetItemAdjectives( ([
    "sails" : ({"holed"}),
    "ship" : ({"old"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "lurker" : 4,
  ]) );
  SetListen( ([
    "default" : "You can almost hear the crash of the surf from here.",
  ]) );
  SetSmell( ([
    "default" : "A light wind brings the ocean breeze to your nostrils.",
  ]) );
}

