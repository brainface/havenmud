//Illura@haven
//Room 24
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetShort("a bridge of ice");
  SetLong(
    "The ice bridge extends across a void as deep as it is inky "
    "black. Spiralling columns line the walks leading back to the "
    "tundra or forward, toward an open ring-shaped walkway. Scrapes "
    "in the ice from the heavy steps of mechanical feet are "
    "interspersed with shavings of blueish rust."
  );
  SetExits( ([
    "north" : TAIGA_ROOM "25",
    "south" : TAIGA_ROOM "23",
  ]) );
  SetItems( ([
    "bridge" : "The slender, graceful bridge of ice crystal looks formed neither by the hands of man nor natural means, but seems magic in nature. It crosses to a platform of ancient ice across the giant rift in the flesh of Kailie.",
    "columns" : "Massive columns formed from spiraling ice.",
    "void" : "The world would drop away from you rather quickly, should you step off the side of this bridge.",
    "scrapes" : "Shaved and dented spots dot the ice of this part of the bridge.",
    ({"shavings", "rust"}) : "Bits of star metal are strewn across the ice.",
  ]) );
  SetItemAdjectives( ([
    "ice" : "bridge",
    "spiraling" : "columns",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "golem" : 4,
  ]) );
  SetListen( ([
    "default" : "Clanking and screeching metal sounds fill the air.",
  ]) );
  SetSmell( ([
    "default" : "The air smells rusty.",
  ]) );
}
