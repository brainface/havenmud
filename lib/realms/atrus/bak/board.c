#include <lib.h>
inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("board");
   SetId( ({ "board" }) );
   set_board_id("atrboard");
   SetShort("the board of Atrus");
   SetLong("Write something, don't stand there and stare at it..");
}
