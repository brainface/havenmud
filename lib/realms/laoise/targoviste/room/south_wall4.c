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
    "The outer wall of Targoviste sits to the south, looming "
    "overhead and blocking out what little illumination managed "
    "to get past the Estergrym Mountains. Smooth black stone paves "
    "the bailey. Flecks of blood red are dotted along the "
    "obsidian-colored marble, seeming to float just beneath its surface. "
    "To the north rises the wall of the inner keep, within which the "
    "spires of the cathedral of Aberach can be seen reaching "
    "upwards. The bailey continues to the east and west from here, "
    "leading off in to the distance."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Wind buffets the walls of the fortress.",
  ]) );
  SetSmell( ([
    "default" : "The air is damp.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "south_wall3",
    "west" : TARG_ROOM "south_wall5",
  ]) );
}
