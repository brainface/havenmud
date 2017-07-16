//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 


#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("damhairboard");
  SetShort("the board for the Damhair religion");
  SetId( ({ 
    "board", "religion"
  }) );
  SetAdjectives( ({ 
    "damhair", "religious", "religion", "board", "for", "the" 
  }) );
  SetLong(
    "The Damhair board waits for those of the faith to read "
    "it and write on it.");
  SetPreventGet(1);
  set_board_id("damhairboard");
}
