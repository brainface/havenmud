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
  SetShort("before the inner wall of Targoviste");
  SetLong(
    "Within the outer bailey of Targoviste sits "
    "its second line of defense. Formed of the same black "
    "granite as the outer fortifications, this wall has "
    "arrow slits at regular intervals. The inner wall bows "
    "out slightly on both sides of its gate, allowing "
    "arrow slits on both sides to have a clear view of "
    "any attackers. Similar apertures are spaced along the "
    "exterior wall, which lies to the west. Massive gates are "
    "centered on both walls, and can be closed to pin an enemy "
    "within this enclosure in time of conflict. The Estergrym "
    "Mountains loom above the city, blocking out the dim light "
    "of the darkened sky above."
  );
  SetItems( ([ 


  ]));

  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The wind howls down this narrow defile.",
  ]) );
  SetSmell( ([
    "default" : "A damp scent pervades the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "west_inner2",
    "west" : TARG_ROOM "west_wall3",
    
  ]) );
}
