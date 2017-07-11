//
// The Magildan message board
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("magildanboard");
   SetShort("The Magildan message board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "message", "magildan" }) );
   SetLong("This is the Magildan message board. Feel free to post a "
           "message!");
   set_board_id("magildanboard");
}
