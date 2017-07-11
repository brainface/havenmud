#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("an idea board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "idea" }) );
  set_board_id("idea_bb");
}
