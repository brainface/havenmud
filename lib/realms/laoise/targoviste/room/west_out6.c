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
  SetShort("before the outer wall of Targoviste");
  SetLong(
    "A narrow band of flat land extends west from here, "
    "ending where the Estergrym Mountains rear upwards, "
    "reaching far in to the sky and blocking out any light. "
    "To the east rises the outer wall of Targoviste, its "
    "top surmounted by battlements. To the south lies the "
    "main entrance to Targoviste, while to the north the "
    "outer wall continues, curving east to encircle the "
    "city."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([
    "default" : "The wind whips across the plain.",
  ]) );
  SetSmell( ([
     "default" : "A hint of peat tones the swiftly churning air.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "west_out5",
    "northeast" : TARG_ROOM "west_out7",
  ]) );
}
