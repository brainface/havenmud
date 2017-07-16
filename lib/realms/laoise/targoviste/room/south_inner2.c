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
  SetDayLight(-20);
  SetTown("Targoviste");
  SetShort("the inner keep of Targoviste");
  SetLong(
    "East and west of here stretches the inner keep of Targoviste, "
    "which is within the final defensive wall of the stronghold. "
    "High above the city rise the Estergrym Mountains, their jagged "
    "edges reaching towards a dark sky. Buildings that appear designed "
    "for commerce rather than the defense of the city lie nearby. The "
    "building to the east has a sign above its door which depicts a "
    "stack of coins. Above the entrance to the western building is "
    "a plaque showing a quilled pen writing upon a piece of parchment. "
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Wind howls through the battlements that rise overhead.",
  ]) );
  SetSmell( ([
    "default" : "Moisture fills the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "south_inner1",
    "west" : TARG_ROOM "south_inner3",
  ]) );
}
