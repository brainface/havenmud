#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId( ({ "board", "cavalier board", "news", "cavalier news" }) );
  set_board_id("haven_cavalier_board");
  SetShort("Haven Cavalier News");
  SetLong("This is where news about your class is posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }
