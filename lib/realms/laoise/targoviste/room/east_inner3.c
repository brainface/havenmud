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
    "To the northeast the black marble of the inner keep widens "
    "in to a small open area, which centers on a marble fountain. "
    "Scattered spots of blood red trail along the black marble of "
    "the inner keep, which is bounded on both sides by walls. West "
    "of here stands a plain building, its small size and lack of "
    "fortifications suggesting is a place of business. Several other "
    "buildings stand to the north, signs above their entrances indicating "
    "their purpose."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The quiet rush of water comes from the northeast",
  ]) );
  SetSmell( ([
    "default" : "A faint smell of smoke drifts in from the north.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "east_inner2",
    "northeast" : TARG_ROOM "keep_e",
    "southwest" : TARG_ROOM "south_inner1",
  ]) );
}
