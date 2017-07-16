//
// The Jidoormage Public Message Board
// Created by Zaxan Zimtafarous@Haven
//

#include <lib.h>

inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("mageboard");
   SetAdjectives( ({ "message", "jidoor", "mage" }) );
   SetShort("the Jidoormage's Public Message Board");
   SetId( ({ "board" }) );
   SetLong("This board was erected for jidoormages to make public "
       "posts or for outsiders to post messages for jidoormages. "
      "It looks a bit dusty from misuse."
       
        "little usage."
 );
   set_board_id("jidoor_mage_public_board");
}
