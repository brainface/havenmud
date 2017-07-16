//-- Davantalus@Haven --//
//--    Ungkh    --//
//--   19990925   --//
// *Torak forgot this room, what a wanker! //

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("an empty hut");
  SetClimate("indoors");
  SetLong(
    "The sides of this hut are made of long, thin reeds tied into a wall-like construct, the thatched roof above is pitch black presumably from years of smoke. The hut is empty.");
  SetSmell( ([
    "default" :
    "The smell of old smoke drifts stagnantly through the hut.",
    ]) );
  SetListen( ([ "default" : "The noise of Ungkh is greatly reduced inside this small hut."
    ]) );

  SetExits( ([
    "out" : U_ROOM + "armour01",
    ]) );
  }
