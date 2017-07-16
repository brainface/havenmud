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
  SetClimate("indoors");
  SetAmbientLight(30);
  SetTown("Targoviste");
  SetShort("the Heart's Blood tavern");
  SetLong(
    "This building runs along the wall of the inner keep, following "
    "its line of travel. Nestling up against the wall in this way "
    "requires the building to have a generally triangular shape. "
    "The north and east walls meet to the east of here, while a "
    "third wall runs southeast. Across the right angle to the east "
    "is a counter with stools lined up before it, which appears to be "
    "for serving drinks. The rest of the room is filled with a scattering "
    "of tables, all surrounded by groups of chairs. A fireplace is "
    "centered in the southwest wall, its warmth filling the room while "
    "a special screen prevents its light from leaking out and illuminating "
    "the tavern."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A rumble of voices fills the tavern.",
  ]) );
  SetSmell( ([
    "default" : "The scent of cooking fills the room.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "bar2",
    "southeast" : TARG_ROOM "bar1",
    "out" : TARG_ROOM "north_wall6",
  ]) );
}
