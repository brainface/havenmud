//-- Torak@Haven --//
//--    Ungkh    --//
//--   7/17/99   --//

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("the town hall");
  SetClimate("indoors");
  SetLong(
    "This shabby hut serves as the town hall "
    "for Ungkh.  The walls lean, the roof has "
    "holes and the draft is steady.  This "
    "hut is used very little."
    );
  SetSmell( ([
    ]) );
  SetListen( ([
    ]) );
  SetItems( ([
    ({ "hut" , "shabby hut", "roof", "walls" }) :
       (: GetLong :),
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetEnters( ([
    ]) );
  SetInventory( ([
    U_NPC + "hunh_mayor" : 1,
    U_NPC + "elite_guard1" : 1,
    U_NPC + "elite_guard2" : 1,
    ]) );
  SetExits( ([
    "out" : U_ROOM + "hall01",
    ]) );
  }
