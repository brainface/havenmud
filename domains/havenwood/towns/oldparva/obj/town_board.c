#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  bboard::create();
   SetKeyName("parvaboard");
   SetShort("the Parva Town Board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "parva","town" }) );
   SetLong("The Parva Town Board waits for those of the town to read "
         "and post on it.");
   SetPreventGet(1);
   set_board_id("parvaboard");
}
