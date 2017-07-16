#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("Main Street");
  SetLong("Long description.");

  SetItems( ([
    ({ "hall" }) : "A town hall!  Yes!"
  ]) );

  SetItemAdjectives( ([
    "hall" : ({ "town" })
  ]) );

  SetExits( ([
    "east" : K_ROOM "main_02",
    "west" : K_ROOM "main_04"
  ]) );

  SetEnters( ([
    "hall" : K_ROOM "town_hall"
  ]) );
}
