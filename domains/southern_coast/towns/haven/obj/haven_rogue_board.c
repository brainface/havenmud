#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","rogue board" }) );
  set_board_id("haven_rogue_board");
  SetShort("Haven Thieves' Guild messages");
  SetLong("This is where news about your profession is posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }
