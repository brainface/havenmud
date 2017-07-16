// Title: Durgoroth Town
// File: town_board.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Discussion board of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_BOARD;

static void create() {
	bboard::create();
	SetKeyName("board");
	SetId(({ "board","town board","durgoroth board",
		"durgoroth discussion board" }) );
	set_board_id("durgoroth_board");
	SetShort("the Durgoroth Discussion Board");
	SetLong("This is where news and discussion involving "
		"Durgoroth town is posted.\n"
		"Type <post> \"topic\" to post a new message. \n"
		"Typing a '.' on a single line will exit you from \n"
		"the edit mode. ");
	}
