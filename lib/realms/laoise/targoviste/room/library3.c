// Targoviste
// Laoise
// August 2004
// Sage

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("the library of Targoviste");
  SetLong(
    "A wide strip of black wood runs from east to west here, connecting "
    "parts of the library. In the north part of this room is an alcove, "
    "where the shelves curve around a pair of leather chairs. A sturdy "
    "table sits between them, holding a small altar. Shelves run from "
    "floor to ceiling along the north and south walls, except within the "
    "alcove where the walls are simple, bare black stone." 
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "This area of the library is relatively quiet.",
  ]) );
  SetSmell( ([
    "default" : "The acrid tang of sulfur disturbs the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "library4",
    "west" : TARG_ROOM "library2",
    "southeast" : TARG_ROOM "library5",
    "southwest" : TARG_ROOM "library1",
  ]) );
}
