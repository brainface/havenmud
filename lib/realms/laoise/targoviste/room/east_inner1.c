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
    "blah"
 
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 


  ]) );
  SetSmell( ([


  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "east_inner2",
    "west" : TARG_ROOM "library5",
    "southeast" : TARG_ROOM "keep_e",
  ]) );
}
