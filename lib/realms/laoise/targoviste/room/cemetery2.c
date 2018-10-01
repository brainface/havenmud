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
  SetShort("the Targoviste cemetery");
  SetLong(
    "Neat and orderly rows of graves stretch to the north. A broad avenue "
    "of grass runs between the rows, forming a path through the cemetery. "
    "The nearest headstone is formed from red marble, cut in to the shape " 
    "of a rectangle with the longer side perpendicular to the ground. Atop "
    "this headstone is the figure of a skeleton, kneeling with its head bent "
    "forward in supplication. To the west there appears to be an area of open "
    "grass. The wall of the cemetery stands to the south, its top surmounted "
    "by iron spikes."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A unnatural quiet grips the air.",
  ]) );
  SetSmell( ([
    "default" : "The rich smell of fresh-turned earth fills the cemetery.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "cemetery1",
    "west" : TARG_ROOM "cemetery3", 
  ]) );
}
