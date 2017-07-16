#include <lib.h>
#include "../../averath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
   SetInventory( ([ AVERATH_OBJ "hats/beret" : 2,
   	AVERATH_OBJ "hats/biretta" : 2, 
   	AVERATH_OBJ "hats/bowler" : 2,
   	AVERATH_OBJ "hats/fedora" : 2,
   	AVERATH_OBJ "hats/trilby" : 2,
   	AVERATH_OBJ "hats/beanie" : 2,
   ]) );
}
