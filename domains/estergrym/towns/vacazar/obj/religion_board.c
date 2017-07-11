// Coded by Zeratul
// 3-29-2000

#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId( ({ "board", "religion board", "skadar faithful board" }) );
  set_board_id("skadar_religion_board");
  SetShort("Skadar Board of the Faithful");
  SetLong(
     "This is where news from the faithful of Skadar is posted. \n" 
     "Type <post> \"topic\" to post a new message. \n"
     "Typing a '.' on a single line will exit you from \n"
     "the edit mode. "
  );
  }
