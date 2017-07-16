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
  SetShort("the bank");
  SetClimate("indoors");
  SetLong(
    "This shabby hut serves as the town bank "
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
    U_NPC + "bic_banker" : 1,
    ]) );
  SetExits( ([
    "out" : U_ROOM + "bank",
    ]) );
  }
