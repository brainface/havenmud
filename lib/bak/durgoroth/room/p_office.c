// Title: Durgoroth Town
// File: p_office.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: Durgoroth post office
//
// Revision History: 
//

#include <lib.h>
inherit LIB_POST_OFFICE;
#include "../durgoroth.h"
 
static void create() {
	post_office::create();
	SetTown("Durgoroth");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetShort("Durgoroth Post Office");
	SetLong("This is the city post office of Durgoroth. \n"
		"From here, citizens may send and receive their mail by typing \n"
		"<mail>.  Once in, simply follow the instructions.");
	SetObviousExits("out");
	SetExits( ([
		"out" : D_ROOM + "/road09",
		 ]) );
	SetProperty("no attack",1);
 SetProperty("no magic", 1);
	SetProperty("no bump",1);
	}

