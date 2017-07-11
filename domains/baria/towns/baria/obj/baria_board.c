#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","town board" }) );
  set_board_id("baria_board");
  SetShort("Baria's Town Board");
  SetLong("This is where news and changes about Baria are posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode.  ");
}

