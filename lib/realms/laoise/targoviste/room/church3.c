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
  SetAmbientLight(30);
  SetClimate("indoors");
  SetTown("Targoviste");
  SetShort("the cathedral of Aberach");
  SetLong(
    "Here the transept, or crosspiece, intersects the main aisle. Exactly "
    "at their crossing an elaborate design is carved in to the floor, which "
    "is formed of a material which manages to be both the darkest black and "
    "completely clear, without visible end. Above, the central tower of the "
    "cathedral rises directly above, soaring upwards so far that it becomes "
    "a tunnel of darkness. To the east stands the main altar, while to the "
    "north and south the transept ends in open areas."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A deathly quiet fills the cathedral.",
  ]) );
  SetSmell( ([
    "default" : "A complex blend of musky incense, a coppery sharpness "
    "and a faint whiff of sulpher hang in the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "church4",
    "south" : TARG_ROOM "church2",
    "east" : TARG_ROOM "altar",
    "west" : TARG_ROOM "church1",
  ]) );
}
