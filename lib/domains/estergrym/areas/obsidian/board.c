#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("obsidian_apostles");
  SetShort("the Obsidian Apostles Board");
  SetId( ({ "board", "obsdian apostles board" }) );
  SetLong("This is a board,");
  set_board_id("apostles");
 }
