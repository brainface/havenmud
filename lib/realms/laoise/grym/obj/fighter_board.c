#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","fighter board" }) );
  set_board_id("grymxoria_fighter_board");
  SetShort("Grymxoria Hunter and Barbarian Board");
  SetLong("This is a discussion board for the Hunters and Barbarians "
	  "of the Grymxorian Arena. "
          "Type <post> \"topic\" to post a new message. "
          "Typing a '.' on a single line will exit you from "
          "the edit mode. ");
 }
