//Illura@haven
//Room 23
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
    "On either side of this slick, crystal bridge of ice the land "
    "falls out from beneath you into unending darkness. Spiralling "
    "columns line the walks, topped with aeries containing ancient nests "
    "of worn tundra mosses between the arching buttresses. To the south "
    "stands the tundra."
  );
  SetExits( ([
    "north" : TAIGA_ROOM "24",
    "south" : TAIGA_ROOM "20",
  ]) );
  SetItems( ([
    "bridge" : "The slender, graceful bridge of ice crystal looks formed neither by the hands of man nor natural means, but seems magic in nature. It crosses to a platform of ancient ice across the giant rift in the flesh of Kailie.",
    "columns" : "Massive columns formed from spiraling ice.",
    "aeries" : "High above the bridge stand ice-formed aeries, providing nests for the ancient clan of hippogryphs.",
    ({"nests", "mosses"}) : "Nests of gathered mosses.",
    "buttresses" : "Arches of ice crystal support the bridge structure, surmounted by crenelations and supported by fanciful columns.",
  ]) );
  SetItemAdjectives( ([
    "bridge" : ({"crystal", "slick"}),
    "columns" : "spiraling",
    "nests" : "ancient",
    "buttresses" : "arching",
    "mosses" : ({"worn", "tundra"}),
  ]) );
  SetInventory( ([
    TAIGA_NPC + "hippo" : 4,
  ]) );
  SetListen( ([
    "default" : "Gryphon cries fill the air.",
  ]) );
  SetSmell( ([
    "default" : "The wind is tinged with the musk of lions and acrid fowl scent.",
  ]) );
}
