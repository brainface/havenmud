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
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("within the outer bailey of Targoviste");
  SetLong(
    "High overhead the jagged craigs of the Estergrym Mountains "
    "claw towards a darkened sky. To the northeast their spikes are "
    "echoed in the spires rising from within the inner keep. "
    "On all sides massive walls of black stone loom overhead, their "
    "battlements overlooking this open area. The exterior wall of "
    "a building traces by to the northeast, the inner wall of the keep "
    "visible above it. East and northwest of here the outer bailey "
    "continues, its smooth pavement circling the inner fortifications. " 
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([
    "default" : "Winds whistles through the peaks of the Estergrym Mountains.",
   ]) );
  SetSmell( ([
    "default" : "The air is free of any distinct scents.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "south_wall6",
    "northwest" : TARG_ROOM "west_wall1",
  ]) );
}
