//Illura@haven
//factory2
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside a factory");
  SetLong(
    "This is the main office of the factory. A desk strewn with smudgy "
    "papers is the only real furniture to be had, but someone has "
    "swept the place up from time to time in an effort to keep most "
    "of the mess to a minimum. Samples of different colored oil "
    "are kept in tiny bottles on racks around the room. The only "
    "exit is back into the rest of the factory."
  );
  SetExits( ([
    "south" : OIL_ROOM "/factory1",
  ]) );
  SetItems( ([
    ({"desk"}) : "The desk is wooden, and pocked with scoremarks and smudged with oil and soot.",
    ({"papers", "paper"}) : "The documents pertain to the manufacture and sale of pitch.",
    ({"oil", "bottle", "bottles", "rack", "racks"}) : "The small racks are covered with what appear to be repurposed perfume bottles filled with differing quantities of oil and oil-like substances."
  ]) );
  SetItemAdjectives( ([
    "papers" : "smudgy",
    "oil" : ({"colored", "tiny"})
  ]) );
  SetInventory( ([
    OIL_NPC + "boss" : 1,
  ]) );
  SetListen( ([
    "default" : "You hear clanging and bustling back in the other room.",
  ]) );
  SetSmell( ([
    "default" : "Black smoke fills the air no matter where you turn in this factory.",
  ]) );
}

