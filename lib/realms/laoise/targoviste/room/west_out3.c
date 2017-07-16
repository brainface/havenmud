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
  SetShort("before the outer wall of Targoviste");
  SetLong(
    "To the east rises the gigantic outer wall of Targoviste. "
    "Formed of jet colored stone the wall extends to the north "
    "and south from here. Northward lie the gates to the city and "
    "the main entrance of Targoviste. A small strip of flat land "
    "lies to the west, ending abruptly as the Estergrym Mountains "
    "rise sharply from the plains. The mountains loom high overhead, "
    "blocking out any light that may have penetrated the clouds."
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([
    "default" : "A cold wind whistles across the plain.", 
  ]) );
  SetSmell( ([
    "default" : "Humidity thickens the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "west_out4",
    "south" : TARG_ROOM "west_out2",
  ]) );
}
