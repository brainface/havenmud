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
  SetAmbientLight(-20);
  SetTown("Targoviste");
  SetShort("before the inner wall of Targoviste");
  SetLong(
    "To the west stands the inner wall of Targoviste. Formed of "
    "the same black granite as the outer wall, this part of the "
    "stronghold has arrow slits spaced at regular intervals, allowing "
    "defenders a clear shot at any assailants. Battlements surmount "
    "both walls, their crenulations giving defenders a line of "
    "sight, while remaining protected behind the merlons. This main "
    "throughfare passes through huge gates set in to the inner "
    "wall, to the west, and the outer wall to the east."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A rumble of voices comes from the building to the "
    "north.",
  ]) );
  SetSmell( ([
    "default" : "The smell of cooking wafts through the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "east_wall3",
    "west" : TARG_ROOM "east_in2",
  ]) );
}
