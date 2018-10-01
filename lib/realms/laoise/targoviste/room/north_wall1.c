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
    "The outer bailey extends to the east and southwest "
    "of here, continuing to form a ring around the inner "
    "fortifications of Targoviste. To the southeast is the "
    "exterior wall of a building, formed of large blocks of "
    "black granite. The paving of the outer bailey of a "
    "black stone which is polished to a high sheen and "
    "has visible flecks of a vibrant red color embedded "
    "within it. Southwest of here is the main throughfare "
    "of Targoviste, while to the east the outer bailey "
    "continues."    
  );
  SetListen( ([ 
    "default" : "Occasionally a flurry of noise comes from the "
    "building to the southeast.",

  ]) );
  SetSmell( ([
    "default" : "An extremely faint hint of peat scents the air.",


  ]) );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "north_wall2",
    "southwest" : TARG_ROOM "west_wall5",
  ]) );
}
