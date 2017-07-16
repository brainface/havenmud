//
// The Jidoor Message Board
// Created by Zaxan@Haven
//

#include <lib.h>

inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("jidoorboard");
   SetAdjectives( ({ "message", "jidoor" }) );
   SetShort("The Jidoor message board");
   SetId( ({ "board" }) );
   SetLong("This is the Jidoor message board. Feel free to post a "
           "message!");
   set_board_id("jidoorboard");
}