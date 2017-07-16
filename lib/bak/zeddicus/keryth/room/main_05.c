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
    ({ "store" }) : "A general store!  Yes!",
    ({ "bank" })          : "A bank!  Yes!"
  ]) );

  SetItemAdjectives( ([
    "store" : ({ "general" })
  ]) );

  SetExits( ([
    "east" : K_ROOM "main_04",
    "west" : K_ROOM "main_06"
  ]) );

  SetEnters( ([
    "store" : K_ROOM "g_store",
    "bank"  : K_ROOM "bank"
  ]) );
}
