// Title: Durgoroth Town
// File: faithful_board.c
// Author: Tim Morris aka Morgoth@Haven
// Date: May 1998
//
// Abstract: Discussion board for the Faithful of Saa'HaGoth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_BOARD;

static void create() {
	bboard::create();
	SetKeyName("board");
	SetId(({ "board","faithful board","saa'hagoth board",
		"Saahagoth board" }) );
	set_board_id("saahagoth_faithful_board");
	SetShort("Faithful of Saa'HaGoth Discussion Board");
	SetLong("This is where the faithful of Saa'HaGoth \n"
		"can post notes of interest to each other. \n"
		"Type <post> \"topic\" to post a new message. \n"
		"Typing a '.' on a single line will exit you from \n"
		"the edit mode.");
	}
