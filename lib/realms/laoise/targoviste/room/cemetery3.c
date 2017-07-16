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
  SetShort("an open area within the cemetery");
  SetLong(
    "This is a small region of open grass within the cemetery "
    "of Targoviste. Within this area of open grass there are "
    "occasional signs of disturbed soil, as if something clawed "
    "its way up out of the ground, leaving a region of loose soil. "
    "A masauleum looms to the west of this open area. Set up against "
    "the inner wall, this structure is a small, square building, topped "
    "by an arched roof. Gargoyles top each corner, and atop the roof "
    "stands a cloaked figure. To the east this open area of grass narrows "
    "to a path which runs between the lines of headstones that fill "
    "the rest of the cemetery." 
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A hush fills the air.",
  ]) );
  SetSmell( ([
    "default" : "The smell of damp earth permiates the cemetery.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "cemetery2",
    "northeast" : TARG_ROOM "cemetery1", 
    "out" : TARG_ROOM "south_wall2",
  ]) );
}
