//Illura@haven
//Room 21
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetShort("Within the Gurovian Wastes");
  SetLong(
    "The icy, desolate tundra is whipped with bitter, cold "
    "winds. The only thing as far as the eye can see is snow "
    "and from the pure drifts, rising crepescular rays leading "
    "up to the sky with filmy, eerie, constant light. There "
    "seems to be something magical about this place, something "
    "older than the gods."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "18",
    "west" : TAIGA_ROOM "20",
    "east" : TAIGA_ROOM "22",
  ]) );
  SetItems( ([
    ({"snow", "drifts"}) : "Densely packed snow has piled into deep drifts.",
    ({"rays", "light"}) : "Shimmering gold rays of wavering light give the tundra a misleading glow of warmth.",
  ]) );
  SetItemAdjectives( ([
    "drifts" : "pure",
    "light" : ({"filmy", "eerie", "constant"}),
    "rays" : ({"rising", "crepescular"}),
  ]) );
  SetInventory( ([
    TAIGA_NPC + "mistress" : 3,
  ]) );
  SetListen( ([
    "default" : 
    "A steady, barely audible hum seems to come from somewhere.",
  ]) );
  SetSmell( ([
    "default" : "The gilten lights issue a fragrance touched by divinity.",
  ]) );
}
