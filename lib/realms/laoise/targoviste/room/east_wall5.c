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
    "The spires of the cathedral of Aberach rise to the "
    "northwest, stabbing up towards the gloomy sky hanging "
    "overhead. Immediately to the north and west of here "
    "a wall rises, reaching nearly half the height of the "
    "inner keep which stands behind it. Along the top of this "
    "wall are a line of iron spikes, held together by a "
    "horizontal bar of metal. To the south this near wall "
    "turns sharply to the west. Atop the corner that this "
    "forms perches a huge gargoyle, pervading the area with "
    "a malevolent aura." 
  );
  SetItems( ([ 
    "gargoyle" : "This gargoyle is in the form of a rampaging "
    "beast. It has the flat muzzle of a lion but the lean body "
    "of a wolf. Wings similar to those of a raven rise from its "
    "back, stretching out behind its body and flaring towards "
    "the sky. Its eyes seems to glow slightly and fill the area "
    "with an aura of evil.",
  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "No sound disturbs the air.",
  ]) );
  SetSmell( ([
    "default" : "A faint wiff of fresh-turned earth eases "
    "through the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "east_wall4",
    "southwest" : TARG_ROOM "south_wall1",
  ]) );
}
