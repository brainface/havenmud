#include <lib.h>
#include "../../averath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
   SetInventory( ([
   AVERATH_OBJ + "lager" : 4,
   AVERATH_OBJ + "ale" : 4,
   AVERATH_OBJ + "whiskey" : 4,
   AVERATH_OBJ + "water" : 6,
   AVERATH_OBJ + "cheese_camembert" : 2,
   ]) );
}

