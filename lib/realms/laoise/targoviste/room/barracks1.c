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
    "The southeast wall of the barracks runs along the "
    "line traced by the wall of the inner keep, forming a "
    "triangular building. To the northwest runs a wall that "
    "segements off part of the building, forming a somewhat "
    "rectangular area for training. Along all visible wall "
    "space run racks of weapons and armours. In the center "
    "of the open area a round plaque is set in to the floor, "
    "with a pair of matching lines spaced equally on either "
    "side. Surrounding the short lines and center decoration " 
    "is another line forming a square, designating the practice "
    "area. Niches along the walls hold dark blue spheres which "
    "illuminate the area."
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
     "north" : TARG_ROOM "barracks2",
     "west" : TARG_ROOM "west_wall4",
     "northeast" : TARG_ROOM "barracks3",
  ]) );
}
