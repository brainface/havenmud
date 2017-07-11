#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("an ooc board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "ooc" }) );
  set_board_id("ooc_bb");
  SetLong("Please post out of character chat here.");
}
