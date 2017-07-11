#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","cleric board" }) );
  set_board_id("lloryk_cleric_board");
  SetShort("Eclat News Board");
  SetLong("This is where news regarding Eclat is posted. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }

