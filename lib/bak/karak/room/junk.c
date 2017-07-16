#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetNoClean(1);
  SetInventory( ([
                    K_OBJ + "/sword" : 3,
                    K_OBJ + "/haxe" : 2,
                    K_OBJ + "/axe" : 1,
                    K_OBJ + "/flail" : 1,
                    K_OBJ + "/comp" : 2 ]) );

}
