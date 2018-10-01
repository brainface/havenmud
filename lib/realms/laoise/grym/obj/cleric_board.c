#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","cleric board" }) );
  set_board_id("grymxoria_cleric_board");
  SetShort("Saahagoth Clerical Board");
  SetLong("This is where news about your faith is posted. "
          "type <post> \"topic\" to post a new message. "
          "Typing a '.' on a single line will exit you from "
          "the edit mode. ");
 }
