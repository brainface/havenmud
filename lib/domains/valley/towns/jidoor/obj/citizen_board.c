#include <lib.h>

inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("jidoorboard");
   SetAdjectives( ({ "message", "jidoor" }) );
   SetShort("The Jidoor Citizens' Message Board");
   SetId( ({ "board" }) );
   SetLong("This is the Jidoor Citizens' message board. " 
           "Feel free to post a message!");
   set_board_id("jidoor_citizen_board");
}
