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
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("inside the Targoviste barracks");
  SetLong(
    "Dark blue orbs are set in niches along the walls "
    "of this triangular building. To the northwest a wall "
    "runs at an angle parallel to that of the southeastern "
    "wall, forming a somewhat rectangular shape for the "
    "majority of the barracks. Along the walls are wooden "
    "racks holding a variety of armours and weapons. On "
    "the floor a line forms a large square, with a plaque "
    "in the center. On opposite sides of the middle, an "
    "equal distance apart, are a pair of short lines. "
    "To the southwest the barracks continue, following the "
    "path set by wall of the inner keep. To the west an "
    "archway leads through the wall to a different part of "
    "the barracks, while to the north lies the outer bailey."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A low murmur of voices fills the barracks.",
  ]) );
  SetSmell( ([
    "default" : "The air is filled with the faint smell of cleaning "
    "oils and polished wood.",
  ]) );
  SetExits( ([ 
     "north" : TARG_ROOM "north_wall2",
     "west" : TARG_ROOM "barracks2",
     "southwest" : TARG_ROOM "barracks1",
  ]) );
}
