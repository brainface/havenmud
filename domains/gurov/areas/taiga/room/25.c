//Illura@haven
//Room 25
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetShort("a crystal mezzanine");
  SetLong(
    "The walkway here forks both left and right at the end of "
    "a bridge made solely of ice, flanked on the outside by "
    "an imposing balustrade of columns, shimmering and frozen. "
    "The center of the ring-shaped walkway leads down to the "
    "cold, arctic waters of the northern ocean."
  );
  SetExits( ([
   "northeast" : TAIGA_ROOM "26",
    "south" : TAIGA_ROOM "24",
    "northwest" : TAIGA_ROOM "30",
  ]) );
  SetItems( ([
    "walkway" : "The walkway is made of solid ice, but is not too slippery.",
    "bridge" : "The slender, graceful bridge of ice crystal looks formed neither by the hands of man nor natural means, but
seems magic in nature. It crosses to a platform of ancient ice across the giant rift in the flesh of Kailie.",
    ({"balustrade", "columns"}) : "The balustrade of ice columns arcades the walkway, keeping you from falling over the
edge.",
    ({"waters", "water", "ocean"}) : "The foamy seas are incomprehensibly far below.",
  ]) );
  SetItemAdjectives( ([
    "walkway" : ({"ring", "shaped"}),
    "balustrade" : "imposing",
    "waters" : ({"cold", "arctic"}),
    "ocean" : "northern",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "guardian" : 4,
  ]) );
  SetListen( ([
    "default" : 
    "You swear that you can almost hear sibilant voices singing in a forgotten tongue.",
  ]) );
  SetSmell( ([
    "default" : "The salty seas waft into the thin air.",
  ]) );
}
