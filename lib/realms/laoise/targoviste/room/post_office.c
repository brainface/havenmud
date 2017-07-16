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
  SetClimate("indoors");
  SetAmbientLight(30);
  SetTown("Targoviste");
  SetShort("the Targoviste post office");
  SetLong(
    "This is a small room that the citizens of Targoviste use for "
    "communicating with the outside world. Along the east wall are "
    "rows of cubbyholes, each with a small plaque along its bottom. "
    "Agains the north wall sits a long desk, covered with various writing "
    "materials, including parchment and ink wells. The west wall is covered "
    "by what appears to be a board, used for communcation with the "
    "world beyond Targoviste. In the northeast corner of the room stands a "
    "small altar, with several sticks of incense set before."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "A low rumble of commerce fills the room.",
  ]) );
  SetSmell( ([
    "default" : "A light scent of incense pervades the air.",
    "incense" : "The incense smells musky, with the faint coppery scent "
    "of blood beneath it.",
  ]) );
  SetExits( ([ 
    "out" : TARG_ROOM "south_inner3",
  ]) );
}
