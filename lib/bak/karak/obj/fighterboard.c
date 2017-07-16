#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","fighter board" }) );
  set_board_id("orcfighter_board");
  SetShort("Orc Fighter News Board");
  SetLong("The orcs are too cheap to buy a real guildhall. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }

