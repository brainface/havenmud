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
    "To the east is the outer wall of a building which "
    "is formed of blocks of granite, tightly joined together. "
    "High above the inner wall of Targoviste can be seen, "
    "rising high over the building as it continues to the "
    "south and east. To the north is the main passage "
    "through the various fortifications. To the south the "
    "outer bailey continues, winding around the inner keep. "
    "The granite of the bailey is polished to a faint sheen, "
    "making the occasional streak of blood red stand out "
    "clearly."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The wind whistles across the polish "
    "granite of the bailey.",
  ]) );
  SetSmell( ([
    "default" : "A ting of dampness pervades the air.",
  ]) );
  SetExits( ([ 
    "north"  : TARG_ROOM "west_wall2",
    "southeast" : TARG_ROOM "south_wall7",
  ]) );
}
