#include <lib.h>
#include "../../averath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
   SetInventory( ([
   AVERATH_OBJ + "trout" : 12,
   AVERATH_OBJ + "bass" : 5,
   AVERATH_OBJ + "shark" : 1,
   AVERATH_OBJ + "water" : 10,
   AVERATH_OBJ + "shovel" : 3,
   ]) );
}
