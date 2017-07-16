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
    "The spires of the Aberach cathedral rise to the northeast. "
    "To the west and south curves the inner wall of the keep of "
    "Targoviste. Formed from massive blocks of black stone, this wall "
    "is topped by battlements that overlook the outer bailey and inner "
    "keep. Smooth black marble paves this area, with small flecks of red "
    "scattered within the darkness. A building stands to the east, its "
    "lack of fortifications suggesting it is a place of business. An open "
    "area within the inner keep sits to the northwest." 
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The faint burble of a fountain can be hear to the northwest.",
  ]) );
  SetSmell( ([
    "default" : "The air lacks any distinctive smell.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "west_inner2",
    "northwest" : TARG_ROOM "keep_w",
    "southeast" : TARG_ROOM "south_inner3",
  ]) );
}
