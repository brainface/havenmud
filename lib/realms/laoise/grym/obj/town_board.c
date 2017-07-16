#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","town board" }) );
  set_board_id("grymxoria_board");
  SetShort("Grymxoria News Board");
  SetLong("This is where news about Gryxoria Town is posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }
