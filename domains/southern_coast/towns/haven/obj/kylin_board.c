#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","cleric board" }) );
  set_board_id("kylin_board");
  SetShort("Kylin Religion Board");
  SetLong("This is where news about your faith is posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }
