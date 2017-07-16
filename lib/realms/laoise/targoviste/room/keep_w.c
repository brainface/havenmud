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
    "To the west stands the inner keep of Targoviste, its "
    "gate formed of giant slabs of black granite. Atop the wall "
    "sit several gatehouses, from which chains trail down to "
    "buildings in the outer bailey. Northeast of here is a large "
    "building which appears to be the library. Southeast of here "
    "is a building displaying the sign of a post office. To the "
    "east the cathedral of Aberach soars high in to the air, its "
    "spires clawing towards the darkened sky."
  );
  SetItems( ([ 
    ({ "chains", "chain" }) :
    "This system "
    "appears intended to allow the exterior buildings to be "
    "collapsed in event of an assault upon the stronghold.",

  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Wind screams through the spires of the nearby "
    "cathedral.",
  ]) );
  SetSmell( ([
    "default" : "The wind whips by too quickly for any smells to "
    "be discerned.",
  ]) );
  SetExits( ([ 
    "west" : TARG_ROOM "west_wall3",
    "east" : TARG_ROOM "west_inner2",
    "northeast" : TARG_ROOM "west_inner3",
    "southeast" : TARG_ROOM "west_inner1",
  ]) );
}
