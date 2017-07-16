#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","mage board" }) );
  set_board_id("grymxoria_mage_board");
  SetShort("Grymxoria Mage Discussion Board");
  SetLong("This is a discussion board for the mages of Grymxoria. "
          "Type <post> \"topic\" to post a new message. "
          "Typing a '.' on a single line will exit you from "
          "the edit mode. ");
 }
