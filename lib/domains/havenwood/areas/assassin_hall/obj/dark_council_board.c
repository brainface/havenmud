// Davantalus@Haven 20000107
//
// Discussion board of the Dark Council Guild
//

#include <lib.h>
inherit LIB_BOARD;

static void create() {
        bboard::create();
        SetKeyName("board");
        SetId(({ "board","dark council board","council board" }) );
        set_board_id("dark_council_guild_board");
        SetShort("Dark Council Guild Discussion Board");
        SetLong("This is where matters of guild and member "
                       "are discussed. Questions and comments of "
                       "interest to other guild members should also "
                       "be placed here.");
        }
