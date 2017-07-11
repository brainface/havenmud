/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include <std.h>
#include "../gwonish.h";

inherit LIB_ROOM;


static void create() {
  ::create();

  SetInventory( ([
    GWONISH_OBJ "club" : 1,
    GWONISH_OBJ "spear" : 1,
    GWONISH_OBJ "serrated" : 1,
    STD_OBJ     "digging/shovel" : 1,
    STD_FISHING "newbie_pole" : 1,
    STD_OBJ     "storage/backpack" : 1,
    STD_CLOTHING "tail_wrap" : 3,
  ]) );
}

