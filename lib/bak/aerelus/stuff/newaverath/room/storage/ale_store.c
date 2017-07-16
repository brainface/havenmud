#include <lib.h>
#include "../averath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
   SetInventory( ([
   AVERATH_OBJ + "lager" : 10,
   AVERATH_OBJ + "ale" : 10,
   AVERATH_OBJ + "whiskey" : 10,
   AVERATH_OBJ + "water" : 20,
   ]) );
}
