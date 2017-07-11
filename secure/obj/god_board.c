#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("a staff board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "staff" }) );
  set_board_id("god_bb");
  SetLong("This board is the primary means of communication "
          "between the Immortals on Haven.  Please use it.");
}
