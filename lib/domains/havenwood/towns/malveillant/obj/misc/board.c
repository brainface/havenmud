#include <lib.h>

inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("malveillantboard");
   SetAdjectives( ({ "message", "malveillant" }) );
   SetShort("The Malveillant Citizen's Message Board");
   SetId( ({ "board" }) );
   SetLong("This is the Malveillant Citizen's message board. " 
           "Feel free to post a message!");
   set_board_id("malveillant_citizen_board");
}
