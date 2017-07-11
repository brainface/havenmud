#include <lib.h>

inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("an arch board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "arch" }) );
  set_board_id("arch_bb");
  SetLong(
     "This board is the primary means of communication between the Archs "
     "on Haven. Please use it. "
  );
}

void init() {
  ::init();
  if (base_name(environment(this_object())) != "/domains/staff/room/archroom") {
  eventDestruct();
  return;
  }
}
