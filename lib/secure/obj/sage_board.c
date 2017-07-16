#include <lib.h>

inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("a sage board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "sage" }) );
  set_board_id("sage_bb");
  SetLong(
     "This board is the primary means of communication between the Sages "
     "on Haven. Please use it. "
  );
}

void init() {
  ::init();
  if (base_name(environment(this_object())) != "/domains/staff/room/sageroom") {
  eventDestruct();
  return;
  }
}
