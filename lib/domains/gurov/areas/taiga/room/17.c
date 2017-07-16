//Illura@haven
//Room 17
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("at the edge of the Gurovian Wastes");
  SetLong(
    "The tundra expands from here in every direction but southward, "
    "where trees lead back into the thickening wilds. Other than "
    "scrubby lichens and black trees poking through the permafrost, "
    "there are only blown drifts of snow, some eerily taking on "
    "the shapes of creatures or ancient ruins. Everything sparkles "
    "with a thin iridescent covering of ice crystal."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "14",
    "north" : TAIGA_ROOM "20",
    "east" : TAIGA_ROOM "18",
  ]) );
  SetItems( ([
    "trees" : "The few trees here are black and withered.",
    "lichens" : "Curly lichen pokes out of the hard frozen ground.",
    ({"drifts", "snow"}) : "Snow covers the ground and stands in piles that look like familiar creatures or places.",
    ({"crystal", "ice"}) : "Ice covers the snow in glassine sheets.",
  ]) );
  SetItemAdjectives( ([
    "lichens" : "scrubby",
    "trees" : "black",
    "drifts" : "blown",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "mistress" : 2,
  ]) );
  SetListen( ([
    "default" : "The wind howls across the wastes.",
  ]) );
  SetSmell( ([
    "default" : "The thin air leaves your nostrils tingling.",
  ]) );
}
