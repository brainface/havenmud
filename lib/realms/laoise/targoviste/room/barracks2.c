// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("inside the Targoviste barracks");
  SetLong(
    "This is the sleeping quarters for the guards "
    "of Targoviste. To the southeast a wall runs, "
    "cutting diagonally across the barracks and giving "
    "this area a semblance of privacy. Tucked in to the "
    "northwest corner is a small altar, set upon a table. "
    "Bunk beds line the north, west and southeast wall, "
    "stacked in tiers. To the east and south arched "
    "openings in the stone walls lead out to the main "
    "part of the barracks. "
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A low murmur of voices can be heard from "
    "other parts of the barracks.",
  ]) );
  SetSmell( ([
    "default" : "The smell of straw wafts from the bunks.",
  ]) );
  SetExits( ([ 
     "east" : TARG_ROOM "barracks3",
     "south" : TARG_ROOM "barracks1",
  ]) );
}
