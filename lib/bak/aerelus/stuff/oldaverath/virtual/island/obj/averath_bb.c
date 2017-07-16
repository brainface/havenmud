#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("a wall with notes on it");
  SetKeyName("wall");
  SetId( ({ "wall", "note", "notes" }) );
  SetAdjectives( ({ "wall", "with" }) );
  set_board_id("averath_bb");
}
