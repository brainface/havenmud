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
    "South and west of here sits a long low buiding, set up against "
    "the wall of the inner keep. The building bends, following the "
    "wall as it curves away in the distance. Overhead rises "
    "the inner keep, within which the spires of the cathedral of "
    "Aberach can be seen stabbing towards a darkened sky. South of "
    "here is the main throughfare of Targoviste. The black marble "
    "path of the outer bailey trails away to the northwest and south."
  );
  SetItems( ([ 
    ({ "building", "inn", "tavern" }) :
    "From the roof of this "
    "building juts a chimney, from which a trail of smoke drifts, "
    "pulled to the southwest by the passing breeze.",


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A myriad of noises comes from the building to the south, "
    "including a scattering of voices. ",
  ]) );
  SetSmell( ([
    "default" : "The faint smell of food wafts through the air.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "east_wall2",
    "northwest" : TARG_ROOM "north_wall7",
  ]) );
}
