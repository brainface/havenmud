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
    ({ "office" }) : "A post office!  Yes!",
    ({ "library" })     : "A library!  Yes!"
  ]) );

  SetItemAdjectives( ([
    "office" : ({ "post", "postal" })
  ]) );

  SetExits( ([
    "east" : K_ROOM "main_03",
    "west" : K_ROOM "main_05"
  ]) );

  SetEnters( ([
    "office" : K_ROOM "p_office",
    "library"     : K_ROOM "library1"
  ]) );
}
