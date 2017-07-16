#include <lib.h>
inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetKeyName("eclatboard");
   SetShort("the board for the Eclat religion");
   SetId( ({ "board","board for eclat religion","board for eclat" }) );
   SetAdjectives( ({ "eclatish" }) );
   SetLong("The Eclatish board waits for those of the faith to read "
           "it and write on it.");
   SetPreventGet(1);
   set_board_id("eclatboard");
}
