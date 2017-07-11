//
// A ladder
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"
#include <climb.h>

inherit LIB_DUMMY;
inherit LIB_CLIMB;

static void create() {
	dummy::create();
        SetKeyName("ladder");
	SetId( ({ "ladder", "small ladder", "wooden ladder, "
		  "small, wooden ladder" }) );
	SetShort("a small, wooden ladder");
	SetLong("This small ladder looks very unsturdy, yet still capable "
		"of holding a good deal of weight.");
	SetClimb(ROOM "/mt1", CLIMB_UP);
}


/* Approved by Balishae on Mon Nov 24 06:55:04 1997. */
