#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../../averath.h"
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
    STD_STORAGE "pouch" : 1,
    STD_FISHING "pole": 1,
    STD_LIGHT "torch": 3,
    STD_KNIFE "pocket_knife" : 2,
    STD_INSTRUMENTS "lyre" : 1,
    STD_INSTRUMENTS "drum" : 1,
    STD_STORAGE "backpack" : 2,
    STD_INSTRUMENTS "fife" : 1,
    STD_POLE "staff" : 1,
    STD_LOCKPICKS "picks" : 1,
      AVERATH_OBJ "clothing/l_boots" : 2,
  ]) );
}
