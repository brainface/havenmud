#include <lib.h>
inherit LIB_BOARD;
 
static void create() {
   bboard::create();
   SetKeyName("board");
   SetShort("the Ditmar Town Board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "ditmar","town" }) );
   SetLong("This board is for discussing Ditmar.  To write on it, "
           "type:  post <subject>, where <subject> is the subject "
           "of your message.  To read messages, type:  read <message"
           "number>, where <messagenumber> is the number of the message "
           "you wish to read.");
   SetPreventGet(1);
   set_board_id("ditmar_town_board");
}