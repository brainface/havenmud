#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","cavalier board" }) );
  set_board_id("grymxoria_cavalier_board");
  SetShort("Army and Guard Discussion Board");
  SetLong("This is a discussion board for the Grymxorian Army and "
		"Guard.  "
          "type <post> \"topic\" to post a new message. "
          "typing a '.' on a single line will exit you from "
          "the edit mode. ");
 }
