#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
   SetInventory( ([
   BAZAAR_OBJ + "trout" : 12,
   BAZAAR_OBJ + "bass" : 5,
   BAZAAR_OBJ + "shark" : 1,
   BAZAAR_OBJ + "water" : 10,
   BAZAAR_OBJ + "shovel" : 3,
   ]) );
}
