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
    "The giant cathedral of Aberach rises to the southeast, "
    "its spires echoing the jagged Estergrym mountains which "
    "reach high overhead. To the east a large building sits "
    "against the wall of the inner keep, extending towards the "
    "cathedral. Decorating its entrance is a plaque etched with "
    "the image of an open book with a sphere of flame suspended "
    "above its pages. South of here is an open area within the "
    "inner keep of Targoviste, which appears to contain a fountain. "
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A high-pitched keening sound comes from the spires "
    "of the cathedral.",
  ]) );
  SetSmell( ([
    "default" : "The acrid tang of sulphur rides the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "library1",
    "south" : TARG_ROOM "west_inner2",
    "southwest" : TARG_ROOM "keep_w",
  ]) );
}
