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
  SetDomain("Estergrym");
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
    "north" : TARG_ROOM "east_out2",
    "south" : TARG_ROOM "east_out4",

  ]) );
}
