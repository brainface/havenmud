//Illura@haven
//Room 13
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("Along the glacial cliffs");
  SetLong(
    "Slow moving glaciers long ago carved a deep crevasse "
    "here, leading down to the icy ocean to the east. The "
    "edge of the taiga has been rubbed bare over time, exposing "
    "dark rocks under the soil. This place has a keen sadness "
    "about it, seeping from the stones and carried on the wind."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "10",
    "north" : TAIGA_ROOM "15",
    "west" : TAIGA_ROOM "12",
  ]) );
  SetItems( ([
    "glaciers" : "The glaciers have long since receeded.",
    "crevasse" : "The cliff is steep and very deep.",
    ({"rocks", "stones"}) : "The black rocks seem to exude a melancholy feeling.",
    "soil" : "The soil here is very thin over the rocks.",
    "ocean" : "The sea crashes against the treacherous cliffs far below.",
  ]) );
  SetItemAdjectives( ([
    "crevasse" : "deep",
    "ocean" : "icy",
    "rocks" : "dark",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "lemming" : 10,
  ]) );
  SetListen( ([
    "default" : "The winds wail constantly around you.",
  ]) );
  SetSmell( ([
    "default" : "The tangy salt of the sea fills your nose.",
  ]) );
}
