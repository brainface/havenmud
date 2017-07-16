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
    "The main aisle of the cathedral begins here and extends to "
    "the east. To the west stands the arched entrance to this edifice "
    "of dark worship. High overhead the ceiling rises to an arch "
    "which is supported by a multitude of vaulting ribs spreading "
    "outwards in a fan shape. Large windows dominate the walls, their "
    "elaborate tracing continuing upwards to where they disappear in "
    "darkness. The floor is formed of a strange substance, which appears "
    "black, yet gives the impression of an endless clear space within it."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A reverent hush pervades this house of worship.",

  ]) );
  SetSmell( ([
    "default" : "The musky smell of incense sits heavily in the air.",
  ]) );
  SetExits( ([ 
    "east": TARG_ROOM "church3",
    "west" : TARG_ROOM "west_inner2",
  ]) );
}
