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
    "To the east stands the inner wall of Targoviste. Formed of "
    "the same black granite as the outer wall, this part of the "
    "stronghold has arrow slits spaced at regular intervals, allowing "
    "defenders a clear shot at any assailants. Battlements surmount "
    "both walls, their crenulations giving defenders a line of "
    "sight, while remaining protected behind the merlons. From here "
    "the main throughfare stretches east, passing through first the "
    "inner then outer gates of Targoviste, to finally exit the city. "
    "In the center of this open area sits a fountain, carved "
    "from the same polished black marble as the paving of the "
    "outer bailey."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Voices can be heard faintly, coming from the north.",
  ]) );
  SetSmell( ([
    "default" : "A slight puff of smoke colors the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "east_wall3",
    "west" : TARG_ROOM "east_inner2",
/*
    "northwest" : TARG_ROOM "east_inner1",
*/
    "southwest" : TARG_ROOM "east_inner3",
  ]) );
}
