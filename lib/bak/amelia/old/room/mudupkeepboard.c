#include <lib.h>
inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetShort("Mud Upkeep Board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "mud","upkeep" }) );
   SetKeyName("mudupkeepboard");
   SetLong("mudupkeepboard:amelia and haun only");
   set_board_id("mudupkeepboard");
}
