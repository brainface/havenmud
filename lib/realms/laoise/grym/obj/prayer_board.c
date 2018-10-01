#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","prayer board", "prayer idea board", "idea board" }) );
  set_board_id("grymxoria_prayer_board");
  SetShort("Grymxoria Prayer Idea Board");
  SetLong("This is a board for the clerics of Grymxoria to post "
          "their ideas for new prayers. "
          "Type <post> \"topic\" to post a new message. "
          "Typing a '.' on a single line will exit you from "
          "the edit mode. ");
 }
