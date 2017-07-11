#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","town board" }) );
  set_board_id("lloryk_board");
  SetShort("Lloryk News Board");
  SetLong("This is where news about Llorykshire is posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }

