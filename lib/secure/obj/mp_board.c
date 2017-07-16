#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("a multiplayer board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "multiplayer" }) );
  set_board_id("eu_bb");
}
