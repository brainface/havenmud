//Illura@haven
//Room 7
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("Next to a beaver lodge");
  SetLong(
    "The upwellings of glacial-fed lakes are dotted here and there "
    "with the wooden lodges made by beavers, making their homes happily "
    "beneath the spreading pine boughs from the ample wood supply. The "
    "moss here is slushy with partially melted snows that have drifted "
    "in from the north."
  );
  SetExits( ([
    "north" : TAIGA_ROOM "10",
    "west" : TAIGA_ROOM "6",
  ]) );
  SetItems( ([
    ({"upwellings", "lakes"}) : "Tiny ponds of collected snow water.",
    ({"lodges", "lodge"}) : "Beavers make their homes here.",
    "boughs" : "Heavy branches hang from the pine trees.",
    ({"moss", "snow"}) : "The moss underfoot is slushy and wet from snowmelt.",
  ]) );
  SetItemAdjectives( ([
    "lakes" : ({"glacial", "fed"}),
    "lodge" : "wooden",
    "boughs" : ({"spreading", "pine"}),
    "snow" : "melted",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "beaver" : 3,
  ]) );
  SetListen( ([
    "default" : "Sounds of quiet construction and chewing can be heard.",
  ]) );
  SetSmell( ([
    "default" : "It smells like wet fur and pine shavings.",
  ]) );
}
