// Targoviste
// Laoise
// August 2004
// Evoker Leader

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
  SetShort("the library of Targoviste");
  SetLong(
    "This set of rooms is tucked within the keep, surrounding the "
    "main chapel to the south. As they run to the east, these "
    "rooms curve, bending around the shape of the cathedral. Tall "
    "bookshelves line all the avaliable wall space, extending "
    "upwards to reach the ceiling. In the center of this room are "
    "a pair of large armchairs, which are arranged facing each "
    "other on opposite sides of a blood red carpet."
  );
  SetItems( ([ 
    ({ "shelf", "shelves" }) :
    "Formed of black wood, they hold weighty tomes which are "
    "inscribed with many different languages and symbols.",

  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "Strange sounds come from the north.",
  ]) );
  SetSmell( ([
    "default" : "Musky incense fails to obscure the sharp taint of sulphur in the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "library2",
    "northeast" : TARG_ROOM "library3",
    "out" : TARG_ROOM "west_inner3",
  ]) );
}
