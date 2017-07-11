// Coded by Zeratul
// 3-29-2000

#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId( ({ "board", "town board", "vacazar town board" }) );
  set_board_id("vacazar_board");
  SetShort("Vacazar Town Board");
  SetLong(
     "This is where news about Vacazar is posted. \n"
     "Type <post> \"topic\" to post a new message. \n"
     "Typing a '.' on a single line will exit you from \n"
     "the edit mode. "
  );
  }
