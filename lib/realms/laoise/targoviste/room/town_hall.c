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
  SetTown("Targoviste");
  SetShort("the headquarters of Targoviste");
  SetLong(
    "This is the organizational center of the stronghold of "
    "Targoviste. Hung upon the three open walls are massive "
    "illustrations of the world of Kailie. These maps have small "
    "metal pins stuck in to them at various points, each pin "
    "bearing a small flag of beaten metal with a symbol etched "
    "on it. In the center of the room is a large table, formed of "
    "black wood, with intricately carved legs which curve up from the "
    "ground. The slab-like top has a topgraphical map of the world, "
    "with miniature trees and buildings indicating the contents of "
    "different regions. The commanders of the city of Targoviste "
    "meet here to plan their stragies for world domination."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The areas is quiet and calm.",
  ]) );
  SetSmell( ([
    "default" : "The room smells of polished wood and cleaning oil.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "east_inner2",
  ]) );
}
