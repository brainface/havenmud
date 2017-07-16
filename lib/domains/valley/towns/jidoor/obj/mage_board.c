//
// The Jidoormage Message Board
// Created by Zaxan@Haven
//

#include <lib.h>

inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("mageboard");
   SetAdjectives( ({ "message", "jidoor", "mage" }) );
   SetShort("a message board for Jidoormages");
   SetId( ({ "board" }) );
   SetLong("Crafted out of some dense white material, this board was created so "
       "Jidoormages could discuss in written word, the issues of their guild.   A "
       "small diagram in the lower right corner indicates that to write on the board, "
  "you must place your finger upon the white surface and use your finger as the "
 "writing instrument."
 );
   set_board_id("jidoor_mage_board");
}
