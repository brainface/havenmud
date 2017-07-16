// Title: Durgoroth Town
// File: sr_general.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract:	Store room for the Durgoroth general store
//
// Revision History: 


#include <lib.h>
inherit LIB_STOREROOM;
#include "../durgoroth.h"


static void create() {
	storeroom::create();
	SetNoClean(1);
	SetPurgeInterval(7);
	SetInventory( ([
                "/std/lockpicks/newbiepicks" : 6,
		"/std/obj/light/torch" : 2,
		"/std/obj/light/match" : 3,
                "/std/clothing/coat" : 6,
		]) );
	}
