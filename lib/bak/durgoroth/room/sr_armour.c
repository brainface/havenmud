// Title: Durgoroth Town
// File: sr_armour.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract:	Store room for the Durgoroth's Finest Armours
//
// Revision History: 
//


#include <lib.h>
#include "../durgoroth.h"
inherit LIB_STOREROOM;


static void create() {
	storeroom::create();
	SetNoClean(1);
	SetPurgeInterval(7);
	SetInventory( ([
                "/std/armour/shirt/vest_leather" : 3,
                "/std/armour/helmet/helm_open" : 3,
		]) );
	}
