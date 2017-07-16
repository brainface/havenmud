//-- Torak@Haven --//

#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("ungkhshamanboard");
  SetId(({ "board","faith board" }) );
  set_board_id("ungkhshamanboard");
  SetShort("Kuthar News and Faith Board");
  SetLong("This is where news regarding Kuthar is posted. \n"
          "Feel free to post spell suggestions, or anything else. \n"
          "type <post> \"topic\" to post a new message. \n"
          "typing a '.' on a single line will exit you from \n"
          "the edit mode. ");
 }
