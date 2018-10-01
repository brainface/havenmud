#include <lib.h>
inherit LIB_BOARD;

static void create() {
  bboard::create();
  SetKeyName("board");
  SetId(({ "board","spell board", "idea board", "spell idea board" }) );
  set_board_id("grymxoria_spell_board");
  SetShort("Spell Idea Board");
  SetLong("This is a discussion board where mages of Grymxoria "
          "can post ideas for new spells. "
          "Type <post> \"topic\" to post a new message. "
          "Typing a '.' on a single line will exit you from "
          "the edit mode. ");
 }
