#include "../karak.h"
#include <lib.h>
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetNoClean(1);
  SetShort("Karak weapon storage");
  SetInventory( ([
    KARAK_OBJ + "sword" : 3,
    KARAK_OBJ + "haxe" : 2,
    KARAK_OBJ + "axe" : 1,
    KARAK_OBJ + "flail" : 1,
  ]) );
}
