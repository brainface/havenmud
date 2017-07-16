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
    "Black marble gleams and stretches away to all sides. North of "
    "here it ends at a small building, which has a plaque showing a "
    "stack of coins hung above its entrance. To the northeast the "
    "shining marble of the inner keep leads to an open square, within "
    "which sits a fountain. A second small building sits to the west, "
    "its sign depicting a piece of parchment and a quill. Spires of "
    "the church of Aberach loom in to the sky, echoing the rugged peaks "
    "of the Estergrym Mountains, which surround Targoviste on all sides. "
  );
  SetItems( ([ 
    ({ "bank", "building" }) : "The sign on the building to the north "
    "suggests that it is the local bank.",
    ({ "office", "second building" }) : "This appears to be the local post office.",
  ]));
  SetItemAdjectives( ([
    "bank" : ({ "north", "nearby", "small", "first" }),
    "office" : ({ "west", "second", "small", "post" }),

  ]) );
  SetListen( ([ 
    "default" : "The quiet gurgle of a fountain can be heard to the "
    "northeast",
  ]) );
  SetSmell( ([
    "default" : "A smell of mist touches the air.",
  ]) );
  SetExits( ([ 
    "west" : TARG_ROOM "south_inner2",
    "northeast" : TARG_ROOM "east_inner3",
  ]) );
  SetEnters( ([
    "bank" : TARG_ROOM "bank",
  ]) );
}
