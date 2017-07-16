#include <lib.h>
inherit LIB_BOARD;
 
static void create() {
   bboard::create();
   SetKeyName("board");
   SetShort("the Marn Faith Board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "marn","faith" }) );
   SetLong("This board is for discussing the Marn religion.  To write on it, "
           "type:  post <subject>, where <subject> is the subject "
           "of your message.  To read messages, type:  read <message"
           "number>, where <messagenumber> is the number of the message "
           "you wish to read.");
   SetPreventGet(1);
   set_board_id("marn_faith_board");
}