#include <lib.h>
inherit LIB_BBOARD;

static void create() {
  ::create();
  SetShort("an emotes board");
  SetKeyName("board");
  SetId( ({ "board" }) );
  SetAdjectives( ({ "emotes", "emote" }) );
  set_board_id("emotes_bb");
  SetLong("This board is where you should list the emotes you want "
          "to be added to the mud, with as much or as little detail "
          "as you feel like providing. (ie Can it be targeted? "
          "What should the text say? etc)");
}
