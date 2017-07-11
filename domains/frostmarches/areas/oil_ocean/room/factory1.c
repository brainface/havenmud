//Illura@haven
//factory1
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
    "The factory floor is holed with shallow wells and strewn "
    "with simple machines meant to pull up oil from them in "
    "metal pails. Winches drag the pails up to a second level "
    "that seems even more rickety than the first. Steam vents "
    "noisily from several areas, making it as hard to see as "
    "it is to breathe in the hot enclosure. A slapdash stairway "
    "leads up, and an open doorway leads to a small office "
    "to the north."
  );
  SetExits( ([
    "out" : OIL_ROOM "/e2",
    "north" : OIL_ROOM "/factory2",
    "up" : OIL_ROOM "/factory3"
  ]) );
  SetItems( ([
    ({"floor", "well", "wells"}) : "The workers have mined out holes in the floor to dig deep into the surface of the oil ocean. This also brings up noxious gases and heat, not to mention the sticky black crude.",
    ({"machine", "machines", "winch", "winches"}) : "The cogs of these machines look like they could split apart in an instant, causing disaster for anyone standing around or below them.",
    ({"pail", "pails", "oil"}) : "Countless pails of oil are brought upward and then back down in a rickety endless cycle. Until something breaks.",
    ({"stairway"}) : "The stairway leads up, for the daring worker.",
    ({"doorway"}) : "The doorway is north."
  ]) );
  SetItemAdjectives( ([
    "floor" : ({"factory", "holed", "shallow"}),
    "machines" : ({"simple"}),
    "pail" : ({"metal"}),
    "stairway" : ({"slapdash"}),
    "doorway" : ({"open"})
  ]) );
  SetInventory( ([
    OIL_NPC + "worker" : 4,
  ]) );
  SetListen( ([
    "default" : "There is a buzz of activity here.",
  ]) );
  SetSmell( ([
    "default" : "Black smoke fills the air no matter where you turn in this factory.",
  ]) );
}
