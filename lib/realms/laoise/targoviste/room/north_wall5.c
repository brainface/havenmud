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
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "The Estergrym Mountains rise high overhead, clawing "
    "jaggedly towards a darkened sky. The polished black "
    "marble of the outer bailey stretches to the east and "
    "west from here, small flecks of crimson scattered "
    "just below its gleaming surface. To the south the spires "
    "of the cathedral of Aberach, are visible, rising above "
    "the wall of the inner keep. North of here stands the "
    "outer wall of the city, battlements running along its "
    "top."
  );
  SetListen( ([ 
    "default" : "The wind whistles through the battlements of "
    "the outer wall.",
  ]) );
  SetSmell( ([
    "default" : "A hint of moisture fills the air.",
  ]) );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "north_wall6",
    "west" : TARG_ROOM "north_wall4",
  ]) );
}
