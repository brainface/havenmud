#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
   SetKeyName("soleilboard");
   SetShort("the Soleil Town Board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "soleil","town" }) );
   SetLong("The Soleil Town Board waits for those of the town to read "
         "and post on it.");
   SetPreventGet(1);
   set_board_id("soleilboard");
}
