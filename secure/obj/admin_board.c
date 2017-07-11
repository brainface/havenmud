#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("an admin board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "staff" }) );
  set_board_id("admin_bb");
  SetLong("This board is the primary means of communication "
          "between the Admins on Haven.  Please use it.");
}

void init() {
  ::init();
  if (base_name(environment(this_object())) != "/domains/staff/room/admin") {
   eventDestruct();
   return;
  }
}
