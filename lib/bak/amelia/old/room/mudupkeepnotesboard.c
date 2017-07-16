#include <lib.h>
inherit LIB_BOARD;

static void create() {
   bboard::create();
   SetShort("the Mud Upkeep Board");
   SetId( ({ "board" }) );
   SetAdjectives( ({ "mud","upkeep","notes" }) );
   SetKeyName("Mud Upkeep Board");
   SetLong("Post about areas/etc. that need fixing.  If your "
          "area/etc. is mentioned, please deal with it and "
           "remove the post when you've got stuff fixed.");
   set_board_id("mudupkeepnotesboard");
}
