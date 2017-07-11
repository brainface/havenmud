#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","dark order board" }) );
  set_board_id("darkorder_board");
  SetShort("Dark Order Board");
  SetLong("This is where members of the Dark Order can communicate.");
  SetPreventGet("You can't take the board!");
 }
