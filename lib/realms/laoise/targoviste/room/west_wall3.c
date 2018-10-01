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
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "This is an open space between the outer and inner walls "
    "of the stronghold, designed to provide a trap for any "
    "enemies who may breech the outer wall. The bailey is "
    "paved with polished black granite which contains small "
    "flecks of a blood red stone. To the east lies the main "
    "keep and center of the stronghold, while to the west is "
    "the outer wall and Targoviste Road. To the north and "
    "south stretches the outer bailey, which appears to contain "
    "several buildings."
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The wind swirls across the smooth granite of the bailey.",
  ]) );
  SetSmell( ([
    "default" : "A damp scent pervades the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "west_wall4",
    "south" : TARG_ROOM "west_wall2",
    "east" : TARG_ROOM "keep_w",
    "west" : TARG_ROOM "west_out4",
  ]) );
}
