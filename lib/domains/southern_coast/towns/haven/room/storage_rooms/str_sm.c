//
// The Smithy Storage Room
// Filename: str_sm.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//
// mahk 2018: added more general weapons

#include <lib.h>
#include <std.h>
#include "../haven.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetPurgeInterval(3);
   SetInventory( ([
     "/std/weapon/melee/brass_knuckles" : 3,
     "/std/weapon/pole/staff" : 2,
     "/std/weapon/slash/longsword" : 2,
     "/std/weapon/blunt/iron_mace" : 2,
     "/std/weapon/knife/stiletto" : 2,
     "/std/weapon/projectile/long_bow" : 2,
   ]) );
}


/* Approved by Haun on Tue Apr 27 21:19:12 1999. */


