#include <lib.h>
inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "parva","town" }) );
   SetShort("the Parva Town Board");
   SetLong("The Parva Town Board is for citizens and visitors to "
           "post info relating to Parva.  Type <post> \"topic\" to "
           "post a new message.  Typing a '.' on a single line will "
            "exit you from the edit mode.");
   SetPreventGet("The board is securely nailed to the wall.");
   set_board_id("parvatownboard");
}
