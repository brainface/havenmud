#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","mage board" }) );
  set_board_id("haven_mage_board");
  SetShort("Haven Library Board");
  SetLong("This is where news about your art is posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }
