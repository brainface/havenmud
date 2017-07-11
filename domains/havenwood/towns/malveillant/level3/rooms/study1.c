/*   Portia  1-9-99
     A study room.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a noisy study area");
  SetClimate("indoors");
SetAmbientLight(20);
  SetExits( ([
    "northeast" : MAL_ROOMS3 + "hall5",
    "southeast" : MAL_ROOMS3 + "hall4",
    ]) );
  SetInventory( ([
    MAL_NPC3 + "student1" : 1,
    MAL_NPC3 + "student2" : 1,
    ]) );
  SetListen( ([
    "default" : "The air is full of the sounds of magic.",
    ]) );
  SetSmell( ([
    "default" : "The room smells of old paper and incense.",
    ]) );
  SetLong("This is a common study room for the "
    "students of the Ring of Magic. The walls of the "
    "circular structure curve in towards the east here. "
    "Many tables "
    "are littered with books and papers of all sorts. "
    "Many great mages of all types have spent countless "
    "hours studying here. Candles and torches give the "
    "room a mysterious glow.");
  SetItems( ([
    ({"structure", "study", "room"}) : (:GetLong:),
    ({"table", "tables"}) : "The tables are littered "
        "with papers and books.",
    ({"books", "book"}) : "The books seem as though "
        "they contain great power.",
    ({"papers", "paper"}) : "The papers litter the desk "
        "rather haphazardly.",
    ({"walls", "wall"}) : "The obsidian walls curve eastward.",
    ({"candles", "candle", "torches", "torch"}) :
        "The candles and torches light the room.",
    ({"glow", "light"}) : "The light is rather mysterious.",
    ]) );
  SetItemAdjectives( ([
    "structure" : ({"circular", "common", "study"}),
    "walls" : ({"obsidian", "curved"}),
    "glow" : "mysterious",
    ]) );
  }
