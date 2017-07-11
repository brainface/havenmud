#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","spell board" }) );
  set_board_id("haven_spell_board");
  SetShort("Spell Idea Board");
  SetLong("This is an OOC board to post spell ideas on. \n"
          "Reasonable requests will be added to the game. \n" 
          "Also note that this is a way to leave a touch \n"
         "on the game.  Ever heard of \"Tensor's Floating Disk\" \n"
        "in AD&D, well, what about \"Damien's Magic Spell\" \n"
       "Feel free to comment.");
 }
