#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("a humour board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "humour" }) );
  set_board_id("humour_bb");
}
