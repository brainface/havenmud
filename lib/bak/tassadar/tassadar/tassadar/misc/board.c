#include <lib.h>
inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("tassboard");
   SetShort("the board of Tassadar");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "tassadars" }) );
   SetLong("Write something, don't stand there and stare at it..");
   SetPreventGet(1);
   set_board_id("tassboard");
}
