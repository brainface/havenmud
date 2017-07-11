#include <lib.h>
#include <domains.h>
#include "../gurov.h"
inherit LIB_ROOM;

int BlockCitizens();

static void create() {
  ::create();
  SetShort("a large gate leading into Gurov");
  SetTown("Gurov");
  SetExits( ([
    "north" : GUROV_ROOM "cr1",
    "east"  : GUROV_AREAS "newbiepath/room/neargate",
    ]) );
  AddExit("south", GUROV_VIRTUAL "gurovrd/0,10", (: BlockCitizens :) );
  SetLong(
    "The capital city of the Principality of Gurov is a large and imposing "
    "affair surrounded by a high wall. The stonework gate seems to be a well "
    "reinforced affair designed to repel any invasion from Estergrym or the "
    "fierce goden pirates. The Gurov Road leads to the south, heading back "
    "into the heart of the Principality. Piles of horse and mule droppings "
    "seem to abound."
    );
  SetItems( ([
    "gate" : "The gate is a stone, wood, and iron marvel that appears strong "
             "enough to repel any invasion or raid.",
    ({ "pile" }) : "The piles are the natural result of daily traders coming in and "
             "out of the city, pausing their wagons for inspection as needed.",
    ]) );
  SetItemAdjectives( ([
    "gate" : ({ "stone", "stonework" }),
    ]) );
  SetSmell( ([
    "default" : "The smells of horse and mule droppings eminates from piles "
                "near the gates.",
    ({ "pile", "piles" }) : "They smell, predictably, like horse and mule "
                            "droppings.",
    ]) );
  SetInventory( ([
    GUROV_NPC "guard" : 1,
    GUROV_NPC "citizen" : 2,
    ]) );
}

int BlockCitizens() {
  if (this_player()->id("gurov_citizen")) return 0;
  return 1;
}
