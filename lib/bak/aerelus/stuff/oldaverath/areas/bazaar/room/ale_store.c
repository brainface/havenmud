#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
   SetInventory( ([
   BAZAAR_OBJ + "lager" : 10,
   BAZAAR_OBJ + "ale" : 10,
   BAZAAR_OBJ + "whiskey" : 10,
   BAZAAR_OBJ + "water" : 20,
   ]) );
  }
