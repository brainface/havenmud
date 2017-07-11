// File: ranger_board.c
// Author: Sabrielle
// Date: August 1998
//
// Discussion board of the Ranger Guild
//

#include <lib.h>
inherit LIB_BOARD;

static void create() {
        bboard::create();
        SetKeyName("board");
        SetId(({ "board","ranger board","ranger guild board" }) );
        set_board_id("ranger_guild_board");
        SetBoardOwners( ({ "blaize" }) );
        SetShort("Ranger Guild Discussion Board");
        SetLong("This is where discussion involving rangers "
                "and the ranger guild is posted, including, "
                "questions and comments of interest to other " 
                "guild members.");
        }

