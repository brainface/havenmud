#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("town builder board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "town","builder" }) );
  set_board_id("town_builder_board");
  SetLong(
     "This board is where anything code related is discussed. Ideals of "
     "religion and items, to verbs and emotes. "
  );
}
