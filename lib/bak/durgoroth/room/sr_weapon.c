// Title: Durgoroth Town
// File: sr_weapon.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract:	Store room for the Jugard's Exceptional Weapons
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
                "/std/weapon/melee/cestus" : 3,
                "/std/weapon/melee/brass_knuckles" : 3,
                "/std/weapon/sword" : 3,
                 "/std/weapon/mace" : 3,
                  "/std/weapon/hatchet" : 3,
		]) );
	}
