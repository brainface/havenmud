#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","kysarin board" }) );
  set_board_id("kysar_board");
  SetShort("the Kuthar Faith Board");
  SetLong("This is where news and changes about the Kuthar\n"
          "faith are posted. Type <post> \"topic\" to post\n"
          "a new message. Typing a '.' on a single line will\n"
          "exit you from the edit mode.");
}

