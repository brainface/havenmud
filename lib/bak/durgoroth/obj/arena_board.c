// Title: Durgoroth Town
// File: arena_board.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Discussion board of the Durgoroth arena
//
// Revision History: 
//

#include <lib.h>
inherit LIB_BOARD;

static void create() {
	bboard::create();
	SetKeyName("board");
	SetId(({ "board","arena board","durgoroth arena board" }) );
	set_board_id("durgoroth_arena_board");
	SetShort("Durgoroth Arena Discussion Board");
	SetLong("This is where discussion involving warriors \n"
		"and the Durgoroth arena is posted, including, \n"
		"but not limited to challenges.\n"
		"Type <post> \"topic\" to post a new message. \n"
		"Typing a '.' on a single line will exit you from \n"
		"the edit mode.");
	}
