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
  SetShort(" blah ");
  SetLong(
    "blah"
 
  );
  SetListen( ([ 


  ]) );
  SetSmell( ([


  ]) );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "east_out5",
    "southwest" : TARG_ROOM "east_out7",

  ]) );
}
