//-- Torak@Haven --//
//--    Ungkh    --//
//--   7/20/99   --//

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("a small hut");
  SetClimate("indoors");
  SetLong(
    "The walls in this hut are lavishly decorated "
    "and the floor is cleaner here than anywhere in "
    "Ungkh.  There is a large bed in the corner, "
    "large anough for two ogres.  A nightstand rests "
    "beside it, with various items upon it."
    );
  SetSmell( ([
    "default" :
    "The sweet smell of perfume wafts blissfully through the hut.",
    ]) );
  SetListen( ([
    ]) );
  SetItems( ([
    ({ "hut" , "floor", "walls" }) :
       (: GetLong :),
    ({ "bed", "pedals", "pedal", "rose", "sheets" }) :
       "The bed has silken sheets upon it, with rose pedals "
       "covering it.",
    ({ "nightstand" }) :
       "The nightstand is full of precious and ornate items "
       "from Ungkh, which are worthless anywhere else.",
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetEnters( ([
    ]) );
  SetInventory( ([
    U_OBJ + "sign" : 1,
    U_NPC + "aria_whore" : 1,
    ]) );
  SetExits( ([
    "out" : U_ROOM + "road03",
    ]) );
  }
