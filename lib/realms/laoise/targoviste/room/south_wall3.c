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
    "Black marble forms the paving of the outer bailey, which "
    "is a space between the outer wall of the city and the inner "
    "keep. The darkened sky is barely visible, obscured by the "
    "Estergrym Mountains as they reach high in to the air. To the "
    "north and south rise walls formed of jet granite. Atop both are "
    "intricate battlements whose crenellations provide sheltered "
    "defense locations. The outer bailey continues to the east and "
    "west. Towards the north rises the inner keep, which contains the "
    "cathedral of Aberach."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The wind rushes across the smooth stones of the bailey.",
  ]) );
  SetSmell( ([
    "default" : "A moist scent fills the air.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "south_wall2",
    "west" : TARG_ROOM "south_wall4",
  ]) );
}
